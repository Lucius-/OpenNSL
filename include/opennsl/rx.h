/** \addtogroup pkt Packet Transmit and Receive
 *  @{
 */
/*****************************************************************************
 * 
 * (C) Copyright Broadcom Corporation 2013-2014
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * 
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 ***************************************************************************//**
 * \file			rx.h
 ******************************************************************************/

#ifndef __OPENNSL_RX_H__
#define __OPENNSL_RX_H__

#include <opennsl/types.h>
#include <opennsl/pkt.h>
#include <opennsl/tx.h>

#define OPENNSL_RX_CHANNELS     4          /**< Max. number of RX channels. */
#define OPENNSL_RCO_F_ALL_COS   0x40000000 
/** Return values from PKT RX callout routines. */
typedef enum opennsl_rx_e {
    rxReservedEnum1, 
    OPENNSL_RX_NOT_HANDLED,     /**< Packet not processed. */
    rxReservedEnum2, 
    OPENNSL_RX_HANDLED_OWNED    /**< Packet handled and owned. */
} opennsl_rx_t;

typedef opennsl_rx_t (*opennsl_rx_cb_f)(
    int unit, 
    opennsl_pkt_t *pkt, 
    void *cookie);

typedef int (*opennsl_rx_alloc_f)(
    int reserved1, 
    int reserved2, 
    uint32 reserved3, 
    void **reserved4);

typedef int (*opennsl_rx_free_f)(
    int reserved1, 
    void *reserved2);

/** 
 * Channel-specific RX data.
 * 
 * The number of chains allowed for the channel controls the burst size
 * that the channel accepts.
 * 
 * The 'rate_pps' field is DEPRECATED. The rate may be set on a per-COS
 * basis using opennsl_rx_rate_set/get.
 * 
 * IMPORTANT: If OPENNSL_RX_F_MULTI_DCB is NOT used (single DCB per
 * packet) then the rx_free routine must be given the allocation pointer
 * (pkt->alloc_ptr) rather than the packet data pointer
 * (pkt->_pkt_data.data or pkt->pkt_data[0].data).
 */
typedef struct opennsl_rx_chan_cfg_s {
    int reserved1; 
    int reserved2; 
    int reserved3; 
    uint32 reserved4; 
} opennsl_rx_chan_cfg_t;

/** User-configurable, per-unit RX configuration. */
typedef struct opennsl_rx_cfg_s {
    int pkt_size;                       /**< Default packet size. */
    int pkts_per_chain;                 /**< Packets per DMA chain. */
    int global_pps;                     /**< Global rate limiting as packets per
                                           second. */
    int max_burst;                      /**< Max. packets to be received in a
                                           single burst. */
    opennsl_rx_chan_cfg_t chan_cfg[OPENNSL_RX_CHANNELS]; /**< RX channel configuration. */
    opennsl_rx_alloc_f rx_alloc;        /**< RX packet allocation function. */
    opennsl_rx_free_f rx_free;          /**< RX packet free function. */
    int32 flags;                        /**< See OPENNSL_RX_F_* definitions. */
} opennsl_rx_cfg_t;

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Start packet reception for the given device.
 *
 *\description If cfg is non-NULL, that configuration is copied to the device's
 *          local configuration.  The rx_alloc and rx_free members of cfg may
 *          be NULL in which case the default values for these functions are
 *          used.  These are normally the =opennsl_rx_pool_alloc functions.
 *          If the RX thread is not already running (only one thread runs for
 *          all devices) then that thread is started.
 *
 *\param    unit [IN]   Unit number.
 *\param    cfg [IN]   Configuration to use (may be NULL)
 *
 *\retval    OPENNSL_E_NONE Success; RX is now running on the device
 *\retval    OPENNSL_E_PARAM Invalid device or pkt_size/pkts_per_chain is 0
 *\retval    OPENNSL_E_MEMORY Unable to allocate necessary objects for
 *          initialization
 ******************************************************************************/
extern int opennsl_rx_start(
    int unit, 
    opennsl_rx_cfg_t *cfg) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Stop the RX software module.
 *
 *\description If RX is running on the given device, it will be given an
 *          indication that it should stop.  If this is the last device
 *          running, the RX thread will be signaled to terminate.  This
 *          function polls for acknowledgment of that operation will sleep
 *          between polls.  The current settings force will result in checking
 *          for acknowledgment 10 times at one-half second intervals.  A
 *          warning may be printed if the thread does not exit.
 *
 *\param    unit [IN]   Unit number.
 *\param    cfg [OUT]   Saved configuration state
 *
 *\retval    OPENNSL_E_NONE Success; RX is no longer running on this device
 ******************************************************************************/
extern int opennsl_rx_stop(
    int unit, 
    opennsl_rx_cfg_t *cfg) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Register or unregister to receive callbacks for received packets.
 *
 *\description See =opennsl_rx_reg_f for more information about the registration
 *          prototype.
 *          See =opennsl_rx_cb_f for more information about the callback
 *          function prototype for callback.  In particular, see =opennsl_rx_t
 *          for the legal return values of the callback.
 *          The callback is placed on an ordered list associated with the
 *          given device and will be called when packets are received on that
 *          device
 *          To set the interrupt and CoS settings for the callback, the flags
 *          parameter should be properly configured with the macros described
 *          above in =rx_callback_flags .
 *          As mentioned, callbacks may be registered to receive packets in
 *          interrupt context.  This is generally not recommended.
 *          A function may be registered multiple times with different
 *          priorities.  However, if the same function and priority are
 *          registered twice, the flags and cookie must match.  .
 *
 *\param    unit [IN]   Unit number.
 *\param    name [IN]   String to identify function; for reporting only
 *\param    callback [IN]   Function pointer to be called
 *\param    priority [IN]   Relative priority of the callback; 0 is lowest
 *\param    cookie [IN]   Application data passed on callback
 *\param    flags [IN]   CoS and interrupt level flags; see =rx_callback_flags
 *
 *\retval    OPENNSL_E_NONE Success
 *\retval    OPENNSL_E_MEMORY Could not allocate an entry on the callback list
 *\retval    OPENNSL_E_PARAM Register was called with a NULL callback or
 *          re-registered with mismatched flags or cookie.
 ******************************************************************************/
extern int opennsl_rx_register(
    int unit, 
    const char *name, 
    opennsl_rx_cb_f callback, 
    uint8 priority, 
    void *cookie, 
    uint32 flags) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Register or unregister to receive callbacks for received packets.
 *
 *\description See =opennsl_rx_reg_f for more information about the registration
 *          prototype.
 *          See =opennsl_rx_cb_f for more information about the callback
 *          function prototype for callback.  In particular, see =opennsl_rx_t
 *          for the legal return values of the callback.
 *          The callback is placed on an ordered list associated with the
 *          given device and will be called when packets are received on that
 *          device
 *          To set the interrupt and CoS settings for the callback, the flags
 *          parameter should be properly configured with the macros described
 *          above in =rx_callback_flags .
 *          As mentioned, callbacks may be registered to receive packets in
 *          interrupt context.  This is generally not recommended.
 *          A function may be registered multiple times with different
 *          priorities.  However, if the same function and priority are
 *          registered twice, the flags and cookie must match.  .
 *
 *\param    unit [IN]   Unit number.
 *\param    callback [IN]   Function pointer to be called
 *\param    priority [IN]   Relative priority of the callback; 0 is lowest
 *
 *\retval    OPENNSL_E_NONE Success
 *\retval    OPENNSL_E_MEMORY Could not allocate an entry on the callback list
 *\retval    OPENNSL_E_PARAM Register was called with a NULL callback or
 *          re-registered with mismatched flags or cookie.
 ******************************************************************************/
extern int opennsl_rx_unregister(
    int unit, 
    opennsl_rx_cb_f callback, 
    uint8 priority) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Allocate or deallocate a packet buffer as configured.
 *
 *\description The RX module is configured with the =opennsl_rx_cfg_t structure
 *          which includes a pointer to packet buffer allocation and
 *          deallocation routines.  These functions are a gateway to those
 *          configured functions which, by default, are the
 *          =opennsl_rx_pool_alloc functions.
 *
 *\param    unit [IN]   Unit number.
 *\param    pkt_data [IN]   For opennsl_rx_free, pointer to the data to free
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_MEMORY Otherwise
 ******************************************************************************/
extern int opennsl_rx_free(
    int unit, 
    void *pkt_data) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#if defined(OPENNSL_RPC_SUPPORT) || defined(OPENNSL_RCPU_SUPPORT)
#endif
#endif /* __OPENNSL_RX_H__ */
/*@}*/

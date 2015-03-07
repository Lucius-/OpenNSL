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
 * \file			pkt.h
 ******************************************************************************/

#ifndef __OPENNSL_PKT_H__
#define __OPENNSL_PKT_H__

#include <shared/rx.h>
#include <opennsl/types.h>
#include <opennsl/vlan.h>

/** 
 * The packet structure. The packet layout is as follows:
 * 
 *   DMAC + SMAC     12 bytes
 *   VLAN tag         4 bytes (may be filled in by SW on network switch)
 *   payload          N bytes
 *   CRC              4 bytes
 *   pad              M bytes
 *   SL tag           4 bytes (may be unused)
 *   HiGig Header    12 bytes (may be unused)
 * 
 * The rule is: alloc_len = 12 + 4 + N + 4 + M + 4 + 12 (all of above).
 * payload_len (below) is N.
 * 
 * Note that the payload may grow until M == 0; the CRC moves. The SL and
 * HiGig headers will not move.
 * 
 * The "IEEE packet" is everything from the DMAC through the CRC
 * (inclusive), not including SL tag or HiGig header.
 * 
 * Scatter/gather is used to put the data into the right positions on
 * transmit and receive. The SL/HiGig headers are parsed on RX into data
 * members in the packet structure. On TX, opennsl_tx will send the
 * packet according to the unit type. It will not check or affect any
 * fields except maybe the CRC. Other routines will be provided to ensure
 * the HiGig and SL tags are properly set up from the data in the packet
 * structure.
 */
typedef struct opennsl_pkt_s opennsl_pkt_t;

typedef void (*opennsl_pkt_cb_f)(
    int reserved1, 
    opennsl_pkt_t *reserved2, 
    void *reserved3);

/** OPENNSL packet gather block type. */
typedef struct opennsl_pkt_blk_s {
    uint8 *data;    
    int len;        
} opennsl_pkt_blk_t;

/** Set of 'reasons' (see opennslRxReason*) why a packet came to the CPU. */
typedef _shr_rx_reasons_t opennsl_rx_reasons_t;

/** Stacking header packet forwarding options. */
typedef enum opennsl_pkt_stk_forward_e {
    pktReservedEnum1, 
    pktReservedEnum2, 
    pktReservedEnum3, 
    pktReservedEnum4, 
    pktReservedEnum5, 
    pktReservedEnum6, 
    pktReservedEnum7, 
    pktReservedEnum8, 
    pktReservedEnum9, 
    pktReservedEnum10, 
    pktReservedEnum11, 
    pktReservedEnum12, 
    pktReservedEnum13, 
    pktReservedEnum14, 
    pktReservedEnum15 
} opennsl_pkt_stk_forward_t;

/** Decap Tunnel Types */
typedef enum opennsl_rx_decap_tunnel_e {
    opennslpktReservedEnum16, 
    opennslpktReservedEnum17, 
    opennslpktReservedEnum18, 
    opennslpktReservedEnum19, 
    opennslpktReservedEnum20, 
    opennslpktReservedEnum21, 
    opennslpktReservedEnum22, 
    opennslpktReservedEnum23, 
    opennslpktReservedEnum24, 
    opennslpktReservedEnum25, 
    opennslpktReservedEnum26, 
    opennslpktReservedEnum27, 
    opennslpktReservedEnum28, 
    opennslpktReservedEnum29, 
    opennslpktReservedEnum30, 
    opennslpktReservedEnum31, 
    opennslpktReservedEnum32, 
    opennslpktReservedEnum33, 
    opennslpktReservedEnum34 
} opennsl_rx_decap_tunnel_t;

/** OAM DM timestamp options. */
typedef enum opennsl_pkt_timestamp_mode_e {
    pktReservedEnum35, 
    pktReservedEnum36, 
    pktReservedEnum37, 
    pktReservedEnum38 
} opennsl_pkt_timestamp_mode_t;

/** OAM LM counter options. */
typedef enum opennsl_pkt_oam_lm_counter_mode_e {
    pktReservedEnum39, 
    pktReservedEnum40, 
    pktReservedEnum41, 
    pktReservedEnum42 
} opennsl_pkt_oam_lm_counter_mode_t;

/** Initialize a OPENNSL packet structure. */
struct opennsl_pkt_s { 
    opennsl_pkt_blk_t *pkt_data;        /**< Pointer to array of data blocks. */
    uint8 blk_count;                    /**< Number of blocks in data array. */
    uint8 unit;                         /**< Unit number. */
    uint8 reserved1; 
    uint8 reserved2; 
    opennsl_vlan_t vlan;                /**< 802.1q VID or VSI or VPN. */
    uint8 reserved3; 
    uint8 reserved4; 
    opennsl_vlan_t reserved5; 
    uint8 reserved6; 
    uint8 reserved7; 
    opennsl_color_t reserved8; 
    int8 src_port;                      /**< Source port used in header/tag. */
    opennsl_trunk_t reserved9; 
    uint16 reserved10; 
    uint8 reserved11; 
    uint16 reserved12; 
    uint8 reserved13; 
    opennsl_gport_t reserved14; 
    opennsl_gport_t reserved15; 
    opennsl_multicast_t reserved16; 
    uint32 reserved17; 
    opennsl_pkt_stk_forward_t reserved18; 
    uint32 reserved19; 
    uint32 reserved20; 
    uint32 reserved21; 
    uint32 reserved22; 
    opennsl_if_t reserved23; 
    uint16 pkt_len;                     /**< Packet length according to flags. */
    uint16 reserved24; 
    opennsl_pbmp_t tx_pbmp;             /**< Target ports. */
    opennsl_pbmp_t tx_upbmp;            /**< Untagged target ports. */
    opennsl_pbmp_t reserved25; 
    uint8 reserved26; 
    uint32 reserved27; 
    opennsl_rx_reasons_t reserved28; 
    uint32 reserved29; 
    uint8 reserved30; 
    uint8 reserved31; 
    uint8 reserved32; 
    uint8 reserved33; 
    uint32 reserved34; 
    uint32 reserved35; 
    opennsl_if_t reserved36; 
    opennsl_vlan_action_t reserved37; 
    opennsl_vlan_action_t reserved38; 
    uint32 reserved39; 
    uint32 reserved40; 
    uint32 reserved41; 
    void *reserved42; 
    void *reserved43; 
    opennsl_pkt_cb_f call_back;         /**< Callback function. */
    uint32 flags;                       /**< OPENNSL_PKT_F_xxx flags. */
    void *reserved44; 
    int8 reserved45; 
    opennsl_pkt_blk_t _pkt_data;        /**< For single block packets (internal). */
    opennsl_pkt_t *reserved46; 
    void *reserved47; 
    int8 reserved48; 
    opennsl_pkt_t *reserved49; 
    void *reserved50; 
    void *reserved51; 
    uint8 reserved52[16]; 
    uint8 reserved53[12]; 
    uint8 reserved54[4]; 
    uint8 reserved55[4]; 
    uint8 reserved56[16]; 
    uint8 reserved57; 
    uint8 reserved58[10]; 
    int reserved59; 
    int reserved60; 
    uint32 reserved61; 
    opennsl_pbmp_t reserved62; 
    opennsl_pbmp_t reserved63; 
    uint32 reserved64; 
    uint8 reserved65; 
    uint8 reserved66; 
    uint16 reserved67; 
    uint32 reserved68; 
    void *reserved69; 
    uint16 reserved70; 
    uint16 reserved71; 
    opennsl_pkt_timestamp_mode_t reserved72; 
    opennsl_pkt_oam_lm_counter_mode_t reserved73; 
    opennsl_pkt_oam_lm_counter_mode_t reserved74; 
    uint8 reserved75; 
    opennsl_rx_decap_tunnel_t reserved76; 
    opennsl_gport_t reserved77; 
    opennsl_gport_t reserved78; 
    uint32 reserved79; 
    int reserved80; 
    opennsl_gport_t reserved81; 
    uint32 reserved82; 
    uint32 reserved83; 
};

#define OPENNSL_TX_CRC_ALLOC    0x10       /**< Allocate buffer for CRC. */
#define OPENNSL_TX_CRC_REGEN    0x20       /**< Regenerate CRC. */
#define OPENNSL_TX_CRC_APPEND   (OPENNSL_TX_CRC_ALLOC + OPENNSL_TX_CRC_REGEN) 
#define OPENNSL_TX_ETHER        0x100000   /**< Fully mapped packet TX. */
#define OPENNSL_PKT_ONE_BUF_SETUP(pkt, buf, _len)  \
    do { \
        (pkt)->_pkt_data.data = (buf); \
        (pkt)->_pkt_data.len = (_len); \
        (pkt)->pkt_data = &(pkt)->_pkt_data; \
        (pkt)->blk_count = 1; \
    } while (0) 
/***************************************************************************//** 
 *\brief Initialize packet flags based on the type of device.
 *
 *\description Based on the device type of unit, initializes the flags for
 *          opennsl_pkt_t starting with init_flags.
 *
 *\param    unit [IN]   Unit number.
 *\param    pkt [IN]   Packet structure to modify
 *\param    init_flags [IN]   Initial flags to start with
 *
 *\retval    OPENNSL_E_NONE On success
 ******************************************************************************/
extern int opennsl_pkt_flags_init(
    int unit, 
    opennsl_pkt_t *pkt, 
    uint32 init_flags) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Allocate or deallocate a packet structure and packet data.
 *
 *\description opennsl_pkt_alloc will allocate a packet structure using
 *          sal_alloc, allocate a packet data buffer of size bytes using
 *          soc_cm_salloc and then link this buffer into the packet structure.
 *           It will call =opennsl_pkt_flags_init to set up the packet.
 *          opennsl_pkt_free deallocates a packet allocated by
 *          opennsl_pkt_alloc.
 *          opennsl_pkt_free supports freeing multiple packet data blocks.
 *          opennsl_pkt_alloc does not currently work when unit is a remote
 *          device.
 *
 *\param    unit [IN]   Unit number.
 *\param    size [IN]   Number of bytes to allocate for buffer space
 *\param    flags [IN]   Initial flags for the packet structure
 *\param    pkt_buf [OUT]   Structure to be allocated.
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_MEMORY Not enough memory - pkt_buf will be NULL
 ******************************************************************************/
extern int opennsl_pkt_alloc(
    int unit, 
    int size, 
    uint32 flags, 
    opennsl_pkt_t **pkt_buf) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Allocate or deallocate a packet structure and packet data.
 *
 *\description opennsl_pkt_alloc will allocate a packet structure using
 *          sal_alloc, allocate a packet data buffer of size bytes using
 *          soc_cm_salloc and then link this buffer into the packet structure.
 *           It will call =opennsl_pkt_flags_init to set up the packet.
 *          opennsl_pkt_free deallocates a packet allocated by
 *          opennsl_pkt_alloc.
 *          opennsl_pkt_free supports freeing multiple packet data blocks.
 *          opennsl_pkt_alloc does not currently work when unit is a remote
 *          device.
 *
 *\param    unit [IN]   Unit number.
 *\param    pkt [IN]   Structure to be allocated.
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_MEMORY Not enough memory - pkt_buf will be NULL
 ******************************************************************************/
extern int opennsl_pkt_free(
    int unit, 
    opennsl_pkt_t *pkt) LIB_DLL_EXPORTED ;

#endif /* __OPENNSL_PKT_H__ */
/*@}*/

/** \addtogroup port Port Management
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
 * \file			port.h
 ******************************************************************************/

#ifndef __OPENNSL_PORT_H__
#define __OPENNSL_PORT_H__

#include <shared/portmode.h>
#include <shared/port.h>
#include <shared/switch.h>
#include <opennsl/types.h>
#include <opennsl/stat.h>
#include <shared/port_ability.h>

#define OPENNSL_PIPES_MAX       _SHR_SWITCH_MAX_PIPES 
/** Port Configuration structure. */
typedef struct opennsl_port_config_s {
    opennsl_pbmp_t fe;                  /**< Mask of FE ports. */
    opennsl_pbmp_t ge;                  /**< Mask of GE ports. */
    opennsl_pbmp_t xe;                  /**< Mask of 10gig ports. */
    opennsl_pbmp_t ce;                  /**< Mask of 100gig ports. */
    opennsl_pbmp_t e;                   /**< Mask of eth ports. */
    opennsl_pbmp_t hg;                  /**< Mask of Higig ports. */
    opennsl_pbmp_t sci;                 /**< Mask of SCI ports. */
    opennsl_pbmp_t sfi;                 /**< Mask of SFI ports. */
    opennsl_pbmp_t spi;                 /**< Mask of SPI ports. */
    opennsl_pbmp_t spi_subport;         /**< Mask of SPI subports. */
    opennsl_pbmp_t port;                /**< Mask of all front panel ports. */
    opennsl_pbmp_t cpu;                 /**< Mask of CPU ports. */
    opennsl_pbmp_t all;                 /**< Mask of all ports. */
    opennsl_pbmp_t stack_int;           /**< Deprecated - unused. */
    opennsl_pbmp_t stack_ext;           /**< Mask of Stack ports. */
    opennsl_pbmp_t tdm;                 /**< Mask of TDM ports. */
    opennsl_pbmp_t pon;                 /**< Mask of PON ports. */
    opennsl_pbmp_t llid;                /**< Mask of LLID ports. */
    opennsl_pbmp_t il;                  /**< Mask of ILKN ports. */
    opennsl_pbmp_t xl;                  /**< Mask of XLAUI ports. */
    opennsl_pbmp_t rcy;                 /**< Mask of RECYCLE ports. */
    opennsl_pbmp_t per_pipe[OPENNSL_PIPES_MAX]; /**< Mask of ports per pipe. The number of
                                           pipes per device can be obtained via
                                           num_pipes field of opennsl_info_t. */
} opennsl_port_config_t;

/** Port ability */
typedef _shr_port_ability_t opennsl_port_ability_t;

/** 
 * Port ability mask.
 * 
 * The following flags are used to indicate which set of capabilities are
 * provided by a PHY or MAC when retrieving the ability of a port,
 * setting or getting the local advertisement, getting the remote
 * advertisement, or setting the MAC encapsulation and/or CRC modes.
 */
typedef _shr_port_mode_t opennsl_port_abil_t;

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Retrieved the port configuration for the specified device.
 *
 *\description opennsl_port_config_get returns all known ports configured on the
 *          specified device.
 *          The logical information indicates port bit maps to represent the
 *          ports on the specified unit (see the Broadcom Network Switching
 *          Stacking Guide for a description of logical port lists).
 *          =OPENNSL_PORT_CONFIG_t describes the meaning of each field.
 *
 *\param    unit [IN]   Unit number.
 *\param    config [OUT]   Pointer to port configuration structure populated on
 *          successful return.
 *
 *\retval    OPENNSL_E_NONE
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_port_config_get(
    int unit, 
    opennsl_port_config_t *config) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Enable or disable a port.
 *
 *\description Controls whether a port is enabled or disabled for transmission
 *          and reception of packets.  The chip should not be configured so as
 *          to switch any packets to a disabled port because the packets may
 *          build up in the MMU.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    enable [IN]   Boolean value indicating enable (1) or disable (0).
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_XXX Operation failed, if retrieving the current enabled
 *          state, the value of the parameter enable is undefined.
 ******************************************************************************/
extern int opennsl_port_enable_set(
    int unit, 
    opennsl_port_t port, 
    int enable) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Get or set the default VLAN for packets that ingress untagged.
 *
 *\description All packets that ingress a port untagged are treated as if they
 *          were tagged with the value specified by
 *          opennsl_port_untagged_vlan_set. All ports are initially configured
 *          with the untagged VLAN set to the default VLAN (or VLAN 1). If the
 *          packet egresses on a port that is configured as a tagged port, the
 *          VLAN ID in the egressing packet is set to this value.
 *          If the (port,vid) resolves to a VLAN gport, untagged packets will
 *          be sent to the to the VLAN port, and not the default VLAN. 
 *          Similarly, if (port,vid) resolves to a MPLS gport, untagged
 *          packets will be sent to the MPLS port and not to the default VLAN.
 *           In either case, the value does not affect the egress behavior of
 *          packets.
 *          To affect egress behavior of a VLAN gport, a GPORT ID is passed as
 *          the  port parameter.  The vid is used as the untagged vid on
 *          ingress into a PEP.  Specifically, when an STAG only packet
 *          arrives on a provider port, and egresses a customer port, the
 *          given vid is added to the untagged packet on egress.
 *          These APIs can also be used for WLAN gports. They will set/get the
 *          default  VLAN for untagged packets coming in from a WLAN source
 *          port.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device port number or logical device
 *\param    vid [IN]   VLAN ID used for packets that ingress the port untagged.
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_UNAVAIL The specified port cannot have an untagged VLAN.
 *\retval    OPENNSL_E_PARAM Invalid port or VLAN ID.
 *\retval    OPENNSL_E_XXX Operation failed
 ******************************************************************************/
extern int opennsl_port_untagged_vlan_set(
    int unit, 
    opennsl_port_t port, 
    opennsl_vlan_t vid) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Get or set the current operating speed of a port.
 *
 *\description Set or get the speed of the specified port. opennsl_port_speed_set
 *          disables auto-negotiation if it is enabled. When setting a speed,
 *          if an error is returned the PHY and the MAC may not be properly
 *          set for operation. A value of 0 indicates, set max speed. For
 *          correct operation  following an error, a valid speed must be set.
 *          When retrieving the current speed of a port, if auto-negotiation
 *          is enabled the current negotiated speed is returned. If
 *          auto-negotiation is in progress or there is no link, speed
 *          returned is undefined. If auto-negotiation is disabled, the forced
 *          speed of the port is returned regardless of the link state.
 *          opennsl_port_speed_max returns the maximum possible operating
 *          speed of the port based on the attributes of the MAC and the PHY.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    speed [OUT]   Speed specified in Mbps.
 *
 *\retval    OPENNSL_E_NONE Speed set or retrieved as requested.
 *\retval    OPENNSL_E_INIT Port module not initialized, see .
 *\retval    OPENNSL_E_CONFIG The requested port speed is not supported. In some
 *          configurations the actual speed of the MAC is derived from the PHY
 *          directly and can not be forced to a specific value.
 *\retval    OPENNSL_E_XXX Error occurred, if retrieving port speed, the returned
 *          speed is undefined. If setting speed, the operational state of the
 *          port is undefined.
 ******************************************************************************/
extern int opennsl_port_speed_max(
    int unit, 
    opennsl_port_t port, 
    int *speed) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Get or set the current operating speed of a port.
 *
 *\description Set or get the speed of the specified port. opennsl_port_speed_set
 *          disables auto-negotiation if it is enabled. When setting a speed,
 *          if an error is returned the PHY and the MAC may not be properly
 *          set for operation. A value of 0 indicates, set max speed. For
 *          correct operation  following an error, a valid speed must be set.
 *          When retrieving the current speed of a port, if auto-negotiation
 *          is enabled the current negotiated speed is returned. If
 *          auto-negotiation is in progress or there is no link, speed
 *          returned is undefined. If auto-negotiation is disabled, the forced
 *          speed of the port is returned regardless of the link state.
 *          opennsl_port_speed_max returns the maximum possible operating
 *          speed of the port based on the attributes of the MAC and the PHY.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    speed [IN]   Speed specified in Mbps.
 *
 *\retval    OPENNSL_E_NONE Speed set or retrieved as requested.
 *\retval    OPENNSL_E_INIT Port module not initialized, see .
 *\retval    OPENNSL_E_CONFIG The requested port speed is not supported. In some
 *          configurations the actual speed of the MAC is derived from the PHY
 *          directly and can not be forced to a specific value.
 *\retval    OPENNSL_E_XXX Error occurred, if retrieving port speed, the returned
 *          speed is undefined. If setting speed, the operational state of the
 *          port is undefined.
 ******************************************************************************/
extern int opennsl_port_speed_set(
    int unit, 
    opennsl_port_t port, 
    int speed) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/** opennsl_port_if_t */
typedef _shr_port_if_t opennsl_port_if_t;

#define OPENNSL_PORT_PHY_CLAUSE45   _SHR_PORT_PHY_CLAUSE45 
#define OPENNSL_PORT_PHY_CLAUSE45_ADDR(_devad, _regad)  \
    _SHR_PORT_PHY_CLAUSE45_ADDR(_devad, _regad) 
#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Read or write PHY registers associated with a port.
 *
 *\description Most PHY-related operations are performed automatically by the API
 *          to satisfy requests. When direct access to the PHY registers are
 *          required for diagnostic purposes or special configuration these
 *          functions can be used. Use of these routines may interfere with
 *          the normal operation of the API, extreme care must be taken when
 *          manipulating PHYs. Normal configuration of speed, duplicity, and
 *          auto-negotiation must be performed using the normal opennsl_port
 *          APIs. .
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    flags [IN]   Flags indicating how to access the PHY, and which PHY if
 *          the port has an internal serdes. See =OPENNSL_PORT_PHY_flags for
 *          details.
 *\param    phy_reg_addr [IN]   Register address in the PHY
 *\param    phy_data [IN]   Data to be written or data read
 *\param    phy_mask [IN]   Mask write data when modifying register
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_UNAVAIL Requested operation not supported
 *\retval    OPENNSL_E_XXX Operation failed
 ******************************************************************************/
extern int opennsl_port_phy_modify(
    int unit, 
    opennsl_port_t port, 
    uint32 flags, 
    uint32 phy_reg_addr, 
    uint32 phy_data, 
    uint32 phy_mask) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/** MDI crossover control. */
typedef _shr_port_mdix_t opennsl_port_mdix_t;

/** MDI crossover status. */
typedef _shr_port_mdix_status_t opennsl_port_mdix_status_t;

/** Combo port control/status. */
typedef _shr_port_medium_t opennsl_port_medium_t;

#define OPENNSL_PORT_LINK_STATUS_UP 1          
#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Retrieve the current link status of a port.
 *
 *\description This call returns the link status of the port. With linkscan
 *          running (see =linkscan ), the current link status is retrieved
 *          from the linkscan task. This is the normal mode of operation, as
 *          link status in the PHY registers is latched low. If multiple
 *          sources (threads) read the physical link status in the PHY
 *          register, the linkscan task and/or applications can miss a link
 *          down event.
 *          If linkscan is not running, the current link status is retrieved
 *          from the PHY directly.
 *          The possible values of status are:.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number.
 *\param    status [OUT]   One of OPENNSL_PORT_LINK_STATUS_*.
 *
 *\retval    OPENNSL_E_NONE Current link state is returned in status
 *\retval    OPENNSL_E_INIT Port module not initialized
 *\retval    OPENNSL_E_XXX Error condition reported from lower layers of software.
 *          In the event of an error code other than OPENNSL_E_NONE, the up
 *          parameter is undefined on return.
 ******************************************************************************/
extern int opennsl_port_link_status_get(
    int unit, 
    opennsl_port_t port, 
    int *status) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#define OPENNSL_PORT_VLAN_MEMBER_INGRESS    0x00000001 
#define OPENNSL_PORT_VLAN_MEMBER_EGRESS     0x00000002 
#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Set or retrieve current behavior of tagged packets arriving/leaving on a
 *       port not a member of the specified VLAN.
 *
 *\description Ingress filtering, if enabled, drops all packets arriving on a
 *          port with a VLAN tag identifying a VLAN of which the port is not a
 *          member. If disabled, packets will not be dropped if the port is
 *          not a member of the VLAN specified in the packet. It may however
 *          be dropped for other reasons such as spanning tree state, head of
 *          line blocking etc. For switch family?III, ingress filtering is
 *          also applied.
 *          This function supersedes =opennsl_port_ifilter_get . Valid
 *          settings for flags are described in
 *          =OPENNSL_PORT_VLAN_MEMBER_FLAGS_table .
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    flags [IN]   Flags to indicate port filtering mode
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_UNAVAIL Operation not supported on underlying device
 *\retval    OPENNSL_E_XXX Operation failed.
 ******************************************************************************/
extern int opennsl_port_vlan_member_set(
    int unit, 
    opennsl_port_t port, 
    uint32 flags) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Get the current count of cells or packets queued on a port for
 *       transmission.
 *
 *\description Returns a count that is either the number of internal device cells
 *          (device specific) or the number of packets queued for egress on
 *          the specified port. In general, the count returned should only be
 *          considered as 0 (indicating there are no packets queued on the
 *          port) or >0 (indicating some packets are queued on the port).
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number.
 *\param    count [OUT]   Returned count of cells or packets queued for egress on
 *          the specified port.
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_BADID Invalid port number specified
 *\retval    OPENNSL_E_UNAVIL Operation not supported on the specified port.
 ******************************************************************************/
extern int opennsl_port_queued_count_get(
    int unit, 
    opennsl_port_t port, 
    uint32 *count) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/** opennsl_port_info_s */
typedef struct opennsl_port_info_s {
    uint32 action_mask;                 /**< OPENNSL_PORT_ATTR_xxx. */
    uint32 action_mask2;                /**< OPENNSL_PORT_ATTR2_xxx. */
    int enable;                         
    int linkstatus;                     
    int autoneg;                        
    int speed;                          
    int duplex;                         
    int linkscan;                       
    uint32 learn;                       
    int discard;                        
    uint32 vlanfilter;                  
    int untagged_priority;              
    opennsl_vlan_t untagged_vlan;       
    int stp_state;                      
    int pfm;                            
    int loopback;                       
    int phy_master;                     
    opennsl_port_if_t interface;        
    int pause_tx;                       
    int pause_rx;                       
    int encap_mode;                     
    opennsl_mac_t pause_mac;            
    opennsl_port_abil_t local_advert;   
    opennsl_port_ability_t local_ability; 
    int remote_advert_valid;            
    opennsl_port_abil_t remote_advert;  
    opennsl_port_ability_t remote_ability; 
    int mcast_limit;                    
    int mcast_limit_enable;             
    int bcast_limit;                    
    int bcast_limit_enable;             
    int dlfbc_limit;                    
    int dlfbc_limit_enable;             
    int speed_max;                      
    opennsl_port_abil_t ability;        
    opennsl_port_ability_t port_ability; 
    int frame_max;                      
    opennsl_port_mdix_t mdix;           
    opennsl_port_mdix_status_t mdix_status; 
    opennsl_port_medium_t medium;       
    uint32 fault;                       
} opennsl_port_info_t;

/** Features that can be controlled on a per-port basis. */
typedef enum opennsl_port_control_e {
    opennslportReservedEnum1 = 0, 
    opennslportReservedEnum2 = 1, 
    opennslportReservedEnum3 = 2, 
    opennslportReservedEnum4 = 3, 
    opennslportReservedEnum5 = 4, 
    opennslportReservedEnum6 = 5, 
    opennslportReservedEnum7 = 6, 
    opennslportReservedEnum8 = 7, 
    opennslPortControlIP4 = 8,          /**< Enable IPv4 Routing on port. */
    opennslPortControlIP6 = 9,          /**< Enable IPv6 Routing on port. */
    opennslportReservedEnum9 = 10, 
    opennslportReservedEnum10 = 11, 
    opennslportReservedEnum11 = 12, 
    opennslportReservedEnum12 = 13, 
    opennslportReservedEnum13 = 14, 
    opennslportReservedEnum14 = 15, 
    opennslportReservedEnum15 = 16, 
    opennslportReservedEnum16 = 17, 
    opennslportReservedEnum17 = 18, 
    opennslportReservedEnum18 = 19, 
    opennslportReservedEnum19 = 20, 
    opennslportReservedEnum20 = 21, 
    opennslportReservedEnum21 = 22, 
    opennslportReservedEnum22 = 23, 
    opennslportReservedEnum23 = 24, 
    opennslportReservedEnum24 = 25, 
    opennslportReservedEnum25 = 26, 
    opennslportReservedEnum26 = 27, 
    opennslportReservedEnum27 = 28, 
    opennslportReservedEnum28 = 29, 
    opennslportReservedEnum29 = 30, 
    opennslportReservedEnum30 = 31, 
    opennslportReservedEnum31 = 32, 
    opennslportReservedEnum32 = 33, 
    opennslportReservedEnum33 = 34, 
    opennslportReservedEnum34 = 35, 
    opennslportReservedEnum35 = 36, 
    opennslportReservedEnum36 = 37, 
    opennslportReservedEnum37 = 38, 
    opennslportReservedEnum38 = 39, 
    opennslportReservedEnum39 = 40, 
    opennslportReservedEnum40 = 41, 
    opennslportReservedEnum41 = 42, 
    opennslportReservedEnum42 = 43, 
    opennslportReservedEnum43 = 44, 
    opennslportReservedEnum44 = 45, 
    opennslportReservedEnum45 = 46, 
    opennslportReservedEnum46 = 47, 
    opennslportReservedEnum47 = 48, 
    opennslportReservedEnum48 = 49, 
    opennslportReservedEnum49 = 50, 
    opennslportReservedEnum50 = 51, 
    opennslportReservedEnum51 = 52, 
    opennslportReservedEnum52 = 53, 
    opennslportReservedEnum53 = 54, 
    opennslportReservedEnum54 = 55, 
    opennslportReservedEnum55 = 56, 
    opennslportReservedEnum56 = 57, 
    opennslportReservedEnum57 = 58, 
    opennslportReservedEnum58 = 59, 
    opennslportReservedEnum59 = 60, 
    opennslportReservedEnum60 = 61, 
    opennslportReservedEnum61 = 62, 
    opennslportReservedEnum62 = 63, 
    opennslportReservedEnum63 = 64, 
    opennslportReservedEnum64 = 65, 
    opennslportReservedEnum65 = 66, 
    opennslportReservedEnum66 = 67, 
    opennslportReservedEnum67 = 68, 
    opennslportReservedEnum68 = 69, 
    opennslportReservedEnum69 = 70, 
    opennslportReservedEnum70 = 71, 
    opennslportReservedEnum71 = 72, 
    opennslportReservedEnum72 = 73, 
    opennslportReservedEnum73 = 74, 
    opennslportReservedEnum74 = 75, 
    opennslportReservedEnum75 = 76, 
    opennslportReservedEnum76 = 77, 
    opennslportReservedEnum77 = 78, 
    opennslportReservedEnum78 = 79, 
    opennslportReservedEnum79 = 80, 
    opennslportReservedEnum80 = 81, 
    opennslportReservedEnum81 = 82, 
    opennslportReservedEnum82 = 83, 
    opennslportReservedEnum83 = 84, 
    opennslportReservedEnum84 = 85, 
    opennslportReservedEnum85 = 86, 
    opennslportReservedEnum86 = 87, 
    opennslportReservedEnum87 = 88, 
    opennslportReservedEnum88 = 89, 
    opennslportReservedEnum89 = 90, 
    opennslportReservedEnum90 = 91, 
    opennslportReservedEnum91 = 92, 
    opennslportReservedEnum92 = 93, 
    opennslportReservedEnum93 = 94, 
    opennslportReservedEnum94 = 95, 
    opennslportReservedEnum95 = 96, 
    opennslportReservedEnum96 = 97, 
    opennslportReservedEnum97 = 98, 
    opennslportReservedEnum98 = 99, 
    opennslportReservedEnum99 = 100, 
    opennslportReservedEnum100 = 101, 
    opennslportReservedEnum101 = 102, 
    opennslportReservedEnum102 = 103, 
    opennslportReservedEnum103 = 104, 
    opennslportReservedEnum104 = 105, 
    opennslportReservedEnum105 = 106, 
    opennslportReservedEnum106 = 107, 
    opennslportReservedEnum107 = 108, 
    opennslportReservedEnum108 = 109, 
    opennslportReservedEnum109 = 110, 
    opennslportReservedEnum110 = 111, 
    opennslportReservedEnum111 = 112, 
    opennslportReservedEnum112 = 113, 
    opennslportReservedEnum113 = 114, 
    opennslportReservedEnum114 = 115, 
    opennslportReservedEnum115 = 116, 
    opennslportReservedEnum116 = 117, 
    opennslportReservedEnum117 = 118, 
    opennslportReservedEnum118 = 119, 
    opennslportReservedEnum119 = 120, 
    opennslportReservedEnum120 = 121, 
    opennslportReservedEnum121 = 122, 
    opennslportReservedEnum122 = 123, 
    opennslportReservedEnum123 = 124, 
    opennslportReservedEnum124 = 125, 
    opennslportReservedEnum125 = 126, 
    opennslportReservedEnum126 = 127, 
    opennslportReservedEnum127 = 128, 
    opennslportReservedEnum128 = 129, 
    opennslportReservedEnum129 = 130, 
    opennslportReservedEnum130 = 131, 
    opennslportReservedEnum131 = 132, 
    opennslportReservedEnum132 = 133, 
    opennslportReservedEnum133 = 134, 
    opennslportReservedEnum134 = 135, 
    opennslportReservedEnum135 = 136, 
    opennslportReservedEnum136 = 137, 
    opennslportReservedEnum137 = 138, 
    opennslportReservedEnum138 = 139, 
    opennslportReservedEnum139 = 140, 
    opennslportReservedEnum140 = 141, 
    opennslportReservedEnum141 = 142, 
    opennslportReservedEnum142 = 143, 
    opennslportReservedEnum143 = 144, 
    opennslportReservedEnum144 = 145, 
    opennslportReservedEnum145 = 146, 
    opennslportReservedEnum146 = 147, 
    opennslportReservedEnum147 = 148, 
    opennslportReservedEnum148 = 149, 
    opennslportReservedEnum149 = 150, 
    opennslportReservedEnum150 = 151, 
    opennslportReservedEnum151 = 152, 
    opennslportReservedEnum152 = 153, 
    opennslportReservedEnum153 = 154, 
    opennslportReservedEnum154 = 155, 
    opennslportReservedEnum155 = 156, 
    opennslportReservedEnum156 = 157, 
    opennslportReservedEnum157 = 158, 
    opennslportReservedEnum158 = 159, 
    opennslportReservedEnum159 = 160, 
    opennslportReservedEnum160 = 161, 
    opennslportReservedEnum161, 
    opennslportReservedEnum162 = 162, 
    opennslportReservedEnum163 = 163, 
    opennslportReservedEnum164 = 164, 
    opennslportReservedEnum165 = 165, 
    opennslportReservedEnum166 = 166, 
    opennslportReservedEnum167 = 167, 
    opennslportReservedEnum168 = 168, 
    opennslportReservedEnum169 = 169, 
    opennslportReservedEnum170 = 170, 
    opennslportReservedEnum171 = 171, 
    opennslportReservedEnum172 = 172, 
    opennslportReservedEnum173 = 173, 
    opennslportReservedEnum174 = 174, 
    opennslportReservedEnum175 = 175, 
    opennslportReservedEnum176 = 176, 
    opennslportReservedEnum177 = 177, 
    opennslportReservedEnum178 = 178, 
    opennslportReservedEnum179 = 179, 
    opennslportReservedEnum180 = 180, 
    opennslportReservedEnum181 = 181, 
    opennslportReservedEnum182 = 182, 
    opennslportReservedEnum183 = 183, 
    opennslportReservedEnum184 = 184, 
    opennslportReservedEnum185 = 185, 
    opennslportReservedEnum186 = 186, 
    opennslportReservedEnum187 = 187, 
    opennslportReservedEnum188 = 188, 
    opennslportReservedEnum189 = 189, 
    opennslportReservedEnum190 = 190, 
    opennslportReservedEnum191 = 191, 
    opennslportReservedEnum192 = 192, 
    opennslportReservedEnum193 = 193, 
    opennslportReservedEnum194 = 194, 
    opennslportReservedEnum195 = 195, 
    opennslportReservedEnum196 = 196, 
    opennslportReservedEnum197 = 197, 
    opennslportReservedEnum198 = 198, 
    opennslportReservedEnum199 = 199, 
    opennslportReservedEnum200 = 200, 
    opennslportReservedEnum201 = 201, 
    opennslportReservedEnum202 = 202, 
    opennslportReservedEnum203 = 203, 
    opennslportReservedEnum204 = 204, 
    opennslportReservedEnum205 = 205, 
    opennslportReservedEnum206 = 206, 
    opennslportReservedEnum207 = 207, 
    opennslportReservedEnum208 = 208, 
    opennslportReservedEnum209 = 209, 
    opennslportReservedEnum210 = 210, 
    opennslportReservedEnum211 = 211, 
    opennslportReservedEnum212 = 212, 
    opennslportReservedEnum213 = 213, 
    opennslportReservedEnum214 = 214, 
    opennslportReservedEnum215 = 215, 
    opennslportReservedEnum216 = 216, 
    opennslportReservedEnum217 = 217, 
    opennslportReservedEnum218 = 218, 
    opennslportReservedEnum219 = 219, 
    opennslportReservedEnum220 = 220, 
    opennslportReservedEnum221 = 221, 
    opennslportReservedEnum222 = 222, 
    opennslportReservedEnum223 = 223, 
    opennslportReservedEnum224 = 224, 
    opennslportReservedEnum225 = 225, 
    opennslportReservedEnum226 = 226, 
    opennslportReservedEnum227 = 227, 
    opennslportReservedEnum228 = 228, 
    opennslportReservedEnum229 = 229, 
    opennslportReservedEnum230 = 230, 
    opennslportReservedEnum231 = 231, 
    opennslportReservedEnum232 = 232, 
    opennslportReservedEnum233 = 233, 
    opennslportReservedEnum234 = 234, 
    opennslportReservedEnum235 = 235, 
    opennslportReservedEnum236 = 236, 
    opennslportReservedEnum237 = 237, 
    opennslportReservedEnum238 = 238, 
    opennslportReservedEnum239 = 239, 
    opennslportReservedEnum240 = 240, 
    opennslportReservedEnum241 = 241, 
    opennslportReservedEnum242 = 242, 
    opennslportReservedEnum243 = 243, 
    opennslportReservedEnum244 = 244, 
    opennslportReservedEnum245 = 245, 
    opennslportReservedEnum246 = 246, 
    opennslportReservedEnum247 = 247, 
    opennslportReservedEnum248 = 248, 
    opennslportReservedEnum249 = 249, 
    opennslportReservedEnum250 = 250, 
    opennslportReservedEnum251 = 251, 
    opennslportReservedEnum252 = 252, 
    opennslportReservedEnum253 = 253, 
    opennslportReservedEnum254 = 254, 
    opennslportReservedEnum255 = 255, 
    opennslportReservedEnum256 = 256, 
    opennslportReservedEnum257 = 257, 
    opennslportReservedEnum258 = 258, 
    opennslportReservedEnum259 = 259, 
    opennslportReservedEnum260 = 260, 
    opennslportReservedEnum261 = 261, 
    opennslportReservedEnum262 = 262, 
    opennslportReservedEnum263 = 263, 
    opennslportReservedEnum264 = 264, 
    opennslportReservedEnum265 = 265, 
    opennslportReservedEnum266 = 266, 
    opennslportReservedEnum267 = 267, 
    opennslportReservedEnum268 = 268, 
    opennslportReservedEnum269 = 269, 
    opennslportReservedEnum270 = 270, 
    opennslportReservedEnum271 = 271, 
    opennslportReservedEnum272 = 272, 
    opennslportReservedEnum273 = 273, 
    opennslportReservedEnum274 = 274, 
    opennslportReservedEnum275 = 275, 
    opennslportReservedEnum276, 
    opennslportReservedEnum277, 
    opennslportReservedEnum278, 
    opennslportReservedEnum279 = 276, 
    opennslportReservedEnum280 = 277, 
    opennslportReservedEnum281 = 278, 
    opennslportReservedEnum282 = 279, 
    opennslportReservedEnum283 = 280, 
    opennslportReservedEnum284 = 281, 
    opennslportReservedEnum285 = 282, 
    opennslportReservedEnum286 = 283, 
    opennslportReservedEnum287 = 284, 
    opennslportReservedEnum288 = 285, 
    opennslportReservedEnum289 = 286, 
    opennslportReservedEnum290 = 287, 
    opennslportReservedEnum291 = 288, 
    opennslportReservedEnum292 = 289, 
    opennslportReservedEnum293 = 290, 
    opennslportReservedEnum294 = 291, 
    opennslportReservedEnum295 = 292, 
    opennslportReservedEnum296 = 293, 
    opennslportReservedEnum297 = 294, 
    opennslportReservedEnum298 = 295, 
    opennslportReservedEnum299 = 296, 
    opennslportReservedEnum300 = 297, 
    opennslportReservedEnum301 = 298, 
    opennslportReservedEnum302 = 299, 
    opennslportReservedEnum303 = 300 
} opennsl_port_control_t;

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Get or set various features at the port level.
 *
 *\description Control or examine various features at the port level.
 *          opennsl_port_control_set can be used to enable/disable various
 *          features at the port level. The <type> parameter to the API
 *          identifies the feature to be controlled.
 *          opennsl_port_control_get returns the current value of the port
 *          feature identified by <type> parameter.
 *          The feature types are show in =PORT_CONTROL_v :.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    type [IN]   Port feature enumerator
 *\param    value [IN]   Value of the bit field in port table
 *
 *\retval    OPENNSL_E_NONE No Error
 *\retval    OPENNSL_E_UNAVAIL Feature unavailable
 *\retval    OPENNSL_E_PORT Invalid Port number specified
 *\retval    OPENNSL_E_XXX Error occurred
 ******************************************************************************/
extern int opennsl_port_control_set(
    int unit, 
    opennsl_port_t port, 
    opennsl_port_control_t type, 
    int value) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Get the GPORT ID for the specified local port number.
 *
 *\description This API can be used to get the GPORT ID corresponding to a local
 *          port number.  The supplied port number should return FALSE on a
 *          OPENNSL_GPORT_IS_SET(port) test.
 *          The GPORT ID returned in this API is a MODPORT type. Therefore
 *          this call will fail on devices without a module ID.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Port number
 *\param    gport [OUT]   GPORT ID
 *
 *\retval    OPENNSL_E_NONE No Error
 *\retval    OPENNSL_E_UNAVAIL Feature unavailable
 *\retval    OPENNSL_E_PORT Invalid Port number
 *\retval    OPENNSL_E_PARAM Invalid Parameter
 *\retval    OPENNSL_E_XXX Error occurred
 ******************************************************************************/
extern int opennsl_port_gport_get(
    int unit, 
    opennsl_port_t port, 
    opennsl_gport_t *gport) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Enable/disable packet and byte counters for the selected gport.
 *
 *\description This API will initialize statistic collection for the given GPORT
 *          (enable=TRUE) or release the HW resources used for the tracking
 *          the statistics (enable=FALSE).
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   GPORT ID
 *\param    enable [IN]   Non-zero to enable counter collection, zero to disable.
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_port_stat_enable_set(
    int unit, 
    opennsl_gport_t port, 
    int enable) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#if defined(INCLUDE_CES)
#endif
#endif /* __OPENNSL_PORT_H__ */
/*@}*/

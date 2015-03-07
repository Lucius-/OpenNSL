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
#include <shared/phyconfig.h>
#include <opennsl/types.h>
#include <opennsl/stat.h>
#include <shared/port_ability.h>

/** Port Configuration structure. */
typedef struct opennsl_port_config_s {
    opennsl_pbmp_t fe;          /**< Mask of FE ports. */
    opennsl_pbmp_t ge;          /**< Mask of GE ports. */
    opennsl_pbmp_t xe;          /**< Mask of 10gig ports. */
    opennsl_pbmp_t ce;          /**< Mask of 100gig ports. */
    opennsl_pbmp_t e;           /**< Mask of eth ports. */
    opennsl_pbmp_t hg;          /**< Mask of Higig ports. */
    opennsl_pbmp_t sci;         /**< Mask of SCI ports. */
    opennsl_pbmp_t sfi;         /**< Mask of SFI ports. */
    opennsl_pbmp_t spi;         /**< Mask of SPI ports. */
    opennsl_pbmp_t spi_subport; /**< Mask of SPI subports. */
    opennsl_pbmp_t port;        /**< Mask of all front panel ports. */
    opennsl_pbmp_t cpu;         /**< Mask of CPU ports. */
    opennsl_pbmp_t all;         /**< Mask of all ports. */
    opennsl_pbmp_t stack_int;   /**< Deprecated - unused. */
    opennsl_pbmp_t stack_ext;   /**< Mask of Stack ports. */
    opennsl_pbmp_t tdm;         /**< Mask of TDM ports. */
    opennsl_pbmp_t pon;         /**< Mask of PON ports. */
    opennsl_pbmp_t llid;        /**< Mask of LLID ports. */
    opennsl_pbmp_t il;          /**< Mask of ILKN ports. */
    opennsl_pbmp_t xl;          /**< Mask of XLAUI ports. */
    opennsl_pbmp_t rcy;         /**< Mask of RECYCLE ports. */
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
 *\brief Retrieved the port configuration for the specified device or for all
 *       ports known to OPENNSLX.
 *
 *\description opennsl_port_config_get returns all known ports configured on the
 *          specified device. opennslx_port_config_get returns a structure
 *          containing all ports known to the OPENNSLX subsystem.
 *          In both cases, the logical information represented is similar
 *          except the OPENNSL level indicates port bit maps to represent the
 *          ports on the specified unit while the OPENNSLX level call
 *          represents the ports as logical port lists (see the Broadcom
 *          Network Switching Stacking Guide for a description of logical port
 *          lists). =OPENNSL_PORT_CONFIG_t describes the meaning of each
 *          field.
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
 *\param    enable [OUT]   Boolean value indicating enable (1) or disable (0).
 *
 *\retval    OPENNSL_E_NONE Operation completed successfully
 *\retval    OPENNSL_E_XXX Operation failed, if retrieving the current enabled
 *          state, the value of the parameter enable is undefined.
 ******************************************************************************/
extern int opennsl_port_enable_get(
    int unit, 
    opennsl_port_t port, 
    int *enable) LIB_DLL_EXPORTED ;

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
 *          set for operation. For correct operation following an error, a
 *          valid speed must be set.
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
 *          set for operation. For correct operation following an error, a
 *          valid speed must be set.
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

/***************************************************************************//** 
 *\brief Get or set the current operating speed of a port.
 *
 *\description Set or get the speed of the specified port. opennsl_port_speed_set
 *          disables auto-negotiation if it is enabled. When setting a speed,
 *          if an error is returned the PHY and the MAC may not be properly
 *          set for operation. For correct operation following an error, a
 *          valid speed must be set.
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
extern int opennsl_port_speed_get(
    int unit, 
    opennsl_port_t port, 
    int *speed) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/** opennsl_port_if_t */
typedef _shr_port_if_t opennsl_port_if_t;

#define OPENNSL_PORT_IF_SFI     _SHR_PORT_IF_SFI 
#define OPENNSL_PORT_IF_XLAUI   _SHR_PORT_IF_XLAUI 
#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Configure the physical interface between the MAC and the PHY for the
 *       specified port.
 *
 *\description Provides ability to change the physical interface used between the
 *          MAC in the switch device and the PHY. Under normal conditions this
 *          setting will be configured during port initialization and should
 *          not change. This function is provided for diagnostic purposes
 *          only. For information on initial physical interface settings, see.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    intf [IN]   Interface to configure or retrieved interface setting.
 *
 *\retval    OPENNSL_E_NONE Operation performed successfully
 *\retval    OPENNSL_E_INIT Port module not initialized, see .
 *\retval    OPENNSL_E_UNAVAIL Requested interface is not available on the
 *          specified port.
 *\retval    OPENNSL_E_XXX Operation failed, if retrieving current operating mode
 *          result value in intf is undefined.
 ******************************************************************************/
extern int opennsl_port_interface_set(
    int unit, 
    opennsl_port_t port, 
    opennsl_port_if_t intf) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Configure the physical interface between the MAC and the PHY for the
 *       specified port.
 *
 *\description Provides ability to change the physical interface used between the
 *          MAC in the switch device and the PHY. Under normal conditions this
 *          setting will be configured during port initialization and should
 *          not change. This function is provided for diagnostic purposes
 *          only. For information on initial physical interface settings, see.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    intf [OUT]   Interface to configure or retrieved interface setting.
 *
 *\retval    OPENNSL_E_NONE Operation performed successfully
 *\retval    OPENNSL_E_INIT Port module not initialized, see .
 *\retval    OPENNSL_E_UNAVAIL Requested interface is not available on the
 *          specified port.
 *\retval    OPENNSL_E_XXX Operation failed, if retrieving current operating mode
 *          result value in intf is undefined.
 ******************************************************************************/
extern int opennsl_port_interface_get(
    int unit, 
    opennsl_port_t port, 
    opennsl_port_if_t *intf) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

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
 *          line blocking etc. For switch family III, ingress filtering is
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
    opennslportReservedEnum1, 
    opennslportReservedEnum2, 
    opennslportReservedEnum3, 
    opennslportReservedEnum4, 
    opennslportReservedEnum5, 
    opennslportReservedEnum6, 
    opennslportReservedEnum7, 
    opennslportReservedEnum8, 
    opennslPortControlIP4,              /**< Enable IPv4 Routing on port. */
    opennslPortControlIP6,              /**< Enable IPv6 Routing on port. */
    opennslportReservedEnum9, 
    opennslportReservedEnum10, 
    opennslportReservedEnum11, 
    opennslportReservedEnum12, 
    opennslportReservedEnum13, 
    opennslportReservedEnum14, 
    opennslportReservedEnum15, 
    opennslportReservedEnum16, 
    opennslportReservedEnum17, 
    opennslportReservedEnum18, 
    opennslportReservedEnum19, 
    opennslportReservedEnum20, 
    opennslportReservedEnum21, 
    opennslportReservedEnum22, 
    opennslportReservedEnum23, 
    opennslportReservedEnum24, 
    opennslportReservedEnum25, 
    opennslportReservedEnum26, 
    opennslportReservedEnum27, 
    opennslportReservedEnum28, 
    opennslportReservedEnum29, 
    opennslportReservedEnum30, 
    opennslportReservedEnum31, 
    opennslportReservedEnum32, 
    opennslportReservedEnum33, 
    opennslportReservedEnum34, 
    opennslportReservedEnum35, 
    opennslportReservedEnum36, 
    opennslportReservedEnum37, 
    opennslportReservedEnum38, 
    opennslportReservedEnum39, 
    opennslportReservedEnum40, 
    opennslportReservedEnum41, 
    opennslportReservedEnum42, 
    opennslportReservedEnum43, 
    opennslportReservedEnum44, 
    opennslportReservedEnum45, 
    opennslportReservedEnum46, 
    opennslportReservedEnum47, 
    opennslportReservedEnum48, 
    opennslportReservedEnum49, 
    opennslportReservedEnum50, 
    opennslportReservedEnum51, 
    opennslportReservedEnum52, 
    opennslportReservedEnum53, 
    opennslportReservedEnum54, 
    opennslportReservedEnum55, 
    opennslportReservedEnum56, 
    opennslportReservedEnum57, 
    opennslportReservedEnum58, 
    opennslportReservedEnum59, 
    opennslportReservedEnum60, 
    opennslportReservedEnum61, 
    opennslportReservedEnum62, 
    opennslportReservedEnum63, 
    opennslportReservedEnum64, 
    opennslportReservedEnum65, 
    opennslportReservedEnum66, 
    opennslportReservedEnum67, 
    opennslportReservedEnum68, 
    opennslportReservedEnum69, 
    opennslportReservedEnum70, 
    opennslportReservedEnum71, 
    opennslportReservedEnum72, 
    opennslportReservedEnum73, 
    opennslportReservedEnum74, 
    opennslportReservedEnum75, 
    opennslportReservedEnum76, 
    opennslportReservedEnum77, 
    opennslportReservedEnum78, 
    opennslportReservedEnum79, 
    opennslportReservedEnum80, 
    opennslportReservedEnum81, 
    opennslportReservedEnum82, 
    opennslportReservedEnum83, 
    opennslportReservedEnum84, 
    opennslportReservedEnum85, 
    opennslportReservedEnum86, 
    opennslportReservedEnum87, 
    opennslportReservedEnum88, 
    opennslportReservedEnum89, 
    opennslportReservedEnum90, 
    opennslportReservedEnum91, 
    opennslportReservedEnum92, 
    opennslportReservedEnum93, 
    opennslportReservedEnum94, 
    opennslportReservedEnum95, 
    opennslportReservedEnum96, 
    opennslportReservedEnum97, 
    opennslportReservedEnum98, 
    opennslportReservedEnum99, 
    opennslportReservedEnum100, 
    opennslportReservedEnum101, 
    opennslportReservedEnum102, 
    opennslportReservedEnum103, 
    opennslportReservedEnum104, 
    opennslportReservedEnum105, 
    opennslportReservedEnum106, 
    opennslportReservedEnum107, 
    opennslportReservedEnum108, 
    opennslportReservedEnum109, 
    opennslportReservedEnum110, 
    opennslportReservedEnum111, 
    opennslportReservedEnum112, 
    opennslportReservedEnum113, 
    opennslportReservedEnum114, 
    opennslportReservedEnum115, 
    opennslportReservedEnum116, 
    opennslportReservedEnum117, 
    opennslportReservedEnum118, 
    opennslportReservedEnum119, 
    opennslportReservedEnum120, 
    opennslportReservedEnum121, 
    opennslportReservedEnum122, 
    opennslportReservedEnum123, 
    opennslportReservedEnum124, 
    opennslportReservedEnum125, 
    opennslportReservedEnum126, 
    opennslportReservedEnum127, 
    opennslportReservedEnum128, 
    opennslportReservedEnum129, 
    opennslportReservedEnum130, 
    opennslportReservedEnum131, 
    opennslportReservedEnum132, 
    opennslportReservedEnum133, 
    opennslportReservedEnum134, 
    opennslportReservedEnum135, 
    opennslportReservedEnum136, 
    opennslportReservedEnum137, 
    opennslportReservedEnum138, 
    opennslportReservedEnum139, 
    opennslportReservedEnum140, 
    opennslportReservedEnum141, 
    opennslportReservedEnum142, 
    opennslportReservedEnum143, 
    opennslportReservedEnum144, 
    opennslportReservedEnum145, 
    opennslportReservedEnum146, 
    opennslportReservedEnum147, 
    opennslportReservedEnum148, 
    opennslportReservedEnum149, 
    opennslportReservedEnum150, 
    opennslportReservedEnum151, 
    opennslportReservedEnum152, 
    opennslportReservedEnum153, 
    opennslportReservedEnum154, 
    opennslportReservedEnum155, 
    opennslportReservedEnum156, 
    opennslportReservedEnum157, 
    opennslportReservedEnum158, 
    opennslportReservedEnum159, 
    opennslportReservedEnum160, 
    opennslportReservedEnum161, 
    opennslportReservedEnum162, 
    opennslportReservedEnum163, 
    opennslportReservedEnum164, 
    opennslportReservedEnum165, 
    opennslportReservedEnum166, 
    opennslportReservedEnum167, 
    opennslportReservedEnum168, 
    opennslportReservedEnum169, 
    opennslportReservedEnum170, 
    opennslportReservedEnum171, 
    opennslportReservedEnum172, 
    opennslportReservedEnum173, 
    opennslportReservedEnum174, 
    opennslportReservedEnum175, 
    opennslportReservedEnum176, 
    opennslportReservedEnum177, 
    opennslportReservedEnum178, 
    opennslportReservedEnum179, 
    opennslportReservedEnum180, 
    opennslportReservedEnum181, 
    opennslportReservedEnum182, 
    opennslportReservedEnum183, 
    opennslportReservedEnum184, 
    opennslportReservedEnum185, 
    opennslportReservedEnum186, 
    opennslportReservedEnum187, 
    opennslportReservedEnum188, 
    opennslportReservedEnum189, 
    opennslportReservedEnum190, 
    opennslportReservedEnum191, 
    opennslportReservedEnum192, 
    opennslportReservedEnum193, 
    opennslportReservedEnum194, 
    opennslportReservedEnum195, 
    opennslportReservedEnum196, 
    opennslportReservedEnum197, 
    opennslportReservedEnum198, 
    opennslportReservedEnum199, 
    opennslportReservedEnum200, 
    opennslportReservedEnum201, 
    opennslportReservedEnum202, 
    opennslportReservedEnum203, 
    opennslportReservedEnum204, 
    opennslportReservedEnum205, 
    opennslportReservedEnum206, 
    opennslportReservedEnum207, 
    opennslportReservedEnum208, 
    opennslportReservedEnum209, 
    opennslportReservedEnum210, 
    opennslportReservedEnum211, 
    opennslportReservedEnum212, 
    opennslportReservedEnum213, 
    opennslportReservedEnum214, 
    opennslportReservedEnum215, 
    opennslportReservedEnum216, 
    opennslportReservedEnum217, 
    opennslportReservedEnum218, 
    opennslportReservedEnum219, 
    opennslportReservedEnum220, 
    opennslportReservedEnum221, 
    opennslportReservedEnum222, 
    opennslportReservedEnum223, 
    opennslportReservedEnum224, 
    opennslportReservedEnum225, 
    opennslportReservedEnum226, 
    opennslportReservedEnum227, 
    opennslportReservedEnum228, 
    opennslportReservedEnum229, 
    opennslportReservedEnum230, 
    opennslportReservedEnum231, 
    opennslportReservedEnum232, 
    opennslportReservedEnum233, 
    opennslportReservedEnum234, 
    opennslportReservedEnum235, 
    opennslportReservedEnum236, 
    opennslportReservedEnum237, 
    opennslportReservedEnum238, 
    opennslportReservedEnum239, 
    opennslportReservedEnum240, 
    opennslportReservedEnum241, 
    opennslportReservedEnum242, 
    opennslportReservedEnum243, 
    opennslportReservedEnum244, 
    opennslportReservedEnum245, 
    opennslportReservedEnum246, 
    opennslportReservedEnum247, 
    opennslportReservedEnum248, 
    opennslportReservedEnum249, 
    opennslportReservedEnum250, 
    opennslportReservedEnum251, 
    opennslportReservedEnum252, 
    opennslportReservedEnum253, 
    opennslportReservedEnum254, 
    opennslportReservedEnum255, 
    opennslportReservedEnum256, 
    opennslportReservedEnum257, 
    opennslportReservedEnum258, 
    opennslportReservedEnum259, 
    opennslportReservedEnum260, 
    opennslportReservedEnum261, 
    opennslportReservedEnum262, 
    opennslportReservedEnum263, 
    opennslportReservedEnum264, 
    opennslportReservedEnum265, 
    opennslportReservedEnum266, 
    opennslportReservedEnum267, 
    opennslportReservedEnum268, 
    opennslportReservedEnum269, 
    opennslportReservedEnum270, 
    opennslportReservedEnum271, 
    opennslportReservedEnum272, 
    opennslportReservedEnum273, 
    opennslportReservedEnum274, 
    opennslportReservedEnum275, 
    opennslportReservedEnum276, 
    opennslportReservedEnum277, 
    opennslportReservedEnum278, 
    opennslportReservedEnum279 = 282, 
    opennslportReservedEnum280 = 283, 
    opennslportReservedEnum281 = 284, 
    opennslportReservedEnum282 = 285, 
    opennslportReservedEnum283 = 286, 
    opennslportReservedEnum284 = 287 
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
 *          For the OPENNSL API, the GPORT ID returned in this API is a
 *          MODPORT type. Therefore this call will fail on devices without a
 *          module ID.
 *          For the OPENNSLX API, the GPORT ID is of MODPORT type for devices
 *          with a module ID, and DEVPORT type for devices without a module
 *          ID.
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

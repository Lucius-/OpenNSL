/** \addtogroup l3 Layer 3 Management
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
 * \file			l3.h
 ******************************************************************************/

#ifndef __OPENNSL_L3_H__
#define __OPENNSL_L3_H__

#if defined(INCLUDE_L3)

#include <opennsl/types.h>
#include <opennsl/stat.h>

#define OPENNSL_L3_WITH_ID      (1 << 6)   /**< ID is provided. */
#define OPENNSL_L3_REPLACE      (1 << 8)   /**< Replace existing entry. */
#define OPENNSL_L3_L2TOCPU      (1 << 12)  /**< Packet to CPU unrouted, XGS12: Set
                                              IPMC for UC address. */
#define OPENNSL_L3_MULTIPATH    (1 << 14)  /**< Specify ECMP treatment. */
#define OPENNSL_L3_IP6          (1 << 17)  /**< IPv6. */
#define OPENNSL_L3_DST_DISCARD  (1 << 20)  /**< Destination match discard. */
#define OPENNSL_L3_COPY_TO_CPU  (1 << 23)  /**< Send a copy to CPU. */
/** L3 Interface QOS setting. */
typedef struct opennsl_l3_intf_qos_s {
    uint32 reserved1; 
    int reserved2; 
    uint8 reserved3; 
    uint8 reserved4; 
    int reserved5; 
} opennsl_l3_intf_qos_t;

/** 
 * L3 Interface Structure.
 * 
 * Contains information required for manipulating L3 interfaces.
 */
typedef struct opennsl_l3_intf_s {
    uint32 l3a_flags;                   /**< See OPENNSL_L3_XXX flag definitions. */
    opennsl_vrf_t l3a_vrf;              /**< Virtual router instance. */
    opennsl_if_t l3a_intf_id;           /**< Interface ID. */
    opennsl_mac_t l3a_mac_addr;         /**< MAC address. */
    opennsl_vlan_t l3a_vid;             /**< VLAN ID. */
    opennsl_vlan_t reserved1; 
    int reserved2; 
    int reserved3; 
    int l3a_mtu;                        /**< MTU. */
    opennsl_if_group_t reserved4; 
    opennsl_l3_intf_qos_t reserved5; 
    opennsl_l3_intf_qos_t reserved6; 
    opennsl_l3_intf_qos_t reserved7; 
    int reserved8; 
    int reserved9; 
    int reserved10; 
    uint16 reserved11; 
    uint32 reserved12; 
    uint8 reserved13; 
} opennsl_l3_intf_t;

/** 
 * L3 Egress Structure.
 * 
 * Description of an L3 forwarding destination.
 */
typedef struct opennsl_l3_egress_s {
    uint32 flags;                   /**< Interface flags (OPENNSL_L3_TGID,
                                       OPENNSL_L3_L2TOCPU). */
    uint32 reserved1; 
    opennsl_if_t intf;              /**< L3 interface (source MAC, tunnel). */
    opennsl_mac_t mac_addr;         /**< Next hop forwarding destination mac. */
    opennsl_vlan_t reserved2; 
    opennsl_module_t reserved3; 
    opennsl_port_t port;            /**< Port packet switched to (if
                                       !OPENNSL_L3_TGID). */
    opennsl_trunk_t reserved4; 
    uint32 reserved5; 
    opennsl_mpls_label_t reserved6; 
    int reserved7; 
    int reserved8; 
    uint8 reserved9; 
    uint8 reserved10; 
    uint8 reserved11; 
    int reserved12; 
    opennsl_if_t reserved13; 
    opennsl_failover_t reserved14; 
    opennsl_if_t reserved15; 
    opennsl_multicast_t reserved16; 
    int reserved17; 
    int reserved18; 
    int reserved19; 
    uint32 reserved20; 
} opennsl_l3_egress_t;

/** 
 * L3 Host Structure.
 * 
 * Contains information required for manipulating L3 host table entries.
 * 
 * The OPENNSL_L3_IP6 flag in l3a_flags must be set to specify whether
 * the IPv4 or IPv6 addresses are valid.
 */
typedef struct opennsl_l3_host_s {
    uint32 l3a_flags;           /**< See OPENNSL_L3_xxx flag definitions. */
    uint32 reserved1; 
    opennsl_vrf_t l3a_vrf;      /**< Virtual router instance. */
    opennsl_ip_t l3a_ip_addr;   /**< Destination host IP address (IPv4). */
    opennsl_ip6_t l3a_ip6_addr; /**< Destination host IP address (IPv6). */
    opennsl_cos_t reserved2; 
    opennsl_if_t l3a_intf;      /**< L3 intf associated with this address. */
    opennsl_mac_t reserved3; 
    opennsl_module_t reserved4; 
    opennsl_port_t reserved5; 
    opennsl_port_t reserved6; 
    int reserved7; 
    int reserved8; 
    opennsl_if_t reserved9; 
    opennsl_if_t reserved10; 
} opennsl_l3_host_t;

/** 
 * L3 Route Structure
 * 
 * Contains information required for manipulating L3 route table entries.
 * 
 * The OPENNSL_L3_IP6 flag in l3a_flags must be set to specify whether
 * the IPv4 or IPv6 addresses are valid.
 */
typedef struct opennsl_l3_route_s {
    uint32 l3a_flags;                   /**< See OPENNSL_L3_xxx flag definitions. */
    uint32 reserved1; 
    opennsl_vrf_t l3a_vrf;              /**< Virtual router instance. */
    opennsl_ip_t l3a_subnet;            /**< IP subnet address (IPv4). */
    opennsl_ip6_t l3a_ip6_net;          /**< IP subnet address (IPv6). */
    opennsl_ip_t l3a_ip_mask;           /**< IP subnet mask (IPv4). */
    opennsl_ip6_t l3a_ip6_mask;         /**< IP subnet mask (IPv6). */
    opennsl_if_t l3a_intf;              /**< L3 interface associated with route. */
    opennsl_ip_t reserved2; 
    opennsl_mac_t reserved3; 
    opennsl_module_t reserved4; 
    opennsl_port_t reserved5; 
    opennsl_port_t reserved6; 
    opennsl_vlan_t reserved7; 
    opennsl_cos_t reserved8; 
    uint32 reserved9; 
    opennsl_mpls_label_t reserved10; 
    int reserved11; 
} opennsl_l3_route_t;

/** 
 * L3 Information Structure.
 * 
 * Contains information about L3 hardware capacity and utilization.
 * 
 * 
 */
typedef struct opennsl_l3_info_s {
    int reserved1; 
    int reserved2; 
    int reserved3; 
    int reserved4; 
    int l3info_max_host;    /**< L3 host table size(unit is IPv4 unicast). */
    int l3info_max_route;   /**< L3 route table size (unit is IPv4 route). */
    int reserved5; 
    int reserved6; 
    int reserved7; 
    int reserved8; 
    int reserved9; 
    int reserved10; 
    int reserved11; 
    int reserved12; 
    int reserved13; 
    int reserved14; 
    int reserved15; 
    int reserved16; 
    int reserved17; 
    int reserved18; 
    int reserved19; 
    int reserved20; 
} opennsl_l3_info_t;

/** L3 ECMP structure */
typedef struct opennsl_l3_egress_ecmp_s {
    uint32 flags;           /**< See OPENNSL_L3_xxx flag definitions. */
    opennsl_if_t ecmp_intf; /**< L3 interface ID pointing to egress ecmp object. */
    int max_paths;          /**< Max number of paths in ECMP group. If max_paths
                               <= 0, the default max path which can be set by
                               the API opennsl_l3_route_max_ecmp_set will be
                               picked. */
    uint32 reserved1; 
    uint32 reserved2; 
    uint32 reserved3; 
    uint32 reserved4; 
    uint32 reserved5; 
    uint32 reserved6; 
} opennsl_l3_egress_ecmp_t;

typedef int (*opennsl_l3_host_traverse_cb)(
    int unit, 
    int index, 
    opennsl_l3_host_t *info, 
    void *user_data);

typedef int (*opennsl_l3_route_traverse_cb)(
    int unit, 
    int index, 
    opennsl_l3_route_t *info, 
    void *user_data);

typedef int (*opennsl_l3_egress_traverse_cb)(
    int unit, 
    opennsl_if_t intf, 
    opennsl_l3_egress_t *info, 
    void *user_data);

typedef int (*opennsl_l3_egress_ecmp_traverse_cb)(
    int unit, 
    opennsl_l3_egress_ecmp_t *ecmp, 
    int intf_count, 
    opennsl_if_t *intf_array, 
    void *user_data);

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Initialize the OPENNSL L3 subsystem.
 *
 *\description Initialize all L3 tables and internal data structures.
 *
 *\param    unit [IN]   Unit number.
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_init(
    int unit) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Get the status of hardware tables.
 *
 *\description Returns the L3 table capacities and usage, including information
 *          about the host and route tables.
 *
 *\param    unit [IN]   Unit number.
 *\param    l3info [OUT]   L3 capacity and usage information
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_info(
    int unit, 
    opennsl_l3_info_t *l3info) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/***************************************************************************//** 
 *\brief Initialize a opennsl_l3_intf_t structure.
 *
 *\description Initializes an interface structure to default values.  This
 *          function should be used to initialize any interface structure
 *          prior to filling it out and passing it to an API function.  This
 *          ensures that subsequent API releases may add new structure members
 *          to the opennsl_l3_intf_t structure, and opennsl_l3_intf_t_init
 *          will initialize the new members to correct default values.
 *
 *\param    intf [IN,OUT]   Interface information
 *
 *\retval    Nothing
 ******************************************************************************/
extern void opennsl_l3_intf_t_init(
    opennsl_l3_intf_t *intf) LIB_DLL_EXPORTED ;

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Create a new L3 interface.
 *
 *\description Creates a new L3 interface.
 *          The MAC address for the new L3 interface is l3a_mac_addr, and the
 *          VLAN identifier is l3a_vid.
 *          The valid flags are as follows:.
 *
 *\param    unit [IN]   Unit number.
 *\param    intf [IN,OUT]   Interface information =L3_INTF_CREATE_FLAGS_table
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_intf_create(
    int unit, 
    opennsl_l3_intf_t *intf) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Delete an L3 interface.
 *
 *\description Deletes an entry from the L3 interface table.
 *          This function supersedes =opennsl_l3_interface_destroy .
 *
 *\param    unit [IN]   Unit number.
 *\param    intf [IN]   L3 interface information. Valid fields: l3a_intf_id - ID
 *          of interface to be deleted
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_intf_delete(
    int unit, 
    opennsl_l3_intf_t *intf) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Search for L3 interface by VLAN only.
 *
 *\description Find the L3 interface ID based on VLAN.  If more than one
 *          interface is found in the same VLAN, only the first is returned.
 *          This function supersedes =opennsl_l3_interface_find_by_vlan .
 *
 *\param    unit [IN]   Unit number.
 *\param    intf [IN,OUT]   L3 interface information. Valid Input: l3a_vid - 
 *          Interface VLAN, l3a_intf_id - L3 interface number, if found
 *
 *\retval    OPENNSL_E_NOT_FOUND - Interface not found
 *\retval    OPENNSL_E_XXX - Other error code
 ******************************************************************************/
extern int opennsl_l3_intf_find_vlan(
    int unit, 
    opennsl_l3_intf_t *intf) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/***************************************************************************//** 
 *\brief Initialize a opennsl_l3_egress_t structure.
 *
 *\description Initializes an egress object structure to default values. This
 *          function should be used to initialize any host structure prior to
 *          filling it out and passing it to an API function.  This ensures
 *          that subsequent API releases may add new structure members to the
 *          opennsl_l3_egress_t structure, and opennsl_l3_egress_t_init will
 *          initialize the new members to correct default values.
 *
 *\param    egr [IN,OUT]   Egress object entry information
 *
 *\retval    Nothing
 ******************************************************************************/
extern void opennsl_l3_egress_t_init(
    opennsl_l3_egress_t *egr) LIB_DLL_EXPORTED ;

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Create an Egress forwarding object.
 *
 *\description Create a unicast L3 Egress forwarding object on a physical port.
 *          On network switch, this API can be used to create additional types
 *          of L3 Egress objects:.
 *
 *\param    unit [IN]   Unit number.
 *\param    flags [IN]   OPENNSL_L3_REPLACE: replace existing. OPENNSL_L3_WITH_ID:
 *          intf argument is given.
 *\param    egr [IN,OUT]   Egress forwarding destination.
 *\param    if_id [IN,OUT]
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_egress_create(
    int unit, 
    uint32 flags, 
    opennsl_l3_egress_t *egr, 
    opennsl_if_t *if_id) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Destroy an Egress forwarding object.
 *
 *\description Destroy an Egress forwarding path.  Only unused egress objects can
 *          be deleted. That is, if forwarding path is used by
 *          routes/hosts/multipath objects operation will return
 *          OPENNSL_E_BUSY. .
 *
 *\param    unit [IN]   Unit number.
 *\param    intf [IN]   L3 interface ID pointing to Egress object.
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_egress_destroy(
    int unit, 
    opennsl_if_t intf) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Get an Egress forwarding object.
 *
 *\description Get an Egress forwarding path properties. .
 *
 *\param    unit [IN]   Unit number.
 *\param    intf [IN]   L3 interface ID pointing to Egress object.
 *\param    egr [OUT]   Egress forwarding path properties.
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_egress_get(
    int unit, 
    opennsl_if_t intf, 
    opennsl_l3_egress_t *egr) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Traverse through the egress object table and run callback at each valid
 *       entry.
 *
 *\description Goes through L3 egress table and runs the user callback function
 *          at each valid entry, passing back the information for that egress
 *          object entry.
 *
 *\param    unit [IN]   Unit number.
 *\param    trav_fn [IN]   Callback function
 *\param    user_data [IN]   User data to be passed to callback function
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_egress_traverse(
    int unit, 
    opennsl_l3_egress_traverse_cb trav_fn, 
    void *user_data) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/***************************************************************************//** 
 *\brief Initialize L3 Egress ECMP object structure.
 *
 *\description Initializes a L3 Egress ECMP object structure to default values.
 *          This function should be used to initialize the L3 Egress ECMP
 *          object  structure prior to invocation of opennsl_l3_egress_ecmp_*
 *          APIs. This ensures that the structure members are initialized to
 *          the correct default values.
 *
 *\param    ecmp [IN,OUT]   L3 Egress ECMP object structure
 *
 *\retval    Nothing
 ******************************************************************************/
extern void opennsl_l3_egress_ecmp_t_init(
    opennsl_l3_egress_ecmp_t *ecmp) LIB_DLL_EXPORTED ;

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Create an Egress ECMP forwarding object.
 *
 *\description Create an Egress ECMP forwarding object. The L3 interface ID
 *          pointing to the created Egress ECMP object is returned in
 *          ecmp->ecmp_intf.
 *
 *\param    unit [IN]   Unit number.
 *\param    ecmp [IN,OUT]   ECMP group info.
 *\param    intf_count [IN]   Number of elements in intf_array.
 *\param    intf_array [IN]   Array of Egress forwarding objects.
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_egress_ecmp_create(
    int unit, 
    opennsl_l3_egress_ecmp_t *ecmp, 
    int intf_count, 
    opennsl_if_t *intf_array) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Destroy an Egress ECMP forwarding object.
 *
 *\description Destroy the Egress ECMP forwarding object pointed to by
 *          ecmp->ecmp_intf.  Only unused egress objects can be deleted. If
 *          forwarding path is used by routes/hosts objects, operation will
 *          return OPENNSL_E_BUSY. .
 *
 *\param    unit [IN]   Unit number.
 *\param    ecmp [IN]   ECMP group info.
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_egress_ecmp_destroy(
    int unit, 
    opennsl_l3_egress_ecmp_t *ecmp) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Traverse through the valid Egress ECMP forwarding objects and run
 *       callback.
 *
 *\description Goes through all the valid Egress ECMP forwarding objects and runs
 *          the user callback function, passing back the information for that
 *          Egress ECMP forwarding object (including its set of Egress
 *          forwarding objects).
 *
 *\param    unit [IN]   Unit number.
 *\param    trav_fn [IN]   Callback function
 *\param    user_data [IN]   User data to be passed to callback function
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_egress_ecmp_traverse(
    int unit, 
    opennsl_l3_egress_ecmp_traverse_cb trav_fn, 
    void *user_data) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/***************************************************************************//** 
 *\brief Initialize a opennsl_l3_host_t structure.
 *
 *\description Initializes a host structure to default values.  This function
 *          should be used to initialize any host structure prior to filling
 *          it out and passing it to an API function.  This ensures that
 *          subsequent API releases may add new structure members to the
 *          opennsl_l3_host_t structure, and opennsl_l3_host_t_init will
 *          initialize the new members to correct default values.
 *
 *\param    ip [IN,OUT]
 *
 *\retval    Nothing
 ******************************************************************************/
extern void opennsl_l3_host_t_init(
    opennsl_l3_host_t *ip) LIB_DLL_EXPORTED ;

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Add an entry into the L3 switching table.
 *
 *\description Add an entry to the L3 host table
 *          The valid flags are as follows:.
 *
 *\param    unit [IN]   Unit number.
 *\param    info [IN]   Pointer to opennsl_l3_host_t containing fields related to
 *          L3 host table: =L3_HOST_ADD_FIELDS_table
 *
 *\retval    OPENNSL_E_XXX
 *\retval    This function supersedes .
 ******************************************************************************/
extern int opennsl_l3_host_add(
    int unit, 
    opennsl_l3_host_t *info) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Delete an entry from the L3 host table.
 *
 *\description Deletes an L3 host table entry matching the IP address specified.
 *          The valid flag is:.
 *
 *\param    unit [IN]   Unit number.
 *\param    ip_addr [IN]   Pointer to opennsl_l3_host_t containing fields related
 *          to the IP address to be deleted from the L3 host table:
 *          =L3_HOST_DELETE_FIELDS_table
 *
 *\retval    OPENNSL_E_XXX
 *\retval    This function supersedes .
 ******************************************************************************/
extern int opennsl_l3_host_delete(
    int unit, 
    opennsl_l3_host_t *ip_addr) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Traverse through the L3 table and run callback at each valid L3 entry.
 *
 *\description Goes through L3 host table and runs the user callback function at
 *          each valid L3 host entry, passing back the information for that L3
 *          host entry.
 *          The valid flag is:.
 *
 *\param    unit [IN]   Unit number.
 *\param    flags [IN]   Operation control flags
 *\param    start [IN]   The starting valid entry number to be traversed
 *\param    end [IN]   The last valid entry number to be traversed
 *\param    cb [IN]   Callback function
 *\param    user_data [IN]   User data to be passed to callback function
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_host_traverse(
    int unit, 
    uint32 flags, 
    uint32 start, 
    uint32 end, 
    opennsl_l3_host_traverse_cb cb, 
    void *user_data) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/***************************************************************************//** 
 *\brief Initialize a opennsl_l3_route_t structure.
 *
 *\description Initializes a route structure to default values.  This function
 *          should be used to initialize any route structure prior to filling
 *          it out and passing it to an API function.  This ensures that
 *          subsequent API releases may add new structure members to the
 *          opennsl_l3_route_t structure, and opennsl_l3_route_t_init will
 *          initialize the new members to correct default values.
 *
 *\param    route [IN,OUT]   Route information
 *
 *\retval    Nothing
 ******************************************************************************/
extern void opennsl_l3_route_t_init(
    opennsl_l3_route_t *route) LIB_DLL_EXPORTED ;

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Add an IP route to the L3 route table.
 *
 *\description Adds an L3 route to the route table.
 *          The valid flags are as follows:.
 *
 *\param    unit [IN]   Unit number.
 *\param    info [IN]   Pointer to opennsl_l3_host_t containing fields related to
 *          routing table: =L3_ROUTE_ADD_FIELDS_table
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_route_add(
    int unit, 
    opennsl_l3_route_t *info) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Delete an IP route from the DEFIP table.
 *
 *\description Deletes an L3 route from the route table.
 *          The valid flags are as follows:.
 *
 *\param    unit [IN]   Unit number.
 *\param    info [IN]   Pointer to opennsl_l3_route_t containing the route to
 *          delete. Valid Fields: =L3_ROUTE_DELETE_FIELDS_table and if
 *          OPENNSL_L3_MULTIPATH flag is set, the following fields are also
 *          applicable: =L3_ROUTE_DELETE_MULTICAST_FIELDS_table
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_route_delete(
    int unit, 
    opennsl_l3_route_t *info) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Traverse through the routing table and run callback at each route.
 *
 *\description Goes through the route table and runs the callback function at
 *          each valid route, passing it the route information.
 *          The valid flag is:.
 *
 *\param    unit [IN]   Unit number.
 *\param    flags [IN]   Operation control flags
 *\param    start [IN]   The starting route number to be traversed
 *\param    end [IN]   The last route number to be traversed
 *\param    trav_fn [IN]   Callback function
 *\param    user_data [IN]   User data to be passed to callback routine
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_l3_route_traverse(
    int unit, 
    uint32 flags, 
    uint32 start, 
    uint32 end, 
    opennsl_l3_route_traverse_cb trav_fn, 
    void *user_data) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

/***************************************************************************//** 
 *\brief Initialize a opennsl_l3_info_t_init structure.
 *
 *\description Initializes a L3 information structure to default values. This
 *          function  should be used to initialize any L3 information
 *          structure prior to filling it out and passing it to an API
 *          function. This ensures that subsequent API releases may add new
 *          structure members to the opennsl_l3_info_t structure, and
 *          opennsl_l3_info_t_init will initialize the new members to correct
 *          default values.
 *
 *\param    info [IN,OUT]   Pointer to L3 information structure to initialize.
 *
 *\retval    Nothing
 ******************************************************************************/
extern void opennsl_l3_info_t_init(
    opennsl_l3_info_t *info) LIB_DLL_EXPORTED ;

#endif /* defined(INCLUDE_L3) */

#endif /* __OPENNSL_L3_H__ */
/*@}*/

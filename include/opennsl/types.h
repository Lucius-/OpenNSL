/** \addtogroup types Types
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
 * \file			types.h
 ******************************************************************************/

#ifndef __OPENNSL_TYPES_H__
#define __OPENNSL_TYPES_H__

#include <sal/types.h>
#include <sal/commdefs.h>
#include <shared/bitop.h>
#include <shared/pbmp.h>
#include <shared/util.h>

/** opennsl_multicast_t */
typedef int opennsl_multicast_t;

#if !defined(OPENNSL_LOCAL_UNITS_MAX)
#endif
#if !defined(OPENNSL_UNITS_MAX)
#endif
#define OPENNSL_PBMP_CLEAR(pbm)  _SHR_PBMP_CLEAR(pbm) 
#define OPENNSL_PBMP_ITER(bmp, port)  _SHR_PBMP_ITER((bmp), (port)) 
#define OPENNSL_PBMP_COUNT(pbm, count)  _SHR_PBMP_COUNT(pbm, count) 
#define OPENNSL_PBMP_EQ(pbm_a, pbm_b)  _SHR_PBMP_EQ(pbm_a, pbm_b) 
#define OPENNSL_PBMP_ASSIGN(dst, src)  _SHR_PBMP_ASSIGN(dst, src) 
#define OPENNSL_PBMP_PORT_SET(pbm, port)  _SHR_PBMP_PORT_SET(pbm, port) 
#define OPENNSL_PBMP_PORT_ADD(pbm, port)  _SHR_PBMP_PORT_ADD(pbm, port) 
/** Set the default tag protocol ID (TPID) for the specified port. */
typedef int opennsl_port_t;

/** opennsl_pbmp_t */
typedef _shr_pbmp_t opennsl_pbmp_t;

/** opennsl_mac_t */
typedef uint8 opennsl_mac_t[6];

/** opennsl_ip_t */
typedef uint32 opennsl_ip_t;

/** opennsl_ip6_t */
typedef uint8 opennsl_ip6_t[16];

/** opennsl_if_t */
typedef int opennsl_if_t;

/** opennsl_if_group_t */
typedef int opennsl_if_group_t;

/** opennsl_vrf_t */
typedef int opennsl_vrf_t;

/** opennsl_mpls_label_t */
typedef uint32 opennsl_mpls_label_t;

#define OPENNSL_VLAN_DEFAULT    ((opennsl_vlan_t)0x0001) 
/** opennsl_vlan_t */
typedef uint16 opennsl_vlan_t;

/** opennsl_cos_t */
typedef int opennsl_cos_t;

/** opennsl_module_t */
typedef int opennsl_module_t;

/** opennsl_trunk_t */
typedef int opennsl_trunk_t;

/** 
 * GPORT (generic port) definitions.
 * See shared/gport.h for more details.
 */
typedef int opennsl_gport_t;

/** Multicast distribution set */
typedef int opennsl_fabric_distribution_t;

/** Failover Object */
typedef int opennsl_failover_t;

/** opennsl_stg_t */
typedef int opennsl_stg_t;

/** opennsl_color_t */
typedef enum opennsl_color_e {
    opennsltypesReservedEnum1,  
    opennsltypesReservedEnum2,  
    opennsltypesReservedEnum3,  
    opennsltypesReservedEnum4,  
    opennsltypesReservedEnum5,  
    opennsltypesReservedEnum6,  
    opennsltypesReservedEnum7   
} opennsl_color_t;

#if defined(LE_HOST)
#else
#define opennsl_htonl(_l)       (_l)       
#define opennsl_htons(_s)       (_s)       
#define opennsl_ntohl(_l)       (_l)       
#define opennsl_ntohs(_s)       (_s)       
#endif
/** VLAN Action definitions. */
typedef enum opennsl_vlan_action_e {
    opennsltypesReservedEnum8, 
    opennsltypesReservedEnum9, 
    opennsltypesReservedEnum10, 
    opennsltypesReservedEnum11, 
    opennsltypesReservedEnum12, 
    opennsltypesReservedEnum13, 
    opennsltypesReservedEnum14, 
    opennsltypesReservedEnum15, 
    opennsltypesReservedEnum16, 
    opennsltypesReservedEnum17, 
    opennsltypesReservedEnum18, 
    opennsltypesReservedEnum19 
} opennsl_vlan_action_t;

#endif /* __OPENNSL_TYPES_H__ */
/*@}*/

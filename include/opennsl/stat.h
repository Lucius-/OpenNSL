/** \addtogroup stat Statistics
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
 * \file			stat.h
 ******************************************************************************/

#ifndef __OPENNSL_STAT_H__
#define __OPENNSL_STAT_H__

#include <opennsl/types.h>

/** 
 * Statistics counters.
 * 
 * Note: the following RFC 2465 MIBs are not supported:
 * 
 *   snmpIpv6IfStatsInTooBigErrors,
 *   snmpIpv6IfStatsInNoRoutes,
 *   snmpIpv6IfStatsInUnknownProtos,
 *   snmpIpv6IfStatsInTruncatedPkts,
 *   snmpIpv6IfStatsInDelivers,
 *   snmpIpv6IfStatsOutRequests,
 *   snmpIpv6IfStatsOutFragOKs,
 *   snmpIpv6IfStatsOutFragFails,
 *   snmpIpv6IfStatsOutFragCreates,
 *   snmpIpv6IfStatsReasmReqds,
 *   snmpIpv6IfStatsReasmOKs,
 *   snmpIpv6IfStatsReasmFails,
 */
typedef enum opennsl_stat_val_e {
    statReservedEnum1, 
    statReservedEnum2, 
    statReservedEnum3, 
    opennsl_spl_snmpIfInDiscards,       /**< RFC 1213 */
    opennsl_spl_snmpIfInErrors,         /**< RFC 1213 */
    statReservedEnum4, 
    statReservedEnum5, 
    statReservedEnum6, 
    statReservedEnum7, 
    opennsl_spl_snmpIfOutDiscards,      /**< RFC 1213 */
    opennsl_spl_snmpIfOutErrors,        /**< RFC 1213 */
    statReservedEnum8, 
    statReservedEnum9, 
    statReservedEnum10, 
    statReservedEnum11, 
    statReservedEnum12, 
    statReservedEnum13, 
    statReservedEnum14, 
    statReservedEnum15, 
    statReservedEnum16, 
    statReservedEnum17, 
    statReservedEnum18, 
    statReservedEnum19, 
    statReservedEnum20, 
    statReservedEnum21, 
    statReservedEnum22, 
    statReservedEnum23, 
    statReservedEnum24, 
    statReservedEnum25, 
    statReservedEnum26, 
    statReservedEnum27, 
    statReservedEnum28, 
    statReservedEnum29, 
    statReservedEnum30, 
    statReservedEnum31, 
    statReservedEnum32, 
    statReservedEnum33, 
    statReservedEnum34, 
    statReservedEnum35, 
    statReservedEnum36, 
    statReservedEnum37, 
    statReservedEnum38, 
    statReservedEnum39, 
    statReservedEnum40, 
    statReservedEnum41, 
    statReservedEnum42, 
    statReservedEnum43, 
    statReservedEnum44, 
    statReservedEnum45, 
    statReservedEnum46, 
    statReservedEnum47, 
    statReservedEnum48, 
    statReservedEnum49, 
    statReservedEnum50, 
    statReservedEnum51, 
    statReservedEnum52, 
    statReservedEnum53, 
    statReservedEnum54, 
    opennsl_spl_snmpIfHCInOctets,       /**< RFC 2233 */
    opennsl_spl_snmpIfHCInUcastPkts,    /**< RFC 2233 */
    opennsl_spl_snmpIfHCInMulticastPkts, /**< RFC 2233 */
    opennsl_spl_snmpIfHCInBroadcastPkts, /**< RFC 2233 */
    opennsl_spl_snmpIfHCOutOctets,      /**< RFC 2233 */
    opennsl_spl_snmpIfHCOutUcastPkts,   /**< RFC 2233 */
    opennsl_spl_snmpIfHCOutMulticastPkts, /**< RFC 2233 */
    opennsl_spl_snmpIfHCOutBroadcastPckts, /**< RFC 2233 */
    statReservedEnum55, 
    statReservedEnum56, 
    statReservedEnum57, 
    statReservedEnum58, 
    statReservedEnum59, 
    statReservedEnum60, 
    statReservedEnum61, 
    statReservedEnum62, 
    statReservedEnum63, 
    statReservedEnum64, 
    statReservedEnum65, 
    statReservedEnum66, 
    statReservedEnum67, 
    statReservedEnum68, 
    statReservedEnum69, 
    statReservedEnum70, 
    statReservedEnum71, 
    statReservedEnum72, 
    statReservedEnum73, 
    statReservedEnum74, 
    statReservedEnum75, 
    statReservedEnum76, 
    statReservedEnum77, 
    statReservedEnum78, 
    snmpOpenNSLReceivedPkts64Octets,    /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts65to127Octets, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts128to255Octets, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts256to511Octets, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts512to1023Octets, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts1024to1518Octets, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts1519to2047Octets, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts2048to4095Octets, /**< Broadcom-specific */
    snmpOpenNSLReceivedPkts4095to9216Octets, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts64Octets, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts65to127Octets, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts128to255Octets, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts256to511Octets, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts512to1023Octets, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts1024to1518Octets, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts1519to2047Octets, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts2048to4095Octets, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts4095to9216Octets, /**< Broadcom-specific */
    statReservedEnum79, 
    statReservedEnum80, 
    statReservedEnum81, 
    statReservedEnum82, 
    statReservedEnum83, 
    statReservedEnum84, 
    statReservedEnum85, 
    statReservedEnum86, 
    statReservedEnum87, 
    statReservedEnum88, 
    statReservedEnum89, 
    statReservedEnum90, 
    statReservedEnum91, 
    statReservedEnum92, 
    statReservedEnum93, 
    statReservedEnum94, 
    statReservedEnum95, 
    statReservedEnum96, 
    statReservedEnum97, 
    statReservedEnum98, 
    statReservedEnum99, 
    statReservedEnum100, 
    statReservedEnum101, 
    statReservedEnum102, 
    statReservedEnum103, 
    statReservedEnum104, 
    statReservedEnum105, 
    statReservedEnum106, 
    statReservedEnum107, 
    statReservedEnum108, 
    statReservedEnum109, 
    statReservedEnum110, 
    statReservedEnum111, 
    statReservedEnum112, 
    statReservedEnum113, 
    statReservedEnum114, 
    statReservedEnum115, 
    statReservedEnum116, 
    statReservedEnum117, 
    statReservedEnum118, 
    statReservedEnum119, 
    statReservedEnum120, 
    statReservedEnum121, 
    statReservedEnum122, 
    statReservedEnum123, 
    statReservedEnum124, 
    statReservedEnum125, 
    statReservedEnum126, 
    statReservedEnum127, 
    statReservedEnum128, 
    statReservedEnum129, 
    statReservedEnum130, 
    statReservedEnum131, 
    statReservedEnum132, 
    statReservedEnum133, 
    statReservedEnum134, 
    statReservedEnum135, 
    statReservedEnum136, 
    statReservedEnum137, 
    statReservedEnum138, 
    statReservedEnum139, 
    statReservedEnum140, 
    statReservedEnum141, 
    statReservedEnum142, 
    snmpOpenNSLReceivedPkts9217to16383Octets, /**< Broadcom-specific */
    snmpOpenNSLTransmittedPkts9217to16383Octets, /**< Broadcom-specific */
    statReservedEnum143, 
    statReservedEnum144, 
    statReservedEnum145, 
    statReservedEnum146, 
    statReservedEnum147, 
    statReservedEnum148, 
    statReservedEnum149, 
    statReservedEnum150, 
    statReservedEnum151, 
    statReservedEnum152, 
    statReservedEnum153, 
    statReservedEnum154, 
    statReservedEnum155, 
    statReservedEnum156, 
    statReservedEnum157, 
    statReservedEnum158, 
    statReservedEnum159, 
    statReservedEnum160, 
    statReservedEnum161, 
    statReservedEnum162, 
    statReservedEnum163, 
    statReservedEnum164, 
    statReservedEnum165, 
    statReservedEnum166, 
    statReservedEnum167, 
    statReservedEnum168, 
    statReservedEnum169, 
    statReservedEnum170, 
    statReservedEnum171, 
    statReservedEnum172, 
    statReservedEnum173, 
    statReservedEnum174, 
    statReservedEnum175, 
    statReservedEnum176, 
    statReservedEnum177, 
    statReservedEnum178, 
    statReservedEnum179, 
    statReservedEnum180, 
    statReservedEnum181 
} opennsl_stat_val_t;

#define OPENNSL_STAT_NAME_INITIALIZER \
{ \
    "statReservedEnum1", \
    "statReservedEnum2", \
    "statReservedEnum3", \
    "opennsl_spl_snmpIfInDiscards", \
    "opennsl_spl_snmpIfInErrors", \
    "statReservedEnum4", \
    "statReservedEnum5", \
    "statReservedEnum6", \
    "statReservedEnum7", \
    "opennsl_spl_snmpIfOutDiscards", \
    "opennsl_spl_snmpIfOutErrors", \
    "statReservedEnum8", \
    "statReservedEnum9", \
    "statReservedEnum10", \
    "statReservedEnum11", \
    "statReservedEnum12", \
    "statReservedEnum13", \
    "statReservedEnum14", \
    "statReservedEnum15", \
    "statReservedEnum16", \
    "statReservedEnum17", \
    "statReservedEnum18", \
    "statReservedEnum19", \
    "statReservedEnum20", \
    "statReservedEnum21", \
    "statReservedEnum22", \
    "statReservedEnum23", \
    "statReservedEnum24", \
    "statReservedEnum25", \
    "statReservedEnum26", \
    "statReservedEnum27", \
    "statReservedEnum28", \
    "statReservedEnum29", \
    "statReservedEnum30", \
    "statReservedEnum31", \
    "statReservedEnum32", \
    "statReservedEnum33", \
    "statReservedEnum34", \
    "statReservedEnum35", \
    "statReservedEnum36", \
    "statReservedEnum37", \
    "statReservedEnum38", \
    "statReservedEnum39", \
    "statReservedEnum40", \
    "statReservedEnum41", \
    "statReservedEnum42", \
    "statReservedEnum43", \
    "statReservedEnum44", \
    "statReservedEnum45", \
    "statReservedEnum46", \
    "statReservedEnum47", \
    "statReservedEnum48", \
    "statReservedEnum49", \
    "statReservedEnum50", \
    "statReservedEnum51", \
    "statReservedEnum52", \
    "statReservedEnum53", \
    "statReservedEnum54", \
    "opennsl_spl_snmpIfHCInOctets", \
    "opennsl_spl_snmpIfHCInUcastPkts", \
    "opennsl_spl_snmpIfHCInMulticastPkts", \
    "opennsl_spl_snmpIfHCInBroadcastPkts", \
    "opennsl_spl_snmpIfHCOutOctets", \
    "opennsl_spl_snmpIfHCOutUcastPkts", \
    "opennsl_spl_snmpIfHCOutMulticastPkts", \
    "opennsl_spl_snmpIfHCOutBroadcastPckts", \
    "statReservedEnum55", \
    "statReservedEnum56", \
    "statReservedEnum57", \
    "statReservedEnum58", \
    "statReservedEnum59", \
    "statReservedEnum60", \
    "statReservedEnum61", \
    "statReservedEnum62", \
    "statReservedEnum63", \
    "statReservedEnum64", \
    "statReservedEnum65", \
    "statReservedEnum66", \
    "statReservedEnum67", \
    "statReservedEnum68", \
    "statReservedEnum69", \
    "statReservedEnum70", \
    "statReservedEnum71", \
    "statReservedEnum72", \
    "statReservedEnum73", \
    "statReservedEnum74", \
    "statReservedEnum75", \
    "statReservedEnum76", \
    "statReservedEnum77", \
    "statReservedEnum78", \
    "snmpOpenNSLReceivedPkts64Octets", \
    "snmpOpenNSLReceivedPkts65to127Octets", \
    "snmpOpenNSLReceivedPkts128to255Octets", \
    "snmpOpenNSLReceivedPkts256to511Octets", \
    "snmpOpenNSLReceivedPkts512to1023Octets", \
    "snmpOpenNSLReceivedPkts1024to1518Octets", \
    "snmpOpenNSLReceivedPkts1519to2047Octets", \
    "snmpOpenNSLReceivedPkts2048to4095Octets", \
    "snmpOpenNSLReceivedPkts4095to9216Octets", \
    "snmpOpenNSLTransmittedPkts64Octets", \
    "snmpOpenNSLTransmittedPkts65to127Octets", \
    "snmpOpenNSLTransmittedPkts128to255Octets", \
    "snmpOpenNSLTransmittedPkts256to511Octets", \
    "snmpOpenNSLTransmittedPkts512to1023Octets", \
    "snmpOpenNSLTransmittedPkts1024to1518Octets", \
    "snmpOpenNSLTransmittedPkts1519to2047Octets", \
    "snmpOpenNSLTransmittedPkts2048to4095Octets", \
    "snmpOpenNSLTransmittedPkts4095to9216Octets", \
    "statReservedEnum79", \
    "statReservedEnum80", \
    "statReservedEnum81", \
    "statReservedEnum82", \
    "statReservedEnum83", \
    "statReservedEnum84", \
    "statReservedEnum85", \
    "statReservedEnum86", \
    "statReservedEnum87", \
    "statReservedEnum88", \
    "statReservedEnum89", \
    "statReservedEnum90", \
    "statReservedEnum91", \
    "statReservedEnum92", \
    "statReservedEnum93", \
    "statReservedEnum94", \
    "statReservedEnum95", \
    "statReservedEnum96", \
    "statReservedEnum97", \
    "statReservedEnum98", \
    "statReservedEnum99", \
    "statReservedEnum100", \
    "statReservedEnum101", \
    "statReservedEnum102", \
    "statReservedEnum103", \
    "statReservedEnum104", \
    "statReservedEnum105", \
    "statReservedEnum106", \
    "statReservedEnum107", \
    "statReservedEnum108", \
    "statReservedEnum109", \
    "statReservedEnum110", \
    "statReservedEnum111", \
    "statReservedEnum112", \
    "statReservedEnum113", \
    "statReservedEnum114", \
    "statReservedEnum115", \
    "statReservedEnum116", \
    "statReservedEnum117", \
    "statReservedEnum118", \
    "statReservedEnum119", \
    "statReservedEnum120", \
    "statReservedEnum121", \
    "statReservedEnum122", \
    "statReservedEnum123", \
    "statReservedEnum124", \
    "statReservedEnum125", \
    "statReservedEnum126", \
    "statReservedEnum127", \
    "statReservedEnum128", \
    "statReservedEnum129", \
    "statReservedEnum130", \
    "statReservedEnum131", \
    "statReservedEnum132", \
    "statReservedEnum133", \
    "statReservedEnum134", \
    "statReservedEnum135", \
    "statReservedEnum136", \
    "statReservedEnum137", \
    "statReservedEnum138", \
    "statReservedEnum139", \
    "statReservedEnum140", \
    "statReservedEnum141", \
    "statReservedEnum142", \
    "snmpOpenNSLReceivedPkts9217to16383Octets", \
    "snmpOpenNSLTransmittedPkts9217to16383Octets", \
    "statReservedEnum143", \
    "statReservedEnum144", \
    "statReservedEnum145", \
    "statReservedEnum146", \
    "statReservedEnum147", \
    "statReservedEnum148", \
    "statReservedEnum149", \
    "statReservedEnum150", \
    "statReservedEnum151", \
    "statReservedEnum152", \
    "statReservedEnum153", \
    "statReservedEnum154", \
    "statReservedEnum155", \
    "statReservedEnum156", \
    "statReservedEnum157", \
    "statReservedEnum158", \
    "statReservedEnum159", \
    "statReservedEnum160", \
    "statReservedEnum161", \
    "statReservedEnum162", \
    "statReservedEnum163", \
    "statReservedEnum164", \
    "statReservedEnum165", \
    "statReservedEnum166", \
    "statReservedEnum167", \
    "statReservedEnum168", \
    "statReservedEnum169", \
    "statReservedEnum170", \
    "statReservedEnum171", \
    "statReservedEnum172", \
    "statReservedEnum173", \
    "statReservedEnum174", \
    "statReservedEnum175", \
    "statReservedEnum176", \
    "statReservedEnum177", \
    "statReservedEnum178", \
    "statReservedEnum179", \
    "statReservedEnum180"  \
}

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Get the specified statistics from the device.
 *
 *\description The native statistics are 64-bits wide; use opennsl_stat_get32()
 *          for 32-bit  statistics. Some counters are implemented on a given
 *          port only when it is  operating in a specific mode, for example,
 *          10 or 100, and not 1000 Mbps.  If the counter is not implemented
 *          on the specified port, or on the port  given its current operating
 *          mode, OPENNSL_E_UNAVAIL is returned.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Zero-based device or logical port number
 *\param    type [IN]   SNMP statistics type defined in opennsl_stat_val_t
 *\param    value [OUT]   Counter value
 *
 *\retval    OPENNSL_E_NONE Success.
 *\retval    OPENNSL_E_PARAM Illegal parameter.
 *\retval    OPENNSL_E_BADID Illegal port number.
 *\retval    OPENNSL_E_INTERNAL Device access failure.
 *\retval    OPENNSL_E_UNAVAIL Counter/variable is not implemented on this current
 *          chip.
 ******************************************************************************/
extern int opennsl_stat_get(
    int unit, 
    opennsl_port_t port, 
    opennsl_stat_val_t type, 
    uint64 *value) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Get the specified statistics from the device.
 *
 *\description This API will retrieve a set of statistic values of the types
 *          specified in the stat_arr array.  The number of values in the
 *          stat_arr array and the available positions in the value_arr array
 *          must match the number given in the nstat argument. 64-bit values
 *          may be truncated to fit into a 32-bit array for
 *          opennsl_stat_multi_get32 .
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   <UNDEF>
 *\param    nstat [IN]   Number of elements in stat array
 *\param    stat_arr [IN]   Array of SNMP statistics types defined in
 *          opennsl_stat_val_t
 *\param    value_arr [OUT]   Collected 64-bit or 32-bit statistics values
 *
 *\retval    OPENNSL_E_xxx
 ******************************************************************************/
extern int opennsl_stat_multi_get(
    int unit, 
    opennsl_port_t port, 
    int nstat, 
    opennsl_stat_val_t *stat_arr, 
    uint64 *value_arr) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#endif /* __OPENNSL_STAT_H__ */
/*@}*/

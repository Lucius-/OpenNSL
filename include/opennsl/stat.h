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
    statReservedEnum1 = 0, 
    statReservedEnum2 = 1, 
    statReservedEnum3 = 2, 
    opennsl_spl_snmpIfInDiscards = 3,   /**< RFC 1213 */
    opennsl_spl_snmpIfInErrors = 4,     /**< RFC 1213 */
    statReservedEnum4 = 5, 
    statReservedEnum5 = 6, 
    statReservedEnum6 = 7, 
    statReservedEnum7 = 8, 
    opennsl_spl_snmpIfOutDiscards = 9,  /**< RFC 1213 */
    opennsl_spl_snmpIfOutErrors = 10,   /**< RFC 1213 */
    statReservedEnum8 = 11, 
    statReservedEnum9 = 12, 
    statReservedEnum10 = 13, 
    statReservedEnum11 = 14, 
    statReservedEnum12 = 15, 
    statReservedEnum13 = 16, 
    statReservedEnum14 = 17, 
    statReservedEnum15 = 18, 
    statReservedEnum16 = 19, 
    statReservedEnum17 = 20, 
    statReservedEnum18 = 21, 
    statReservedEnum19 = 22, 
    statReservedEnum20 = 23, 
    statReservedEnum21 = 24, 
    statReservedEnum22 = 25, 
    statReservedEnum23 = 26, 
    statReservedEnum24 = 27, 
    statReservedEnum25 = 28, 
    statReservedEnum26 = 29, 
    statReservedEnum27 = 30, 
    statReservedEnum28 = 31, 
    statReservedEnum29 = 32, 
    statReservedEnum30 = 33, 
    statReservedEnum31 = 34, 
    statReservedEnum32 = 35, 
    statReservedEnum33 = 36, 
    statReservedEnum34 = 37, 
    statReservedEnum35 = 38, 
    statReservedEnum36 = 39, 
    statReservedEnum37 = 40, 
    statReservedEnum38 = 41, 
    statReservedEnum39 = 42, 
    statReservedEnum40 = 43, 
    statReservedEnum41 = 44, 
    statReservedEnum42 = 45, 
    statReservedEnum43 = 46, 
    statReservedEnum44 = 47, 
    statReservedEnum45 = 48, 
    statReservedEnum46 = 49, 
    statReservedEnum47 = 50, 
    statReservedEnum48 = 51, 
    statReservedEnum49 = 52, 
    statReservedEnum50 = 53, 
    statReservedEnum51 = 54, 
    statReservedEnum52 = 55, 
    statReservedEnum53 = 56, 
    statReservedEnum54 = 57, 
    opennsl_spl_snmpIfHCInOctets = 58,  /**< RFC 2233 */
    opennsl_spl_snmpIfHCInUcastPkts = 59, /**< RFC 2233 */
    opennsl_spl_snmpIfHCInMulticastPkts = 60, /**< RFC 2233 */
    opennsl_spl_snmpIfHCInBroadcastPkts = 61, /**< RFC 2233 */
    opennsl_spl_snmpIfHCOutOctets = 62, /**< RFC 2233 */
    opennsl_spl_snmpIfHCOutUcastPkts = 63, /**< RFC 2233 */
    opennsl_spl_snmpIfHCOutMulticastPkts = 64, /**< RFC 2233 */
    opennsl_spl_snmpIfHCOutBroadcastPckts = 65, /**< RFC 2233 */
    statReservedEnum55 = 66, 
    statReservedEnum56 = 67, 
    statReservedEnum57 = 68, 
    statReservedEnum58 = 69, 
    statReservedEnum59 = 70, 
    statReservedEnum60 = 71, 
    statReservedEnum61 = 72, 
    statReservedEnum62 = 73, 
    statReservedEnum63 = 74, 
    statReservedEnum64 = 75, 
    statReservedEnum65 = 76, 
    statReservedEnum66 = 77, 
    statReservedEnum67 = 78, 
    statReservedEnum68 = 79, 
    statReservedEnum69 = 80, 
    statReservedEnum70 = 81, 
    statReservedEnum71 = 82, 
    statReservedEnum72 = 83, 
    statReservedEnum73 = 84, 
    statReservedEnum74 = 85, 
    statReservedEnum75 = 86, 
    statReservedEnum76 = 87, 
    statReservedEnum77 = 88, 
    statReservedEnum78 = 89, 
    statReservedEnum79 = 90, 
    statReservedEnum80 = 91, 
    statReservedEnum81 = 92, 
    statReservedEnum82 = 93, 
    statReservedEnum83 = 94, 
    statReservedEnum84 = 95, 
    statReservedEnum85 = 96, 
    statReservedEnum86 = 97, 
    statReservedEnum87 = 98, 
    statReservedEnum88 = 99, 
    statReservedEnum89 = 100, 
    statReservedEnum90 = 101, 
    statReservedEnum91 = 102, 
    statReservedEnum92 = 103, 
    statReservedEnum93 = 104, 
    statReservedEnum94 = 105, 
    statReservedEnum95 = 106, 
    statReservedEnum96 = 107, 
    statReservedEnum97 = 108, 
    statReservedEnum98 = 109, 
    statReservedEnum99 = 110, 
    statReservedEnum100 = 111, 
    statReservedEnum101 = 112, 
    statReservedEnum102 = 113, 
    statReservedEnum103 = 114, 
    statReservedEnum104 = 115, 
    statReservedEnum105 = 116, 
    statReservedEnum106 = 117, 
    statReservedEnum107 = 118, 
    statReservedEnum108 = 119, 
    statReservedEnum109 = 120, 
    statReservedEnum110 = 121, 
    statReservedEnum111 = 122, 
    statReservedEnum112 = 123, 
    statReservedEnum113 = 124, 
    statReservedEnum114 = 125, 
    statReservedEnum115 = 126, 
    statReservedEnum116 = 127, 
    statReservedEnum117 = 128, 
    statReservedEnum118 = 129, 
    statReservedEnum119 = 130, 
    statReservedEnum120 = 131, 
    statReservedEnum121 = 132, 
    statReservedEnum122 = 133, 
    statReservedEnum123 = 134, 
    statReservedEnum124 = 135, 
    statReservedEnum125 = 136, 
    statReservedEnum126 = 137, 
    statReservedEnum127 = 138, 
    statReservedEnum128 = 139, 
    statReservedEnum129 = 140, 
    statReservedEnum130 = 141, 
    statReservedEnum131 = 142, 
    statReservedEnum132 = 143, 
    statReservedEnum133 = 144, 
    statReservedEnum134 = 145, 
    statReservedEnum135 = 146, 
    statReservedEnum136 = 147, 
    statReservedEnum137 = 148, 
    statReservedEnum138 = 149, 
    statReservedEnum139 = 150, 
    statReservedEnum140 = 151, 
    statReservedEnum141 = 152, 
    statReservedEnum142 = 153, 
    statReservedEnum143 = 154, 
    statReservedEnum144 = 155, 
    statReservedEnum145 = 156, 
    statReservedEnum146 = 157, 
    statReservedEnum147 = 158, 
    statReservedEnum148 = 159, 
    statReservedEnum149 = 160, 
    statReservedEnum150 = 161, 
    statReservedEnum151 = 162, 
    statReservedEnum152 = 163, 
    statReservedEnum153 = 164, 
    statReservedEnum154 = 165, 
    statReservedEnum155 = 166, 
    statReservedEnum156 = 167, 
    statReservedEnum157 = 168, 
    statReservedEnum158 = 169, 
    statReservedEnum159 = 170, 
    statReservedEnum160 = 171, 
    statReservedEnum161 = 172, 
    statReservedEnum162 = 173, 
    statReservedEnum163 = 174, 
    statReservedEnum164 = 175, 
    statReservedEnum165 = 176, 
    statReservedEnum166 = 177, 
    statReservedEnum167 = 178, 
    statReservedEnum168 = 179, 
    statReservedEnum169 = 180, 
    statReservedEnum170 = 181, 
    statReservedEnum171 = 182, 
    statReservedEnum172 = 183, 
    statReservedEnum173 = 184, 
    statReservedEnum174 = 185, 
    statReservedEnum175 = 186, 
    statReservedEnum176 = 187, 
    statReservedEnum177 = 188, 
    statReservedEnum178 = 189, 
    statReservedEnum179 = 190, 
    statReservedEnum180 = 191, 
    statReservedEnum181 = 192, 
    statReservedEnum182 = 193, 
    statReservedEnum183 = 194, 
    statReservedEnum184 = 195, 
    statReservedEnum185 = 196, 
    statReservedEnum186 = 197, 
    statReservedEnum187 = 198, 
    statReservedEnum188 = 199, 
    statReservedEnum189 = 200, 
    statReservedEnum190 = 201, 
    statReservedEnum191 = 202, 
    statReservedEnum192 = 203, 
    statReservedEnum193 = 204, 
    statReservedEnum194 = 205, 
    statReservedEnum195 = 206, 
    statReservedEnum196 = 207, 
    statReservedEnum197 = 208, 
    statReservedEnum198 = 209, 
    statReservedEnum199 = 210, 
    statReservedEnum200 = 211, 
    statReservedEnum201 = 212 
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
    "statReservedEnum180", \
    "statReservedEnum181", \
    "statReservedEnum182", \
    "statReservedEnum183", \
    "statReservedEnum184", \
    "statReservedEnum185", \
    "statReservedEnum186", \
    "statReservedEnum187", \
    "statReservedEnum188", \
    "statReservedEnum189", \
    "statReservedEnum190", \
    "statReservedEnum191", \
    "statReservedEnum192", \
    "statReservedEnum193", \
    "statReservedEnum194", \
    "statReservedEnum195", \
    "statReservedEnum196", \
    "statReservedEnum197", \
    "statReservedEnum198", \
    "statReservedEnum199", \
    "statReservedEnum200"  \
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
 *          opennsl_stat_multi_get32.
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

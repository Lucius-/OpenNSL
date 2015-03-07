/** \addtogroup switch Switch Management
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
 * \file			switch.h
 ******************************************************************************/

#ifndef __OPENNSL_SWITCH_H__
#define __OPENNSL_SWITCH_H__

#include <opennsl/port.h>
#include <opennsl/error.h>
#include <shared/switch.h>

/** Switch controls. */
typedef enum opennsl_switch_control_e {
    opennslswitchReservedEnum1 = 0, 
    opennslswitchReservedEnum2 = 1, 
    opennslswitchReservedEnum3 = 2, 
    opennslswitchReservedEnum4 = 3, 
    opennslswitchReservedEnum5 = 4, 
    opennslswitchReservedEnum6 = 5, 
    opennslswitchReservedEnum7 = 6, 
    opennslswitchReservedEnum8 = 7, 
    opennslswitchReservedEnum9 = 8, 
    opennslswitchReservedEnum10 = 9, 
    opennslswitchReservedEnum11 = 10, 
    opennslswitchReservedEnum12 = 11, 
    opennslswitchReservedEnum13 = 12, 
    opennslswitchReservedEnum14 = 13, 
    opennslswitchReservedEnum15 = 14, 
    opennslswitchReservedEnum16 = 15, 
    opennslswitchReservedEnum17 = 16, 
    opennslswitchReservedEnum18 = 17, 
    opennslswitchReservedEnum19 = 18, 
    opennslswitchReservedEnum20 = 19, 
    opennslswitchReservedEnum21 = 20, 
    opennslswitchReservedEnum22 = 21, 
    opennslswitchReservedEnum23 = 22, 
    opennslswitchReservedEnum24 = 23, 
    opennslswitchReservedEnum25 = 24, 
    opennslswitchReservedEnum26 = 25, 
    opennslswitchReservedEnum27 = 26, 
    opennslswitchReservedEnum28 = 27, 
    opennslswitchReservedEnum29 = 28, 
    opennslswitchReservedEnum30 = 29, 
    opennslswitchReservedEnum31 = 30, 
    opennslswitchReservedEnum32 = 31, 
    opennslswitchReservedEnum33 = 32, 
    opennslswitchReservedEnum34 = 33, 
    opennslswitchReservedEnum35 = 34, 
    opennslswitchReservedEnum36 = 35, 
    opennslswitchReservedEnum37 = 36, 
    opennslswitchReservedEnum38 = 37, 
    opennslswitchReservedEnum39 = 38, 
    opennslswitchReservedEnum40 = 39, 
    opennslswitchReservedEnum41 = 40, 
    opennslswitchReservedEnum42 = 41, 
    opennslswitchReservedEnum43 = 42, 
    opennslswitchReservedEnum44 = 43, 
    opennslswitchReservedEnum45 = 44, 
    opennslswitchReservedEnum46 = 45, 
    opennslswitchReservedEnum47 = 46, 
    opennslswitchReservedEnum48 = 47, 
    opennslswitchReservedEnum49 = 48, 
    opennslswitchReservedEnum50 = 49, 
    opennslswitchReservedEnum51 = 50, 
    opennslswitchReservedEnum52 = 51, 
    opennslswitchReservedEnum53 = 52, 
    opennslswitchReservedEnum54 = 53, 
    opennslswitchReservedEnum55 = 54, 
    opennslswitchReservedEnum56 = 55, 
    opennslswitchReservedEnum57 = 56, 
    opennslswitchReservedEnum58 = 57, 
    opennslswitchReservedEnum59 = 58, 
    opennslswitchReservedEnum60 = 59, 
    opennslswitchReservedEnum61 = 60, 
    opennslswitchReservedEnum62 = 61, 
    opennslswitchReservedEnum63 = 62, 
    opennslswitchReservedEnum64 = 63, 
    opennslswitchReservedEnum65 = 64, 
    opennslswitchReservedEnum66 = 65, 
    opennslswitchReservedEnum67 = 66, 
    opennslswitchReservedEnum68 = 67, 
    opennslswitchReservedEnum69 = 68, 
    opennslswitchReservedEnum70 = 69, 
    opennslswitchReservedEnum71 = 70, 
    opennslswitchReservedEnum72 = 71, 
    opennslswitchReservedEnum73 = 72, 
    opennslswitchReservedEnum74 = 73, 
    opennslswitchReservedEnum75 = 74, 
    opennslswitchReservedEnum76 = 75, 
    opennslswitchReservedEnum77 = 76, 
    opennslswitchReservedEnum78 = 77, 
    opennslswitchReservedEnum79 = 78, 
    opennslswitchReservedEnum80 = 79, 
    opennslswitchReservedEnum81 = 80, 
    opennslswitchReservedEnum82 = 81, 
    opennslswitchReservedEnum83 = 82, 
    opennslswitchReservedEnum84 = 83, 
    opennslSwitchArpReplyToCpu = 84,    /**< ARP replies to CPU. */
    opennslswitchReservedEnum85 = 85, 
    opennslSwitchArpRequestToCpu = 86,  /**< ARP requests to CPU. */
    opennslswitchReservedEnum86 = 87, 
    opennslswitchReservedEnum87 = 88, 
    opennslSwitchNdPktToCpu = 89,       /**< ND packets to CPU. */
    opennslswitchReservedEnum88 = 90, 
    opennslswitchReservedEnum89 = 91, 
    opennslSwitchIgmpPktToCpu = 92,     /**< IGMP packets to CPU. */
    opennslswitchReservedEnum90, 
    opennslswitchReservedEnum91 = 93, 
    opennslSwitchDhcpPktToCpu = 94,     /**< DHCP packets to CPU. */
    opennslswitchReservedEnum92 = 95, 
    opennslswitchReservedEnum93 = 96, 
    opennslswitchReservedEnum94 = 97, 
    opennslswitchReservedEnum95 = 98, 
    opennslswitchReservedEnum96 = 99, 
    opennslswitchReservedEnum97 = 100, 
    opennslswitchReservedEnum98 = 101, 
    opennslswitchReservedEnum99 = 102, 
    opennslswitchReservedEnum100 = 103, 
    opennslswitchReservedEnum101 = 104, 
    opennslswitchReservedEnum102 = 105, 
    opennslswitchReservedEnum103 = 106, 
    opennslswitchReservedEnum104 = 107, 
    opennslswitchReservedEnum105 = 108, 
    opennslswitchReservedEnum106 = 109, 
    opennslswitchReservedEnum107 = 110, 
    opennslswitchReservedEnum108 = 111, 
    opennslswitchReservedEnum109 = 112, 
    opennslswitchReservedEnum110 = 113, 
    opennslswitchReservedEnum111 = 114, 
    opennslswitchReservedEnum112 = 115, 
    opennslswitchReservedEnum113 = 116, 
    opennslswitchReservedEnum114 = 117, 
    opennslswitchReservedEnum115 = 118, 
    opennslswitchReservedEnum116 = 119, 
    opennslswitchReservedEnum117 = 120, 
    opennslswitchReservedEnum118 = 121, 
    opennslswitchReservedEnum119 = 122, 
    opennslswitchReservedEnum120 = 123, 
    opennslswitchReservedEnum121 = 124, 
    opennslswitchReservedEnum122 = 125, 
    opennslswitchReservedEnum123 = 126, 
    opennslswitchReservedEnum124 = 127, 
    opennslswitchReservedEnum125 = 128, 
    opennslswitchReservedEnum126 = 129, 
    opennslswitchReservedEnum127 = 130, 
    opennslswitchReservedEnum128 = 131, 
    opennslswitchReservedEnum129 = 132, 
    opennslswitchReservedEnum130 = 133, 
    opennslswitchReservedEnum131 = 134, 
    opennslswitchReservedEnum132 = 135, 
    opennslSwitchHashControl = 136,     /**< Hash Control of fields. */
    opennslswitchReservedEnum133 = 137, 
    opennslswitchReservedEnum134 = 138, 
    opennslswitchReservedEnum135 = 139, 
    opennslswitchReservedEnum136 = 140, 
    opennslswitchReservedEnum137 = 141, 
    opennslswitchReservedEnum138 = 142, 
    opennslswitchReservedEnum139 = 143, 
    opennslswitchReservedEnum140 = 144, 
    opennslswitchReservedEnum141 = 145, 
    opennslswitchReservedEnum142 = 146, 
    opennslSwitchHashSeed0 = 147,       /**< network switch hash seeds. */
    opennslSwitchHashSeed1 = 148,       /**< For enhanced hashing algoithm. */
    opennslSwitchHashField0PreProcessEnable = 149, /**< Enable pre-processing for enhanced
                                           hash mode 0. */
    opennslSwitchHashField1PreProcessEnable = 150, /**< Enable pre-processing for enhanced
                                           hash mode 1. */
    opennslSwitchHashField0Config = 151, /**< network switch enhanced hash mode 0
                                           config. */
    opennslSwitchHashField0Config1 = 152, /**< network switch enhanced hash mode 0
                                           config 1. */
    opennslSwitchHashField1Config = 153, /**< network switch enhanced hash mode 1
                                           config. */
    opennslSwitchHashField1Config1 = 154, /**< network switch enhanced hash mode 1
                                           config 1. */
    opennslswitchReservedEnum143 = 155, 
    opennslSwitchHashSelectControl = 156, /**< network switch field selection
                                           control. */
    opennslSwitchHashIP4Field0 = 157,   /**< network switch enhanced hash field. */
    opennslSwitchHashIP4Field1 = 158,   /**< Selections for IPv4 packets. */
    opennslSwitchHashIP4TcpUdpField0 = 159, /**< network switch enhanced hash field. */
    opennslSwitchHashIP4TcpUdpField1 = 160, /**< Selections for IPv4 TCP/UDP packets. */
    opennslSwitchHashIP4TcpUdpPortsEqualField0 = 161, /**< network switch enhanced hash field. */
    opennslSwitchHashIP4TcpUdpPortsEqualField1 = 162, /**< Selections for IPv4 TCP/UDP packets
                                           with source L4 port equals to
                                           destination L4 port. */
    opennslSwitchHashIP6Field0 = 163,   /**< network switch enhanced hash field. */
    opennslSwitchHashIP6Field1 = 164,   /**< Selections for IPv6 packets. */
    opennslSwitchHashIP6TcpUdpField0 = 165, /**< network switch enhanced hash field. */
    opennslSwitchHashIP6TcpUdpField1 = 166, /**< Selections for IPv6 TCP/UDP packets. */
    opennslSwitchHashIP6TcpUdpPortsEqualField0 = 167, /**< network switch enhanced hash field. */
    opennslSwitchHashIP6TcpUdpPortsEqualField1 = 168, /**< Selections for IPv6 TCP/UDP packets
                                           with source L4 port equals to
                                           destination L4 port. */
    opennslswitchReservedEnum144 = 169, 
    opennslswitchReservedEnum145 = 170, 
    opennslswitchReservedEnum146 = 171, 
    opennslswitchReservedEnum147 = 172, 
    opennslswitchReservedEnum148 = 173, 
    opennslswitchReservedEnum149 = 174, 
    opennslswitchReservedEnum150 = 175, 
    opennslswitchReservedEnum151 = 176, 
    opennslswitchReservedEnum152 = 177, 
    opennslswitchReservedEnum153 = 178, 
    opennslswitchReservedEnum154 = 179, 
    opennslswitchReservedEnum155 = 180, 
    opennslswitchReservedEnum156 = 181, 
    opennslswitchReservedEnum157 = 182, 
    opennslswitchReservedEnum158 = 183, 
    opennslswitchReservedEnum159 = 184, 
    opennslswitchReservedEnum160 = 185, 
    opennslswitchReservedEnum161 = 186, 
    opennslswitchReservedEnum162 = 187, 
    opennslswitchReservedEnum163 = 188, 
    opennslswitchReservedEnum164 = 189, 
    opennslswitchReservedEnum165 = 190, 
    opennslswitchReservedEnum166 = 191, 
    opennslswitchReservedEnum167 = 192, 
    opennslswitchReservedEnum168 = 193, 
    opennslswitchReservedEnum169 = 194, 
    opennslswitchReservedEnum170 = 195, 
    opennslswitchReservedEnum171 = 196, 
    opennslswitchReservedEnum172 = 197, 
    opennslswitchReservedEnum173 = 198, 
    opennslswitchReservedEnum174 = 199, 
    opennslswitchReservedEnum175 = 200, 
    opennslswitchReservedEnum176 = 201, 
    opennslswitchReservedEnum177 = 202, 
    opennslswitchReservedEnum178 = 203, 
    opennslswitchReservedEnum179 = 204, 
    opennslswitchReservedEnum180 = 205, 
    opennslswitchReservedEnum181 = 206, 
    opennslswitchReservedEnum182 = 207, 
    opennslswitchReservedEnum183 = 208, 
    opennslswitchReservedEnum184 = 209, 
    opennslSwitchECMPHashSet0Offset = 210, /**< network switch enhanced hash bits. */
    opennslSwitchECMPHashSet1Offset = 211, /**< Selections for ECMP. */
    opennslswitchReservedEnum185 = 212, 
    opennslswitchReservedEnum186 = 213, 
    opennslswitchReservedEnum187 = 214, 
    opennslswitchReservedEnum188 = 215, 
    opennslswitchReservedEnum189 = 216, 
    opennslswitchReservedEnum190 = 217, 
    opennslswitchReservedEnum191 = 218, 
    opennslswitchReservedEnum192 = 219, 
    opennslswitchReservedEnum193 = 220, 
    opennslswitchReservedEnum194 = 221, 
    opennslswitchReservedEnum195 = 222, 
    opennslswitchReservedEnum196 = 223, 
    opennslswitchReservedEnum197 = 224, 
    opennslswitchReservedEnum198 = 225, 
    opennslswitchReservedEnum199 = 226, 
    opennslswitchReservedEnum200 = 227, 
    opennslswitchReservedEnum201 = 228, 
    opennslswitchReservedEnum202 = 229, 
    opennslSwitchL3EgressMode = 230,    /**< Enable advanced egress management. */
    opennslswitchReservedEnum203 = 231, 
    opennslswitchReservedEnum204 = 232, 
    opennslswitchReservedEnum205 = 233, 
    opennslswitchReservedEnum206 = 234, 
    opennslswitchReservedEnum207 = 235, 
    opennslswitchReservedEnum208 = 236, 
    opennslswitchReservedEnum209 = 237, 
    opennslswitchReservedEnum210 = 238, 
    opennslswitchReservedEnum211 = 239, 
    opennslswitchReservedEnum212 = 240, 
    opennslswitchReservedEnum213 = 241, 
    opennslswitchReservedEnum214 = 242, 
    opennslSwitchControlSync = 243,     /**< Force a sync of the Level 2 warm boot
                                           state on demand. */
    opennslswitchReservedEnum215 = 244, 
    opennslswitchReservedEnum216 = 245, 
    opennslswitchReservedEnum217 = 246, 
    opennslswitchReservedEnum218 = 247, 
    opennslswitchReservedEnum219 = 248, 
    opennslswitchReservedEnum220 = 249, 
    opennslswitchReservedEnum221 = 250, 
    opennslswitchReservedEnum222 = 251, 
    opennslswitchReservedEnum223 = 252, 
    opennslswitchReservedEnum224 = 253, 
    opennslswitchReservedEnum225 = 254, 
    opennslswitchReservedEnum226 = 255, 
    opennslswitchReservedEnum227 = 256, 
    opennslswitchReservedEnum228 = 257, 
    opennslswitchReservedEnum229 = 258, 
    opennslswitchReservedEnum230 = 259, 
    opennslswitchReservedEnum231 = 260, 
    opennslswitchReservedEnum232 = 261, 
    opennslswitchReservedEnum233 = 262, 
    opennslswitchReservedEnum234 = 263, 
    opennslswitchReservedEnum235 = 264, 
    opennslswitchReservedEnum236 = 265, 
    opennslswitchReservedEnum237 = 266, 
    opennslswitchReservedEnum238 = 267, 
    opennslswitchReservedEnum239 = 268, 
    opennslswitchReservedEnum240 = 269, 
    opennslswitchReservedEnum241 = 270, 
    opennslswitchReservedEnum242 = 271, 
    opennslswitchReservedEnum243 = 272, 
    opennslswitchReservedEnum244 = 273, 
    opennslswitchReservedEnum245 = 274, 
    opennslswitchReservedEnum246 = 275, 
    opennslswitchReservedEnum247 = 276, 
    opennslswitchReservedEnum248 = 277, 
    opennslswitchReservedEnum249 = 278, 
    opennslswitchReservedEnum250 = 279, 
    opennslswitchReservedEnum251 = 280, 
    opennslswitchReservedEnum252 = 281, 
    opennslswitchReservedEnum253 = 282, 
    opennslswitchReservedEnum254 = 283, 
    opennslswitchReservedEnum255 = 284, 
    opennslswitchReservedEnum256 = 285, 
    opennslswitchReservedEnum257 = 286, 
    opennslswitchReservedEnum258 = 287, 
    opennslswitchReservedEnum259 = 288, 
    opennslswitchReservedEnum260 = 289, 
    opennslswitchReservedEnum261 = 290, 
    opennslswitchReservedEnum262 = 291, 
    opennslswitchReservedEnum263 = 292, 
    opennslswitchReservedEnum264 = 293, 
    opennslswitchReservedEnum265 = 294, 
    opennslswitchReservedEnum266 = 295, 
    opennslswitchReservedEnum267 = 296, 
    opennslswitchReservedEnum268 = 297, 
    opennslswitchReservedEnum269 = 298, 
    opennslswitchReservedEnum270 = 299, 
    opennslswitchReservedEnum271 = 300, 
    opennslswitchReservedEnum272 = 301, 
    opennslswitchReservedEnum273 = 302, 
    opennslswitchReservedEnum274 = 303, 
    opennslswitchReservedEnum275 = 304, 
    opennslswitchReservedEnum276 = 305, 
    opennslswitchReservedEnum277 = 306, 
    opennslswitchReservedEnum278 = 307, 
    opennslswitchReservedEnum279 = 308, 
    opennslswitchReservedEnum280 = 309, 
    opennslswitchReservedEnum281 = 310, 
    opennslswitchReservedEnum282 = 311, 
    opennslswitchReservedEnum283 = 312, 
    opennslswitchReservedEnum284 = 313, 
    opennslswitchReservedEnum285 = 314, 
    opennslswitchReservedEnum286 = 315, 
    opennslswitchReservedEnum287 = 316, 
    opennslswitchReservedEnum288 = 317, 
    opennslswitchReservedEnum289 = 318, 
    opennslswitchReservedEnum290 = 319, 
    opennslswitchReservedEnum291 = 320, 
    opennslswitchReservedEnum292 = 321, 
    opennslswitchReservedEnum293 = 322, 
    opennslswitchReservedEnum294 = 323, 
    opennslswitchReservedEnum295 = 324, 
    opennslswitchReservedEnum296 = 325, 
    opennslswitchReservedEnum297 = 326, 
    opennslswitchReservedEnum298 = 327, 
    opennslswitchReservedEnum299 = 328, 
    opennslswitchReservedEnum300 = 329, 
    opennslswitchReservedEnum301 = 330, 
    opennslswitchReservedEnum302 = 331, 
    opennslswitchReservedEnum303 = 332, 
    opennslswitchReservedEnum304 = 333, 
    opennslswitchReservedEnum305 = 334, 
    opennslswitchReservedEnum306 = 335, 
    opennslswitchReservedEnum307 = 336, 
    opennslswitchReservedEnum308 = 337, 
    opennslswitchReservedEnum309 = 338, 
    opennslswitchReservedEnum310 = 339, 
    opennslswitchReservedEnum311 = 340, 
    opennslswitchReservedEnum312 = 341, 
    opennslswitchReservedEnum313 = 342, 
    opennslswitchReservedEnum314 = 343, 
    opennslswitchReservedEnum315 = 344, 
    opennslswitchReservedEnum316 = 345, 
    opennslswitchReservedEnum317 = 346, 
    opennslswitchReservedEnum318 = 347, 
    opennslswitchReservedEnum319 = 348, 
    opennslswitchReservedEnum320 = 349, 
    opennslswitchReservedEnum321 = 350, 
    opennslswitchReservedEnum322 = 351, 
    opennslswitchReservedEnum323 = 352, 
    opennslswitchReservedEnum324 = 353, 
    opennslswitchReservedEnum325 = 354, 
    opennslswitchReservedEnum326 = 355, 
    opennslswitchReservedEnum327 = 356, 
    opennslswitchReservedEnum328 = 357, 
    opennslswitchReservedEnum329 = 358, 
    opennslswitchReservedEnum330 = 359, 
    opennslswitchReservedEnum331 = 360, 
    opennslswitchReservedEnum332 = 361, 
    opennslswitchReservedEnum333 = 362, 
    opennslswitchReservedEnum334 = 363, 
    opennslswitchReservedEnum335 = 364, 
    opennslswitchReservedEnum336 = 365, 
    opennslswitchReservedEnum337 = 366, 
    opennslswitchReservedEnum338 = 367, 
    opennslswitchReservedEnum339 = 368, 
    opennslswitchReservedEnum340 = 369, 
    opennslswitchReservedEnum341 = 370, 
    opennslswitchReservedEnum342 = 371, 
    opennslswitchReservedEnum343 = 372, 
    opennslswitchReservedEnum344 = 373, 
    opennslswitchReservedEnum345 = 374, 
    opennslswitchReservedEnum346 = 375, 
    opennslswitchReservedEnum347 = 376, 
    opennslswitchReservedEnum348 = 377, 
    opennslswitchReservedEnum349 = 378, 
    opennslswitchReservedEnum350 = 379, 
    opennslswitchReservedEnum351 = 380, 
    opennslswitchReservedEnum352 = 381, 
    opennslswitchReservedEnum353 = 382, 
    opennslswitchReservedEnum354 = 383, 
    opennslswitchReservedEnum355 = 384, 
    opennslswitchReservedEnum356 = 385, 
    opennslswitchReservedEnum357 = 386, 
    opennslswitchReservedEnum358 = 387, 
    opennslswitchReservedEnum359 = 388, 
    opennslswitchReservedEnum360 = 389, 
    opennslswitchReservedEnum361 = 390, 
    opennslswitchReservedEnum362 = 391, 
    opennslswitchReservedEnum363 = 392, 
    opennslswitchReservedEnum364 = 393, 
    opennslswitchReservedEnum365 = 394, 
    opennslswitchReservedEnum366 = 395, 
    opennslswitchReservedEnum367 = 396, 
    opennslswitchReservedEnum368 = 397, 
    opennslswitchReservedEnum369 = 398, 
    opennslswitchReservedEnum370 = 399, 
    opennslswitchReservedEnum371 = 400, 
    opennslswitchReservedEnum372 = 401, 
    opennslswitchReservedEnum373 = 402, 
    opennslswitchReservedEnum374 = 403, 
    opennslswitchReservedEnum375 = 404, 
    opennslswitchReservedEnum376 = 405, 
    opennslswitchReservedEnum377 = 406, 
    opennslswitchReservedEnum378 = 407, 
    opennslswitchReservedEnum379 = 408, 
    opennslswitchReservedEnum380 = 409, 
    opennslswitchReservedEnum381 = 410, 
    opennslswitchReservedEnum382 = 411, 
    opennslswitchReservedEnum383 = 412, 
    opennslswitchReservedEnum384 = 413, 
    opennslswitchReservedEnum385 = 414, 
    opennslswitchReservedEnum386 = 415, 
    opennslswitchReservedEnum387 = 416, 
    opennslswitchReservedEnum388 = 417, 
    opennslswitchReservedEnum389 = 418, 
    opennslswitchReservedEnum390 = 419, 
    opennslswitchReservedEnum391 = 420, 
    opennslswitchReservedEnum392 = 421, 
    opennslswitchReservedEnum393 = 422, 
    opennslswitchReservedEnum394 = 423, 
    opennslswitchReservedEnum395 = 424, 
    opennslswitchReservedEnum396 = 425, 
    opennslswitchReservedEnum397 = 426, 
    opennslswitchReservedEnum398 = 427, 
    opennslswitchReservedEnum399 = 428, 
    opennslswitchReservedEnum400 = 429, 
    opennslswitchReservedEnum401 = 430, 
    opennslswitchReservedEnum402 = 431, 
    opennslswitchReservedEnum403 = 432, 
    opennslswitchReservedEnum404 = 433, 
    opennslswitchReservedEnum405 = 434, 
    opennslswitchReservedEnum406 = 435, 
    opennslswitchReservedEnum407 = 436, 
    opennslswitchReservedEnum408 = 437, 
    opennslswitchReservedEnum409 = 438, 
    opennslswitchReservedEnum410 = 439, 
    opennslswitchReservedEnum411 = 440, 
    opennslswitchReservedEnum412 = 441, 
    opennslswitchReservedEnum413 = 442, 
    opennslswitchReservedEnum414 = 443, 
    opennslswitchReservedEnum415 = 444, 
    opennslswitchReservedEnum416 = 445, 
    opennslswitchReservedEnum417 = 446, 
    opennslswitchReservedEnum418 = 447, 
    opennslswitchReservedEnum419 = 448, 
    opennslswitchReservedEnum420 = 449, 
    opennslswitchReservedEnum421 = 450, 
    opennslswitchReservedEnum422 = 451, 
    opennslswitchReservedEnum423 = 452, 
    opennslswitchReservedEnum424 = 453, 
    opennslswitchReservedEnum425 = 454, 
    opennslswitchReservedEnum426 = 455, 
    opennslswitchReservedEnum427 = 456, 
    opennslswitchReservedEnum428 = 457, 
    opennslswitchReservedEnum429 = 458, 
    opennslswitchReservedEnum430 = 459, 
    opennslswitchReservedEnum431 = 460, 
    opennslswitchReservedEnum432 = 461, 
    opennslswitchReservedEnum433 = 462, 
    opennslswitchReservedEnum434 = 463, 
    opennslswitchReservedEnum435 = 464, 
    opennslswitchReservedEnum436 = 465, 
    opennslswitchReservedEnum437 = 466, 
    opennslswitchReservedEnum438 = 467, 
    opennslswitchReservedEnum439 = 468, 
    opennslswitchReservedEnum440 = 469, 
    opennslswitchReservedEnum441 = 470, 
    opennslswitchReservedEnum442 = 471, 
    opennslswitchReservedEnum443 = 472, 
    opennslswitchReservedEnum444 = 473, 
    opennslswitchReservedEnum445 = 474, 
    opennslswitchReservedEnum446 = 475, 
    opennslswitchReservedEnum447 = 476, 
    opennslswitchReservedEnum448 = 477, 
    opennslswitchReservedEnum449 = 478, 
    opennslswitchReservedEnum450 = 479, 
    opennslswitchReservedEnum451 = 480, 
    opennslswitchReservedEnum452 = 481, 
    opennslswitchReservedEnum453 = 482, 
    opennslswitchReservedEnum454 = 483, 
    opennslswitchReservedEnum455 = 484, 
    opennslswitchReservedEnum456 = 485, 
    opennslswitchReservedEnum457 = 486, 
    opennslswitchReservedEnum458 = 487, 
    opennslswitchReservedEnum459 = 488, 
    opennslswitchReservedEnum460 = 489, 
    opennslswitchReservedEnum461 = 490, 
    opennslswitchReservedEnum462 = 491, 
    opennslswitchReservedEnum463 = 492, 
    opennslswitchReservedEnum464 = 493, 
    opennslswitchReservedEnum465 = 494, 
    opennslswitchReservedEnum466 = 495, 
    opennslswitchReservedEnum467 = 496, 
    opennslswitchReservedEnum468 = 497, 
    opennslswitchReservedEnum469 = 498, 
    opennslswitchReservedEnum470 = 499, 
    opennslswitchReservedEnum471 = 500, 
    opennslswitchReservedEnum472 = 501, 
    opennslswitchReservedEnum473 = 502, 
    opennslswitchReservedEnum474 = 503, 
    opennslswitchReservedEnum475 = 504, 
    opennslswitchReservedEnum476 = 505, 
    opennslswitchReservedEnum477 = 506, 
    opennslswitchReservedEnum478 = 507, 
    opennslswitchReservedEnum479 = 508, 
    opennslswitchReservedEnum480 = 509, 
    opennslswitchReservedEnum481 = 510, 
    opennslswitchReservedEnum482 = 511, 
    opennslswitchReservedEnum483 = 512, 
    opennslswitchReservedEnum484 = 513, 
    opennslswitchReservedEnum485 = 514, 
    opennslswitchReservedEnum486 = 515, 
    opennslswitchReservedEnum487 = 516, 
    opennslswitchReservedEnum488 = 517, 
    opennslswitchReservedEnum489 = 518, 
    opennslswitchReservedEnum490 = 519, 
    opennslswitchReservedEnum491 = 520, 
    opennslswitchReservedEnum492 = 521, 
    opennslswitchReservedEnum493 = 522, 
    opennslswitchReservedEnum494 = 523, 
    opennslswitchReservedEnum495 = 524, 
    opennslswitchReservedEnum496 = 525, 
    opennslswitchReservedEnum497 = 526, 
    opennslswitchReservedEnum498 = 527, 
    opennslswitchReservedEnum499 = 528, 
    opennslswitchReservedEnum500 = 529, 
    opennslswitchReservedEnum501 = 530, 
    opennslswitchReservedEnum502 = 531, 
    opennslswitchReservedEnum503 = 532, 
    opennslswitchReservedEnum504 = 533, 
    opennslswitchReservedEnum505 = 534, 
    opennslswitchReservedEnum506 = 535, 
    opennslswitchReservedEnum507 = 536, 
    opennslswitchReservedEnum508 = 537, 
    opennslswitchReservedEnum509 = 538, 
    opennslswitchReservedEnum510 = 539, 
    opennslswitchReservedEnum511 = 540, 
    opennslswitchReservedEnum512 = 541, 
    opennslswitchReservedEnum513 = 542, 
    opennslswitchReservedEnum514 = 543, 
    opennslswitchReservedEnum515 = 544, 
    opennslswitchReservedEnum516 = 545, 
    opennslswitchReservedEnum517 = 546, 
    opennslswitchReservedEnum518 = 547, 
    opennslswitchReservedEnum519 = 548, 
    opennslswitchReservedEnum520 = 549, 
    opennslswitchReservedEnum521 = 550, 
    opennslswitchReservedEnum522 = 551, 
    opennslswitchReservedEnum523 = 552, 
    opennslswitchReservedEnum524 = 553, 
    opennslswitchReservedEnum525 = 554, 
    opennslswitchReservedEnum526 = 555, 
    opennslswitchReservedEnum527 = 556, 
    opennslswitchReservedEnum528 = 557, 
    opennslswitchReservedEnum529 = 558, 
    opennslswitchReservedEnum530 = 559, 
    opennslswitchReservedEnum531 = 560, 
    opennslswitchReservedEnum532 = 561, 
    opennslswitchReservedEnum533 = 562, 
    opennslswitchReservedEnum534 = 563, 
    opennslswitchReservedEnum535 = 564, 
    opennslswitchReservedEnum536 = 565, 
    opennslswitchReservedEnum537 = 566, 
    opennslswitchReservedEnum538 = 567, 
    opennslswitchReservedEnum539 = 568, 
    opennslswitchReservedEnum540 = 569, 
    opennslswitchReservedEnum541 = 570, 
    opennslswitchReservedEnum542 = 571, 
    opennslswitchReservedEnum543 = 572, 
    opennslswitchReservedEnum544 = 573, 
    opennslswitchReservedEnum545 = 574, 
    opennslswitchReservedEnum546 = 575, 
    opennslswitchReservedEnum547 = 576, 
    opennslswitchReservedEnum548 = 577, 
    opennslswitchReservedEnum549 = 578, 
    opennslswitchReservedEnum550 = 579, 
    opennslswitchReservedEnum551 = 580, 
    opennslswitchReservedEnum552 = 581, 
    opennslswitchReservedEnum553 = 582, 
    opennslswitchReservedEnum554 = 583, 
    opennslswitchReservedEnum555 = 584, 
    opennslswitchReservedEnum556 = 585, 
    opennslswitchReservedEnum557 = 586, 
    opennslswitchReservedEnum558 = 587, 
    opennslswitchReservedEnum559 = 588, 
    opennslswitchReservedEnum560 = 589, 
    opennslswitchReservedEnum561 = 590, 
    opennslswitchReservedEnum562 = 591, 
    opennslswitchReservedEnum563 = 592, 
    opennslswitchReservedEnum564 = 593, 
    opennslswitchReservedEnum565 = 594, 
    opennslswitchReservedEnum566 = 595, 
    opennslswitchReservedEnum567 = 596, 
    opennslswitchReservedEnum568 = 597, 
    opennslswitchReservedEnum569 = 598, 
    opennslswitchReservedEnum570 = 599, 
    opennslswitchReservedEnum571 = 600, 
    opennslswitchReservedEnum572 = 601, 
    opennslswitchReservedEnum573 = 602, 
    opennslswitchReservedEnum574 = 603, 
    opennslswitchReservedEnum575 = 604, 
    opennslswitchReservedEnum576 = 605, 
    opennslswitchReservedEnum577 = 606, 
    opennslswitchReservedEnum578 = 607, 
    opennslswitchReservedEnum579 = 608, 
    opennslswitchReservedEnum580 = 609, 
    opennslswitchReservedEnum581 = 610, 
    opennslswitchReservedEnum582 = 611, 
    opennslswitchReservedEnum583 = 612, 
    opennslswitchReservedEnum584 = 613, 
    opennslswitchReservedEnum585 = 614, 
    opennslswitchReservedEnum586 = 615, 
    opennslswitchReservedEnum587 = 616, 
    opennslswitchReservedEnum588 = 617, 
    opennslswitchReservedEnum589 = 618, 
    opennslswitchReservedEnum590 = 619, 
    opennslswitchReservedEnum591 = 620, 
    opennslswitchReservedEnum592 = 621, 
    opennslswitchReservedEnum593 = 622, 
    opennslswitchReservedEnum594 = 623, 
    opennslswitchReservedEnum595 = 624, 
    opennslswitchReservedEnum596 = 625, 
    opennslswitchReservedEnum597 = 626, 
    opennslswitchReservedEnum598 = 627, 
    opennslswitchReservedEnum599 = 628, 
    opennslswitchReservedEnum600 = 629, 
    opennslswitchReservedEnum601 = 630, 
    opennslswitchReservedEnum602 = 631, 
    opennslswitchReservedEnum603 = 632, 
    opennslswitchReservedEnum604 = 633, 
    opennslswitchReservedEnum605 = 634, 
    opennslswitchReservedEnum606 = 635, 
    opennslswitchReservedEnum607 = 636, 
    opennslswitchReservedEnum608 = 637, 
    opennslswitchReservedEnum609 = 638, 
    opennslswitchReservedEnum610 = 639, 
    opennslswitchReservedEnum611 = 640, 
    opennslswitchReservedEnum612 = 641, 
    opennslswitchReservedEnum613 = 642, 
    opennslswitchReservedEnum614 = 643, 
    opennslswitchReservedEnum615 = 644, 
    opennslswitchReservedEnum616 = 645, 
    opennslswitchReservedEnum617 = 646, 
    opennslswitchReservedEnum618 = 647, 
    opennslswitchReservedEnum619 = 648, 
    opennslswitchReservedEnum620 = 649, 
    opennslswitchReservedEnum621 = 650, 
    opennslswitchReservedEnum622 = 651, 
    opennslswitchReservedEnum623 = 652, 
    opennslswitchReservedEnum624 = 653, 
    opennslswitchReservedEnum625 = 654, 
    opennslswitchReservedEnum626 = 655, 
    opennslswitchReservedEnum627 = 656, 
    opennslswitchReservedEnum628 = 657, 
    opennslswitchReservedEnum629 = 658, 
    opennslswitchReservedEnum630 = 659, 
    opennslswitchReservedEnum631 = 660, 
    opennslswitchReservedEnum632 = 661, 
    opennslswitchReservedEnum633 = 662, 
    opennslswitchReservedEnum634 = 663, 
    opennslswitchReservedEnum635 = 664, 
    opennslswitchReservedEnum636 = 665, 
    opennslswitchReservedEnum637 = 666, 
    opennslswitchReservedEnum638 = 667, 
    opennslswitchReservedEnum639 = 668, 
    opennslswitchReservedEnum640 = 669, 
    opennslswitchReservedEnum641 = 670, 
    opennslswitchReservedEnum642 = 671, 
    opennslswitchReservedEnum643 = 672, 
    opennslswitchReservedEnum644 = 673, 
    opennslswitchReservedEnum645 = 674, 
    opennslswitchReservedEnum646 = 675, 
    opennslswitchReservedEnum647 = 676, 
    opennslswitchReservedEnum648 = 677, 
    opennslswitchReservedEnum649 = 678, 
    opennslswitchReservedEnum650 = 679, 
    opennslswitchReservedEnum651 = 680, 
    opennslswitchReservedEnum652 = 681, 
    opennslswitchReservedEnum653 = 682, 
    opennslswitchReservedEnum654 = 683, 
    opennslswitchReservedEnum655 = 684, 
    opennslswitchReservedEnum656 = 685, 
    opennslswitchReservedEnum657 = 686, 
    opennslswitchReservedEnum658 = 687, 
    opennslswitchReservedEnum659 = 688, 
    opennslswitchReservedEnum660 = 689, 
    opennslswitchReservedEnum661 = 690, 
    opennslswitchReservedEnum662 = 691, 
    opennslswitchReservedEnum663 = 692, 
    opennslswitchReservedEnum664 = 693, 
    opennslswitchReservedEnum665 = 694, 
    opennslswitchReservedEnum666 = 695, 
    opennslswitchReservedEnum667 = 696, 
    opennslswitchReservedEnum668 = 697, 
    opennslswitchReservedEnum669 = 698, 
    opennslswitchReservedEnum670 = 699, 
    opennslswitchReservedEnum671 = 700, 
    opennslswitchReservedEnum672 = 701, 
    opennslswitchReservedEnum673 = 702, 
    opennslswitchReservedEnum674 = 703, 
    opennslswitchReservedEnum675 = 704, 
    opennslswitchReservedEnum676 = 705, 
    opennslswitchReservedEnum677 = 706, 
    opennslswitchReservedEnum678 = 707, 
    opennslswitchReservedEnum679 = 708, 
    opennslswitchReservedEnum680 = 709, 
    opennslswitchReservedEnum681 = 710, 
    opennslswitchReservedEnum682 = 711, 
    opennslswitchReservedEnum683 = 712, 
    opennslswitchReservedEnum684 = 713, 
    opennslswitchReservedEnum685 = 714, 
    opennslswitchReservedEnum686 = 715, 
    opennslswitchReservedEnum687 = 716, 
    opennslSwitchBstEnable = 717,       /**< Enable BST tracking. */
    opennslSwitchBstTrackingMode = 718, /**< BST resource usage tracking mode. */
    opennslswitchReservedEnum688 = 719, 
    opennslswitchReservedEnum689 = 720, 
    opennslswitchReservedEnum690 = 721, 
    opennslswitchReservedEnum691 = 722, 
    opennslswitchReservedEnum692 = 723, 
    opennslswitchReservedEnum693 = 724, 
    opennslswitchReservedEnum694 = 725, 
    opennslswitchReservedEnum695 = 726, 
    opennslswitchReservedEnum696 = 727, 
    opennslswitchReservedEnum697 = 728, 
    opennslswitchReservedEnum698 = 729, 
    opennslswitchReservedEnum699 = 730, 
    opennslswitchReservedEnum700 = 731, 
    opennslswitchReservedEnum701 = 732, 
    opennslswitchReservedEnum702 = 733, 
    opennslswitchReservedEnum703 = 734, 
    opennslswitchReservedEnum704 = 735, 
    opennslswitchReservedEnum705 = 736, 
    opennslswitchReservedEnum706 = 737, 
    opennslswitchReservedEnum707 = 738, 
    opennslswitchReservedEnum708 = 739, 
    opennslswitchReservedEnum709 = 740, 
    opennslswitchReservedEnum710 = 741, 
    opennslswitchReservedEnum711 = 742, 
    opennslswitchReservedEnum712 = 743, 
    opennslswitchReservedEnum713 = 744, 
    opennslswitchReservedEnum714 = 745, 
    opennslswitchReservedEnum715 = 746, 
    opennslswitchReservedEnum716 = 747, 
    opennslswitchReservedEnum717 = 748, 
    opennslswitchReservedEnum718 = 749, 
    opennslswitchReservedEnum719 = 750, 
    opennslswitchReservedEnum720 = 751, 
    opennslswitchReservedEnum721 = 752, 
    opennslswitchReservedEnum722 = 753, 
    opennslswitchReservedEnum723 = 754, 
    opennslswitchReservedEnum724 = 755, 
    opennslswitchReservedEnum725 = 756, 
    opennslswitchReservedEnum726 = 757, 
    opennslswitchReservedEnum727 = 758, 
    opennslswitchReservedEnum728 = 759, 
    opennslswitchReservedEnum729 = 760, 
    opennslswitchReservedEnum730 = 761, 
    opennslswitchReservedEnum731 = 762, 
    opennslswitchReservedEnum732 = 763, 
    opennslswitchReservedEnum733 = 764, 
    opennslswitchReservedEnum734 = 765, 
    opennslswitchReservedEnum735 = 766, 
    opennslswitchReservedEnum736 = 767, 
    opennslswitchReservedEnum737 = 768, 
    opennslswitchReservedEnum738 = 769, 
    opennslswitchReservedEnum739 = 770, 
    opennslswitchReservedEnum740 = 771, 
    opennslswitchReservedEnum741 = 772, 
    opennslswitchReservedEnum742 = 773, 
    opennslswitchReservedEnum743 = 774, 
    opennslswitchReservedEnum744 = 775, 
    opennslswitchReservedEnum745 = 776, 
    opennslswitchReservedEnum746 = 777, 
    opennslswitchReservedEnum747 = 778, 
    opennslswitchReservedEnum748 = 779, 
    opennslswitchReservedEnum749 = 780, 
    opennslswitchReservedEnum750 = 781, 
    opennslSwitchEcmpMacroFlowHashEnable = 782, /**< Enable ECMP macro-flow hashing. */
    opennslswitchReservedEnum751 = 783, 
    opennslswitchReservedEnum752 = 784, 
    opennslswitchReservedEnum753 = 785, 
    opennslswitchReservedEnum754 = 786, 
    opennslswitchReservedEnum755 = 787, 
    opennslswitchReservedEnum756 = 788, 
    opennslswitchReservedEnum757 = 789, 
    opennslswitchReservedEnum758 = 790, 
    opennslswitchReservedEnum759 = 791, 
    opennslswitchReservedEnum760 = 792, 
    opennslswitchReservedEnum761 = 793, 
    opennslswitchReservedEnum762 = 794, 
    opennslswitchReservedEnum763 = 795, 
    opennslswitchReservedEnum764 = 796, 
    opennslswitchReservedEnum765 = 797, 
    opennslswitchReservedEnum766 = 798, 
    opennslswitchReservedEnum767 = 799, 
    opennslswitchReservedEnum768 = 800, 
    opennslswitchReservedEnum769 = 801, 
    opennslswitchReservedEnum770 = 802, 
    opennslswitchReservedEnum771 = 803, 
    opennslswitchReservedEnum772 = 804, 
    opennslswitchReservedEnum773 = 805, 
    opennslswitchReservedEnum774 = 806, 
    opennslswitchReservedEnum775 = 807, 
    opennslswitchReservedEnum776 = 808, 
    opennslswitchReservedEnum777 = 809, 
    opennslswitchReservedEnum778 = 810, 
    opennslswitchReservedEnum779 = 811, 
    opennslswitchReservedEnum780 = 812, 
    opennslswitchReservedEnum781 = 813, 
    opennslswitchReservedEnum782 = 814, 
    opennslswitchReservedEnum783 = 815, 
    opennslswitchReservedEnum784 = 816, 
    opennslswitchReservedEnum785 = 817, 
    opennslswitchReservedEnum786 = 818, 
    opennslswitchReservedEnum787 = 819, 
    opennslswitchReservedEnum788 = 820, 
    opennslswitchReservedEnum789 = 821, 
    opennslswitchReservedEnum790 = 822, 
    opennslswitchReservedEnum791 = 823, 
    opennslswitchReservedEnum792 = 824, 
    opennslswitchReservedEnum793 = 825, 
    opennslswitchReservedEnum794 = 826, 
    opennslswitchReservedEnum795 = 827, 
    opennslswitchReservedEnum796 = 828, 
    opennslswitchReservedEnum797 = 829, 
    opennslswitchReservedEnum798 = 830, 
    opennslswitchReservedEnum799 = 831, 
    opennslswitchReservedEnum800 = 832, 
    opennslswitchReservedEnum801 = 833, 
    opennslswitchReservedEnum802 = 834, 
    opennslswitchReservedEnum803 = 835, 
    opennslswitchReservedEnum804 = 836, 
    opennslswitchReservedEnum805 = 837, 
    opennslswitchReservedEnum806 = 838, 
    opennslswitchReservedEnum807 = 839, 
    opennslswitchReservedEnum808 = 840, 
    opennslswitchReservedEnum809 = 841, 
    opennslswitchReservedEnum810 = 842, 
    opennslswitchReservedEnum811 = 843, 
    opennslswitchReservedEnum812 = 844, 
    opennslswitchReservedEnum813 = 845, 
    opennslswitchReservedEnum814 = 846, 
    opennslswitchReservedEnum815 = 847, 
    opennslswitchReservedEnum816 = 848, 
    opennslswitchReservedEnum817 = 849, 
    opennslswitchReservedEnum818 = 850, 
    opennslswitchReservedEnum819 = 851, 
    opennslswitchReservedEnum820 = 852, 
    opennslswitchReservedEnum821 = 853, 
    opennslswitchReservedEnum822 = 854, 
    opennslswitchReservedEnum823 = 855, 
    opennslswitchReservedEnum824 = 856, 
    opennslswitchReservedEnum825 = 857, 
    opennslswitchReservedEnum826 = 858, 
    opennslswitchReservedEnum827 = 859, 
    opennslswitchReservedEnum828 = 860, 
    opennslswitchReservedEnum829 = 861, 
    opennslswitchReservedEnum830 = 862, 
    opennslswitchReservedEnum831 = 863, 
    opennslswitchReservedEnum832 = 864, 
    opennslswitchReservedEnum833 = 865, 
    opennslswitchReservedEnum834 = 866, 
    opennslswitchReservedEnum835 = 867, 
    opennslswitchReservedEnum836 = 868, 
    opennslswitchReservedEnum837 = 869, 
    opennslswitchReservedEnum838 = 870, 
    opennslswitchReservedEnum839 = 871, 
    opennslswitchReservedEnum840 = 872, 
    opennslswitchReservedEnum841 = 873, 
    opennslswitchReservedEnum842 = 874, 
    opennslswitchReservedEnum843 = 875, 
    opennslswitchReservedEnum844 = 876, 
    opennslswitchReservedEnum845 = 877, 
    opennslswitchReservedEnum846 = 878, 
    opennslswitchReservedEnum847 = 879, 
    opennslswitchReservedEnum848 = 880, 
    opennslswitchReservedEnum849 = 881, 
    opennslswitchReservedEnum850 = 882, 
    opennslswitchReservedEnum851 = 883, 
    opennslswitchReservedEnum852 = 884, 
    opennslswitchReservedEnum853 = 885, 
    opennslswitchReservedEnum854 = 886, 
    opennslswitchReservedEnum855 = 887, 
    opennslswitchReservedEnum856 = 888, 
    opennslswitchReservedEnum857 = 889, 
    opennslswitchReservedEnum858 = 890, 
    opennslswitchReservedEnum859 = 891, 
    opennslswitchReservedEnum860 = 892, 
    opennslswitchReservedEnum861 = 893, 
    opennslswitchReservedEnum862 = 894, 
    opennslswitchReservedEnum863 = 895, 
    opennslswitchReservedEnum864 = 896, 
    opennslswitchReservedEnum865 = 897, 
    opennslswitchReservedEnum866 = 898, 
    opennslswitchReservedEnum867 = 899, 
    opennslswitchReservedEnum868 = 900, 
    opennslswitchReservedEnum869 = 901, 
    opennslswitchReservedEnum870 = 902, 
    opennslswitchReservedEnum871 = 903, 
    opennslswitchReservedEnum872 = 904, 
    opennslswitchReservedEnum873 = 905, 
    opennslswitchReservedEnum874 = 906, 
    opennslswitchReservedEnum875 = 907, 
    opennslswitchReservedEnum876 = 908, 
    opennslswitchReservedEnum877 = 909, 
    opennslswitchReservedEnum878 = 910, 
    opennslswitchReservedEnum879 = 911, 
    opennslswitchReservedEnum880 = 912, 
    opennslswitchReservedEnum881 = 913, 
    opennslswitchReservedEnum882 = 914, 
    opennslswitchReservedEnum883 = 915, 
    opennslswitchReservedEnum884 = 916 
} opennsl_switch_control_t;

#define OPENNSL_SWITCH_CONTROL_STR \
    "opennslswitchReservedEnum1", \
    "opennslswitchReservedEnum2", \
    "opennslswitchReservedEnum3", \
    "opennslswitchReservedEnum4", \
    "opennslswitchReservedEnum5", \
    "opennslswitchReservedEnum6", \
    "opennslswitchReservedEnum7", \
    "opennslswitchReservedEnum8", \
    "opennslswitchReservedEnum9", \
    "opennslswitchReservedEnum10", \
    "opennslswitchReservedEnum11", \
    "opennslswitchReservedEnum12", \
    "opennslswitchReservedEnum13", \
    "opennslswitchReservedEnum14", \
    "opennslswitchReservedEnum15", \
    "opennslswitchReservedEnum16", \
    "opennslswitchReservedEnum17", \
    "opennslswitchReservedEnum18", \
    "opennslswitchReservedEnum19", \
    "opennslswitchReservedEnum20", \
    "opennslswitchReservedEnum21", \
    "opennslswitchReservedEnum22", \
    "opennslswitchReservedEnum23", \
    "opennslswitchReservedEnum24", \
    "opennslswitchReservedEnum25", \
    "opennslswitchReservedEnum26", \
    "opennslswitchReservedEnum27", \
    "opennslswitchReservedEnum28", \
    "opennslswitchReservedEnum29", \
    "opennslswitchReservedEnum30", \
    "opennslswitchReservedEnum31", \
    "opennslswitchReservedEnum32", \
    "opennslswitchReservedEnum33", \
    "opennslswitchReservedEnum34", \
    "opennslswitchReservedEnum35", \
    "opennslswitchReservedEnum36", \
    "opennslswitchReservedEnum37", \
    "opennslswitchReservedEnum38", \
    "opennslswitchReservedEnum39", \
    "opennslswitchReservedEnum40", \
    "opennslswitchReservedEnum41", \
    "opennslswitchReservedEnum42", \
    "opennslswitchReservedEnum43", \
    "opennslswitchReservedEnum44", \
    "opennslswitchReservedEnum45", \
    "opennslswitchReservedEnum46", \
    "opennslswitchReservedEnum47", \
    "opennslswitchReservedEnum48", \
    "opennslswitchReservedEnum49", \
    "opennslswitchReservedEnum50", \
    "opennslswitchReservedEnum51", \
    "opennslswitchReservedEnum52", \
    "opennslswitchReservedEnum53", \
    "opennslswitchReservedEnum54", \
    "opennslswitchReservedEnum55", \
    "opennslswitchReservedEnum56", \
    "opennslswitchReservedEnum57", \
    "opennslswitchReservedEnum58", \
    "opennslswitchReservedEnum59", \
    "opennslswitchReservedEnum60", \
    "opennslswitchReservedEnum61", \
    "opennslswitchReservedEnum62", \
    "opennslswitchReservedEnum63", \
    "opennslswitchReservedEnum64", \
    "opennslswitchReservedEnum65", \
    "opennslswitchReservedEnum66", \
    "opennslswitchReservedEnum67", \
    "opennslswitchReservedEnum68", \
    "opennslswitchReservedEnum69", \
    "opennslswitchReservedEnum70", \
    "opennslswitchReservedEnum71", \
    "opennslswitchReservedEnum72", \
    "opennslswitchReservedEnum73", \
    "opennslswitchReservedEnum74", \
    "opennslswitchReservedEnum75", \
    "opennslswitchReservedEnum76", \
    "opennslswitchReservedEnum77", \
    "opennslswitchReservedEnum78", \
    "opennslswitchReservedEnum79", \
    "opennslswitchReservedEnum80", \
    "opennslswitchReservedEnum81", \
    "opennslswitchReservedEnum82", \
    "opennslswitchReservedEnum83", \
    "opennslswitchReservedEnum84", \
    "ArpReplyToCpu", \
    "opennslswitchReservedEnum85", \
    "ArpRequestToCpu", \
    "opennslswitchReservedEnum86", \
    "opennslswitchReservedEnum87", \
    "NdPktToCpu", \
    "opennslswitchReservedEnum88", \
    "opennslswitchReservedEnum89", \
    "IgmpPktToCpu", \
    "opennslswitchReservedEnum90", \
    "DhcpPktToCpu", \
    "opennslswitchReservedEnum91", \
    "opennslswitchReservedEnum92", \
    "opennslswitchReservedEnum93", \
    "opennslswitchReservedEnum94", \
    "opennslswitchReservedEnum95", \
    "opennslswitchReservedEnum96", \
    "opennslswitchReservedEnum97", \
    "opennslswitchReservedEnum98", \
    "opennslswitchReservedEnum99", \
    "opennslswitchReservedEnum100", \
    "opennslswitchReservedEnum101", \
    "opennslswitchReservedEnum102", \
    "opennslswitchReservedEnum103", \
    "opennslswitchReservedEnum104", \
    "opennslswitchReservedEnum105", \
    "opennslswitchReservedEnum106", \
    "opennslswitchReservedEnum107", \
    "opennslswitchReservedEnum108", \
    "opennslswitchReservedEnum109", \
    "opennslswitchReservedEnum110", \
    "opennslswitchReservedEnum111", \
    "opennslswitchReservedEnum112", \
    "opennslswitchReservedEnum113", \
    "opennslswitchReservedEnum114", \
    "opennslswitchReservedEnum115", \
    "opennslswitchReservedEnum116", \
    "opennslswitchReservedEnum117", \
    "opennslswitchReservedEnum118", \
    "opennslswitchReservedEnum119", \
    "opennslswitchReservedEnum120", \
    "opennslswitchReservedEnum121", \
    "opennslswitchReservedEnum122", \
    "opennslswitchReservedEnum123", \
    "opennslswitchReservedEnum124", \
    "opennslswitchReservedEnum125", \
    "opennslswitchReservedEnum126", \
    "opennslswitchReservedEnum127", \
    "opennslswitchReservedEnum128", \
    "opennslswitchReservedEnum129", \
    "opennslswitchReservedEnum130", \
    "opennslswitchReservedEnum131", \
    "HashControl", \
    "opennslswitchReservedEnum132", \
    "opennslswitchReservedEnum133", \
    "opennslswitchReservedEnum134", \
    "opennslswitchReservedEnum135", \
    "opennslswitchReservedEnum136", \
    "opennslswitchReservedEnum137", \
    "opennslswitchReservedEnum138", \
    "opennslswitchReservedEnum139", \
    "opennslswitchReservedEnum140", \
    "opennslswitchReservedEnum141", \
    "HashSeed0", \
    "HashSeed1", \
    "HashField0PreProcessEnable", \
    "HashField1PreProcessEnable", \
    "HashField0Config", \
    "HashField0Config1", \
    "HashField1Config", \
    "HashField1Config1", \
    "opennslswitchReservedEnum142", \
    "HashSelectControl", \
    "HashIP4Field0", \
    "HashIP4Field1", \
    "HashIP4TcpUdpField0", \
    "HashIP4TcpUdpField1", \
    "HashIP4TcpUdpPortsEqualField0", \
    "HashIP4TcpUdpPortsEqualField1", \
    "HashIP6Field0", \
    "HashIP6Field1", \
    "HashIP6TcpUdpField0", \
    "HashIP6TcpUdpField1", \
    "HashIP6TcpUdpPortsEqualField0", \
    "HashIP6TcpUdpPortsEqualField1", \
    "opennslswitchReservedEnum143", \
    "opennslswitchReservedEnum144", \
    "opennslswitchReservedEnum145", \
    "opennslswitchReservedEnum146", \
    "opennslswitchReservedEnum147", \
    "opennslswitchReservedEnum148", \
    "opennslswitchReservedEnum149", \
    "opennslswitchReservedEnum150", \
    "opennslswitchReservedEnum151", \
    "opennslswitchReservedEnum152", \
    "opennslswitchReservedEnum153", \
    "opennslswitchReservedEnum154", \
    "opennslswitchReservedEnum155", \
    "opennslswitchReservedEnum156", \
    "opennslswitchReservedEnum157", \
    "opennslswitchReservedEnum158", \
    "opennslswitchReservedEnum159", \
    "opennslswitchReservedEnum160", \
    "opennslswitchReservedEnum161", \
    "opennslswitchReservedEnum162", \
    "opennslswitchReservedEnum163", \
    "opennslswitchReservedEnum164", \
    "opennslswitchReservedEnum165", \
    "opennslswitchReservedEnum166", \
    "opennslswitchReservedEnum167", \
    "opennslswitchReservedEnum168", \
    "opennslswitchReservedEnum169", \
    "opennslswitchReservedEnum170", \
    "opennslswitchReservedEnum171", \
    "opennslswitchReservedEnum172", \
    "opennslswitchReservedEnum173", \
    "opennslswitchReservedEnum174", \
    "opennslswitchReservedEnum175", \
    "opennslswitchReservedEnum176", \
    "opennslswitchReservedEnum177", \
    "opennslswitchReservedEnum178", \
    "opennslswitchReservedEnum179", \
    "opennslswitchReservedEnum180", \
    "opennslswitchReservedEnum181", \
    "opennslswitchReservedEnum182", \
    "opennslswitchReservedEnum183", \
    "ECMPHashSet0Offset", \
    "ECMPHashSet1Offset", \
    "opennslswitchReservedEnum184", \
    "opennslswitchReservedEnum185", \
    "opennslswitchReservedEnum186", \
    "opennslswitchReservedEnum187", \
    "opennslswitchReservedEnum188", \
    "opennslswitchReservedEnum189", \
    "opennslswitchReservedEnum190", \
    "opennslswitchReservedEnum191", \
    "opennslswitchReservedEnum192", \
    "opennslswitchReservedEnum193", \
    "opennslswitchReservedEnum194", \
    "opennslswitchReservedEnum195", \
    "opennslswitchReservedEnum196", \
    "opennslswitchReservedEnum197", \
    "opennslswitchReservedEnum198", \
    "opennslswitchReservedEnum199", \
    "opennslswitchReservedEnum200", \
    "opennslswitchReservedEnum201", \
    "L3EgressMode", \
    "opennslswitchReservedEnum202", \
    "opennslswitchReservedEnum203", \
    "opennslswitchReservedEnum204", \
    "opennslswitchReservedEnum205", \
    "opennslswitchReservedEnum206", \
    "opennslswitchReservedEnum207", \
    "opennslswitchReservedEnum208", \
    "opennslswitchReservedEnum209", \
    "opennslswitchReservedEnum210", \
    "opennslswitchReservedEnum211", \
    "opennslswitchReservedEnum212", \
    "opennslswitchReservedEnum213", \
    "ControlSync", \
    "opennslswitchReservedEnum214", \
    "opennslswitchReservedEnum215", \
    "opennslswitchReservedEnum216", \
    "opennslswitchReservedEnum217", \
    "opennslswitchReservedEnum218", \
    "opennslswitchReservedEnum219", \
    "opennslswitchReservedEnum220", \
    "opennslswitchReservedEnum221", \
    "opennslswitchReservedEnum222", \
    "opennslswitchReservedEnum223", \
    "opennslswitchReservedEnum224", \
    "opennslswitchReservedEnum225", \
    "opennslswitchReservedEnum226", \
    "opennslswitchReservedEnum227", \
    "opennslswitchReservedEnum228", \
    "opennslswitchReservedEnum229", \
    "opennslswitchReservedEnum230", \
    "opennslswitchReservedEnum231", \
    "opennslswitchReservedEnum232", \
    "opennslswitchReservedEnum233", \
    "opennslswitchReservedEnum234", \
    "opennslswitchReservedEnum235", \
    "opennslswitchReservedEnum236", \
    "opennslswitchReservedEnum237", \
    "opennslswitchReservedEnum238", \
    "opennslswitchReservedEnum239", \
    "opennslswitchReservedEnum240", \
    "opennslswitchReservedEnum241", \
    "opennslswitchReservedEnum242", \
    "opennslswitchReservedEnum243", \
    "opennslswitchReservedEnum244", \
    "opennslswitchReservedEnum245", \
    "opennslswitchReservedEnum246", \
    "opennslswitchReservedEnum247", \
    "opennslswitchReservedEnum248", \
    "opennslswitchReservedEnum249", \
    "opennslswitchReservedEnum250", \
    "opennslswitchReservedEnum251", \
    "opennslswitchReservedEnum252", \
    "opennslswitchReservedEnum253", \
    "opennslswitchReservedEnum254", \
    "opennslswitchReservedEnum255", \
    "opennslswitchReservedEnum256", \
    "opennslswitchReservedEnum257", \
    "opennslswitchReservedEnum258", \
    "opennslswitchReservedEnum259", \
    "opennslswitchReservedEnum260", \
    "opennslswitchReservedEnum261", \
    "opennslswitchReservedEnum262", \
    "opennslswitchReservedEnum263", \
    "opennslswitchReservedEnum264", \
    "opennslswitchReservedEnum265", \
    "opennslswitchReservedEnum266", \
    "opennslswitchReservedEnum267", \
    "opennslswitchReservedEnum268", \
    "opennslswitchReservedEnum269", \
    "opennslswitchReservedEnum270", \
    "opennslswitchReservedEnum271", \
    "opennslswitchReservedEnum272", \
    "opennslswitchReservedEnum273", \
    "opennslswitchReservedEnum274", \
    "opennslswitchReservedEnum275", \
    "opennslswitchReservedEnum276", \
    "opennslswitchReservedEnum277", \
    "opennslswitchReservedEnum278", \
    "opennslswitchReservedEnum279", \
    "opennslswitchReservedEnum280", \
    "opennslswitchReservedEnum281", \
    "opennslswitchReservedEnum282", \
    "opennslswitchReservedEnum283", \
    "opennslswitchReservedEnum284", \
    "opennslswitchReservedEnum285", \
    "opennslswitchReservedEnum286", \
    "opennslswitchReservedEnum287", \
    "opennslswitchReservedEnum288", \
    "opennslswitchReservedEnum289", \
    "opennslswitchReservedEnum290", \
    "opennslswitchReservedEnum291", \
    "opennslswitchReservedEnum292", \
    "opennslswitchReservedEnum293", \
    "opennslswitchReservedEnum294", \
    "opennslswitchReservedEnum295", \
    "opennslswitchReservedEnum296", \
    "opennslswitchReservedEnum297", \
    "opennslswitchReservedEnum298", \
    "opennslswitchReservedEnum299", \
    "opennslswitchReservedEnum300", \
    "opennslswitchReservedEnum301", \
    "opennslswitchReservedEnum302", \
    "opennslswitchReservedEnum303", \
    "opennslswitchReservedEnum304", \
    "opennslswitchReservedEnum305", \
    "opennslswitchReservedEnum306", \
    "opennslswitchReservedEnum307", \
    "opennslswitchReservedEnum308", \
    "opennslswitchReservedEnum309", \
    "opennslswitchReservedEnum310", \
    "opennslswitchReservedEnum311", \
    "opennslswitchReservedEnum312", \
    "opennslswitchReservedEnum313", \
    "opennslswitchReservedEnum314", \
    "opennslswitchReservedEnum315", \
    "opennslswitchReservedEnum316", \
    "opennslswitchReservedEnum317", \
    "opennslswitchReservedEnum318", \
    "opennslswitchReservedEnum319", \
    "opennslswitchReservedEnum320", \
    "opennslswitchReservedEnum321", \
    "opennslswitchReservedEnum322", \
    "opennslswitchReservedEnum323", \
    "opennslswitchReservedEnum324", \
    "opennslswitchReservedEnum325", \
    "opennslswitchReservedEnum326", \
    "opennslswitchReservedEnum327", \
    "opennslswitchReservedEnum328", \
    "opennslswitchReservedEnum329", \
    "opennslswitchReservedEnum330", \
    "opennslswitchReservedEnum331", \
    "opennslswitchReservedEnum332", \
    "opennslswitchReservedEnum333", \
    "opennslswitchReservedEnum334", \
    "opennslswitchReservedEnum335", \
    "opennslswitchReservedEnum336", \
    "opennslswitchReservedEnum337", \
    "opennslswitchReservedEnum338", \
    "opennslswitchReservedEnum339", \
    "opennslswitchReservedEnum340", \
    "opennslswitchReservedEnum341", \
    "opennslswitchReservedEnum342", \
    "opennslswitchReservedEnum343", \
    "opennslswitchReservedEnum344", \
    "opennslswitchReservedEnum345", \
    "opennslswitchReservedEnum346", \
    "opennslswitchReservedEnum347", \
    "opennslswitchReservedEnum348", \
    "opennslswitchReservedEnum349", \
    "opennslswitchReservedEnum350", \
    "opennslswitchReservedEnum351", \
    "opennslswitchReservedEnum352", \
    "opennslswitchReservedEnum353", \
    "opennslswitchReservedEnum354", \
    "opennslswitchReservedEnum355", \
    "opennslswitchReservedEnum356", \
    "opennslswitchReservedEnum357", \
    "opennslswitchReservedEnum358", \
    "opennslswitchReservedEnum359", \
    "opennslswitchReservedEnum360", \
    "opennslswitchReservedEnum361", \
    "opennslswitchReservedEnum362", \
    "opennslswitchReservedEnum363", \
    "opennslswitchReservedEnum364", \
    "opennslswitchReservedEnum365", \
    "opennslswitchReservedEnum366", \
    "opennslswitchReservedEnum367", \
    "opennslswitchReservedEnum368", \
    "opennslswitchReservedEnum369", \
    "opennslswitchReservedEnum370", \
    "opennslswitchReservedEnum371", \
    "opennslswitchReservedEnum372", \
    "opennslswitchReservedEnum373", \
    "opennslswitchReservedEnum374", \
    "opennslswitchReservedEnum375", \
    "opennslswitchReservedEnum376", \
    "opennslswitchReservedEnum377", \
    "opennslswitchReservedEnum378", \
    "opennslswitchReservedEnum379", \
    "opennslswitchReservedEnum380", \
    "opennslswitchReservedEnum381", \
    "opennslswitchReservedEnum382", \
    "opennslswitchReservedEnum383", \
    "opennslswitchReservedEnum384", \
    "opennslswitchReservedEnum385", \
    "opennslswitchReservedEnum386", \
    "opennslswitchReservedEnum387", \
    "opennslswitchReservedEnum388", \
    "opennslswitchReservedEnum389", \
    "opennslswitchReservedEnum390", \
    "opennslswitchReservedEnum391", \
    "opennslswitchReservedEnum392", \
    "opennslswitchReservedEnum393", \
    "opennslswitchReservedEnum394", \
    "opennslswitchReservedEnum395", \
    "opennslswitchReservedEnum396", \
    "opennslswitchReservedEnum397", \
    "opennslswitchReservedEnum398", \
    "opennslswitchReservedEnum399", \
    "opennslswitchReservedEnum400", \
    "opennslswitchReservedEnum401", \
    "opennslswitchReservedEnum402", \
    "opennslswitchReservedEnum403", \
    "opennslswitchReservedEnum404", \
    "opennslswitchReservedEnum405", \
    "opennslswitchReservedEnum406", \
    "opennslswitchReservedEnum407", \
    "opennslswitchReservedEnum408", \
    "opennslswitchReservedEnum409", \
    "opennslswitchReservedEnum410", \
    "opennslswitchReservedEnum411", \
    "opennslswitchReservedEnum412", \
    "opennslswitchReservedEnum413", \
    "opennslswitchReservedEnum414", \
    "opennslswitchReservedEnum415", \
    "opennslswitchReservedEnum416", \
    "opennslswitchReservedEnum417", \
    "opennslswitchReservedEnum418", \
    "opennslswitchReservedEnum419", \
    "opennslswitchReservedEnum420", \
    "opennslswitchReservedEnum421", \
    "opennslswitchReservedEnum422", \
    "opennslswitchReservedEnum423", \
    "opennslswitchReservedEnum424", \
    "opennslswitchReservedEnum425", \
    "opennslswitchReservedEnum426", \
    "opennslswitchReservedEnum427", \
    "opennslswitchReservedEnum428", \
    "opennslswitchReservedEnum429", \
    "opennslswitchReservedEnum430", \
    "opennslswitchReservedEnum431", \
    "opennslswitchReservedEnum432", \
    "opennslswitchReservedEnum433", \
    "opennslswitchReservedEnum434", \
    "opennslswitchReservedEnum435", \
    "opennslswitchReservedEnum436", \
    "opennslswitchReservedEnum437", \
    "opennslswitchReservedEnum438", \
    "opennslswitchReservedEnum439", \
    "opennslswitchReservedEnum440", \
    "opennslswitchReservedEnum441", \
    "opennslswitchReservedEnum442", \
    "opennslswitchReservedEnum443", \
    "opennslswitchReservedEnum444", \
    "opennslswitchReservedEnum445", \
    "opennslswitchReservedEnum446", \
    "opennslswitchReservedEnum447", \
    "opennslswitchReservedEnum448", \
    "opennslswitchReservedEnum449", \
    "opennslswitchReservedEnum450", \
    "opennslswitchReservedEnum451", \
    "opennslswitchReservedEnum452", \
    "opennslswitchReservedEnum453", \
    "opennslswitchReservedEnum454", \
    "opennslswitchReservedEnum455", \
    "opennslswitchReservedEnum456", \
    "opennslswitchReservedEnum457", \
    "opennslswitchReservedEnum458", \
    "opennslswitchReservedEnum459", \
    "opennslswitchReservedEnum460", \
    "opennslswitchReservedEnum461", \
    "opennslswitchReservedEnum462", \
    "opennslswitchReservedEnum463", \
    "opennslswitchReservedEnum464", \
    "opennslswitchReservedEnum465", \
    "opennslswitchReservedEnum466", \
    "opennslswitchReservedEnum467", \
    "opennslswitchReservedEnum468", \
    "opennslswitchReservedEnum469", \
    "opennslswitchReservedEnum470", \
    "opennslswitchReservedEnum471", \
    "opennslswitchReservedEnum472", \
    "opennslswitchReservedEnum473", \
    "opennslswitchReservedEnum474", \
    "opennslswitchReservedEnum475", \
    "opennslswitchReservedEnum476", \
    "opennslswitchReservedEnum477", \
    "opennslswitchReservedEnum478", \
    "opennslswitchReservedEnum479", \
    "opennslswitchReservedEnum480", \
    "opennslswitchReservedEnum481", \
    "opennslswitchReservedEnum482", \
    "opennslswitchReservedEnum483", \
    "opennslswitchReservedEnum484", \
    "opennslswitchReservedEnum485", \
    "opennslswitchReservedEnum486", \
    "opennslswitchReservedEnum487", \
    "opennslswitchReservedEnum488", \
    "opennslswitchReservedEnum489", \
    "opennslswitchReservedEnum490", \
    "opennslswitchReservedEnum491", \
    "opennslswitchReservedEnum492", \
    "opennslswitchReservedEnum493", \
    "opennslswitchReservedEnum494", \
    "opennslswitchReservedEnum495", \
    "opennslswitchReservedEnum496", \
    "opennslswitchReservedEnum497", \
    "opennslswitchReservedEnum498", \
    "opennslswitchReservedEnum499", \
    "opennslswitchReservedEnum500", \
    "opennslswitchReservedEnum501", \
    "opennslswitchReservedEnum502", \
    "opennslswitchReservedEnum503", \
    "opennslswitchReservedEnum504", \
    "opennslswitchReservedEnum505", \
    "opennslswitchReservedEnum506", \
    "opennslswitchReservedEnum507", \
    "opennslswitchReservedEnum508", \
    "opennslswitchReservedEnum509", \
    "opennslswitchReservedEnum510", \
    "opennslswitchReservedEnum511", \
    "opennslswitchReservedEnum512", \
    "opennslswitchReservedEnum513", \
    "opennslswitchReservedEnum514", \
    "opennslswitchReservedEnum515", \
    "opennslswitchReservedEnum516", \
    "opennslswitchReservedEnum517", \
    "opennslswitchReservedEnum518", \
    "opennslswitchReservedEnum519", \
    "opennslswitchReservedEnum520", \
    "opennslswitchReservedEnum521", \
    "opennslswitchReservedEnum522", \
    "opennslswitchReservedEnum523", \
    "opennslswitchReservedEnum524", \
    "opennslswitchReservedEnum525", \
    "opennslswitchReservedEnum526", \
    "opennslswitchReservedEnum527", \
    "opennslswitchReservedEnum528", \
    "opennslswitchReservedEnum529", \
    "opennslswitchReservedEnum530", \
    "opennslswitchReservedEnum531", \
    "opennslswitchReservedEnum532", \
    "opennslswitchReservedEnum533", \
    "opennslswitchReservedEnum534", \
    "opennslswitchReservedEnum535", \
    "opennslswitchReservedEnum536", \
    "opennslswitchReservedEnum537", \
    "opennslswitchReservedEnum538", \
    "opennslswitchReservedEnum539", \
    "opennslswitchReservedEnum540", \
    "opennslswitchReservedEnum541", \
    "opennslswitchReservedEnum542", \
    "opennslswitchReservedEnum543", \
    "opennslswitchReservedEnum544", \
    "opennslswitchReservedEnum545", \
    "opennslswitchReservedEnum546", \
    "opennslswitchReservedEnum547", \
    "opennslswitchReservedEnum548", \
    "opennslswitchReservedEnum549", \
    "opennslswitchReservedEnum550", \
    "opennslswitchReservedEnum551", \
    "opennslswitchReservedEnum552", \
    "opennslswitchReservedEnum553", \
    "opennslswitchReservedEnum554", \
    "opennslswitchReservedEnum555", \
    "opennslswitchReservedEnum556", \
    "opennslswitchReservedEnum557", \
    "opennslswitchReservedEnum558", \
    "opennslswitchReservedEnum559", \
    "opennslswitchReservedEnum560", \
    "opennslswitchReservedEnum561", \
    "opennslswitchReservedEnum562", \
    "opennslswitchReservedEnum563", \
    "opennslswitchReservedEnum564", \
    "opennslswitchReservedEnum565", \
    "opennslswitchReservedEnum566", \
    "opennslswitchReservedEnum567", \
    "opennslswitchReservedEnum568", \
    "opennslswitchReservedEnum569", \
    "opennslswitchReservedEnum570", \
    "opennslswitchReservedEnum571", \
    "opennslswitchReservedEnum572", \
    "opennslswitchReservedEnum573", \
    "opennslswitchReservedEnum574", \
    "opennslswitchReservedEnum575", \
    "opennslswitchReservedEnum576", \
    "opennslswitchReservedEnum577", \
    "opennslswitchReservedEnum578", \
    "opennslswitchReservedEnum579", \
    "opennslswitchReservedEnum580", \
    "opennslswitchReservedEnum581", \
    "opennslswitchReservedEnum582", \
    "opennslswitchReservedEnum583", \
    "opennslswitchReservedEnum584", \
    "opennslswitchReservedEnum585", \
    "opennslswitchReservedEnum586", \
    "opennslswitchReservedEnum587", \
    "opennslswitchReservedEnum588", \
    "opennslswitchReservedEnum589", \
    "opennslswitchReservedEnum590", \
    "opennslswitchReservedEnum591", \
    "opennslswitchReservedEnum592", \
    "opennslswitchReservedEnum593", \
    "opennslswitchReservedEnum594", \
    "opennslswitchReservedEnum595", \
    "opennslswitchReservedEnum596", \
    "opennslswitchReservedEnum597", \
    "opennslswitchReservedEnum598", \
    "opennslswitchReservedEnum599", \
    "opennslswitchReservedEnum600", \
    "opennslswitchReservedEnum601", \
    "opennslswitchReservedEnum602", \
    "opennslswitchReservedEnum603", \
    "opennslswitchReservedEnum604", \
    "opennslswitchReservedEnum605", \
    "opennslswitchReservedEnum606", \
    "opennslswitchReservedEnum607", \
    "opennslswitchReservedEnum608", \
    "opennslswitchReservedEnum609", \
    "opennslswitchReservedEnum610", \
    "opennslswitchReservedEnum611", \
    "opennslswitchReservedEnum612", \
    "opennslswitchReservedEnum613", \
    "opennslswitchReservedEnum614", \
    "opennslswitchReservedEnum615", \
    "opennslswitchReservedEnum616", \
    "opennslswitchReservedEnum617", \
    "opennslswitchReservedEnum618", \
    "opennslswitchReservedEnum619", \
    "opennslswitchReservedEnum620", \
    "opennslswitchReservedEnum621", \
    "opennslswitchReservedEnum622", \
    "opennslswitchReservedEnum623", \
    "opennslswitchReservedEnum624", \
    "opennslswitchReservedEnum625", \
    "opennslswitchReservedEnum626", \
    "opennslswitchReservedEnum627", \
    "opennslswitchReservedEnum628", \
    "opennslswitchReservedEnum629", \
    "opennslswitchReservedEnum630", \
    "opennslswitchReservedEnum631", \
    "opennslswitchReservedEnum632", \
    "opennslswitchReservedEnum633", \
    "opennslswitchReservedEnum634", \
    "opennslswitchReservedEnum635", \
    "opennslswitchReservedEnum636", \
    "opennslswitchReservedEnum637", \
    "opennslswitchReservedEnum638", \
    "opennslswitchReservedEnum639", \
    "opennslswitchReservedEnum640", \
    "opennslswitchReservedEnum641", \
    "opennslswitchReservedEnum642", \
    "opennslswitchReservedEnum643", \
    "opennslswitchReservedEnum644", \
    "opennslswitchReservedEnum645", \
    "opennslswitchReservedEnum646", \
    "opennslswitchReservedEnum647", \
    "opennslswitchReservedEnum648", \
    "opennslswitchReservedEnum649", \
    "opennslswitchReservedEnum650", \
    "opennslswitchReservedEnum651", \
    "opennslswitchReservedEnum652", \
    "opennslswitchReservedEnum653", \
    "opennslswitchReservedEnum654", \
    "opennslswitchReservedEnum655", \
    "opennslswitchReservedEnum656", \
    "opennslswitchReservedEnum657", \
    "opennslswitchReservedEnum658", \
    "opennslswitchReservedEnum659", \
    "opennslswitchReservedEnum660", \
    "opennslswitchReservedEnum661", \
    "opennslswitchReservedEnum662", \
    "opennslswitchReservedEnum663", \
    "opennslswitchReservedEnum664", \
    "opennslswitchReservedEnum665", \
    "opennslswitchReservedEnum666", \
    "opennslswitchReservedEnum667", \
    "opennslswitchReservedEnum668", \
    "opennslswitchReservedEnum669", \
    "opennslswitchReservedEnum670", \
    "opennslswitchReservedEnum671", \
    "opennslswitchReservedEnum672", \
    "opennslswitchReservedEnum673", \
    "opennslswitchReservedEnum674", \
    "opennslswitchReservedEnum675", \
    "opennslswitchReservedEnum676", \
    "opennslswitchReservedEnum677", \
    "opennslswitchReservedEnum678", \
    "opennslswitchReservedEnum679", \
    "opennslswitchReservedEnum680", \
    "opennslswitchReservedEnum681", \
    "opennslswitchReservedEnum682", \
    "opennslswitchReservedEnum683", \
    "opennslswitchReservedEnum684", \
    "opennslswitchReservedEnum685", \
    "opennslswitchReservedEnum686", \
    "BstEnable", \
    "BstTrackingMode", \
    "opennslswitchReservedEnum687", \
    "opennslswitchReservedEnum688", \
    "opennslswitchReservedEnum689", \
    "opennslswitchReservedEnum690", \
    "opennslswitchReservedEnum691", \
    "opennslswitchReservedEnum692", \
    "opennslswitchReservedEnum693", \
    "opennslswitchReservedEnum694", \
    "opennslswitchReservedEnum695", \
    "opennslswitchReservedEnum696", \
    "opennslswitchReservedEnum697", \
    "opennslswitchReservedEnum698", \
    "opennslswitchReservedEnum699", \
    "opennslswitchReservedEnum700", \
    "opennslswitchReservedEnum701", \
    "opennslswitchReservedEnum702", \
    "opennslswitchReservedEnum703", \
    "opennslswitchReservedEnum704", \
    "opennslswitchReservedEnum705", \
    "opennslswitchReservedEnum706", \
    "opennslswitchReservedEnum707", \
    "opennslswitchReservedEnum708", \
    "opennslswitchReservedEnum709", \
    "opennslswitchReservedEnum710", \
    "opennslswitchReservedEnum711", \
    "opennslswitchReservedEnum712", \
    "opennslswitchReservedEnum713", \
    "opennslswitchReservedEnum714", \
    "opennslswitchReservedEnum715", \
    "opennslswitchReservedEnum716", \
    "opennslswitchReservedEnum717", \
    "opennslswitchReservedEnum718", \
    "opennslswitchReservedEnum719", \
    "opennslswitchReservedEnum720", \
    "opennslswitchReservedEnum721", \
    "opennslswitchReservedEnum722", \
    "opennslswitchReservedEnum723", \
    "opennslswitchReservedEnum724", \
    "opennslswitchReservedEnum725", \
    "opennslswitchReservedEnum726", \
    "opennslswitchReservedEnum727", \
    "opennslswitchReservedEnum728", \
    "opennslswitchReservedEnum729", \
    "opennslswitchReservedEnum730", \
    "opennslswitchReservedEnum731", \
    "opennslswitchReservedEnum732", \
    "opennslswitchReservedEnum733", \
    "opennslswitchReservedEnum734", \
    "opennslswitchReservedEnum735", \
    "opennslswitchReservedEnum736", \
    "opennslswitchReservedEnum737", \
    "opennslswitchReservedEnum738", \
    "opennslswitchReservedEnum739", \
    "opennslswitchReservedEnum740", \
    "opennslswitchReservedEnum741", \
    "opennslswitchReservedEnum742", \
    "opennslswitchReservedEnum743", \
    "opennslswitchReservedEnum744", \
    "opennslswitchReservedEnum745", \
    "opennslswitchReservedEnum746", \
    "opennslswitchReservedEnum747", \
    "opennslswitchReservedEnum748", \
    "opennslswitchReservedEnum749", \
    "EcmpMacroFlowHashEnable", \
    "opennslswitchReservedEnum750", \
    "opennslswitchReservedEnum751", \
    "opennslswitchReservedEnum752", \
    "opennslswitchReservedEnum753", \
    "opennslswitchReservedEnum754", \
    "opennslswitchReservedEnum755", \
    "opennslswitchReservedEnum756", \
    "opennslswitchReservedEnum757", \
    "opennslswitchReservedEnum758", \
    "opennslswitchReservedEnum759", \
    "opennslswitchReservedEnum760", \
    "opennslswitchReservedEnum761", \
    "opennslswitchReservedEnum762", \
    "opennslswitchReservedEnum763", \
    "opennslswitchReservedEnum764", \
    "opennslswitchReservedEnum765", \
    "opennslswitchReservedEnum766", \
    "opennslswitchReservedEnum767", \
    "opennslswitchReservedEnum768", \
    "opennslswitchReservedEnum769", \
    "opennslswitchReservedEnum770", \
    "opennslswitchReservedEnum771", \
    "opennslswitchReservedEnum772", \
    "opennslswitchReservedEnum773", \
    "opennslswitchReservedEnum774", \
    "opennslswitchReservedEnum775", \
    "opennslswitchReservedEnum776", \
    "opennslswitchReservedEnum777", \
    "opennslswitchReservedEnum778", \
    "opennslswitchReservedEnum779", \
    "opennslswitchReservedEnum780", \
    "opennslswitchReservedEnum781", \
    "opennslswitchReservedEnum782", \
    "opennslswitchReservedEnum783", \
    "opennslswitchReservedEnum784", \
    "opennslswitchReservedEnum785", \
    "opennslswitchReservedEnum786", \
    "opennslswitchReservedEnum787", \
    "opennslswitchReservedEnum788", \
    "opennslswitchReservedEnum789", \
    "opennslswitchReservedEnum790", \
    "opennslswitchReservedEnum791", \
    "opennslswitchReservedEnum792", \
    "opennslswitchReservedEnum793", \
    "opennslswitchReservedEnum794", \
    "opennslswitchReservedEnum795", \
    "opennslswitchReservedEnum796", \
    "opennslswitchReservedEnum797", \
    "opennslswitchReservedEnum798", \
    "opennslswitchReservedEnum799", \
    "opennslswitchReservedEnum800", \
    "opennslswitchReservedEnum801", \
    "opennslswitchReservedEnum802", \
    "opennslswitchReservedEnum803", \
    "opennslswitchReservedEnum804", \
    "opennslswitchReservedEnum805", \
    "opennslswitchReservedEnum806", \
    "opennslswitchReservedEnum807", \
    "opennslswitchReservedEnum808", \
    "opennslswitchReservedEnum809", \
    "opennslswitchReservedEnum810", \
    "opennslswitchReservedEnum811", \
    "opennslswitchReservedEnum812", \
    "opennslswitchReservedEnum813", \
    "opennslswitchReservedEnum814", \
    "opennslswitchReservedEnum815", \
    "opennslswitchReservedEnum816", \
    "opennslswitchReservedEnum817", \
    "opennslswitchReservedEnum818", \
    "opennslswitchReservedEnum819", \
    "opennslswitchReservedEnum820", \
    "opennslswitchReservedEnum821", \
    "opennslswitchReservedEnum822", \
    "opennslswitchReservedEnum823", \
    "opennslswitchReservedEnum824", \
    "opennslswitchReservedEnum825", \
    "opennslswitchReservedEnum826", \
    "opennslswitchReservedEnum827", \
    "opennslswitchReservedEnum828", \
    "opennslswitchReservedEnum829", \
    "opennslswitchReservedEnum830", \
    "opennslswitchReservedEnum831", \
    "opennslswitchReservedEnum832", \
    "opennslswitchReservedEnum833", \
    "opennslswitchReservedEnum834", \
    "opennslswitchReservedEnum835", \
    "opennslswitchReservedEnum836", \
    "opennslswitchReservedEnum837", \
    "opennslswitchReservedEnum838", \
    "opennslswitchReservedEnum839", \
    "opennslswitchReservedEnum840", \
    "opennslswitchReservedEnum841", \
    "opennslswitchReservedEnum842", \
    "opennslswitchReservedEnum843", \
    "opennslswitchReservedEnum844", \
    "opennslswitchReservedEnum845", \
    "opennslswitchReservedEnum846", \
    "opennslswitchReservedEnum847", \
    "opennslswitchReservedEnum848", \
    "opennslswitchReservedEnum849", \
    "opennslswitchReservedEnum850", \
    "opennslswitchReservedEnum851", \
    "opennslswitchReservedEnum852", \
    "opennslswitchReservedEnum853", \
    "opennslswitchReservedEnum854", \
    "opennslswitchReservedEnum855", \
    "opennslswitchReservedEnum856", \
    "opennslswitchReservedEnum857", \
    "opennslswitchReservedEnum858", \
    "opennslswitchReservedEnum859", \
    "opennslswitchReservedEnum860", \
    "opennslswitchReservedEnum861", \
    "opennslswitchReservedEnum862", \
    "opennslswitchReservedEnum863", \
    "opennslswitchReservedEnum864", \
    "opennslswitchReservedEnum865", \
    "opennslswitchReservedEnum866", \
    "opennslswitchReservedEnum867", \
    "opennslswitchReservedEnum868", \
    "opennslswitchReservedEnum869", \
    "opennslswitchReservedEnum870", \
    "opennslswitchReservedEnum871", \
    "opennslswitchReservedEnum872", \
    "opennslswitchReservedEnum873", \
    "opennslswitchReservedEnum874", \
    "opennslswitchReservedEnum875", \
    "opennslswitchReservedEnum876", \
    "opennslswitchReservedEnum877", \
    "opennslswitchReservedEnum878", \
    "opennslswitchReservedEnum879", \
    "opennslswitchReservedEnum880", \
    "opennslswitchReservedEnum881", \
    "opennslswitchReservedEnum882" 

#define OPENNSL_SWITCH_STABLE_APPLICATION   (_SHR_SWITCH_STABLE_APPLICATION) 
#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Configure port-specific and device-wide operating modes. Device wide
 *       operating modes are configured on all ports, except the stack ports.
 *
 *\description These APIs set parameters related to general device operation such
 *          as controlling whether certain types of packets should be sent to
 *          the local CPU, or setting the priority to be used when such
 *          packets are forwarded to the CPU.  The port specific operations
 *          affect only the indicated port (where possible) while the general
 *          APIs affect all ports.  Not all operations can be carried out on
 *          individual ports on all devices.
 *
 *\param    unit [IN]   Unit number.
 *\param    type [IN]   Switch control parameter (see =opennsl_switchs)
 *\param    arg [OUT]   (for _set) Argument whose meaning is dependent on type
 *
 *\retval    OPENNSL_E_UNAVAIL	Feature not available on this device
 *\retval    OPENNSL_E_XXX		Other error
 ******************************************************************************/
extern int opennsl_switch_control_get(
    int unit, 
    opennsl_switch_control_t type, 
    int *arg) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Configure port-specific and device-wide operating modes. Device wide
 *       operating modes are configured on all ports, except the stack ports.
 *
 *\description These APIs set parameters related to general device operation such
 *          as controlling whether certain types of packets should be sent to
 *          the local CPU, or setting the priority to be used when such
 *          packets are forwarded to the CPU.  The port specific operations
 *          affect only the indicated port (where possible) while the general
 *          APIs affect all ports.  Not all operations can be carried out on
 *          individual ports on all devices.
 *
 *\param    unit [IN]   Unit number.
 *\param    type [IN]   Switch control parameter (see =opennsl_switchs)
 *\param    arg [IN]   (for _set) Argument whose meaning is dependent on type
 *
 *\retval    OPENNSL_E_UNAVAIL	Feature not available on this device
 *\retval    OPENNSL_E_XXX		Other error
 ******************************************************************************/
extern int opennsl_switch_control_set(
    int unit, 
    opennsl_switch_control_t type, 
    int arg) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Configure port-specific and device-wide operating modes. Device wide
 *       operating modes are configured on all ports, except the stack ports.
 *
 *\description These APIs set parameters related to general device operation such
 *          as controlling whether certain types of packets should be sent to
 *          the local CPU, or setting the priority to be used when such
 *          packets are forwarded to the CPU.  The port specific operations
 *          affect only the indicated port (where possible) while the general
 *          APIs affect all ports.  Not all operations can be carried out on
 *          individual ports on all devices.
 *
 *\param    unit [IN]   Unit number.
 *\param    port [IN]   Device or logical port number
 *\param    type [IN]   Switch control parameter (see =opennsl_switchs)
 *\param    arg [IN]   (for _set) Argument whose meaning is dependent on type
 *
 *\retval    OPENNSL_E_UNAVAIL	Feature not available on this device
 *\retval    OPENNSL_E_XXX		Other error
 ******************************************************************************/
extern int opennsl_switch_control_port_set(
    int unit, 
    opennsl_port_t port, 
    opennsl_switch_control_t type, 
    int arg) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

typedef void (*opennsl_switch_event_cb_t)(
    int unit, 
    opennsl_switch_event_t event, 
    uint32 arg1, 
    uint32 arg2, 
    uint32 arg3, 
    void *userdata);

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *
 *
 *\param    unit [IN]   Unit number.
 *\param    cb [IN]
 *\param    userdata [IN]
 *
 *\retval   OPENNSL_E_xxx
 ******************************************************************************/
extern int opennsl_switch_event_register(
    int unit, 
    opennsl_switch_event_cb_t cb, 
    void *userdata) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *
 *
 *\param    unit [IN]   Unit number.
 *\param    cb [IN]
 *\param    userdata [IN]
 *
 *\retval   OPENNSL_E_xxx
 ******************************************************************************/
extern int opennsl_switch_event_unregister(
    int unit, 
    opennsl_switch_event_cb_t cb, 
    void *userdata) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#define OPENNSL_HASH_CONTROL_ECMP_ENHANCE   0x0080     /**< Use enhanced ECMP
                                                          hashing. */
#define OPENNSL_HASH_FIELD_CONFIG_CRC16CCITT 0x00000007 /**< 16-bit CRC using CCITT
                                                          polynomial. */
#define OPENNSL_HASH_FIELD_DSTL4        0x00000020 /**< Destination L4 port. */
#define OPENNSL_HASH_FIELD_SRCL4        0x00000040 /**< Source L4 port. */
#define OPENNSL_HASH_FIELD_IP4DST_LO    0x00000100 /**< IPv4 destination address
                                                      lower 16 bits. */
#define OPENNSL_HASH_FIELD_IP4DST_HI    0x00000200 /**< IPv4 destination address
                                                      upper 16 bits. */
#define OPENNSL_HASH_FIELD_IP4SRC_LO    0x00000400 /**< IPv4 source address lower
                                                      16 bits. */
#define OPENNSL_HASH_FIELD_IP4SRC_HI    0x00000800 /**< IPv4 source address upper
                                                      16 bits. */
#define OPENNSL_HASH_FIELD_IP6DST_LO    0x00001000 /**< IPv6 collapsed destination
                                                      address lower 16 bits. */
#define OPENNSL_HASH_FIELD_IP6DST_HI    0x00002000 /**< IPv6 collapsed destination
                                                      address upper 16 bits. */
#define OPENNSL_HASH_FIELD_IP6SRC_LO    0x00004000 /**< IPv6 collapsed source
                                                      address lower 16 bits. */
#define OPENNSL_HASH_FIELD_IP6SRC_HI    0x00008000 /**< IPv6 collapsed source
                                                      address upper 16 bits. */
#endif /* __OPENNSL_SWITCH_H__ */
/*@}*/

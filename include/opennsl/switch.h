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
    opennslswitchReservedEnum1, 
    opennslswitchReservedEnum2, 
    opennslswitchReservedEnum3, 
    opennslswitchReservedEnum4, 
    opennslswitchReservedEnum5, 
    opennslswitchReservedEnum6, 
    opennslswitchReservedEnum7, 
    opennslswitchReservedEnum8, 
    opennslswitchReservedEnum9, 
    opennslswitchReservedEnum10, 
    opennslswitchReservedEnum11, 
    opennslswitchReservedEnum12, 
    opennslswitchReservedEnum13, 
    opennslswitchReservedEnum14, 
    opennslswitchReservedEnum15, 
    opennslswitchReservedEnum16, 
    opennslswitchReservedEnum17, 
    opennslswitchReservedEnum18, 
    opennslswitchReservedEnum19, 
    opennslswitchReservedEnum20, 
    opennslswitchReservedEnum21, 
    opennslswitchReservedEnum22, 
    opennslswitchReservedEnum23, 
    opennslswitchReservedEnum24, 
    opennslswitchReservedEnum25, 
    opennslswitchReservedEnum26, 
    opennslswitchReservedEnum27, 
    opennslswitchReservedEnum28, 
    opennslswitchReservedEnum29, 
    opennslswitchReservedEnum30, 
    opennslswitchReservedEnum31, 
    opennslswitchReservedEnum32, 
    opennslswitchReservedEnum33, 
    opennslswitchReservedEnum34, 
    opennslswitchReservedEnum35, 
    opennslswitchReservedEnum36, 
    opennslswitchReservedEnum37, 
    opennslswitchReservedEnum38, 
    opennslswitchReservedEnum39, 
    opennslswitchReservedEnum40, 
    opennslswitchReservedEnum41, 
    opennslswitchReservedEnum42, 
    opennslswitchReservedEnum43, 
    opennslswitchReservedEnum44, 
    opennslswitchReservedEnum45, 
    opennslswitchReservedEnum46, 
    opennslswitchReservedEnum47, 
    opennslswitchReservedEnum48, 
    opennslswitchReservedEnum49, 
    opennslswitchReservedEnum50, 
    opennslswitchReservedEnum51, 
    opennslswitchReservedEnum52, 
    opennslswitchReservedEnum53, 
    opennslswitchReservedEnum54, 
    opennslswitchReservedEnum55, 
    opennslswitchReservedEnum56, 
    opennslswitchReservedEnum57, 
    opennslswitchReservedEnum58, 
    opennslswitchReservedEnum59, 
    opennslswitchReservedEnum60, 
    opennslswitchReservedEnum61, 
    opennslswitchReservedEnum62, 
    opennslswitchReservedEnum63, 
    opennslswitchReservedEnum64, 
    opennslswitchReservedEnum65, 
    opennslswitchReservedEnum66, 
    opennslswitchReservedEnum67, 
    opennslswitchReservedEnum68, 
    opennslswitchReservedEnum69, 
    opennslswitchReservedEnum70, 
    opennslswitchReservedEnum71, 
    opennslswitchReservedEnum72, 
    opennslswitchReservedEnum73, 
    opennslswitchReservedEnum74, 
    opennslswitchReservedEnum75, 
    opennslswitchReservedEnum76, 
    opennslswitchReservedEnum77, 
    opennslswitchReservedEnum78, 
    opennslswitchReservedEnum79, 
    opennslswitchReservedEnum80, 
    opennslswitchReservedEnum81, 
    opennslswitchReservedEnum82, 
    opennslswitchReservedEnum83, 
    opennslswitchReservedEnum84, 
    opennslSwitchArpReplyToCpu,         /**< ARP replies to CPU. */
    opennslswitchReservedEnum85, 
    opennslSwitchArpRequestToCpu,       /**< ARP requests to CPU. */
    opennslswitchReservedEnum86, 
    opennslswitchReservedEnum87, 
    opennslSwitchNdPktToCpu,            /**< ND packets to CPU. */
    opennslswitchReservedEnum88, 
    opennslswitchReservedEnum89, 
    opennslSwitchIgmpPktToCpu,          /**< IGMP packets to CPU. */
    opennslSwitchIgmpToCPU = opennslSwitchIgmpPktToCpu, /**< Legacy support for IGMP packets to
                                           CPU. */
    opennslswitchReservedEnum90, 
    opennslSwitchDhcpPktToCpu,          /**< DHCP packets to CPU. */
    opennslSwitchDhcpPktDrop,           /**< DHCP packets dropped. */
    opennslswitchReservedEnum91, 
    opennslswitchReservedEnum92, 
    opennslswitchReservedEnum93, 
    opennslswitchReservedEnum94, 
    opennslswitchReservedEnum95, 
    opennslswitchReservedEnum96, 
    opennslswitchReservedEnum97, 
    opennslswitchReservedEnum98, 
    opennslswitchReservedEnum99, 
    opennslswitchReservedEnum100, 
    opennslswitchReservedEnum101, 
    opennslswitchReservedEnum102, 
    opennslswitchReservedEnum103, 
    opennslswitchReservedEnum104, 
    opennslswitchReservedEnum105, 
    opennslswitchReservedEnum106, 
    opennslswitchReservedEnum107, 
    opennslswitchReservedEnum108, 
    opennslswitchReservedEnum109, 
    opennslswitchReservedEnum110, 
    opennslswitchReservedEnum111, 
    opennslswitchReservedEnum112, 
    opennslswitchReservedEnum113, 
    opennslswitchReservedEnum114, 
    opennslswitchReservedEnum115, 
    opennslswitchReservedEnum116, 
    opennslswitchReservedEnum117, 
    opennslswitchReservedEnum118, 
    opennslswitchReservedEnum119, 
    opennslswitchReservedEnum120, 
    opennslswitchReservedEnum121, 
    opennslswitchReservedEnum122, 
    opennslswitchReservedEnum123, 
    opennslswitchReservedEnum124, 
    opennslswitchReservedEnum125, 
    opennslswitchReservedEnum126, 
    opennslswitchReservedEnum127, 
    opennslswitchReservedEnum128, 
    opennslswitchReservedEnum129, 
    opennslswitchReservedEnum130, 
    opennslSwitchHashControl,           /**< Hash Control of fields. */
    opennslswitchReservedEnum131, 
    opennslswitchReservedEnum132, 
    opennslswitchReservedEnum133, 
    opennslswitchReservedEnum134, 
    opennslswitchReservedEnum135, 
    opennslswitchReservedEnum136, 
    opennslswitchReservedEnum137, 
    opennslswitchReservedEnum138, 
    opennslswitchReservedEnum139, 
    opennslswitchReservedEnum140, 
    opennslSwitchHashSeed0,             /**< network switch hash seeds. */
    opennslSwitchHashSeed1,             /**< For enhanced hashing algoithm. */
    opennslSwitchHashField0PreProcessEnable, /**< Enable pre-processing for enhanced
                                           hash mode 0. */
    opennslSwitchHashField1PreProcessEnable, /**< Enable pre-processing for enhanced
                                           hash mode 1. */
    opennslSwitchHashField0Config,      /**< network switch enhanced hash mode 0
                                           config. */
    opennslSwitchHashField0Config1,     /**< network switch enhanced hash mode 0
                                           config 1. */
    opennslSwitchHashField1Config,      /**< network switch enhanced hash mode 1
                                           config. */
    opennslSwitchHashField1Config1,     /**< network switch enhanced hash mode 1
                                           config 1. */
    opennslswitchReservedEnum141, 
    opennslSwitchHashSelectControl,     /**< network switch field selection
                                           control. */
    opennslSwitchHashIP4Field0,         /**< network switch enhanced hash field. */
    opennslSwitchHashIP4Field1,         /**< Selections for IPv4 packets. */
    opennslSwitchHashIP4TcpUdpField0,   /**< network switch enhanced hash field. */
    opennslSwitchHashIP4TcpUdpField1,   /**< Selections for IPv4 TCP/UDP packets. */
    opennslSwitchHashIP4TcpUdpPortsEqualField0, /**< network switch enhanced hash field. */
    opennslSwitchHashIP4TcpUdpPortsEqualField1, /**< Selections for IPv4 TCP/UDP packets
                                           with source L4 port equals to
                                           destination L4 port. */
    opennslSwitchHashIP6Field0,         /**< network switch enhanced hash field. */
    opennslSwitchHashIP6Field1,         /**< Selections for IPv6 packets. */
    opennslSwitchHashIP6TcpUdpField0,   /**< network switch enhanced hash field. */
    opennslSwitchHashIP6TcpUdpField1,   /**< Selections for IPv6 TCP/UDP packets. */
    opennslSwitchHashIP6TcpUdpPortsEqualField0, /**< network switch enhanced hash field. */
    opennslSwitchHashIP6TcpUdpPortsEqualField1, /**< Selections for IPv6 TCP/UDP packets
                                           with source L4 port equals to
                                           destination L4 port. */
    opennslswitchReservedEnum142, 
    opennslswitchReservedEnum143, 
    opennslswitchReservedEnum144, 
    opennslswitchReservedEnum145, 
    opennslswitchReservedEnum146, 
    opennslswitchReservedEnum147, 
    opennslswitchReservedEnum148, 
    opennslswitchReservedEnum149, 
    opennslswitchReservedEnum150, 
    opennslswitchReservedEnum151, 
    opennslswitchReservedEnum152, 
    opennslswitchReservedEnum153, 
    opennslswitchReservedEnum154, 
    opennslswitchReservedEnum155, 
    opennslswitchReservedEnum156, 
    opennslswitchReservedEnum157, 
    opennslswitchReservedEnum158, 
    opennslswitchReservedEnum159, 
    opennslswitchReservedEnum160, 
    opennslswitchReservedEnum161, 
    opennslswitchReservedEnum162, 
    opennslswitchReservedEnum163, 
    opennslswitchReservedEnum164, 
    opennslswitchReservedEnum165, 
    opennslswitchReservedEnum166, 
    opennslswitchReservedEnum167, 
    opennslswitchReservedEnum168, 
    opennslswitchReservedEnum169, 
    opennslswitchReservedEnum170, 
    opennslswitchReservedEnum171, 
    opennslswitchReservedEnum172, 
    opennslswitchReservedEnum173, 
    opennslswitchReservedEnum174, 
    opennslswitchReservedEnum175, 
    opennslswitchReservedEnum176, 
    opennslswitchReservedEnum177, 
    opennslswitchReservedEnum178, 
    opennslswitchReservedEnum179, 
    opennslswitchReservedEnum180, 
    opennslswitchReservedEnum181, 
    opennslswitchReservedEnum182, 
    opennslSwitchECMPHashSet0Offset,    /**< network switch enhanced hash bits. */
    opennslSwitchECMPHashSet1Offset,    /**< Selections for ECMP. */
    opennslswitchReservedEnum183, 
    opennslswitchReservedEnum184, 
    opennslswitchReservedEnum185, 
    opennslswitchReservedEnum186, 
    opennslswitchReservedEnum187, 
    opennslswitchReservedEnum188, 
    opennslswitchReservedEnum189, 
    opennslswitchReservedEnum190, 
    opennslswitchReservedEnum191, 
    opennslswitchReservedEnum192, 
    opennslswitchReservedEnum193, 
    opennslswitchReservedEnum194, 
    opennslswitchReservedEnum195, 
    opennslswitchReservedEnum196, 
    opennslswitchReservedEnum197, 
    opennslswitchReservedEnum198, 
    opennslswitchReservedEnum199, 
    opennslswitchReservedEnum200, 
    opennslSwitchL3EgressMode,          /**< Enable advanced egress management. */
    opennslswitchReservedEnum201, 
    opennslswitchReservedEnum202, 
    opennslswitchReservedEnum203, 
    opennslswitchReservedEnum204, 
    opennslswitchReservedEnum205, 
    opennslswitchReservedEnum206, 
    opennslswitchReservedEnum207, 
    opennslswitchReservedEnum208, 
    opennslswitchReservedEnum209, 
    opennslswitchReservedEnum210, 
    opennslswitchReservedEnum211, 
    opennslswitchReservedEnum212, 
    opennslswitchReservedEnum213, 
    opennslswitchReservedEnum214, 
    opennslswitchReservedEnum215, 
    opennslswitchReservedEnum216, 
    opennslswitchReservedEnum217, 
    opennslswitchReservedEnum218, 
    opennslswitchReservedEnum219, 
    opennslSwitchL3UcastTtl1ToCpu,      /**< Copy L3 Ucast with TTL 1 to CPU. */
    opennslswitchReservedEnum220, 
    opennslswitchReservedEnum221, 
    opennslswitchReservedEnum222, 
    opennslswitchReservedEnum223, 
    opennslswitchReservedEnum224, 
    opennslswitchReservedEnum225, 
    opennslswitchReservedEnum226, 
    opennslswitchReservedEnum227, 
    opennslswitchReservedEnum228, 
    opennslswitchReservedEnum229, 
    opennslswitchReservedEnum230, 
    opennslswitchReservedEnum231, 
    opennslswitchReservedEnum232, 
    opennslswitchReservedEnum233, 
    opennslswitchReservedEnum234, 
    opennslswitchReservedEnum235, 
    opennslswitchReservedEnum236, 
    opennslswitchReservedEnum237, 
    opennslswitchReservedEnum238, 
    opennslswitchReservedEnum239, 
    opennslswitchReservedEnum240, 
    opennslswitchReservedEnum241, 
    opennslswitchReservedEnum242, 
    opennslswitchReservedEnum243, 
    opennslswitchReservedEnum244, 
    opennslswitchReservedEnum245, 
    opennslswitchReservedEnum246, 
    opennslswitchReservedEnum247, 
    opennslswitchReservedEnum248, 
    opennslswitchReservedEnum249, 
    opennslswitchReservedEnum250, 
    opennslswitchReservedEnum251, 
    opennslswitchReservedEnum252, 
    opennslswitchReservedEnum253, 
    opennslswitchReservedEnum254, 
    opennslswitchReservedEnum255, 
    opennslswitchReservedEnum256, 
    opennslswitchReservedEnum257, 
    opennslswitchReservedEnum258, 
    opennslswitchReservedEnum259, 
    opennslswitchReservedEnum260, 
    opennslswitchReservedEnum261, 
    opennslswitchReservedEnum262, 
    opennslswitchReservedEnum263, 
    opennslswitchReservedEnum264, 
    opennslswitchReservedEnum265, 
    opennslswitchReservedEnum266, 
    opennslswitchReservedEnum267, 
    opennslswitchReservedEnum268, 
    opennslswitchReservedEnum269, 
    opennslswitchReservedEnum270, 
    opennslswitchReservedEnum271, 
    opennslswitchReservedEnum272, 
    opennslswitchReservedEnum273, 
    opennslswitchReservedEnum274, 
    opennslswitchReservedEnum275, 
    opennslswitchReservedEnum276, 
    opennslswitchReservedEnum277, 
    opennslswitchReservedEnum278, 
    opennslswitchReservedEnum279, 
    opennslswitchReservedEnum280, 
    opennslswitchReservedEnum281, 
    opennslswitchReservedEnum282, 
    opennslswitchReservedEnum283, 
    opennslswitchReservedEnum284, 
    opennslswitchReservedEnum285, 
    opennslswitchReservedEnum286, 
    opennslswitchReservedEnum287, 
    opennslswitchReservedEnum288, 
    opennslswitchReservedEnum289, 
    opennslswitchReservedEnum290, 
    opennslswitchReservedEnum291, 
    opennslswitchReservedEnum292, 
    opennslswitchReservedEnum293, 
    opennslswitchReservedEnum294, 
    opennslswitchReservedEnum295, 
    opennslswitchReservedEnum296, 
    opennslswitchReservedEnum297, 
    opennslswitchReservedEnum298, 
    opennslswitchReservedEnum299, 
    opennslswitchReservedEnum300, 
    opennslswitchReservedEnum301, 
    opennslswitchReservedEnum302, 
    opennslswitchReservedEnum303, 
    opennslswitchReservedEnum304, 
    opennslswitchReservedEnum305, 
    opennslswitchReservedEnum306, 
    opennslswitchReservedEnum307, 
    opennslswitchReservedEnum308, 
    opennslswitchReservedEnum309, 
    opennslswitchReservedEnum310, 
    opennslswitchReservedEnum311, 
    opennslswitchReservedEnum312, 
    opennslswitchReservedEnum313, 
    opennslswitchReservedEnum314, 
    opennslswitchReservedEnum315, 
    opennslswitchReservedEnum316, 
    opennslswitchReservedEnum317, 
    opennslswitchReservedEnum318, 
    opennslswitchReservedEnum319, 
    opennslswitchReservedEnum320, 
    opennslswitchReservedEnum321, 
    opennslswitchReservedEnum322, 
    opennslswitchReservedEnum323, 
    opennslswitchReservedEnum324, 
    opennslswitchReservedEnum325, 
    opennslswitchReservedEnum326, 
    opennslswitchReservedEnum327, 
    opennslswitchReservedEnum328, 
    opennslswitchReservedEnum329, 
    opennslswitchReservedEnum330, 
    opennslswitchReservedEnum331, 
    opennslswitchReservedEnum332, 
    opennslswitchReservedEnum333, 
    opennslswitchReservedEnum334, 
    opennslswitchReservedEnum335, 
    opennslswitchReservedEnum336, 
    opennslswitchReservedEnum337, 
    opennslswitchReservedEnum338, 
    opennslswitchReservedEnum339, 
    opennslswitchReservedEnum340, 
    opennslswitchReservedEnum341, 
    opennslswitchReservedEnum342, 
    opennslswitchReservedEnum343, 
    opennslswitchReservedEnum344, 
    opennslswitchReservedEnum345, 
    opennslswitchReservedEnum346, 
    opennslswitchReservedEnum347, 
    opennslswitchReservedEnum348, 
    opennslswitchReservedEnum349, 
    opennslswitchReservedEnum350, 
    opennslswitchReservedEnum351, 
    opennslswitchReservedEnum352, 
    opennslswitchReservedEnum353, 
    opennslswitchReservedEnum354, 
    opennslswitchReservedEnum355, 
    opennslswitchReservedEnum356, 
    opennslswitchReservedEnum357, 
    opennslswitchReservedEnum358, 
    opennslswitchReservedEnum359, 
    opennslswitchReservedEnum360, 
    opennslswitchReservedEnum361, 
    opennslswitchReservedEnum362, 
    opennslswitchReservedEnum363, 
    opennslswitchReservedEnum364, 
    opennslswitchReservedEnum365, 
    opennslswitchReservedEnum366, 
    opennslswitchReservedEnum367, 
    opennslswitchReservedEnum368, 
    opennslswitchReservedEnum369, 
    opennslswitchReservedEnum370, 
    opennslswitchReservedEnum371, 
    opennslswitchReservedEnum372, 
    opennslswitchReservedEnum373, 
    opennslswitchReservedEnum374, 
    opennslswitchReservedEnum375, 
    opennslswitchReservedEnum376, 
    opennslswitchReservedEnum377, 
    opennslswitchReservedEnum378, 
    opennslswitchReservedEnum379, 
    opennslswitchReservedEnum380, 
    opennslswitchReservedEnum381, 
    opennslswitchReservedEnum382, 
    opennslswitchReservedEnum383, 
    opennslswitchReservedEnum384, 
    opennslswitchReservedEnum385, 
    opennslswitchReservedEnum386, 
    opennslswitchReservedEnum387, 
    opennslswitchReservedEnum388, 
    opennslswitchReservedEnum389, 
    opennslswitchReservedEnum390, 
    opennslswitchReservedEnum391, 
    opennslswitchReservedEnum392, 
    opennslswitchReservedEnum393, 
    opennslswitchReservedEnum394, 
    opennslswitchReservedEnum395, 
    opennslswitchReservedEnum396, 
    opennslswitchReservedEnum397, 
    opennslswitchReservedEnum398, 
    opennslswitchReservedEnum399, 
    opennslswitchReservedEnum400, 
    opennslswitchReservedEnum401, 
    opennslswitchReservedEnum402, 
    opennslswitchReservedEnum403, 
    opennslswitchReservedEnum404, 
    opennslswitchReservedEnum405, 
    opennslswitchReservedEnum406, 
    opennslswitchReservedEnum407, 
    opennslswitchReservedEnum408, 
    opennslswitchReservedEnum409, 
    opennslswitchReservedEnum410, 
    opennslswitchReservedEnum411, 
    opennslswitchReservedEnum412, 
    opennslswitchReservedEnum413, 
    opennslswitchReservedEnum414, 
    opennslswitchReservedEnum415, 
    opennslswitchReservedEnum416, 
    opennslswitchReservedEnum417, 
    opennslswitchReservedEnum418, 
    opennslswitchReservedEnum419, 
    opennslswitchReservedEnum420, 
    opennslswitchReservedEnum421, 
    opennslswitchReservedEnum422, 
    opennslswitchReservedEnum423, 
    opennslswitchReservedEnum424, 
    opennslswitchReservedEnum425, 
    opennslswitchReservedEnum426, 
    opennslswitchReservedEnum427, 
    opennslswitchReservedEnum428, 
    opennslswitchReservedEnum429, 
    opennslswitchReservedEnum430, 
    opennslswitchReservedEnum431, 
    opennslswitchReservedEnum432, 
    opennslswitchReservedEnum433, 
    opennslswitchReservedEnum434, 
    opennslswitchReservedEnum435, 
    opennslswitchReservedEnum436, 
    opennslswitchReservedEnum437, 
    opennslswitchReservedEnum438, 
    opennslswitchReservedEnum439, 
    opennslswitchReservedEnum440, 
    opennslswitchReservedEnum441, 
    opennslswitchReservedEnum442, 
    opennslswitchReservedEnum443, 
    opennslswitchReservedEnum444, 
    opennslswitchReservedEnum445, 
    opennslswitchReservedEnum446, 
    opennslswitchReservedEnum447, 
    opennslswitchReservedEnum448, 
    opennslswitchReservedEnum449, 
    opennslswitchReservedEnum450, 
    opennslswitchReservedEnum451, 
    opennslswitchReservedEnum452, 
    opennslswitchReservedEnum453, 
    opennslswitchReservedEnum454, 
    opennslswitchReservedEnum455, 
    opennslswitchReservedEnum456, 
    opennslswitchReservedEnum457, 
    opennslswitchReservedEnum458, 
    opennslswitchReservedEnum459, 
    opennslswitchReservedEnum460, 
    opennslswitchReservedEnum461, 
    opennslswitchReservedEnum462, 
    opennslswitchReservedEnum463, 
    opennslswitchReservedEnum464, 
    opennslswitchReservedEnum465, 
    opennslswitchReservedEnum466, 
    opennslswitchReservedEnum467, 
    opennslswitchReservedEnum468, 
    opennslswitchReservedEnum469, 
    opennslswitchReservedEnum470, 
    opennslswitchReservedEnum471, 
    opennslswitchReservedEnum472, 
    opennslswitchReservedEnum473, 
    opennslswitchReservedEnum474, 
    opennslswitchReservedEnum475, 
    opennslswitchReservedEnum476, 
    opennslswitchReservedEnum477, 
    opennslswitchReservedEnum478, 
    opennslswitchReservedEnum479, 
    opennslswitchReservedEnum480, 
    opennslswitchReservedEnum481, 
    opennslswitchReservedEnum482, 
    opennslswitchReservedEnum483, 
    opennslswitchReservedEnum484, 
    opennslswitchReservedEnum485, 
    opennslswitchReservedEnum486, 
    opennslswitchReservedEnum487, 
    opennslswitchReservedEnum488, 
    opennslswitchReservedEnum489, 
    opennslswitchReservedEnum490, 
    opennslswitchReservedEnum491, 
    opennslswitchReservedEnum492, 
    opennslswitchReservedEnum493, 
    opennslswitchReservedEnum494, 
    opennslswitchReservedEnum495, 
    opennslswitchReservedEnum496, 
    opennslswitchReservedEnum497, 
    opennslswitchReservedEnum498, 
    opennslswitchReservedEnum499, 
    opennslswitchReservedEnum500, 
    opennslswitchReservedEnum501, 
    opennslswitchReservedEnum502, 
    opennslswitchReservedEnum503, 
    opennslswitchReservedEnum504, 
    opennslswitchReservedEnum505, 
    opennslswitchReservedEnum506, 
    opennslswitchReservedEnum507, 
    opennslswitchReservedEnum508, 
    opennslswitchReservedEnum509, 
    opennslswitchReservedEnum510, 
    opennslswitchReservedEnum511, 
    opennslswitchReservedEnum512, 
    opennslswitchReservedEnum513, 
    opennslswitchReservedEnum514, 
    opennslswitchReservedEnum515, 
    opennslswitchReservedEnum516, 
    opennslswitchReservedEnum517, 
    opennslswitchReservedEnum518, 
    opennslswitchReservedEnum519, 
    opennslswitchReservedEnum520, 
    opennslswitchReservedEnum521, 
    opennslswitchReservedEnum522, 
    opennslswitchReservedEnum523, 
    opennslswitchReservedEnum524, 
    opennslswitchReservedEnum525, 
    opennslswitchReservedEnum526, 
    opennslswitchReservedEnum527, 
    opennslswitchReservedEnum528, 
    opennslswitchReservedEnum529, 
    opennslswitchReservedEnum530, 
    opennslswitchReservedEnum531, 
    opennslswitchReservedEnum532, 
    opennslswitchReservedEnum533, 
    opennslswitchReservedEnum534, 
    opennslswitchReservedEnum535, 
    opennslswitchReservedEnum536, 
    opennslswitchReservedEnum537, 
    opennslswitchReservedEnum538, 
    opennslswitchReservedEnum539, 
    opennslswitchReservedEnum540, 
    opennslswitchReservedEnum541, 
    opennslswitchReservedEnum542, 
    opennslswitchReservedEnum543, 
    opennslswitchReservedEnum544, 
    opennslswitchReservedEnum545, 
    opennslswitchReservedEnum546, 
    opennslswitchReservedEnum547, 
    opennslswitchReservedEnum548, 
    opennslswitchReservedEnum549, 
    opennslswitchReservedEnum550, 
    opennslswitchReservedEnum551, 
    opennslswitchReservedEnum552, 
    opennslswitchReservedEnum553, 
    opennslswitchReservedEnum554, 
    opennslswitchReservedEnum555, 
    opennslswitchReservedEnum556, 
    opennslswitchReservedEnum557, 
    opennslswitchReservedEnum558, 
    opennslswitchReservedEnum559, 
    opennslswitchReservedEnum560, 
    opennslswitchReservedEnum561, 
    opennslswitchReservedEnum562, 
    opennslswitchReservedEnum563, 
    opennslswitchReservedEnum564, 
    opennslswitchReservedEnum565, 
    opennslswitchReservedEnum566, 
    opennslswitchReservedEnum567, 
    opennslswitchReservedEnum568, 
    opennslswitchReservedEnum569, 
    opennslswitchReservedEnum570, 
    opennslswitchReservedEnum571, 
    opennslswitchReservedEnum572, 
    opennslswitchReservedEnum573, 
    opennslswitchReservedEnum574, 
    opennslswitchReservedEnum575, 
    opennslswitchReservedEnum576, 
    opennslswitchReservedEnum577, 
    opennslswitchReservedEnum578, 
    opennslswitchReservedEnum579, 
    opennslswitchReservedEnum580, 
    opennslswitchReservedEnum581, 
    opennslswitchReservedEnum582, 
    opennslswitchReservedEnum583, 
    opennslswitchReservedEnum584, 
    opennslswitchReservedEnum585, 
    opennslswitchReservedEnum586, 
    opennslswitchReservedEnum587, 
    opennslswitchReservedEnum588, 
    opennslswitchReservedEnum589, 
    opennslswitchReservedEnum590, 
    opennslswitchReservedEnum591, 
    opennslswitchReservedEnum592, 
    opennslswitchReservedEnum593, 
    opennslswitchReservedEnum594, 
    opennslswitchReservedEnum595, 
    opennslswitchReservedEnum596, 
    opennslswitchReservedEnum597, 
    opennslswitchReservedEnum598, 
    opennslswitchReservedEnum599, 
    opennslswitchReservedEnum600, 
    opennslswitchReservedEnum601, 
    opennslswitchReservedEnum602, 
    opennslswitchReservedEnum603, 
    opennslswitchReservedEnum604, 
    opennslswitchReservedEnum605, 
    opennslswitchReservedEnum606, 
    opennslswitchReservedEnum607, 
    opennslswitchReservedEnum608, 
    opennslswitchReservedEnum609, 
    opennslswitchReservedEnum610, 
    opennslswitchReservedEnum611, 
    opennslswitchReservedEnum612, 
    opennslswitchReservedEnum613, 
    opennslswitchReservedEnum614, 
    opennslswitchReservedEnum615, 
    opennslswitchReservedEnum616, 
    opennslswitchReservedEnum617, 
    opennslswitchReservedEnum618, 
    opennslswitchReservedEnum619, 
    opennslswitchReservedEnum620, 
    opennslswitchReservedEnum621, 
    opennslswitchReservedEnum622, 
    opennslswitchReservedEnum623, 
    opennslswitchReservedEnum624, 
    opennslswitchReservedEnum625, 
    opennslswitchReservedEnum626, 
    opennslswitchReservedEnum627, 
    opennslswitchReservedEnum628, 
    opennslswitchReservedEnum629, 
    opennslswitchReservedEnum630, 
    opennslswitchReservedEnum631, 
    opennslswitchReservedEnum632, 
    opennslswitchReservedEnum633, 
    opennslswitchReservedEnum634, 
    opennslswitchReservedEnum635, 
    opennslswitchReservedEnum636, 
    opennslswitchReservedEnum637, 
    opennslswitchReservedEnum638, 
    opennslswitchReservedEnum639, 
    opennslswitchReservedEnum640, 
    opennslswitchReservedEnum641, 
    opennslswitchReservedEnum642, 
    opennslswitchReservedEnum643, 
    opennslswitchReservedEnum644, 
    opennslswitchReservedEnum645, 
    opennslswitchReservedEnum646, 
    opennslswitchReservedEnum647, 
    opennslswitchReservedEnum648, 
    opennslswitchReservedEnum649, 
    opennslswitchReservedEnum650, 
    opennslswitchReservedEnum651, 
    opennslswitchReservedEnum652, 
    opennslswitchReservedEnum653, 
    opennslswitchReservedEnum654, 
    opennslswitchReservedEnum655, 
    opennslswitchReservedEnum656, 
    opennslswitchReservedEnum657, 
    opennslswitchReservedEnum658, 
    opennslswitchReservedEnum659, 
    opennslswitchReservedEnum660, 
    opennslswitchReservedEnum661, 
    opennslswitchReservedEnum662, 
    opennslswitchReservedEnum663, 
    opennslswitchReservedEnum664, 
    opennslswitchReservedEnum665, 
    opennslswitchReservedEnum666, 
    opennslswitchReservedEnum667, 
    opennslswitchReservedEnum668, 
    opennslswitchReservedEnum669, 
    opennslswitchReservedEnum670, 
    opennslswitchReservedEnum671, 
    opennslswitchReservedEnum672, 
    opennslswitchReservedEnum673, 
    opennslswitchReservedEnum674, 
    opennslswitchReservedEnum675, 
    opennslswitchReservedEnum676, 
    opennslswitchReservedEnum677, 
    opennslswitchReservedEnum678, 
    opennslswitchReservedEnum679, 
    opennslswitchReservedEnum680, 
    opennslswitchReservedEnum681, 
    opennslswitchReservedEnum682, 
    opennslswitchReservedEnum683, 
    opennslswitchReservedEnum684, 
    opennslswitchReservedEnum685, 
    opennslswitchReservedEnum686, 
    opennslswitchReservedEnum687, 
    opennslswitchReservedEnum688, 
    opennslswitchReservedEnum689, 
    opennslswitchReservedEnum690, 
    opennslswitchReservedEnum691, 
    opennslswitchReservedEnum692, 
    opennslswitchReservedEnum693, 
    opennslswitchReservedEnum694, 
    opennslswitchReservedEnum695, 
    opennslswitchReservedEnum696, 
    opennslswitchReservedEnum697, 
    opennslswitchReservedEnum698, 
    opennslswitchReservedEnum699, 
    opennslswitchReservedEnum700, 
    opennslswitchReservedEnum701, 
    opennslswitchReservedEnum702, 
    opennslswitchReservedEnum703, 
    opennslswitchReservedEnum704, 
    opennslswitchReservedEnum705, 
    opennslswitchReservedEnum706, 
    opennslswitchReservedEnum707, 
    opennslswitchReservedEnum708, 
    opennslswitchReservedEnum709, 
    opennslswitchReservedEnum710, 
    opennslswitchReservedEnum711, 
    opennslswitchReservedEnum712, 
    opennslswitchReservedEnum713, 
    opennslswitchReservedEnum714, 
    opennslswitchReservedEnum715, 
    opennslswitchReservedEnum716, 
    opennslswitchReservedEnum717, 
    opennslswitchReservedEnum718, 
    opennslswitchReservedEnum719, 
    opennslswitchReservedEnum720, 
    opennslswitchReservedEnum721, 
    opennslswitchReservedEnum722, 
    opennslswitchReservedEnum723, 
    opennslswitchReservedEnum724, 
    opennslswitchReservedEnum725, 
    opennslswitchReservedEnum726, 
    opennslswitchReservedEnum727, 
    opennslswitchReservedEnum728, 
    opennslswitchReservedEnum729, 
    opennslswitchReservedEnum730, 
    opennslswitchReservedEnum731, 
    opennslswitchReservedEnum732, 
    opennslswitchReservedEnum733, 
    opennslswitchReservedEnum734, 
    opennslswitchReservedEnum735, 
    opennslswitchReservedEnum736, 
    opennslswitchReservedEnum737, 
    opennslswitchReservedEnum738, 
    opennslswitchReservedEnum739, 
    opennslswitchReservedEnum740, 
    opennslswitchReservedEnum741, 
    opennslswitchReservedEnum742, 
    opennslswitchReservedEnum743, 
    opennslswitchReservedEnum744, 
    opennslswitchReservedEnum745, 
    opennslswitchReservedEnum746, 
    opennslswitchReservedEnum747, 
    opennslswitchReservedEnum748, 
    opennslswitchReservedEnum749, 
    opennslswitchReservedEnum750, 
    opennslSwitchEcmpMacroFlowHashEnable, /**< Enable ECMP macro-flow hashing. */
    opennslswitchReservedEnum751, 
    opennslswitchReservedEnum752, 
    opennslswitchReservedEnum753, 
    opennslswitchReservedEnum754, 
    opennslswitchReservedEnum755, 
    opennslswitchReservedEnum756, 
    opennslswitchReservedEnum757, 
    opennslswitchReservedEnum758, 
    opennslswitchReservedEnum759, 
    opennslswitchReservedEnum760, 
    opennslswitchReservedEnum761, 
    opennslswitchReservedEnum762, 
    opennslswitchReservedEnum763, 
    opennslswitchReservedEnum764, 
    opennslswitchReservedEnum765, 
    opennslswitchReservedEnum766, 
    opennslswitchReservedEnum767, 
    opennslswitchReservedEnum768, 
    opennslswitchReservedEnum769, 
    opennslswitchReservedEnum770, 
    opennslswitchReservedEnum771, 
    opennslswitchReservedEnum772, 
    opennslswitchReservedEnum773, 
    opennslswitchReservedEnum774, 
    opennslswitchReservedEnum775, 
    opennslswitchReservedEnum776, 
    opennslswitchReservedEnum777, 
    opennslswitchReservedEnum778, 
    opennslswitchReservedEnum779, 
    opennslswitchReservedEnum780, 
    opennslswitchReservedEnum781, 
    opennslswitchReservedEnum782, 
    opennslswitchReservedEnum783, 
    opennslswitchReservedEnum784, 
    opennslswitchReservedEnum785, 
    opennslswitchReservedEnum786, 
    opennslswitchReservedEnum787, 
    opennslswitchReservedEnum788, 
    opennslswitchReservedEnum789, 
    opennslswitchReservedEnum790, 
    opennslswitchReservedEnum791, 
    opennslswitchReservedEnum792, 
    opennslswitchReservedEnum793, 
    opennslswitchReservedEnum794, 
    opennslswitchReservedEnum795, 
    opennslswitchReservedEnum796, 
    opennslswitchReservedEnum797, 
    opennslswitchReservedEnum798, 
    opennslswitchReservedEnum799, 
    opennslswitchReservedEnum800, 
    opennslswitchReservedEnum801, 
    opennslswitchReservedEnum802, 
    opennslswitchReservedEnum803, 
    opennslswitchReservedEnum804, 
    opennslswitchReservedEnum805, 
    opennslswitchReservedEnum806, 
    opennslswitchReservedEnum807, 
    opennslswitchReservedEnum808, 
    opennslswitchReservedEnum809, 
    opennslswitchReservedEnum810, 
    opennslswitchReservedEnum811, 
    opennslswitchReservedEnum812, 
    opennslswitchReservedEnum813, 
    opennslswitchReservedEnum814, 
    opennslswitchReservedEnum815, 
    opennslswitchReservedEnum816, 
    opennslswitchReservedEnum817, 
    opennslswitchReservedEnum818, 
    opennslswitchReservedEnum819, 
    opennslswitchReservedEnum820, 
    opennslswitchReservedEnum821, 
    opennslswitchReservedEnum822, 
    opennslswitchReservedEnum823, 
    opennslswitchReservedEnum824, 
    opennslswitchReservedEnum825, 
    opennslswitchReservedEnum826, 
    opennslswitchReservedEnum827, 
    opennslswitchReservedEnum828, 
    opennslswitchReservedEnum829, 
    opennslswitchReservedEnum830, 
    opennslswitchReservedEnum831, 
    opennslswitchReservedEnum832, 
    opennslswitchReservedEnum833, 
    opennslswitchReservedEnum834, 
    opennslswitchReservedEnum835, 
    opennslswitchReservedEnum836, 
    opennslswitchReservedEnum837, 
    opennslswitchReservedEnum838, 
    opennslswitchReservedEnum839, 
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
    opennslswitchReservedEnum883 = 915 
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
    "DhcpPktDrop", \
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
    "HashControl", \
    "opennslswitchReservedEnum131", \
    "opennslswitchReservedEnum132", \
    "opennslswitchReservedEnum133", \
    "opennslswitchReservedEnum134", \
    "opennslswitchReservedEnum135", \
    "opennslswitchReservedEnum136", \
    "opennslswitchReservedEnum137", \
    "opennslswitchReservedEnum138", \
    "opennslswitchReservedEnum139", \
    "opennslswitchReservedEnum140", \
    "HashSeed0", \
    "HashSeed1", \
    "HashField0PreProcessEnable", \
    "HashField1PreProcessEnable", \
    "HashField0Config", \
    "HashField0Config1", \
    "HashField1Config", \
    "HashField1Config1", \
    "opennslswitchReservedEnum141", \
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
    "opennslswitchReservedEnum142", \
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
    "ECMPHashSet0Offset", \
    "ECMPHashSet1Offset", \
    "opennslswitchReservedEnum183", \
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
    "L3EgressMode", \
    "opennslswitchReservedEnum201", \
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
    "opennslswitchReservedEnum214", \
    "opennslswitchReservedEnum215", \
    "opennslswitchReservedEnum216", \
    "opennslswitchReservedEnum217", \
    "opennslswitchReservedEnum218", \
    "opennslswitchReservedEnum219", \
    "L3UcastTtl1ToCpu", \
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
    "opennslswitchReservedEnum750", \
    "EcmpMacroFlowHashEnable", \
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
 *\param    arg [IN]   (for _set) Argument whose meaning is dependent on type
 *
 *\retval    OPENNSL_E_UNAVAIL	Feature not available on this device
 *\retval    OPENNSL_E_XXX		Other error
 ******************************************************************************/
extern int opennsl_switch_control_set(
    int unit, 
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

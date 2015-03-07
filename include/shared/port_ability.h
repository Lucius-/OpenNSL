/*********************************************************************
 *
 * (C) Copyright Broadcom Corporation 2013-2014
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *******************************************************************
 * File:        port_ability.h
 * Details:     This file defines common network port modes. 
 * 				Its contents are not used directly by applications;
 * 				it is used only by header files of parent APIs which
 * 				need to define port modes.
 ******************************************************************/

#ifndef _SHR_PORTABILITY_H
#define _SHR_PORTABILITY_H

typedef unsigned int    _shr_pa_encap_t;

typedef struct _shr_port_ability_s {
    _shr_port_mode_t speed_half_duplex;
    _shr_port_mode_t speed_full_duplex;
    _shr_port_mode_t pause;
    _shr_port_mode_t interface;
    _shr_port_mode_t medium;
    _shr_port_mode_t loopback;
    _shr_port_mode_t flags;
    _shr_port_mode_t eee;
    _shr_port_mode_t fcmap;
    _shr_pa_encap_t  encap;
} _shr_port_ability_t;

#endif  /* !_SHR_PORTABILITY_H */

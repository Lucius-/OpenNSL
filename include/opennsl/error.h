/** \addtogroup error Error Handling
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
 * \file			error.h
 ******************************************************************************/

#ifndef __OPENNSL_ERROR_H__
#define __OPENNSL_ERROR_H__

#include <shared/error.h>

/** 
 * OPENNSL API error codes.
 * 
 * Note: An error code may be converted to a string by passing the code
 * to opennsl_errmsg().
 */
typedef enum opennsl_error_e {
    OPENNSL_E_NONE         = _SHR_E_NONE, 
    errorReservedEnum1,                 
    OPENNSL_E_MEMORY       = _SHR_E_MEMORY, 
    errorReservedEnum2,                 
    OPENNSL_E_PARAM        = _SHR_E_PARAM, 
    errorReservedEnum3,                 
    errorReservedEnum4,                 
    OPENNSL_E_NOT_FOUND    = _SHR_E_NOT_FOUND, 
    OPENNSL_E_EXISTS       = _SHR_E_EXISTS, 
    errorReservedEnum5,                 
    errorReservedEnum6,                 
    OPENNSL_E_FAIL         = _SHR_E_FAIL, 
    errorReservedEnum7,                 
    errorReservedEnum8,                 
    errorReservedEnum9,                 
    errorReservedEnum10,                
    OPENNSL_E_UNAVAIL      = _SHR_E_UNAVAIL, 
    errorReservedEnum11,                
    errorReservedEnum12                 
} opennsl_error_t;

/** Switch event types */
typedef enum opennsl_switch_event_e {
    OPENNSL_SWITCH_EVENT_IO_ERROR              =   _SHR_SWITCH_EVENT_IO_ERROR, 
    OPENNSL_SWITCH_EVENT_PARITY_ERROR          =   _SHR_SWITCH_EVENT_PARITY_ERROR, 
    OPENNSL_SWITCH_EVENT_THREAD_ERROR          =   _SHR_SWITCH_EVENT_THREAD_ERROR, 
    OPENNSL_SWITCH_EVENT_ACCESS_ERROR          =   _SHR_SWITCH_EVENT_ACCESS_ERROR, 
    OPENNSL_SWITCH_EVENT_ASSERT_ERROR          =   _SHR_SWITCH_EVENT_ASSERT_ERROR, 
    OPENNSL_SWITCH_EVENT_MODID_CHANGE          =   _SHR_SWITCH_EVENT_MODID_CHANGE, 
    OPENNSL_SWITCH_EVENT_DOS_ATTACK            =   _SHR_SWITCH_EVENT_DOS_ATTACK, 
    OPENNSL_SWITCH_EVENT_STABLE_FULL           =   _SHR_SWITCH_EVENT_STABLE_FULL, 
    OPENNSL_SWITCH_EVENT_STABLE_ERROR          =   _SHR_SWITCH_EVENT_STABLE_ERROR, 
    OPENNSL_SWITCH_EVENT_UNCONTROLLED_SHUTDOWN =   _SHR_SWITCH_EVENT_UNCONTROLLED_SHUTDOWN, 
    OPENNSL_SWITCH_EVENT_WARM_BOOT_DOWNGRADE   =   _SHR_SWITCH_EVENT_WARM_BOOT_DOWNGRADE, 
    OPENNSL_SWITCH_EVENT_TUNE_ERROR            =   _SHR_SWITCH_EVENT_TUNE_ERROR, 
    OPENNSL_SWITCH_EVENT_DEVICE_INTERRUPT      =   _SHR_SWITCH_EVENT_DEVICE_INTERRUPT, 
    OPENNSL_SWITCH_EVENT_ALARM                 =   _SHR_SWITCH_EVENT_ALARM, 
    OPENNSL_SWITCH_EVENT_MMU_BST_TRIGGER       =   _SHR_SWITCH_EVENT_MMU_BST_TRIGGER, 
    OPENNSL_SWITCH_EVENT_EPON_ALARM            =   _SHR_SWITCH_EVENT_EPON_ALARM, 
    OPENNSL_SWITCH_EVENT_RUNT_DETECT           =   _SHR_SWITCH_EVENT_RUNT_DETECT, 
    OPENNSL_SWITCH_EVENT_COUNT                 =   _SHR_SWITCH_EVENT_COUNT 
} opennsl_switch_event_t;

#define OPENNSL_SUCCESS(rv)     \
    _SHR_E_SUCCESS(rv) 
#define OPENNSL_FAILURE(rv)     \
    _SHR_E_FAILURE(rv) 
#define opennsl_errmsg(rv)      \
    _SHR_ERRMSG(rv) 
#endif /* __OPENNSL_ERROR_H__ */
/*@}*/

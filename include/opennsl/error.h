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
    errorReservedEnum5,                 
    errorReservedEnum6,                 
    errorReservedEnum7,                 
    OPENNSL_E_FAIL         = _SHR_E_FAIL, 
    errorReservedEnum8,                 
    errorReservedEnum9,                 
    errorReservedEnum10,                
    errorReservedEnum11,                
    OPENNSL_E_UNAVAIL      = _SHR_E_UNAVAIL, 
    errorReservedEnum12,                
    errorReservedEnum13                 
} opennsl_error_t;

/** Switch event types */
typedef enum opennsl_switch_event_e {
    errorReservedEnum14,                
    errorReservedEnum15,                
    errorReservedEnum16,                
    errorReservedEnum17,                
    errorReservedEnum18,                
    errorReservedEnum19,                
    errorReservedEnum20,                
    errorReservedEnum21,                
    errorReservedEnum22,                
    errorReservedEnum23,                
    errorReservedEnum24,                
    errorReservedEnum25,                
    errorReservedEnum26,                
    errorReservedEnum27,                
    OPENNSL_SWITCH_EVENT_MMU_BST_TRIGGER       =   _SHR_SWITCH_EVENT_MMU_BST_TRIGGER, 
    errorReservedEnum28,                
    errorReservedEnum29                 
} opennsl_switch_event_t;

#define OPENNSL_SUCCESS(rv)     \
    _SHR_E_SUCCESS(rv) 
#define OPENNSL_FAILURE(rv)     \
    _SHR_E_FAILURE(rv) 
#define opennsl_errmsg(rv)      \
    _SHR_ERRMSG(rv) 
#endif /* __OPENNSL_ERROR_H__ */
/*@}*/

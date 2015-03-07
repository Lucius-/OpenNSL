/** \addtogroup init Initialization
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
 * \file			init.h
 ******************************************************************************/

#ifndef __OPENNSL_INIT_H__
#define __OPENNSL_INIT_H__

#include <opennsl/types.h>

/***************************************************************************//** 
 *\brief Attach a device as a OPENNSL unit.
 *
 *\description Create a OPENNSL unit instance.  If the unit parameter is
 *          	non-negative, use that value as the unit number for the        
 *          attached device.  Otherwise, search for an unused OPENNSL unit
 *          number. 	If the type parameter is NULL, then search for 	an
 *          appropriate dispatch driver.
 *
 *\param    unit [IN]   Unit number.
 *\param    remunit [IN]   Underlying remote unit
 *
 *\retval    unit			the attached non-negative unit number (if successful)
 *\retval    OPENNSL_E_MEMORY		memory allocation failure
 *\retval    OPENNSL_E_CONFIG		dispatch driver not found
 *\retval    OPENNSL_E_FULL		no available unit numbers
 *\retval    OPENNSL_E_EXISTS		requested unit number already attached
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_attach(
    int unit, 
    char *reserved1, 
    char *reserved2, 
    int remunit) LIB_DLL_EXPORTED ;

/***************************************************************************//** 
 *\brief Detach a device as a OPENNSL unit.
 *
 *\description Destroy a OPENNSL unit instance.  The unit is removed from the
 *          	list of OPENNSL dispatchable units.  Detaching a unit does not
 *          	affect the underlying device if it was attached as a loopback 	or
 *          remote unit. This API is not thread-safe. In a multi-threaded     
 *              environment where multiple threads may be calling various
 *          OPENNSL APIs,         it is recommended that such threads be
 *          stopped before invoking          opennsl_detach().
 *
 *\param    unit [IN]   Unit number.
 *
 *\retval    OPENNSL_E_XXX
 ******************************************************************************/
extern int opennsl_detach(
    int unit) LIB_DLL_EXPORTED ;

#if !defined(OPENNSL_WARM_BOOT_SUPPORT)
#define _opennsl_shutdown(unit)  OPENNSL_E_NONE 
#endif
#endif /* __OPENNSL_INIT_H__ */
/*@}*/

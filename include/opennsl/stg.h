/** \addtogroup stg Spanning Tree
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
 * \file			stg.h
 ******************************************************************************/

#ifndef __OPENNSL_STG_H__
#define __OPENNSL_STG_H__

#include <shared/port.h>
#include <opennsl/types.h>

/** opennsl_stg_stp_e */
typedef enum opennsl_stg_stp_e {
    stgReservedEnum1 = _SHR_PORT_STP_DISABLE, 
    stgReservedEnum2 = _SHR_PORT_STP_BLOCK, 
    stgReservedEnum3 = _SHR_PORT_STP_LISTEN, 
    stgReservedEnum4 = _SHR_PORT_STP_LEARN, 
    OPENNSL_STG_STP_FORWARD = _SHR_PORT_STP_FORWARD, /**< Normal operation. */
    stgReservedEnum5 = _SHR_PORT_STP_COUNT 
} opennsl_stg_stp_t;

#ifndef OPENNSL_HIDE_DISPATCHABLE

/***************************************************************************//** 
 *\brief Set the Spanning Tree Protocol state of a port in the specified STG.
 *
 *\description Sets the specified local port to the indicated Spanning
 *          TreeProtocol (STP) state. The indicated STG must be currently
 *          defined. On some switches  the LISTENING state can be
 *          indistinguishable from the BLOCKING state.
 *
 *\param    unit [IN]   Unit number.
 *\param    stg [IN]   STG ID
 *\param    port [IN]   Local (opennsl) port number
 *\param    stp_state [IN]   Spanning Tree Protocol state
 *
 *\retval    OPENNSL_E_NONE Success
 *\retval    OPENNSL_E_INIT STG module is not currently initialized.
 *\retval    OPENNSL_E_BADID Invalid STG ID
 *\retval    OPENNSL_E_PORT if invalid port specified
 *\retval    OPENNSL_E_NOT_FOUND STG ID is not currently defined
 *\retval    OPENNSL_E_XXX Other possible errors; for details, see
 ******************************************************************************/
extern int opennsl_stg_stp_set(
    int unit, 
    opennsl_stg_t stg, 
    opennsl_port_t port, 
    int stp_state) LIB_DLL_EXPORTED ;

#endif /* OPENNSL_HIDE_DISPATCHABLE */

#endif /* __OPENNSL_STG_H__ */
/*@}*/

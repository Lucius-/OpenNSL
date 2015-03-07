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
 ********************************************************************
 * File:        commdefs.h
 * Details:     OpenNSL specific defines and options
 *******************************************************************/

#ifndef _SAL_COMMDEFS_H
#define _SAL_COMMDEFS_H

#define HAVE_VISIBILITY 1

#if defined(OPENNSL_BUILDING_LIB) && defined(HAVE_VISIBILITY)
#define LIB_DLL_EXPORTED __attribute__((__visibility__("default")))
#elif CDP_PACKAGE
#define LIB_DLL_EXPORTED 
#else
#define LIB_DLL_EXPORTED
#error "Error!!! LIB_DLL_EXPORTED defined to NULL"
#endif

#endif    /* !_SAL_COMMDEFS_H */

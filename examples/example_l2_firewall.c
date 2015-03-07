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
 **********************************************************************
 * \file     example_l2_firewall.c
 *
 * \brief    Example code for Layer2 firewall
 *
 * \details  This example demonstrates a simple Layer 2 Firewall use case,
 * where a network administrator can block unauthorized stations from accessing
 * the network. The match criteria for the firewall rules can be either source
 * MAC address or destination MAC address. Frames matching the firewall rule
 * can either be dropped or forwarded. A centralized firewall server can
 * maintain the firewall rules for all the Layer2 switches in the network.
 * If the match criteria is source MAC address, packets originating with that
 * MAC address are matched. If the match criteria is destination MAC address,
 * packets destined to that MAC address are matched.
 *
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sal/driver.h>
#include <opennsl/error.h>
#include <opennsl/l2.h>
#include <opennsl/vlan.h>

#define DEFAULT_UNIT  0
#define DEFAULT_VLAN  1
#define MAX_DIGITS_IN_CHOICE 5

char example_usage[] =
"Syntax: example_l2_firewall                                           \n\r"
"                                                                      \n\r"
"Paramaters: None.                                                     \n\r"
"                                                                      \n\r"
"Example: The following command is used to allow or block station A    \n\r"
"and station D that are part of VLAN 1 with MAC addresses              \n\r"
"00:00:00:00:00:01 and 00:00:00:00:00:04 respectively.                 \n\r"
"         example_l2_firewall                                          \n\r"
"                                                                      \n\r"
"Usage Guidelines: None.                                               \n\r";

/*****************************************************************//**
 * \brief Block the given station MAC address in the given VLAN.
 *
 * \param mac       [IN]    802.3 MAC address
 * \param vlan      [IN]    VLAN ID
 *
 * \return OPENNSL_E_XXX     OpenNSL API return code
 ********************************************************************/
int example_l2_firewall_block_station(opennsl_mac_t mac, opennsl_vlan_t vlan)
{
  opennsl_error_t rv;
  opennsl_l2_addr_t addr;

  opennsl_l2_addr_t_init(&addr, mac, vlan);

  /* Set the static flag, discard flags */
  addr.flags = (OPENNSL_L2_STATIC | OPENNSL_L2_DISCARD_SRC |
      OPENNSL_L2_DISCARD_DST);

  rv = opennsl_l2_addr_add(DEFAULT_UNIT, &addr);

  return rv;
}

/*****************************************************************//**
 * \brief Unblock the given station MAC address in the given VLAN.
 *
 * \param mac      [IN]     802.3 MAC address
 * \param vlan     [IN]     VLAN ID
 *
 * \return OPENNSL_E_XXX     OpenNSL API return code
 ********************************************************************/
int example_l2_firewall_allow_station(opennsl_mac_t mac, opennsl_vlan_t vlan)
{
  opennsl_error_t rv;
  opennsl_l2_addr_t addr;

  /* Check whether the station exists in the firewall rules */
  rv = opennsl_l2_addr_get(DEFAULT_UNIT, mac, vlan, &addr);

  if (rv == OPENNSL_E_NONE) {
    rv = opennsl_l2_addr_delete(DEFAULT_UNIT, mac, vlan);
  }

  return rv;
}

/*****************************************************************//**
 * \brief Include all ports to default vlan
 *
 * \param unit   [IN]    unit number
 *
 * \return OPENNSL_E_XXX     OpenNSL API return code
 ********************************************************************/
int example_switch_default_vlan_config(int unit)
{
  opennsl_port_config_t pcfg;
  int rv;

  /*
   * Create VLAN with id DEFAULT_VLAN and
   * add ethernet ports to the VLAN
   */
  rv = opennsl_port_config_get(unit, &pcfg);
  if (rv != OPENNSL_E_NONE) {
    printf("Failed to get port configuration. Error %s\n", opennsl_errmsg(rv));
    return rv;
  }

  rv = opennsl_vlan_port_add(unit, DEFAULT_VLAN, pcfg.e, pcfg.e);
  if (rv != OPENNSL_E_NONE) {
    printf("Failed to add ports to VLAN. Error %s\n", opennsl_errmsg(rv));
    return rv;
  }

  return OPENNSL_E_NONE;
}

/**************************************************************************//**
 * \brief   Read numeric menu choice from user.
 *
 * \param   choice         [IN/OUT] choice
 *
 * \return  OPENNSL_E_xxx  OpenNSL API return code
 *****************************************************************************/
int example_read_user_choice(int *choice)
{
    char val;
    char digits[MAX_DIGITS_IN_CHOICE + 1];
    int idx = 0;
    int valid = TRUE;

    /* parse input string until \n */
    while((val = getchar()) != '\n')
    {
        if ((val >= '0' && val <= '9') && idx < MAX_DIGITS_IN_CHOICE)
        {
            digits[idx++] = val;
        }
        else
        {
            valid = FALSE;
        }
    }
    if ((valid == TRUE) && idx != 0)
    {
        digits[idx] = '\0';
        *choice = atoi(digits);
        return(OPENNSL_E_NONE);
    }
    else
    {
        *choice = -1;
        return(OPENNSL_E_FAIL);
    }
}

/*****************************************************************//**
 * \brief Main function for Layer2 firewall application
 *
 * \param argc, argv         commands line arguments
 *
 * \return OPENNSL_E_XXX     OpenNSL API return code
 ********************************************************************/
int main(int argc, char *argv[])
{
  opennsl_error_t   rv;
  opennsl_vlan_t vlan = 1;
  int choice;

  /* Example MAC address of stations A, B, C and D */
  opennsl_mac_t station_a = {0x00, 0x00, 0x00, 0x00, 0x00, 0x1};
  opennsl_mac_t station_d = {0x00, 0x00, 0x00, 0x00, 0x00, 0x4};

  if((argc != 1) || ((argc > 1) && (strcmp(argv[1], "--help") == 0))) {
    printf("%s\n\r", example_usage);
    return OPENNSL_E_PARAM;
  }

  /* Initialize the system. */
  printf("Initializing the system.\r\n");
  rv = opennsl_driver_init();

  if(rv != OPENNSL_E_NONE) {
    printf("\r\nFailed to initialize the system. Error %s\r\n",
        opennsl_errmsg(rv));
    return rv;
  }

  /* Add ports to default vlan. */
  printf("Adding ports to default vlan.\r\n");
  rv = example_switch_default_vlan_config(0);
  if(rv != OPENNSL_E_NONE) {
    printf("\r\nFailed to add default ports. rv: %d\r\n", rv);
    return rv;
  }

  while (1) {
    printf("\r\nUser menu: Select one of the following options\r\n");
    printf("1. Apply firewall\n");
    printf("2. Remove firewall\n");
    printf("9. Launch diagnostic shell\n");
    printf("0. Quit the application\n");

    if(example_read_user_choice(&choice) != OPENNSL_E_NONE)
    {
        printf("Invalid option entered. Please re-enter.\n");
        continue;
    }
    switch(choice){

      case 1:
      {
        /* Apply firewall rules to block station A and D */
        rv = example_l2_firewall_block_station(station_a, vlan);
        if (rv == OPENNSL_E_NONE) {
          printf("L2 firewall: station A blocked successfully\n");
        } else {
          printf("L2 firewall: failed to apply rule. Error %s\n",
                 opennsl_errmsg(rv));
          return rv;
        }

        rv = example_l2_firewall_block_station(station_d, vlan);
        if (rv == OPENNSL_E_NONE) {
          printf("L2 firewall rule: station D blocked successfully\n");
        } else {
          printf("L2 firewall: failed to apply rule. Error %s\n",
                 opennsl_errmsg(rv));
          return rv;
        }
        break;
      } /* End of case 1 */
      case 2:
      {
        /* Remove the firewall rules applied to station A and D */
        rv = example_l2_firewall_allow_station(station_a, vlan);
        if ((rv == OPENNSL_E_NONE) || (rv == OPENNSL_E_NOT_FOUND)) {
          printf("L2 firewall: station A un-blocked successfully\n");
        } else {
          printf("L2 firewall: failed to apply rule. Error %s\n",
                 opennsl_errmsg(rv));
          return rv;
        }

        rv = example_l2_firewall_allow_station(station_d, vlan);
        if ((rv == OPENNSL_E_NONE) || (rv == OPENNSL_E_NOT_FOUND)) {
          printf("L2 firewall rule: station D un-blocked successfully\n");
        }  else {
          printf("L2 firewall: failed to apply rule. Error %s\n",
                 opennsl_errmsg(rv));
          return rv;
        }
        break;
      } /* End of case 2 */
      case 9:
      {
        opennsl_driver_shell();
        break;
      }
      case 0:
      {
        printf("Exiting the application.\n");
        return OPENNSL_E_NONE;
      }
      default:
        break;
    } /* End of switch */
  } /* End of while */

  return OPENNSL_E_NONE;
}


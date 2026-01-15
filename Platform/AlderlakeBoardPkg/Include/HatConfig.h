/** @file
  HAT Configuration Definitions for SAGE

  Copyright (c) 2024, Vicharak Computers. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _HAT_CONFIG_H_
#define _HAT_CONFIG_H_

#include <Uefi/UefiBaseType.h>

#define MAX_PCIE_ROOT_PORTS 9 // Adjust based on N200 max root ports (usually 9 for ADL-N)
#define MAX_USB_PORTS       8 // Adjust based on N200 max USB ports

//
// HAT Configuration Structure
//
typedef struct {
  UINT8  HatId;
  // FSP-M Configs (Pre-Mem)
  UINT32 PcieRpEnableMask;         // Bitmask of enabled Root Ports
  // FSP-S Configs (Post-Mem)
  UINT8  PortUsb20Enable[MAX_USB_PORTS]; // 0: Disable, 1: Enable
  UINT8  PortUsb30Enable[MAX_USB_PORTS]; // 0: Disable, 1: Enable
  // Add other HSIO/MUX configurations here
} HAT_CONFIG;

//
// HAT Configuration Table
// User should populate this based on schematics!
//
HAT_CONFIG mHatConfigTable[] = {
  // HAT 1: 2x PCIe + 2x USB
  {
    .HatId = 0x01,
    .PcieRpEnableMask = 0x03, // Enable RP 0 and 1
    .PortUsb20Enable = {1, 1, 0, 0, 0, 0, 0, 0},
    .PortUsb30Enable = {1, 1, 0, 0, 0, 0, 0, 0}
  },
  // HAT 2: 4x USB
  {
    .HatId = 0x02,
    .PcieRpEnableMask = 0x00, // Disable all RPs (or minimal for base board)
    .PortUsb20Enable = {1, 1, 1, 1, 0, 0, 0, 0},
    .PortUsb30Enable = {1, 1, 1, 1, 0, 0, 0, 0}
  },
  // HAT 3: 4x PCIe x1
  {
    .HatId = 0x03,
    .PcieRpEnableMask = 0x0F, // Enable RP 0-3
    .PortUsb20Enable = {0, 0, 0, 0, 0, 0, 0, 0}, // Minimal/None
    .PortUsb30Enable = {0, 0, 0, 0, 0, 0, 0, 0}
  },
  // Default / No HAT
  {
    .HatId = 0x00,
    .PcieRpEnableMask = 0x01, // Default config
    .PortUsb20Enable = {1, 0, 0, 0, 0, 0, 0, 0},
    .PortUsb30Enable = {1, 0, 0, 0, 0, 0, 0, 0}
  }
};

#define HAT_CONFIG_COUNT (sizeof(mHatConfigTable) / sizeof(HAT_CONFIG))

//
// GUID for passing HAT ID from Pre-Mem to Post-Mem
//
extern EFI_GUID gHatIdHobGuid;

#endif // _HAT_CONFIG_H_

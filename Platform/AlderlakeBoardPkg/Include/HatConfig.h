/** @file
  HAT Configuration Definitions for SAGE

  Copyright (c) 2024, Vicharak Computers. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _HAT_CONFIG_H_
#define _HAT_CONFIG_H_

#pragma pack(1)

typedef struct {
  UINT8  HatId;
  UINT32 PcieRpEnableMask;
  UINT8  PortUsb20Enable[16];
  UINT8  PortUsb30Enable[10];
} HAT_CONFIG;

#pragma pack()

//
// GUID to pass HAT ID from FSP-M (Stage 1B) to FSP-S (Stage 2)
//
extern EFI_GUID gHatIdHobGuid;

#define HAT_CONFIG_COUNT 2

//
// Example Configuration Table - TO BE POPULATED BY USER
//
static HAT_CONFIG mHatConfigTable[HAT_CONFIG_COUNT] = {
  // HAT ID 1: Example PCIe HAT
  {
    .HatId = 1,
    .PcieRpEnableMask = 0x0F, // Enable first 4 Root Ports
    .PortUsb20Enable = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    .PortUsb30Enable = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}
  },
  // HAT ID 2: Example USB HAT
  {
    .HatId = 2,
    .PcieRpEnableMask = 0x01, // Enable only Root Port 0
    .PortUsb20Enable = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    .PortUsb30Enable = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}
  }
};

//
// GUID Definition
//
EFI_GUID gHatIdHobGuid = { 0x12345678, 0x1234, 0x1234, { 0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF } };

#endif // _HAT_CONFIG_H_

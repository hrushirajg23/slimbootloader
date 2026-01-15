/** @file
  GPIO definition table for SAGE (Alder Lake-N)

  Copyright (c) 2023, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _GPIO_TABLE_SAGE_PRE_MEM_H_
#define _GPIO_TABLE_SAGE_PRE_MEM_H_

#include <GpioPinsVer2Lp.h>

GPIO_INIT_CONFIG mGpioTableSagePreMem[] =
{
  //
  // UART0 Debug (Verify with Schematic!)
  // GPP_E0 = RXD
  // GPP_E1 = TXD
  //
  {GPIO_VER2_LP_GPP_H10, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset,  GpioTermNone}},
  {GPIO_VER2_LP_GPP_H11, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset,  GpioTermNone}},

  //
  // I2C Controller for HAT detection (Assuming I2C0 for now - Verify!)
  // GPP_B13 = I2C0_SCL
  // GPP_B14 = I2C0_SDA
  //
  {GPIO_VER2_LP_GPP_H5, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset,  GpioTermNone}},
  {GPIO_VER2_LP_GPP_H4, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone, GpioOutDefault, GpioIntDis, GpioPlatformReset,  GpioTermNone}},

  //
  // Add other critical GPIOs here (PMIC, etc.)
  //
};

#endif // _GPIO_TABLE_SAGE_PRE_MEM_H_

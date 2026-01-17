# SBL Configuration for B2B Connector (Intel Recommended)

Intel recommends a **platform-ID–based configuration approach** for Slim Bootloader (SBL), especially when supporting multiple B2B HAT variants.

---

## Platform ID and UPD Selection

- Each platform has a **unique Platform ID**
- Based on this ID, the corresponding **UPD (UPD configuration)** is loaded at boot time

---

## Configuration Files Overview

SBL platform configuration is generally defined using two types of files:

### 1. YAML Files
- Contain **default platform settings**
- **Not recommended to modify**
- Act as the baseline configuration

### 2. DLT (Delta) Files
- Used to **override or customize** YAML defaults
- Recommended place for **platform-specific changes**

---

## HAT-Based Configuration Strategy

- Each **HAT configuration** will have:
  - Its **own `.dlt` file**
  - A **unique Platform / Board ID**

### Examples

- `usb2pcie2.dlt`
  - Platform ID: `0x001`
- `usb4.dlt`
  - Platform ID: `0x002`

Each Platform ID:
- Is defined inside the respective `.dlt` file
- Must be **stored on the HAT controller**

---

## Runtime Platform Detection

- At boot, SBL will:
  1. Query the HAT controller via **I2C**
  2. Read the **Platform ID**
  3. Load the corresponding `.dlt` configuration

---

## Build Integration

- All `.dlt` files must be added to:
  - `BoardConfigXX.py`
- During build:
  - SBL compiles all configurations into a **single firmware image**

### Output Image
- `FwuImage.bin`

---

## Summary

This approach allows:
- A single SBL image to support **multiple B2B HATs**
- Clean separation between **default settings** and **platform-specific overrides**
- Scalable support for future HAT variants


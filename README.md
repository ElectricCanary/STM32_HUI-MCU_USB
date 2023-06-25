# STM32_HUI-MCU_USB

This is a USB class compliant HUI/MCU interface for the STM32F411 "Blackpill".

The .elf file allows to test on a board without having to compile the project yourself.

You can use the functions in "protocol" for different action without worrying about the HUI/MCU differences. A simple function allows the interface to detect HUI or Mackie Control Universal on plug-in. All track names, VU Meters states, select, mute, solo are stocked in arrays.

The USB function is herited from the [STM32-USB-MIDI](https://github.com/ElectricCanary/STM32-USB-MIDI) project.

## Device Configuration Tool

If you're using the Device Configuration Tool and want to keep the USB feature, you must **leave active** the **"USB_OTG_FS"** under "Connectivity" and the **"USB_DEVICE"** under "Middleware".

Once the code is generated, you must **delete** the folders : **"Middlewares"** and **"USB_DEVICE"**. They are not needed since the whole USB interface is already in the "Core" folder.

You'll also need to **delete** the **" #include "usb_interface.h" "** at the beginning of "main.c" (line 22).

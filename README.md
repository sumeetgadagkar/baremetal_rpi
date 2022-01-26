# Baremetal drivers for the Raspberry-PI 3
This projects aims to implement drivers for all the peripherals on the raspberry pi 3 (using the 64 bit architecture) and provide a level of abstraction for other projects that need access to these drivers. 

# Toolchain
[GNU x86_64 Linux hosted AArch64 ELF bare-metal target (aarch64-none-elf) cross compiler Version 10.3-2021.07](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-a/downloads)

1. Download the toolchain
2. Extract it
3. Rename the folder to "`gcc-arm-aarch64-none-elf`"
4. Place it under "`baremetal_rpi`" folder

# Emulation
For basic emulation of the raspi3 we will use [QEMU 6.2.0](https://www.qemu.org/) (QEMU is not oficially supported on windows)
Note - Install QEMU dependecies before building:
    ```
    sudo apt install -y make gcc libglib2.0-dev libpixman-1-dev git-all
    sudo apt install -y ninja-build
    ```
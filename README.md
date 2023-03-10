This is the repository for my adventures using an RTOS and Libopencm3 for an STM32 microprocessor.

# Requrirements
 1. make
 2. pyhon
 3. arm-none-eabi
 4. stlink-tools

# Instructions
 1. Make sure the required packages are installed
 1. git clone --recurse-submodules https://github.com/libopencm3/libopencm3-template.git your-project
 2. cd your-project
 3. make -C libopencm3 # (Only needed once)
 4. make -C my-project

If you have an older git, or got ahead of yourself and skipped the ```--recurse-submodules```
you can fix things by running ```git submodule update --init``` (This is only needed once)

# Directories
* my-project contains my main application
* libopencm3 contains the libopencm3 repo as a submodule
* rtos contains the rtos files used in this project. (This can maybe be packaged as a submodule, not sure)


# EFM8 SDCC makefiles

Simple makefiles and examples for using the EFM8 series of microcontrollers
with SDCC.

## Example projects

* blink: blinks LEDs on pins P2.2 and P2.3.


## Usage

### Building

Copy one of the example projects, then simply place your source code inside
the `src` directory and add your code to the `C_SRC` variable inside the
makefile. You can then run `make` to build your code.

To provide multiple variations of a projects for different boards/mcu, you
can use the `boards` directory to make different targets. By default, the
makefile will use the `boards/default` target. If you want to make another
targets create a new directory in the `boards` folder and make a `config.mk`
file inside of it with the settings for that build.

To build different board targets, you can call make and set the `BORADS`
variable:

```sh
make BOARD=default
```

### Programming

To program you can use Silicon Labs USB debug adapter. You can buy this from
digikey/mouser for about 35$, or from ebay/aliexpress for about 10$.

To use the command line tools to flash hex files, you will first need to [download
Simplicity Studio](https://www.silabs.com/products/development-tools/software/simplicity-studio). Then from simplicity studio install the 8051 toolchain and flashing devices.
Once installed, you will need to provide the makefiles with the path where you
installed Simplicity Studio, for example:

```makefile
# Inside makefile
SIMPLICITY_STUDIO_PATH = $(HOME)/local/simplicity_studio/SimplicityStudio_v4
```

You should then be able to use the targets provided by the makefiles to
flash from the command line. First to list the connected devices use the
`program-list` target:

```sh
$ make program-list
deviceCount = 1
device (EC3005481E8) {
  adapterLabel = USB Debug Adapter
  SerialNo = EC3005481E8
  targetInterface = c2
  Name = EFM8UB20F32G-QFP32
  Type = MCU
  Family = 8051
  HardwareID = 0x28
  DerivativeID = 0x64
  HardwareRev = 0x0
  DerivativeRev = 0x6
  Unsupported = 0
  Indeterminate = 0
  Connected = 0
  Locked = 0
}
```

From this listing you can see the serial numbers of the connected devices,
`EC3005481E8` in this example. Once you know the serial number, you can use
the `program-efm8` target to flash it:

```sh
make program-efm8 SERIAL_NUM=EC3005481E8
```

## Documentation

### Datasheet

* [C8051F38x](https://www.silabs.com/documents/public/data-sheets/C8051F38x.pdf)
* [efm8ub1](https://www.silabs.com/documents/public/data-sheets/efm8ub1-datasheet.pdf)
* [efm8ub2](https://www.silabs.com/documents/public/data-sheets/efm8ub2-datasheet.pdf)
* [efm8ub3](https://www.silabs.com/documents/public/data-sheets/efm8ub3-datasheet.pdf)

### Reference manuals

* [efm8ub1](https://www.silabs.com/documents/public/reference-manuals/EFM8UB1-RM.pdf)
* [efm8ub2](https://www.silabs.com/documents/public/reference-manuals/EFM8UB2-RM.pdf)
* [efm8ub3](https://www.silabs.com/documents/public/reference-manuals/efm8ub3-reference-manual.pdf)

## Dev tools

* https://www.silabs.com/products/development-tools/software/simplicity-studio

## Programmer code for C2 interface (arduino based):

* https://github.com/x893/C2.Flash
* https://github.com/lhartmann/c2_prog_wifi/blob/master/arduino_libs/c2_prog/c2.cpp
* https://www.silabs.com/documents/public/application-notes/AN127.pdf

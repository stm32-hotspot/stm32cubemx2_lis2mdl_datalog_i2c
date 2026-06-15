# __Example: *lis2mdl_datalog_i2c*__


How to use part LIS2MDL API.

It illustrates it by getting the values of the magnetometer (in mGauss) and displaying them on a HyperTerminal.


## __1. Detailed scenario__

__Initialization phase__: At the beginning of the `main()` function, the `mx_system_init()` function is called to initialize the peripherals.

The application executes the following __example steps__:

__Step 1__: Initializes and enables magnetometer feature of LIS2MDL.

__Step 2__: Gets the measurements of the magnetometer and displays them on a terminal.

__End of example__: It is an endless example that loops infinitely on step 2.

You can follow these execution steps in the terminal logs:
```text
[INFO] Step 1: LIS2MDL sensor init completed
[INFO] Step 1: Enabling MAG feature completed
[INFO] Step 2: MAG X=-1224 Y=730 Z=-916
```


## __2. Example configuration__


This example demonstrates the following driver:

- Part lis2mdl.c/.h
- Part lis2mdl/interfaces/i2c/lis2mdl_io.c/.h


In this example, the LIS2MDL component is configured through the I2C IO operations defined under the interfaces/i2c folder.
Once the I2C is initialized, the LIS2MDL can be initialized too through the call of lis2mdl_drv_init() API.
After this step, the MEMS sensor will be ready to provide the values of the magnetometer.


## __3. Hardware environment and setup__

### __3.1. Generic Setup__

This section describes the hardware setup principles that apply to any board.

### __3.2. Specific board setups__

<details>
<summary>On STM32C5 series.</summary>
  <summary>On board NUCLEO-C562RE.</summary>

  | Board connector | MCU pin | Signal name | ARDUINO <br> connector pin |
  | :-------------: | :-----: | :---------: | :------------------------: |
  |      CN5-10     |   PB6   |  I2C1_SCL   |  ARDUINO CONNECTOR - D15   |
  |      CN5-9      |   PB7   |  I2C1_SDA   |  ARDUINO CONNECTOR - D14   |

</details>

## __4. Software setup__

To create a functional project, complete the following steps:
- Select the appropriate IoC2 file based on the combination of NUCLEO and X-NUCLEO boards. For example, use c562re_iks4a1_lis2mdl_datalog_i2c.ioc2 for NUCLEO-C562RE and X-NUCLEO-IKS4A1.
- Open the IoC2 file with STM32CubeMX2.
- Select the preferred toolchain and generate the source code.
- Copy the main.c, main.h, example.c, and example.h files into the project folder of the generated code.
- Open the Integrated Development Environment (IDE), add the example.c and example.h files to the project.
- Add the USE_TRACE=1 to the global variables of the project.
- Compile the project.

## __5. Troubleshooting__

No specific debug tips.


## __6. See Also__

More information about LIS2MDL part driver can be found in the [LIS2MDL Part Driver](https://dev.st.com/stm32cube-docs/part-drivers-lis2mdl/1.0.0/en/index.html)

More information about the STM32 ecosystem can be found in the [STM32 MCU Developer Zone](https://www.st.com/content/st_com/en/stm32-mcu-developer-zone.html).


## __7. License__

Copyright (c) 2026 STMicroelectronics.

This software is licensed under terms that can be found in the LICENSE file in the root directory
of this software component.
If no LICENSE file comes with this software, it is provided AS-IS.



/**
  ******************************************************************************
  * file           : example.c
  * brief          : example program body
  ******************************************************************************
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "example.h"
#include "lis2mdl.h"
#include "stdio.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private variables */
lis2mdl_object_t *pLis2mdl0; /* pointer referencing the LIS2MDL object instance */
lis2mdl_axes_t data;

/** ########## Step 1 ##########
  * The init of LIS2MDL is triggered by the applicative code
  */

app_status_t app_init(void)
{
  app_status_t return_status = EXEC_STATUS_ERROR;
  /* Retrieve and store the LIS2MDL object pointer */
  pLis2mdl0 = MX_LIS2MDL_getobject();
  /* Initialize the LIS2MDL device 0 */
  if (lis2mdl_drv_init(pLis2mdl0, MX_LIS2MDL) != 0)
  {
    PRINTF("[ERROR] Step 1: LIS2MDL sensor init error\n");
    goto _app_init_exit;
  }
  PRINTF("[INFO] Step 1: LIS2MDL sensor init completed\n");


  /* LIS2MDL device 0: enable the magnetometer feature */
  if (lis2mdl_drv_enable(pLis2mdl0) != 0)
  {
    PRINTF("[ERROR] Step 1: Enabling the MAG feature error\n");
    goto _app_init_exit;
  }
  PRINTF("[INFO] Step 1: Enabling MAG feature completed\n");

  return_status = EXEC_STATUS_INIT_OK;

_app_init_exit:
  return return_status;
}

/** ########## Step 2 ##########
  * Gets the values of the magnetometer.
  * The values are displayed on the terminal.
  * output: EXEC_STATUS_OK if OK, EXEC_STATUS_ERROR in case of error
  */

app_status_t app_process(void)
{
  app_status_t return_status = EXEC_STATUS_ERROR;

  /* LIS2MDL device 0: get the magnetometer value and print it */
  if (lis2mdl_drv_get_axes(pLis2mdl0, &data) != 0)
  {
    PRINTF("[ERROR] Step 2: Reading magnetometer error\n");
    goto _app_process_exit;
  }
  PRINTF("[INFO] Step 2: MAG X=%" PRIi32 " Y=%" PRIi32 " Z=%" PRIi32 "\n",
         (int32_t)data.x_axis, (int32_t)data.y_axis, (int32_t)data.z_axis);

  return_status = EXEC_STATUS_OK;

_app_process_exit:
  return return_status;
}

/** ########## Step 3 ##########
  * In this example, app_deinit is never called and is provided as a reference only.
  */

app_status_t app_deinit(void)
{
  lis2mdl_drv_deinit(pLis2mdl0);

  return EXEC_STATUS_OK;
}

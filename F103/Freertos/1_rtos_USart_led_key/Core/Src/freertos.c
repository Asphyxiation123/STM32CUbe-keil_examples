/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "key_led.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for led0_on_and_off */
osThreadId_t led0_on_and_offHandle;
const osThreadAttr_t led0_on_and_off_attributes = {
  .name = "led0_on_and_off",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for led1taskk02 */
osThreadId_t led1taskk02Handle;
const osThreadAttr_t led1taskk02_attributes = {
  .name = "led1taskk02",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void led_task1(void *argument);
void led_task2(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of led0_on_and_off */
  led0_on_and_offHandle = osThreadNew(led_task1, NULL, &led0_on_and_off_attributes);

  /* creation of led1taskk02 */
  led1taskk02Handle = osThreadNew(led_task2, NULL, &led1taskk02_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_led_task1 */
/**
  * @brief  Function implementing the led0_on_and_off thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_led_task1 */
void led_task1(void *argument)
{
  /* USER CODE BEGIN led_task1 */
  /* Infinite loop */
  for(;;)
  {
		led0_on();
		HAL_Delay(500);
		led0_off();
		HAL_Delay(500);
		
    osDelay(1);
  }
  /* USER CODE END led_task1 */
}

/* USER CODE BEGIN Header_led_task2 */
/**
* @brief Function implementing the led1taskk02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_led_task2 */
void led_task2(void *argument)
{
  /* USER CODE BEGIN led_task2 */
  /* Infinite loop */
  for(;;)
  {
		led1_on();
		HAL_Delay(1000);
		led1_off();
		HAL_Delay(1000);
    osDelay(1);
  }
  /* USER CODE END led_task2 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */


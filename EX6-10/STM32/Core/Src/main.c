/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <math.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
enum LedState { RED_STATE , YELLOW_STATE , GREEN_STATE } ;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define LEDS_NUMBER 12
#define SECOND 1000
#define LAST_LEDS_ARR_INDEX 11
#define LED_STATE_LEVEL 5
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int leds_array[LEDS_NUMBER] = {LED_A_Pin,LED_B_Pin,LED_C_Pin,LED_D_Pin,LED_E_Pin,LED_F_Pin,LED_G_Pin,LED_H_Pin,LED_I_Pin,LED_J_Pin,LED_K_Pin,LED_L_Pin};
void clearAllClock(){
	for(int i = 0; i < LEDS_NUMBER; i++){
		HAL_GPIO_WritePin(GPIOA, leds_array[i], GPIO_PIN_SET);
	}
}

void setNumberOnClock(int num){
	HAL_GPIO_WritePin(GPIOA, leds_array[num], GPIO_PIN_RESET);
}

void clearNumberOnClock(int num){
	HAL_GPIO_WritePin(GPIOA, leds_array[num], GPIO_PIN_SET);
}

void formatClock(int* second, int* min, int* hour){
   //Format numbers
   if(*second == 59){
	   *second = 0;
	   clearNumberOnClock(LAST_LEDS_ARR_INDEX);
	   if(*min == 59){
		   *min = 0;
		   clearNumberOnClock(*hour%LEDS_NUMBER);
		   (*hour)++;
	   }else (*min)++;
   }else (*second)++;

   if(*hour >= 24) *hour = 0;

   //Format display
   if(*second != 0 && *second % LED_STATE_LEVEL == 0){
	   clearNumberOnClock(floor(*second/LED_STATE_LEVEL)-1);
   }
   if(*min != 0 && *min % LED_STATE_LEVEL == 0){
		   clearNumberOnClock(floor(*min/LED_STATE_LEVEL)-1);
	   }
}
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


  int led_index = 0;
  clearAllClock();

  //For Ex10
  int hour = 1;
  int minute = 59;
  int second = 50;
  while (1)
  {
////	   	   Testing Ex6:
//	   	   HAL_GPIO_WritePin(GPIOA, leds_array[led_index], GPIO_PIN_RESET);
//		   led_index = (led_index + 1);
//		   HAL_Delay(SECOND);
//
////	 	   Testing Ex8:
	 	   setNumberOnClock(4);
	 	   HAL_Delay(SECOND);

//
////	   	   Testing Ex9:
//		   setNumberOnClock(4);
//		   HAL_Delay(SECOND);
//		   clearNumberOnClock(4);
//		   HAL_Delay(SECOND);
//
//
////	      Testing Ex10:
//		  setNumberOnClock(hour % LEDS_NUMBER);
//		  setNumberOnClock((int)floor(minute / LED_STATE_LEVEL));
//		  setNumberOnClock((int)floor(second / LED_STATE_LEVEL));
//
//		  HAL_Delay(SECOND);
//		  formatClock(&second, &minute, &hour);


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_B_Pin|LED_C_Pin|LED_D_Pin
                          |LED_E_Pin|LED_F_Pin|LED_G_Pin|LED_H_Pin
                          |LED_I_Pin|LED_J_Pin|LED_K_Pin|LED_L_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_A_Pin LED_B_Pin LED_C_Pin LED_D_Pin
                           LED_E_Pin LED_F_Pin LED_G_Pin LED_H_Pin
                           LED_I_Pin LED_J_Pin LED_K_Pin LED_L_Pin */
  GPIO_InitStruct.Pin = LED_A_Pin|LED_B_Pin|LED_C_Pin|LED_D_Pin
                          |LED_E_Pin|LED_F_Pin|LED_G_Pin|LED_H_Pin
                          |LED_I_Pin|LED_J_Pin|LED_K_Pin|LED_L_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

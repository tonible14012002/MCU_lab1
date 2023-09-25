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
#include <stdbool.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
enum LedState { RED_STATE , YELLOW_STATE , GREEN_STATE } ;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SECOND 1000
#define TOTAL_STATES 3
#define THRESHOLD_COUNTDOWN 1
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

void displayFirstLedCouple(enum LedState state_1){
	switch(state_1){
	 case RED_STATE:
			 HAL_GPIO_WritePin( FIRST_COUPLE_GREEN_GPIO_Port , FIRST_COUPLE_GREEN_Pin , 1) ;
			 HAL_GPIO_WritePin( FIRST_COUPLE_YELLOW_GPIO_Port , FIRST_COUPLE_YELLOW_Pin , 1 ) ;
			 HAL_GPIO_WritePin( FIRST_COUPLE_RED_GPIO_Port , FIRST_COUPLE_RED_Pin , 0 ) ;
			 break;
	 case YELLOW_STATE:
			 HAL_GPIO_WritePin( FIRST_COUPLE_GREEN_GPIO_Port , FIRST_COUPLE_GREEN_Pin , 1) ;
			 HAL_GPIO_WritePin( FIRST_COUPLE_YELLOW_GPIO_Port , FIRST_COUPLE_YELLOW_Pin , 0 ) ;
			 HAL_GPIO_WritePin( FIRST_COUPLE_RED_GPIO_Port , FIRST_COUPLE_RED_Pin , 1 ) ;
			 break;
	 case GREEN_STATE:
			 HAL_GPIO_WritePin( FIRST_COUPLE_GREEN_GPIO_Port , FIRST_COUPLE_GREEN_Pin , 0) ;
			 HAL_GPIO_WritePin( FIRST_COUPLE_YELLOW_GPIO_Port , FIRST_COUPLE_YELLOW_Pin , 1 ) ;
			 HAL_GPIO_WritePin( FIRST_COUPLE_RED_GPIO_Port , FIRST_COUPLE_RED_Pin , 1 ) ;
			 break;
	 default:
		 break;
	}
}

void displaySecondLedCouple(enum LedState state_2){
	switch(state_2){
		case RED_STATE:
			HAL_GPIO_WritePin( SECOND_COUPLE_GREEN_GPIO_Port , SECOND_COUPLE_GREEN_Pin , 1) ;
			HAL_GPIO_WritePin( SECOND_COUPLE_YELLOW_GPIO_Port , SECOND_COUPLE_YELLOW_Pin , 1 ) ;
			HAL_GPIO_WritePin( SECOND_COUPLE_RED_GPIO_Port , SECOND_COUPLE_RED_Pin , 0 ) ;
			break;
		case YELLOW_STATE:
			HAL_GPIO_WritePin( SECOND_COUPLE_GREEN_GPIO_Port , SECOND_COUPLE_GREEN_Pin , 1) ;
			HAL_GPIO_WritePin( SECOND_COUPLE_YELLOW_GPIO_Port , SECOND_COUPLE_YELLOW_Pin , 0 ) ;
			HAL_GPIO_WritePin( SECOND_COUPLE_RED_GPIO_Port , SECOND_COUPLE_RED_Pin , 1 ) ;
			break;
		case GREEN_STATE:
			HAL_GPIO_WritePin( SECOND_COUPLE_GREEN_GPIO_Port , SECOND_COUPLE_GREEN_Pin , 0) ;
			HAL_GPIO_WritePin( SECOND_COUPLE_YELLOW_GPIO_Port , SECOND_COUPLE_YELLOW_Pin , 1 ) ;
			HAL_GPIO_WritePin( SECOND_COUPLE_RED_GPIO_Port , SECOND_COUPLE_RED_Pin , 1 ) ;
			break;
		default:
		  break;
   }
}

void display7SEG_1(int num){
  switch(num){
    case 0:
        HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_C1_GPIO_Port , SEG_C1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_D1_GPIO_Port , SEG_D1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_E1_GPIO_Port , SEG_E1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_F1_GPIO_Port , SEG_F1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_G1_GPIO_Port , SEG_G1_Pin , 1 ) ;
        break;

    case 1:
        HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin , 1 ) ;
        HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_C1_GPIO_Port , SEG_C1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_D1_GPIO_Port , SEG_D1_Pin , 1 ) ;
        HAL_GPIO_WritePin ( SEG_E1_GPIO_Port , SEG_E1_Pin , 1 ) ;
        HAL_GPIO_WritePin ( SEG_F1_GPIO_Port , SEG_F1_Pin , 1 ) ;
        HAL_GPIO_WritePin ( SEG_G1_GPIO_Port , SEG_G1_Pin , 1 ) ;
        break;

    case 2:
        HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_C1_GPIO_Port , SEG_C1_Pin , 1 ) ;
        HAL_GPIO_WritePin ( SEG_D1_GPIO_Port , SEG_D1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_E1_GPIO_Port , SEG_E1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_F1_GPIO_Port , SEG_F1_Pin , 1 ) ;
        HAL_GPIO_WritePin ( SEG_G1_GPIO_Port , SEG_G1_Pin , 0 ) ;
        break;

    case 3:
        HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_C1_GPIO_Port , SEG_C1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_D1_GPIO_Port , SEG_D1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_E1_GPIO_Port , SEG_E1_Pin , 1 ) ;
        HAL_GPIO_WritePin ( SEG_F1_GPIO_Port , SEG_F1_Pin , 1 ) ;
        HAL_GPIO_WritePin ( SEG_G1_GPIO_Port , SEG_G1_Pin , 0 ) ;
        break;

    case 4:
        HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin , 1 ) ;
        HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_C1_GPIO_Port , SEG_C1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_D1_GPIO_Port , SEG_D1_Pin , 1 ) ;
        HAL_GPIO_WritePin ( SEG_E1_GPIO_Port , SEG_E1_Pin , 1 ) ;
        HAL_GPIO_WritePin ( SEG_F1_GPIO_Port , SEG_F1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_G1_GPIO_Port , SEG_G1_Pin , 0 ) ;
        break;
    case 5:
        HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin , 1 ) ;
        HAL_GPIO_WritePin ( SEG_C1_GPIO_Port , SEG_C1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_D1_GPIO_Port , SEG_D1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_E1_GPIO_Port , SEG_E1_Pin , 1 ) ;
        HAL_GPIO_WritePin ( SEG_F1_GPIO_Port , SEG_F1_Pin , 0 ) ;
        HAL_GPIO_WritePin ( SEG_G1_GPIO_Port , SEG_G1_Pin , 0 ) ;
        break;

    default:
      break;
  }
}

  void display7SEG_2(int num){
    switch(num){
      case 0:
		  HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin , 0 ) ;
		  HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin , 0 ) ;
		  HAL_GPIO_WritePin ( SEG_C2_GPIO_Port , SEG_C2_Pin , 0 ) ;
		  HAL_GPIO_WritePin ( SEG_D2_GPIO_Port , SEG_D2_Pin , 0 ) ;
		  HAL_GPIO_WritePin ( SEG_E2_GPIO_Port , SEG_E2_Pin , 0 ) ;
		  HAL_GPIO_WritePin ( SEG_F2_GPIO_Port , SEG_F2_Pin , 0 ) ;
		  HAL_GPIO_WritePin ( SEG_G2_GPIO_Port , SEG_G2_Pin , 1 ) ;
		  break;

      case 1:
          HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin , 1 ) ;
          HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin , 0 ) ;
          HAL_GPIO_WritePin ( SEG_C2_GPIO_Port , SEG_C2_Pin , 0 ) ;
          HAL_GPIO_WritePin ( SEG_D2_GPIO_Port , SEG_D2_Pin , 1 ) ;
          HAL_GPIO_WritePin ( SEG_E2_GPIO_Port , SEG_E2_Pin , 1 ) ;
          HAL_GPIO_WritePin ( SEG_F2_GPIO_Port , SEG_F2_Pin , 1 ) ;
          HAL_GPIO_WritePin ( SEG_G2_GPIO_Port , SEG_G2_Pin , 1 ) ;
          break;

      case 2:
          HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin , 0 ) ;
          HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin , 0 ) ;
          HAL_GPIO_WritePin ( SEG_C2_GPIO_Port , SEG_C2_Pin , 1 ) ;
          HAL_GPIO_WritePin ( SEG_D2_GPIO_Port , SEG_D2_Pin , 0 ) ;
          HAL_GPIO_WritePin ( SEG_E2_GPIO_Port , SEG_E2_Pin , 0 ) ;
          HAL_GPIO_WritePin ( SEG_F2_GPIO_Port , SEG_F2_Pin , 1 ) ;
          HAL_GPIO_WritePin ( SEG_G2_GPIO_Port , SEG_G2_Pin , 0 ) ;
          break;

      case 3:
          HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin , 0 ) ;
          HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin , 0 ) ;
          HAL_GPIO_WritePin ( SEG_C2_GPIO_Port , SEG_C2_Pin , 0 ) ;
          HAL_GPIO_WritePin ( SEG_D2_GPIO_Port , SEG_D2_Pin , 0 ) ;
          HAL_GPIO_WritePin ( SEG_E2_GPIO_Port , SEG_E2_Pin , 1 ) ;
          HAL_GPIO_WritePin ( SEG_F2_GPIO_Port , SEG_F2_Pin , 1 ) ;
          HAL_GPIO_WritePin ( SEG_G2_GPIO_Port , SEG_G2_Pin , 0 ) ;
          break;

      case 4:
          HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin , 1 ) ;
          HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin , 0 ) ;
          HAL_GPIO_WritePin ( SEG_C2_GPIO_Port , SEG_C2_Pin , 0 ) ;
          HAL_GPIO_WritePin ( SEG_D2_GPIO_Port , SEG_D2_Pin , 1 ) ;
          HAL_GPIO_WritePin ( SEG_E2_GPIO_Port , SEG_E2_Pin , 1 ) ;
          HAL_GPIO_WritePin ( SEG_F2_GPIO_Port , SEG_F2_Pin , 0 ) ;
          HAL_GPIO_WritePin ( SEG_G2_GPIO_Port , SEG_G2_Pin , 0 ) ;
          break;
      case 5:
		  HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin , 0 ) ;
		  HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin , 1 ) ;
		  HAL_GPIO_WritePin ( SEG_C2_GPIO_Port , SEG_C2_Pin , 0 ) ;
		  HAL_GPIO_WritePin ( SEG_D2_GPIO_Port , SEG_D2_Pin , 0 ) ;
		  HAL_GPIO_WritePin ( SEG_E2_GPIO_Port , SEG_E2_Pin , 1 ) ;
		  HAL_GPIO_WritePin ( SEG_F2_GPIO_Port , SEG_F2_Pin , 0 ) ;
		  HAL_GPIO_WritePin ( SEG_G2_GPIO_Port , SEG_G2_Pin , 0 ) ;
		  break;
      default:
        break;

    }
  }


int countdown_of_leds[TOTAL_STATES] = {5,2,3}; //countdown time of RED_STATE, YELLOW_STATE, GREEN_STATE respectively

void changeLedState(int *countdown, int *countdown_state){
	 if(*countdown == THRESHOLD_COUNTDOWN){
			  if(*countdown_state != RED_STATE) *countdown_state = TOTAL_STATES % *countdown_state;
			  else *countdown_state = GREEN_STATE;

			  *countdown = countdown_of_leds[*countdown_state];
	 }
	 else (*countdown)--;
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


  int countdown_1_state = GREEN_STATE; //countdown state for first couple of traffic lights
  int countdown_2_state = RED_STATE; //countdown state for second couple of traffic lights
  int countdown_1 = countdown_of_leds[countdown_1_state]; //countdown time for first couple of traffic lights
  int countdown_2 = countdown_of_leds[countdown_2_state]; //countdown time for second couple of traffic lights

  while (1)
  {
	  displayFirstLedCouple(countdown_1_state);
	  displaySecondLedCouple(countdown_2_state);

	  display7SEG_1(countdown_1);
	  display7SEG_2(countdown_2);

	  changeLedState(&countdown_1, &countdown_1_state);
	  changeLedState(&countdown_2, &countdown_2_state);

	  HAL_Delay(SECOND);
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
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, FIRST_COUPLE_RED_Pin|FIRST_COUPLE_YELLOW_Pin|FIRST_COUPLE_GREEN_Pin|SECOND_COUPLE_RED_Pin
                          |SECOND_COUPLE_YELLOW_Pin|SECOND_COUPLE_GREEN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG_A1_Pin|SEG_B1_Pin|SEG_C1_Pin|SEG_C2_Pin
                          |SEG_D2_Pin|SEG_E2_Pin|SEG_F2_Pin|SEG_G2_Pin
                          |SEG_D1_Pin|SEG_E1_Pin|SEG_F1_Pin|SEG_G1_Pin
                          |SEG_A2_Pin|SEG_B2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : FIRST_COUPLE_RED_Pin FIRST_COUPLE_YELLOW_Pin FIRST_COUPLE_GREEN_Pin SECOND_COUPLE_RED_Pin
                           SECOND_COUPLE_YELLOW_Pin SECOND_COUPLE_GREEN_Pin */
  GPIO_InitStruct.Pin = FIRST_COUPLE_RED_Pin|FIRST_COUPLE_YELLOW_Pin|FIRST_COUPLE_GREEN_Pin|SECOND_COUPLE_RED_Pin
                          |SECOND_COUPLE_YELLOW_Pin|SECOND_COUPLE_GREEN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG_A1_Pin SEG_B1_Pin SEG_C1_Pin SEG_C2_Pin
                           SEG_D2_Pin SEG_E2_Pin SEG_F2_Pin SEG_G2_Pin
                           SEG_D1_Pin SEG_E1_Pin SEG_F1_Pin SEG_G1_Pin
                           SEG_A2_Pin SEG_B2_Pin */
  GPIO_InitStruct.Pin = SEG_A1_Pin|SEG_B1_Pin|SEG_C1_Pin|SEG_C2_Pin
                          |SEG_D2_Pin|SEG_E2_Pin|SEG_F2_Pin|SEG_G2_Pin
                          |SEG_D1_Pin|SEG_E1_Pin|SEG_F1_Pin|SEG_G1_Pin
                          |SEG_A2_Pin|SEG_B2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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

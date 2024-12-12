/*
 * fsmfortraffic.c
 *
 *  Created on: Dec 11, 2024
 *      Author: ADMIN
 */


#include "fsmfortraffic.h"

int status = 0;
int timeForGreen = 5000;
int timeForYellow = 3000;
int timeForRed = 8000;
int timeForGreen_tmp;
int timeForYellow_tmp;
int timeForRed_tmp;
void FsmForTrafficLight (void){
	switch (status){
	case INIT:
		status = RED1_GREEN2;
		setTimer(timeForGreen, 0);
		break;
	case RED1_GREEN2:
		value2 = timer_counter[0];
		value1 = timer_counter[0] + timeForYellow/10;
		HAL_GPIO_WritePin(RED_LIGHT_1_GPIO_Port, RED_LIGHT_1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_LIGHT_1_GPIO_Port, YELLOW_LIGHT_1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LIGHT_1_GPIO_Port, GREEN_LIGHT_1_Pin, RESET);

		HAL_GPIO_WritePin(RED_LIGHT_2_GPIO_Port, RED_LIGHT_2_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_LIGHT_2_GPIO_Port, YELLOW_LIGHT_2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LIGHT_2_GPIO_Port, GREEN_LIGHT_2_Pin, SET);
		if(timer_flag[0] == 1){
			status = RED1_YELLOW2;
			setTimer(timeForYellow, 0);
		}
		if (isButtonPressed(0)){
			status = RED_LIGHT_CONFIG;
			clearAllLight();
			value1 = 0;
			value2 = 0;
			setTimer(500, 0);
		}
		break;
	case RED1_YELLOW2:
		value2 = timer_counter[0];
		value1 = timer_counter[0];
		HAL_GPIO_WritePin(RED_LIGHT_1_GPIO_Port, RED_LIGHT_1_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_LIGHT_1_GPIO_Port, YELLOW_LIGHT_1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LIGHT_1_GPIO_Port, GREEN_LIGHT_1_Pin, RESET);

		HAL_GPIO_WritePin(RED_LIGHT_2_GPIO_Port, RED_LIGHT_2_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_LIGHT_2_GPIO_Port, YELLOW_LIGHT_2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LIGHT_2_GPIO_Port, GREEN_LIGHT_2_Pin, RESET);
		if(timer_flag[0] == 1){
			status = GREEN1_RED2;
			setTimer(timeForGreen, 0);
		}
		if (isButtonPressed(0)){
			status = RED_LIGHT_CONFIG;
			clearAllLight();
			value1 = 0;
			value2 = 0;
			setTimer(500, 0);
		}
		break;
	case GREEN1_RED2:
		value2 = timer_counter[0] + timeForYellow/10;
		value1 = timer_counter[0];
		HAL_GPIO_WritePin(RED_LIGHT_1_GPIO_Port, RED_LIGHT_1_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_LIGHT_1_GPIO_Port, YELLOW_LIGHT_1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LIGHT_1_GPIO_Port, GREEN_LIGHT_1_Pin, SET);

		HAL_GPIO_WritePin(RED_LIGHT_2_GPIO_Port, RED_LIGHT_2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_LIGHT_2_GPIO_Port, YELLOW_LIGHT_2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LIGHT_2_GPIO_Port, GREEN_LIGHT_2_Pin, RESET);
		if(timer_flag[0] == 1){
			status = YELLOW1_RED2;
			setTimer(timeForYellow, 0);
		}
		if (isButtonPressed(0)){
			status = RED_LIGHT_CONFIG;
			clearAllLight();
			value1 = 0;
			value2 = 0;
			setTimer(500, 0);
		}
		break;
	case YELLOW1_RED2:
		value2 = timer_counter[0];
		value1 = timer_counter[0];
		HAL_GPIO_WritePin(RED_LIGHT_1_GPIO_Port, RED_LIGHT_1_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_LIGHT_1_GPIO_Port, YELLOW_LIGHT_1_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LIGHT_1_GPIO_Port, GREEN_LIGHT_1_Pin, RESET);

		HAL_GPIO_WritePin(RED_LIGHT_2_GPIO_Port, RED_LIGHT_2_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_LIGHT_2_GPIO_Port, YELLOW_LIGHT_2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LIGHT_2_GPIO_Port, GREEN_LIGHT_2_Pin, RESET);
		if(timer_flag[0] == 1){
			status = RED1_GREEN2;
			setTimer(timeForGreen, 0);
		}
		if (isButtonPressed(0)){
			status = RED_LIGHT_CONFIG;
			clearAllLight();
			value1 = 0;
			value2 = 0;
			setTimer(500, 0);
		}
		break;
	case RED_LIGHT_CONFIG:
		if(isButtonPressed(1)){
			if(value1 > 9900){
				value1 = 0;
			}else{
				value1 += 100;
			}
		}
		if(isButtonPressed(2)){
			timeForRed_tmp = value1*10;
		}

		if(timer_flag[0] == 1){
			HAL_GPIO_TogglePin(RED_LIGHT_1_GPIO_Port, RED_LIGHT_1_Pin);
			HAL_GPIO_TogglePin(RED_LIGHT_2_GPIO_Port, RED_LIGHT_2_Pin);
			setTimer(500, 0);
		}
		if (isButtonPressed(0)){
			status = YELLOW_LIGHT_CONFIG;
			clearAllLight();
			value1 = 0;
			value2 = 0;
			setTimer(500, 0);
		}
		break;
	case YELLOW_LIGHT_CONFIG:
		if(isButtonPressed(1)){
			if(value1 > 9900){
				value1 = 0;
			}else{
				value1 += 100;
			}
		}
		if(isButtonPressed(2)){
			timeForYellow_tmp = value1*10;
		}
		if(timer_flag[0] == 1){
			HAL_GPIO_TogglePin(YELLOW_LIGHT_1_GPIO_Port, YELLOW_LIGHT_1_Pin);
			HAL_GPIO_TogglePin(YELLOW_LIGHT_2_GPIO_Port, YELLOW_LIGHT_2_Pin);
			setTimer(500, 0);
		}
		if (isButtonPressed(0)){
			status = GREEN_LIGHT_CONFIG;
			clearAllLight();
			value1 = 0;
			value2 = 0;
			setTimer(500, 0);
		}
		break;
	case GREEN_LIGHT_CONFIG:

		if(isButtonPressed(1)){
			if(value1 > 9900){
				value1 = 0;
			}else{
				value1 += 100;
			}
		}
		if(isButtonPressed(2)){
			timeForGreen_tmp = value1*10;
			if (timeForGreen_tmp + timeForYellow_tmp != timeForRed_tmp){
				status = ERROR_STATE;
				setTimer(2000, 0);
			}else{
				timeForGreen = timeForGreen_tmp;
				timeForRed = timeForRed_tmp;
				timeForYellow = timeForYellow_tmp;
			}
		}
		if(timer_flag[0] == 1){
			HAL_GPIO_TogglePin(GREEN_LIGHT_1_GPIO_Port, GREEN_LIGHT_1_Pin);
			HAL_GPIO_TogglePin(GREEN_LIGHT_2_GPIO_Port, GREEN_LIGHT_2_Pin);
			setTimer(500, 0);
		}
		if (isButtonPressed(0)){
			status = RED1_GREEN2;
			clearAllLight();
			setTimer(timeForGreen, 0);
		}
		break;
	case ERROR_STATE:
		turnOnAllLight();
		if(timer_flag[0]){
			status = RED1_GREEN2;
			clearAllLight();
			setTimer(timeForGreen, 0);
		}
		break;
	default:
		break;
	}
}

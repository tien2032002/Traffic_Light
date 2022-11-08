/*
 * auto_fsm.c
 *
 *  Created on: 15 thg 10, 2022
 *      Author: Administrator
 */


#include "main.h"
#include "global.h"

int counter;

void auto_fsm() {
	switch (state) {
		case INIT:
			counter=RED_TIME;
			updateLedBuffer(counter, 0);
			setTimer4(RED_TIME*1000);
			setTimer5(1000);
			state=AUTO_RED;
			break;
		case AUTO_RED:

			HAL_GPIO_WritePin(GPIOA, RED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, YELLOW1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GREEN1_Pin, GPIO_PIN_RESET);

			if (counter>YELLOW_TIME) {
				HAL_GPIO_WritePin(GPIOA, RED2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, YELLOW2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, GREEN2_Pin, GPIO_PIN_SET);
				updateLedBuffer(counter, counter-YELLOW_TIME);
			}
			else {
				HAL_GPIO_WritePin(GPIOA, RED2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, YELLOW2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, GREEN2_Pin, GPIO_PIN_RESET);
				updateLedBuffer(counter, counter);
			}

			if (timer5_flag==1) {
				counter--;
				setTimer5(1000);
			}

			if (timer4_flag==1) {
				counter=GREEN_TIME;
				state=AUTO_GREEN;
				setTimer4(GREEN_TIME*1000);
				setTimer5(1000);
			}
			if (flagForButtonPress[SELECT_IDX]==1) {
				flagForButtonPress[SELECT_IDX]=0;
				state=MODIFY_INIT;
				setTimer4(0);
				setTimer5(0);
			}
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(GPIOA, YELLOW1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GREEN1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(GPIOA, YELLOW2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, RED2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, GREEN2_Pin, GPIO_PIN_RESET);

			updateLedBuffer(counter, counter);
			if (timer5_flag==1) {
				counter--;
				setTimer5(1000);
			}
			if (timer4_flag==1) {
				counter=RED_TIME;
				state=AUTO_RED;
				setTimer4(RED_TIME*1000);
				setTimer5(1000);
			}
			if (flagForButtonPress[SELECT_IDX]==1) {
				flagForButtonPress[SELECT_IDX]=0;
				state=MODIFY_INIT;
				setTimer4(0);
				setTimer5(0);
			}
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(GPIOA, GREEN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, YELLOW1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(GPIOA, GREEN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, RED2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, YELLOW2_Pin, GPIO_PIN_RESET);

			updateLedBuffer(counter, counter+YELLOW_TIME);

			if (timer5_flag==1) {
				counter--;
				setTimer5(1000);
			}
			if (timer4_flag==1) {
				counter=YELLOW_TIME;
				state=AUTO_YELLOW;
				setTimer4(YELLOW_TIME*100);
				setTimer5(1000);
			}
			if (flagForButtonPress[SELECT_IDX]==1) {
				flagForButtonPress[SELECT_IDX]=0;
				state=MODIFY_INIT;
				setTimer4(0);
				setTimer5(0);
			}
			break;
		default:
			break;
	}
}

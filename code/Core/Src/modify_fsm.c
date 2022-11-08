/*
 * modify.c
 *
 *  Created on: 14 thg 10, 2022
 *      Author: Administrator
 */

#include "modify_fsm.h"

	int blinking_status=0;

void blinking_led(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
	switch (blinking_status) {
	case 0:
		turn_off_all_led();
		blinking_status=1;
		setTimer3(250);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
		if (timer3_flag==1) {
			blinking_status=2;
			turn_off_all_led();
			setTimer3(250);
		}
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
		if (timer3_flag==1) {
			blinking_status=1;
			turn_off_all_led();
			setTimer3(250);
		}
		break;
	default:
		break;
	}
}

void turn_off_all_led() {
	HAL_GPIO_WritePin(GPIOA, RED1_Pin|RED2_Pin|YELLOW1_Pin|YELLOW2_Pin|GREEN1_Pin|GREEN2_Pin, GPIO_PIN_RESET);
}

void modify_fsm() {
	switch (state) {
	case MODIFY_INIT:
		state=MODIFY_RED;
		setTimer2(10);
	case MODIFY_RED:
		//display
		updateLedBuffer(RED_TIME, 2);
		blinking_led(GPIOA, RED1_Pin);
		blinking_led(GPIOA, RED2_Pin);

		//modify button
		if (flagForButtonPress1s[MODIFY_IDX]==1) {
			if (timer2_flag==1) {
				RED_TIME=RED_TIME+10;
				if (RED_TIME>=100) RED_TIME=RED_TIME-100;
				updateLedBuffer(RED_TIME, 2);
				setTimer2(1000);
				flagForButtonPress1s[MODIFY_IDX]=0;
			}
		}
		else if (flagForButtonPress[MODIFY_IDX]==1) {
			RED_TIME++;
			if (RED_TIME>=100) RED_TIME=RED_TIME-100;
			updateLedBuffer(RED_TIME, 2);
			flagForButtonPress[MODIFY_IDX]=0;
		}

		//set button
		if (flagForButtonPress[SET_IDX]==1) {
			flagForButtonPress[SET_IDX]=0;
			state=INIT;
		}

		//select button

		if (flagForButtonPress[SELECT_IDX]) {
			flagForButtonPress[SELECT_IDX]=0;
			state=MODIFY_YELLOW;
			setTimer2(10);
		}
		break;

	case MODIFY_YELLOW:
		//display
		updateLedBuffer(YELLOW_TIME, 3);
		blinking_led(GPIOA, YELLOW1_Pin);
		blinking_led(GPIOA, YELLOW2_Pin);

		//modify button
		if (flagForButtonPress1s[MODIFY_IDX]==1) {
			if (timer2_flag==1) {
				YELLOW_TIME=YELLOW_TIME+10;
				if (YELLOW_TIME>=100) YELLOW_TIME=YELLOW_TIME-100;
				updateLedBuffer(YELLOW_TIME, 3);
				setTimer2(1000);
				flagForButtonPress1s[MODIFY_IDX]=0;
			}
		}
		else if (flagForButtonPress[MODIFY_IDX]==1) {
			YELLOW_TIME++;
			if (YELLOW_TIME>=100) YELLOW_TIME=YELLOW_TIME-100;
			updateLedBuffer(YELLOW_TIME, 2);
			flagForButtonPress[MODIFY_IDX]=0;
		}

		//set button
		if (flagForButtonPress[SET_IDX]==1) {
			flagForButtonPress[SET_IDX]=0;
			state=INIT;
		}

		//select button

		if (flagForButtonPress[SELECT_IDX]) {
			flagForButtonPress[SELECT_IDX]=0;
			state=MODIFY_GREEN;
			setTimer2(10);
		}
		break;

	case MODIFY_GREEN:
		//display
		updateLedBuffer(GREEN_TIME, 4);
		blinking_led(GPIOA, GREEN1_Pin);
		blinking_led(GPIOA, GREEN2_Pin);

		//modify button
		if (flagForButtonPress1s[MODIFY_IDX]==1) {
			if (timer2_flag==1) {
				GREEN_TIME=GREEN_TIME+10;
				if (GREEN_TIME>=100) GREEN_TIME=GREEN_TIME-100;
				updateLedBuffer(GREEN_TIME, 4);
				setTimer2(1000);
				flagForButtonPress1s[MODIFY_IDX]=0;
			}
		}
		else if (flagForButtonPress[MODIFY_IDX]==1) {
			GREEN_TIME++;
			if (GREEN_TIME>=100) GREEN_TIME=GREEN_TIME-100;
			updateLedBuffer(GREEN_TIME, 2);
			flagForButtonPress[MODIFY_IDX]=0;
		}

		//set button
		if (flagForButtonPress[SET_IDX]==1) {
			flagForButtonPress[SET_IDX]=0;
			state=INIT;
		}

		//select button

		if (flagForButtonPress[SELECT_IDX]) {
			flagForButtonPress[SELECT_IDX]=0;
			state=INIT;
			setTimer2(10);
		}
		break;

	default:
		break;
	}
}

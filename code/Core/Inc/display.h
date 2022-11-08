/*
 * display.h
 *
 *  Created on: 14 thg 10, 2022
 *      Author: Administrator
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_


#include "global.h"
#include "main.h"

extern int led_status;
extern int led_buffer[4];

#define INIT_LED	4
#define LED0		0
#define LED1		1
#define LED2		2
#define LED3		3


void display7SEG(int num);
void display_fsm(int num1_init, int num2_init, int duration);
void updateLedBuffer(int num1, int num2);

void display_LED0();
void display_LED1();
void display_LED2();
void display_LED3();


#endif /* INC_DISPLAY_H_ */

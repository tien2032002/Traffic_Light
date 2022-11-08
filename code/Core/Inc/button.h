/*
 * button.h
 *
 *  Created on: Oct 13, 2022
 *      Author: Administrator
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"

#define N0_OF_BUTTONS 3
#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

void button_reading ( void );
void reset_button_buffer();

extern int flagForButtonPress[N0_OF_BUTTONS];
extern int flagForButtonPress1s[N0_OF_BUTTONS];


#endif /* INC_BUTTON_H_ */


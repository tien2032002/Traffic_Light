/*
 * modify_fsm.h
 *
 *  Created on: 14 thg 10, 2022
 *      Author: Administrator
 */

#ifndef INC_MODIFY_FSM_H_
#define INC_MODIFY_FSM_H_



#include "global.h"
#include "main.h"

extern int 	blinking_status;

void modify_fsm();
void blinking_led(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void turn_off_all_led();


#endif /* INC_MODIFY_FSM_H_ */

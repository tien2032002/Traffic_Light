/*
 * global.h
 *
 *  Created on: 14 thg 10, 2022
 *      Author: Administrator
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "software_timer.h"
#include "display.h"
#include "modify_fsm.h"
#include "auto_fsm.h"
#include "main.h"

//define state
#define INIT         	0
#define AUTO_RED     	1
#define AUTO_GREEN   	2
#define AUTO_YELLOW  	3

#define MODIFY_INIT		10
#define MODIFY_RED		11
#define MODIFY_YELLOW 	12
#define MODIFY_GREEN 	13

#define DEFAULT_RED_TIME     5
#define DEFAULT_YELLOW_TIME  2
#define DEFAULT_GREEN_TIME   3

#define LED_DURATION_DEFAULT	25

#define SELECT_IDX	0
#define MODIFY_IDX	1
#define SET_IDX		2

extern int state;
extern int RED_TIME;
extern int GREEN_TIME;
extern int YELLOW_TIME;

#endif /* INC_GLOBAL_H_ */

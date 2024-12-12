/*
 * display.h
 *
 *  Created on: Dec 11, 2024
 *      Author: ADMIN
 */
#include "all.h"
#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

extern unsigned char NUM[10];
extern int led_buffer [4];
extern int index_led;
extern int value1;
extern int value2;
void display7SEG (int number);
void update7SEG (int index);
void update7SegBuffer();
void clearAllLight();
void turnOnAllLight();

#endif /* INC_DISPLAY_H_ */

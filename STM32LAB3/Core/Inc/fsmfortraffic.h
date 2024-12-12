/*
 * fsmfortraffic.h
 *
 *  Created on: Dec 11, 2024
 *      Author: ADMIN
 */

#ifndef INC_FSMFORTRAFFIC_H_
#define INC_FSMFORTRAFFIC_H_

#include "all.h"
#define INIT 1
#define RED1_GREEN2 2
#define RED1_YELLOW2 3
#define	GREEN1_RED2 4
#define YELLOW1_RED2 5
#define RED_LIGHT_CONFIG 10
#define YELLOW_LIGHT_CONFIG 11
#define GREEN_LIGHT_CONFIG 12
#define ERROR_STATE 20

void FsmForTrafficLight (void);

#endif /* INC_FSMFORTRAFFIC_H_ */

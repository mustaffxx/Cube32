/*
 * cube.h
 *
 *  Created on: Dec 20, 2021
 *      Author: felipe
 */

#ifndef INC_CUBE_H_
#define INC_CUBE_H_

#include "cube_utils.h"
#include "stm32f429i_discovery_lcd.h"

#define START_COORDS 75

extern Point3D position;
extern Point3D rotation;
extern Point3D points[8];

void do_move();
void draw_cube();

#endif /* INC_CUBE_H_ */

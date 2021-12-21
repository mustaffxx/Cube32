/*
 * cube_utils.h
 *
 *  Created on: Dec 20, 2021
 *      Author: felipe
 */

#ifndef INC_CUBE_UTILS_H_
#define INC_CUBE_UTILS_H_

#include "settings.h"
#include <math.h>

typedef struct {
	float x;
	float y;
	float z;
} Point3D;

float Z0;

float calculate_z0();
Point3D translate(Point3D original, Point3D translation);
Point3D rotate(Point3D original, Point3D rotation);
Point3D apply_perspective(Point3D original);
Point3D center_screen(Point3D original);

#endif /* INC_CUBE_UTILS_H_ */

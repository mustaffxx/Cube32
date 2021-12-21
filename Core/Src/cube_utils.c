/*
 * cube_utils.c
 *
 *  Created on: Dec 20, 2021
 *      Author: felipe
 */
#include "cube_utils.h"

float calculate_z0(){
	return ((RESOLUTION_X / 2.0) / tan((FIELD_OF_VIEW / 2.0) * PI / 180.0));
}

Point3D translate(Point3D original, Point3D translation){
	Point3D res;
	res.x = original.x + translation.x;
	res.y = original.y + translation.y;
	res.z = original.z + translation.z;
	return res;
}

Point3D rotate(Point3D original, Point3D rotation){
	Point3D res;
	res.x = original.x * (cos(rotation.z) * cos(rotation.y)) +
					 original.y * (cos(rotation.z) * sin(rotation.y) * sin(rotation.x) - sin(rotation.z) * cos(rotation.x)) +
					 original.z * (cos(rotation.z) * sin(rotation.y) * cos(rotation.x) + sin(rotation.z) * sin(rotation.x));
	res.y = original.x * (sin(rotation.z) * cos(rotation.y)) +
					 original.y * (sin(rotation.z) * sin(rotation.y) * sin(rotation.x) + cos(rotation.z) * cos(rotation.x)) +
					 original.z * (sin(rotation.z) * sin(rotation.y) * cos(rotation.x) - cos(rotation.z) * sin(rotation.x));
	res.z = original.x * (-sin(rotation.y)) +
					 original.y * (cos(rotation.y) * sin(rotation.x)) +
					 original.z * (cos(rotation.y) * cos(rotation.x));
	return res;
}

Point3D apply_perspective(Point3D original){
	Point3D res;
	res.x = original.x * Z0 / (Z0 + original.z);
	res.y = original.y * Z0 / (Z0 + original.z);
	res.z = original.z;
	return res;
}

Point3D center_screen(Point3D original){
	Point3D res;
	res.x = original.x + (RESOLUTION_X / 2);
	res.y = original.y + (RESOLUTION_Y / 2);
	res.z = original.z;
	return res;
}

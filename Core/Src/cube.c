/*
 * cube.c
 *
 *  Created on: Dec 20, 2021
 *      Author: felipe
 */

#include "cube.h"

Point3D position = {0, 0, 2 * START_COORDS};
Point3D rotation = {0, 0, 0};
Point3D points[8] = {
	{-START_COORDS, -START_COORDS, -START_COORDS},
	{-START_COORDS, START_COORDS, -START_COORDS},
	{START_COORDS, START_COORDS, -START_COORDS},
	{START_COORDS, -START_COORDS, -START_COORDS},
	{-START_COORDS, -START_COORDS, START_COORDS},
	{-START_COORDS, START_COORDS, START_COORDS},
	{START_COORDS, START_COORDS, START_COORDS},
	{START_COORDS, -START_COORDS, START_COORDS},
};

void do_move(){
	//rotation.x = rotation.x + 0.005;
	rotation.y = rotation.y + 0.05;
//	rotation.z = rotation.z + 0.001;
}

void draw_cube(){
	Point3D draw_points[8];

	for(int i = 0; i < 8; i++){
		draw_points[i] = rotate(points[i], rotation);
	}

	for(int i = 0; i < 8; i++){
		draw_points[i] = translate(draw_points[i], position);
	}

	for(int i = 0; i < 8; i++){
		draw_points[i] = apply_perspective(draw_points[i]);
	}

	for(int i = 0; i < 8; i++){
		draw_points[i] = center_screen(draw_points[i]);
	}

	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DrawLine(draw_points[0].x, draw_points[0].y, draw_points[1].x, draw_points[1].y);
	BSP_LCD_DrawLine(draw_points[1].x, draw_points[1].y, draw_points[2].x, draw_points[2].y);
	BSP_LCD_DrawLine(draw_points[2].x, draw_points[2].y, draw_points[3].x, draw_points[3].y);
	BSP_LCD_DrawLine(draw_points[3].x, draw_points[3].y, draw_points[0].x, draw_points[0].y);

	BSP_LCD_DrawLine(draw_points[4].x, draw_points[4].y, draw_points[5].x, draw_points[5].y);
	BSP_LCD_DrawLine(draw_points[5].x, draw_points[5].y, draw_points[6].x, draw_points[6].y);
	BSP_LCD_DrawLine(draw_points[6].x, draw_points[6].y, draw_points[7].x, draw_points[7].y);
	BSP_LCD_DrawLine(draw_points[7].x, draw_points[7].y, draw_points[4].x, draw_points[4].y);

	BSP_LCD_DrawLine(draw_points[0].x, draw_points[0].y, draw_points[4].x, draw_points[4].y);
	BSP_LCD_DrawLine(draw_points[1].x, draw_points[1].y, draw_points[5].x, draw_points[5].y);
	BSP_LCD_DrawLine(draw_points[2].x, draw_points[2].y, draw_points[6].x, draw_points[6].y);
	BSP_LCD_DrawLine(draw_points[3].x, draw_points[3].y, draw_points[7].x, draw_points[7].y);

	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	for(int i = 0; i < 8; i++){
		BSP_LCD_FillCircle(draw_points[i].x, draw_points[i].y, 5);
	}
}

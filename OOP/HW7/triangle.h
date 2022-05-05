#pragma once
#include "Point_2D.h"

class triangle
{
public:
	double side_length;
	int rotation_angle;
	double start_x, start_y; 

public:
	triangle(double x, double y, double l, int angle);
	~triangle() = default;
};

extern void gb_draw_triangle(CDC* pDC, triangle& to_draw, double scale = 1.0, Point_2D& translation = Point_2D(0, 0), int screenX = 1000, int screenY = 1000);


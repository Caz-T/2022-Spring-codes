#pragma once
#include "Point_2D.h"
class arc
{
public:
	Point_2D centre;
	double radius;
	int start_angle, end_angle;

public:
	arc(double, double, double, int, int);
	~arc() = default;
};

extern void gb_draw_arc(CDC* pDC, arc& to_draw, double scale = 1.0, Point_2D& translation = Point_2D(0, 0), int screenX = 1000, int screenY = 1000);


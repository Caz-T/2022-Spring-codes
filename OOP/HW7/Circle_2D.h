#pragma once
#include "Point_2d.h"

class Circle_2D
{
public:
	Circle_2D(double centre_x, double centre_y, double r);
	Circle_2D(Point_2D centre, double r);
	~Circle_2D() = default;

public:
	Point_2D centre;
	double radius;
};

extern void gb_draw_circle(CDC* pDC, Circle_2D& c, double scale = 1.0, Point_2D& translation = Point_2D(0, 0), int screenX = 1000, int screenY = 1000);



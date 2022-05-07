#pragma once
class Point_2D
{
public:
	Point_2D(double xx = 0.0, double yy = 0.0);
	~Point_2D();

public:
	double x, y;
};

extern void gb_draw_point(CDC* pDC, Point_2D& pt, double side_length = 10, double scale = 1.0, Point_2D& translation = Point_2D(0, 0), int screenX = 1000, int screenY = 1000);
extern void gb_point_convert_from_global_to_screen(Point_2D& result, Point_2D gbpoint, double scale = 1.0, Point_2D& translation = Point_2D(0, 0), int screenX = 1000, int screenY = 1000);
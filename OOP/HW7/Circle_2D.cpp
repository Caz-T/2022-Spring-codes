#include "pch.h"
#include "Circle_2D.h"

Circle_2D::Circle_2D(double centre_x, double centre_y, double r) : centre(Point_2D(centre_x, centre_y)), radius(r) {}
Circle_2D::Circle_2D(Point_2D cent, double r) : centre(cent), radius(r) {}

void gb_draw_circle(CDC* pDC, Circle_2D& c, double scale, Point_2D& translation, int screenX, int screenY)
{
	Point_2D actual_centre;
	gb_point_convert_from_global_to_screen(actual_centre, c.centre, scale, translation, screenX, screenY);
	double actual_radius = c.radius * scale;
	pDC->Ellipse((int)(actual_centre.x - actual_radius), (int)(actual_centre.y - actual_radius),
		(int)(actual_centre.x + actual_radius), (int)(actual_centre.y + actual_radius));
}

#include "pch.h"
#include "arc.h"

void gb_draw_arc(CDC* pDC, arc& to_draw, double scale, Point_2D& translation, int screenX, int screenY)
{
	Point_2D actual_centre, actual_start;
	gb_point_convert_from_global_to_screen(actual_centre, to_draw.centre, scale, translation, screenX, screenY);
	gb_point_convert_from_global_to_screen(actual_start, Point_2D(to_draw.centre.x + to_draw.radius * cos(to_draw.start_angle *  3.1415926 / 180.0), to_draw.centre.y + to_draw.radius * sin(to_draw.start_angle * 3.1415926 / 180.0)), scale, translation, screenX, screenY);
	int actual_radius = (int)(to_draw.radius * scale);
	pDC->MoveTo(actual_start.x, actual_start.y);
	pDC->AngleArc(actual_centre.x, actual_centre.y, actual_radius, to_draw.start_angle, to_draw.end_angle - to_draw.start_angle);
}

arc::arc(double centre_x, double centre_y, double r, int angstt, int angend): centre(Point_2D(centre_x, centre_y)), radius(r), start_angle(angstt), end_angle(angend) {}

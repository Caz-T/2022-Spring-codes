#include "pch.h"
#include "Point_2D.h"

Point_2D::Point_2D(double xx, double yy) : x(xx), y(yy) {};
Point_2D::~Point_2D() {};
extern void gb_draw_point(CDC* pDC, Point_2D& pt, double side_length, double scale, Point_2D& translation, int screenX, int screenY)
{
    Point_2D n;
    gb_point_convert_from_global_to_screen(n, pt, scale, translation, screenX, screenY);
    int x = (int)(n.x + 0.5);
    int y = (int)(n.y + 0.5);
    pDC->MoveTo(x - side_length, y);
    pDC->LineTo(x + side_length, y);
    pDC->MoveTo(x, y - side_length);
    pDC->LineTo(x, y + side_length);
};

void gb_point_convert_from_global_to_screen(Point_2D& result, Point_2D gbpoint, double scale, Point_2D& translation, int screenX, int screenY)
{
    result.x = (gbpoint.x - translation.x) * scale;
    result.y = (gbpoint.y - translation.y) * scale;
    result.x += (screenX / 2);
    result.y = screenY / 2 - result.y;
};
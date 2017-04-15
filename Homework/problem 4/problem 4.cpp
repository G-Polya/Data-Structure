#include <stdio.h>
#include <stdlib.h>
#include "2_dimensin_figure.h"
#include <math.h>

#define PI 3.14

int main()
{
	Point p1, p2, p3;
	Line s;
	Rect r;
	Circle c1;
	Circle c2;
	double length, R_area, C_area1, C_area2;

	p1 = make_point(1, 1);
	p2 = make_point(3, 3);
	s = make_line(p1, p2);
	r = make_rect(p1, p2);

	c1 = make_Circle_1(p1, 4);
	c2 = make_Circle_2(p2, p1);

	length = line_length(s);
	R_area = rect_area(r);
	C_area1 = Circle_area_1(c1);
	C_area2 = Circle_area_2(c2);


	printf("line_length: %f, rect_area: %f\n", length, R_area);
	printf("C_area1: %f, C_area2: %f\n", C_area1, C_area2);
}

Point make_point(float _x, float _y)
{
	Point p;
	p.x = _x;
	p.y = _y;

	return p;
}

Line make_line(Point _p1, Point _p2)
{
	Line line;
	line.p1 = _p1;
	line.p2 = _p2;

	return line;
}

//_p1과 _p2를 이은 선은 직사각형의 대각선이다
Rect make_rect(Point _p1, Point _p2)
{
	Rect r;
	r.p1 = _p1;
	r.p2 = _p2;

	return r;
}

double line_length(Line s)
{
	return sqrt(pow(s.p1.x - s.p2.x, 2) + pow(s.p1.y - s.p2.y, 2));
}

double rect_area(Rect r)
{
	return fabs(r.p1.x - r.p2.x) * fabs(r.p1.y - r.p2.y);
}


Circle make_Circle_1(Point _center, double _radius)
{
	Circle c;
	c.Center = _center;
	c.Radius = _radius;

	return c;
}

Circle make_Circle_2(Point _center, Point _another)
{
	Circle c;
	c.Center = _center;
	c.Another = _another;

	return c;
}

double Circle_area_1(Circle c)
{
	return c.Radius * PI;
}

double Circle_area_2(Circle c)
{
	c.Radius = sqrt(pow(c.Center.x - c.Another.x, 2) + pow(c.Center.y - c.Another.y, 2));
	return c.Radius * PI;
}

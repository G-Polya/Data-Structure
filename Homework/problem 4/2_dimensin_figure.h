#pragma once

typedef struct Point
{
	double x;
	double y;

} Point;

Point make_point(float _x, float _y);

typedef struct Line
{
	Point p1;
	Point p2;
}Line;

Line make_line(Point _p1, Point _p2);

//p1,p2은 직사각형의 대각선의 양끝점
typedef struct Rect
{
	Point p1;
	Point p2;
} Rect;

Rect make_rect(Point _p1, Point _p2);

double line_length(Line s);

double rect_area(Rect r);

//중심과 반지름이 주어진 원
typedef struct Circle
{
	Point Center;
	Point Another;
	double Radius;
} Circle;

Circle make_Circle_1(Point _center, double _radius);
Circle make_Circle_2(Point _center, Point _another);
double Circle_area_1(Circle c);
double Circle_area_2(Circle c);



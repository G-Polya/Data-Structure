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

typedef struct Rect
{
	Point p1;
	Point p2;
} Rect;

Rect make_rect(Point _p1, Point _p2);

double line_length(Line s);

double rect_area(Rect r);

typedef struct Circle
{
	Point p1;
	float radius;
};
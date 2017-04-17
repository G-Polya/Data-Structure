#pragma once

//직각좌표를 갖는 점: Point
typedef struct Point
{
	double x;		//x좌표
	double y;		//y좌포

} Point;

Point make_point(float _x, float _y);		//점을 생성

//두 점을 잇는 선분
typedef struct Line
{
	Point p1;
	Point p2;
}Line;

Line make_line(Point _p1, Point _p2);		//선분 생성

//p1,p2은 직사각형의 대각선의 양끝점
typedef struct Rect
{
	Point p1;
	Point p2;
} Rect;

Rect make_rect(Point _p1, Point _p2);		//직사각형 생성

double line_length(Line s);					//선분 s의 길이

double rect_area(Rect r);					//직사각형 r의 넓이

//중심과 반지름이 주어진 원
typedef struct Circle
{
	Point Center;
	Point Another;
	double Radius;
} Circle;

Circle make_Circle_1(Point _center, double _radius);		//중심과 반지름이 주어졌을때, 원 생성
Circle make_Circle_2(Point _center, Point _another);		//중심과 원위의 한 점이 주어졌을때, 원 생성
double Circle_area_1(Circle c);								//중심과 반지름이 주어졌을때, 원의 넓이
double Circle_area_2(Circle c);								//중심과 원위의 한 점이 주어졌을때, 원의 넓이			



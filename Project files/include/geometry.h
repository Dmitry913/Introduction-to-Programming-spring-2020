#pragma once

#include "error.h"

class Point
{
public:
    double x;
    double y;

    Point(double _x = 0, double _y = 0);
};

class Segment
{
public:
    Segment(Point *st, Point *ed);

    Point getStart();

private:
    Point *start;
    Point *end;
};

class Circle
{
public:
    Circle(Point *p, double r)
    {

    }

private:
    Point *center;
    double R;
};

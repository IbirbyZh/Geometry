//
//  Point.cpp
//  Geometry
//
//  Created by Шишкин Евгений on 27.02.16.
//  Copyright © 2016 Шишкин Евгений. All rights reserved.
//

#include "Point.hpp"


Point::Point():x(), y(){}

Point::Point(int _x, int _y):x(_x), y(_y){}

Point&& Point::operator +(const Point &_point) const
{
    return std::move(Point(x + _point.X(), y + _point.Y()));
}

Point&& Point::operator -(const Point &_point) const
{
    return std::move(Point(x - _point.X(), y - _point.Y()));
}

int&& Point::operator *(const Point &_point) const
{
    return std::move(x * _point.X() + y * _point.Y());
}

int Point::operator %(const Point &_point) const
{
    if (x * _point.Y() > y * _point.X())
        return 1;
    if (x * _point.Y() > y * _point.X()) {
        return -1;
    }
    return 0;
}

int Point::X() const
{
    return x;
}

int Point::Y() const
{
    return y;
}

void Point::setX(int _x)
{
    x = _x;
}

void Point::setY(int _y)
{
    y = _y;
}

void Point::setX(int&& _x)
{
    x = std::move(_x);
}

void Point::setY(int &&_y)
{
    y = std::move(y);
}
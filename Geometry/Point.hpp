//
//  Point.hpp
//  Geometry
//
//  Created by Шишкин Евгений on 27.02.16.
//  Copyright © 2016 Шишкин Евгений. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <ios>

class Point{
public:
    Point();
    Point(int _x, int _y);
    Point&& operator +(const Point &_point) const;
    Point&& operator -(const Point &_point) const;
    int&& operator *(const Point &_point) const;
    int operator %(const Point &_point) const;
    int X() const;
    int Y() const;
    void setX(int _x);
    void setY(int _y);
    void setX(int&& _x);
    void setY(int&& _y);
private:
    int x, y;
};



#endif /* Point_hpp */

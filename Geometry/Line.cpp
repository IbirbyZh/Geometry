//
//  Line.cpp
//  Geometry
//
//  Created by Шишкин Евгений on 27.02.16.
//  Copyright © 2016 Шишкин Евгений. All rights reserved.
//

#include "Line.hpp"
#include <math.h>

Line::Line(const Point<int>& a, const Point<int>& b):a(b.ord() - a.ord()), b(a.abs() - b.abs()),
                                           c(b.abs() * a.ord() - a.abs() * b.ord()) {}

int Line::A() const
{
    return a;
}

int Line::B() const
{
    return b;
}

int Line::C() const
{
    return c;
}
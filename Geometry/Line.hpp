//
//  Line.hpp
//  Geometry
//
//  Created by Шишкин Евгений on 27.02.16.
//  Copyright © 2016 Шишкин Евгений. All rights reserved.
//

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>
#include "Point.hpp"

class Line{
public:
    Line(const Point<int>& _a, const Point<int>& _b);
    int A() const;
    int B() const;
    int C() const;
    template<class T>
    T Substitution(const Point<T>& p) const{return a * p.abs() + b * p.ord() + c;}
private:
    int a, b, c;
};

#endif /* Line_hpp */

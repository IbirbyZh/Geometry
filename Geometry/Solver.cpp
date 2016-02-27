//
//  Solver.cpp
//  Geometry
//
//  Created by Шишкин Евгений on 27.02.16.
//  Copyright © 2016 Шишкин Евгений. All rights reserved.
//

#include <math.h>
#include "Solver.hpp"
#include "Point.hpp"
#include "Line.hpp"


double Solver::DistanceFromPointToInterval(const Point<int>& S, const Point<int>& A, const Point<int>& B)
{
    Line l(A, B);
    Point<double> n(l.A(), l.B());
    n *= -1.0/n.length2()*l.Substitution(S);
    Point<double> C(S);
    n += S;
    if (fabs((n - A)*(n - B) / sqrt((n - A).length2())/sqrt((n - B).length2()) + 1) <= e)
        return sqrt((C - n).length2());
    else
        return sqrt(std::min((C - A).length2(),(C - B).length2()));
}
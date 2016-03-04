//
//  Solver.cpp
//  Geometry
//
//  Created by Шишкин Евгений on 27.02.16.
//  Copyright © 2016 Шишкин Евгений. All rights reserved.
//

#include <ratio>
#include <algorithm>
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

std::pair<double, double> Solver::LineIntersect(int A, int B, int C, int a, int b, int c)
{
    double X, Y, D;
    X = (-C * b + c * B);
    Y = (A * (-c) - a * (-C));
    D = A * b - B * a;
    return std::make_pair(X / D, Y / D);
    
}

bool Solver::Intersect(const Point<int>& A,const Point<int>& B, const Point<int>& C, const Point<int>& D)
{
    Point<int> V1 = B - A;
    Point<int> V2 = D - C;
    if (V1 % V2 == 0){
        if (V1 % (D - A) != 0){
            return false;
        }else{
            return (std::min(B.abs(), D.abs()) >= std::max(A.abs(), C.abs())) &&
                   (std::min(B.ord(), D.ord()) >= std::max(A.ord(), C.ord()));
        }
    }else{
        return (((C - A) % (B - A)) * ((B - A) % (D - A)) >= 0) &&
               (((A - C) % (D - C)) * ((D - C) % (B - C)) >= 0);
    }
    
}
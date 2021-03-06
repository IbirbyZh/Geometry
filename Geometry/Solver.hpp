//
//  Solver.hpp
//  Geometry
//
//  Created by Шишкин Евгений on 27.02.16.
//  Copyright © 2016 Шишкин Евгений. All rights reserved.
//

#ifndef Solver_hpp
#define Solver_hpp

#include <stdio.h>
#include <utility>
#include "Point.hpp"

struct Solver{
    static double DistanceFromPointToInterval(const Point<int>& S, const Point<int>& A, const Point<int>& B);
    static std::pair<double, double> LineIntersect(int A, int B, int C, int a, int b, int c);
    static bool Intersect(const Point<int>& A, const Point<int>& B, const Point<int>& C, const Point<int>& D);
    static void TwoCircle(const Point<long long>& O1, const long long R1, const Point<long long>& O2, const long long R2, bool ch);
    static void Tangent(const Point<long long>& O1, const long long R1, const Point<long long>& O2);
};

#endif /* Solver_hpp */

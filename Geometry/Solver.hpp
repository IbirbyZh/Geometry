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
#include "Point.hpp"

struct Solver{
    static double DistanceFromPointToInterval(const Point<int>& S, const Point<int>& A, const Point<int>& B);
};

#endif /* Solver_hpp */

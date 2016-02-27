//
//  main.cpp
//  Geometry
//
//  Created by Шишкин Евгений on 27.02.16.
//  Copyright © 2016 Шишкин Евгений. All rights reserved.
//

#include <iostream>
#include <ostream>
#include <iomanip>
#include <math.h>
#include "Point.hpp"
#include "Solver.hpp"

int main(int argc, const char * argv[]) {
    int ax, ay, bx, by, cx, cy;
    std::cin >> ax >> ay >> bx >> by >> cx >> cy;
    Point<int> S(ax, ay);
    Point<int> A(bx, by);
    Point<int> B(cx, cy);
    if (bx == cx && by == cy){
        Point<double> ans(S - A);
        std::cout << std::fixed << std::setprecision(6)
        << sqrt(ans.length2()) << std::endl;
        return 0;
    }
    std::cout << std::fixed << std::setprecision(6)
    << Solver::DistanceFromPointToInterval(S, A, B) << std::endl;
    return 0;
}
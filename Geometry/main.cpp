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
    int x1, x2, x3, x4, y1, y2, y3, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if (x1 > x2){
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    if (x1 == x2 && y1 > y2){
        std::swap(y1, y2);
    }
    if (x3 > x4){
        std::swap(x3, x4);
        std::swap(y3, y4);
    }
    if (x3 == x4 && y3 > y4){
        std::swap(y3, y4);
    }
    bool ans = Solver::Intersect(Point<int>(x1, y1), Point<int>(x2, y2),
                                 Point<int>(x3, y3), Point<int>(x4, y4));
    /*
    std::cout << std::fixed << std::setprecision(10)
    << ans.first << ' ' << ans.second;
    */
    std::cout << ((ans) ? "YES" : "NO");
    return 0;
}
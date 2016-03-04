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
    int n;
    int x1, y1, r1, x2, y2, r2;
    std::cin >> n;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        bool a = false;
        if (r2 < r1){
            std::swap(x1, x2);
            std::swap(r1, r2);
            std::swap(y1, y2);
            a = true;
        }
        Solver::TwoCircle(Point<long long>(x1, y1), r1, Point<long long>(x2, y2) , r2, a);
    }
    return 0;
}
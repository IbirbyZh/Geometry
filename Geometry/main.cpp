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
#include <vector>
#include "Point.hpp"
#include "Solver.hpp"

int main(int argc, const char * argv[]) {
    freopen("hull.in", "r", stdin);
    freopen("hull.out", "w", stdout);
    int x1, y1, n;
    std::cin >> n;
    std::vector<Point<long long>> p, ans;
    for(int i = 0; i < n; ++i){
        std::cin >>x1 >> y1;
        p.push_back(Point<long long>(x1, y1));
        if (p[i].ord() < p[0].ord() || (p[i].ord() == p[0].ord() && p[i].abs() < p[0].abs()))
            std::swap(p[0], p[i]);
    }
    std::sort(p.begin(), p.end(), [&](const Point<long long>&a, const Point<long long>&b)
    {
        if ((a - p[0]) % (b - p[0]) > 0 || ((a - p[0]) % (b - p[0]) == 0 && (a - p[0]).length2() < (b - p[0]).length2()))
            return true;
        return false;
    });
    p.push_back(p[0]);
    for (int i = 0; i < n + 1; ++i){
        if (i != 0 && p[i].abs() == p[i-1].abs() && p[i].ord() == p[i-1].ord())
            continue;
        int size = ans.size();
        while(size >= 2 && (ans[size - 1] - ans[size - 2]) % (p[i] - ans[size - 1]  ) <= 0){
            ans.pop_back();
            --size;
        }
        ans.push_back(p[i]);
    }
    std::cout << ans.size() <<'\n';
    for(int i = 0; i < ans.size(); ++i){
        std::cout << ans[i].abs() << ' ' << ans[i].ord() <<'\n';
    }
    return 0;
}
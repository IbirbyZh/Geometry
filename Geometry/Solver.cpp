//
//  Solver.cpp
//  Geometry
//
//  Created by Шишкин Евгений on 27.02.16.
//  Copyright © 2016 Шишкин Евгений. All rights reserved.
//

#include <ratio>
#include <iomanip>
#include <iostream>
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

void Solver::TwoCircle(const Point<long long>& O1, const long long R1, const Point<long long>& O2, const long long R2, bool ch){
    int k = 0;
    if (O1 == O2){
        if (R1 == R2){
            std::cout << "3\n";
            return;
        }else{
            std::cout << "0\n";
            return;
        }
    }
    long long len = (O2 - O1).length2();
    if(len == (R1 - R2) * (R1 - R2) || len == (R1 + R2) * (R1 + R2)){
        k = 1;
    }else{
        k = 2;
    }
    if(len > (R1 + R2) * (R1 + R2) || len < (R2 - R1) * (R2 - R1)){
        std::cout << "0\n";
        return;
    }
    Point<double> OH = O2 - O1;
    OH /= sqrt(OH.length2());
    OH *= static_cast<double>(R1 * R1 - R2 * R2 + len) / (2 * sqrt(len));
    Point<double> H = OH + O1;
    if (k == 2){
        Point<double> DH = O2 - O1;
        DH.rotate();
        DH /= sqrt(DH.length2());
        DH *= sqrt(R1 * R1 - OH.length2());
        Point<double> A = H + DH;
        Point<double> B = H - DH;
        std::cout << "2\n";
        std::cout << std::fixed << std::setprecision(10)
        << H.abs() << ' ' << H.ord() << '\n'
        << ((ch) ? sqrt(len) - sqrt(OH.length2())*(OH * (O2 - O1) > 0 ? 1 : -1): sqrt(OH.length2())) << ' ' << sqrt(DH.length2()) << '\n'
        << A.abs() << ' ' << A.ord() << '\n'
        << B.abs() << ' ' << B.ord() << '\n';
    }else{
        std::cout << "1\n";
        std::cout << std::fixed << std::setprecision(10)
        << H.abs() << ' ' << H.ord() << '\n';
        return;
    }
    
}


void Solver::Tangent(const Point<long long>& O1, const long long R1, const Point<long long>& O2)
{
    if ((O2 - O1).length2() < R1 * R1){
        std::cout << 0 <<'\n';
        return;
    }
    if ((O2 - O1).length2() == R1 * R1){
        std::cout << 1 <<'\n';
        std::cout << std::fixed << std::setprecision(10)
        <<O2.abs() << ' ' << O2.ord() << '\n';
        return;
    }
    Point<double> OP(O1 - O2);
    double l = sqrt(OP.length2());
    double r = sqrt((l + R1) * (l - R1));
    OP *= r * r / (l * l);
    Point<double> P = OP + O2;
    Point<double> D(OP);
    D.rotate();
    D /= sqrt(D.length2());
    D *= sqrt(r * r - OP.length2());
    Point<double> A = (P + D);
    Point<double> B = (P - D);
    std::cout << "2\n";
    std::cout << std::fixed << std::setprecision(10)
    << P.abs() << ' ' << P.ord() << '\n'
    << sqrt(OP.length2())<< ' ' << sqrt(D.length2()) << '\n'
    << A.abs() << ' ' << A.ord() << '\n'
    << B.abs() << ' ' << B.ord() << '\n';
    
}

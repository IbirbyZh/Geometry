//
//  Point.hpp
//  Geometry
//
//  Created by Шишкин Евгений on 27.02.16.
//  Copyright © 2016 Шишкин Евгений. All rights reserved.
//
/*
template<class T>
class Point
{
public:
    typedef T value_type;
    
    Point(const T& x = T(), const T& y = T());
    Point(const Point&);
    template<class X> Point(const Point<X>&);
    
    T abs() const;
    T ord() const;
    
    void abs(T);
    void ord(T);
    
    Point& operator=(const Point&);
    template<class X> Point<T>& operator= (const Point<X>&);
    template<class X> Point<T>& operator+=(const Point<X>&);
    template<class X> Point<T>& operator+(const Point<X>&);
    template<class X> Point<T>& operator-=(const Point<X>&);
    template<class X> Point<T>& operator-(const Point<X>&);
    
    template<class X> X operator*(const Point<X>&);
    template<class X> X operator%(const Point<X>&);
 
    Point<T>& operator*=(const T&);
    Point<T>& operator/=(const T&);
 
    T length2();
};

template<>
class Point<double>
{
public:
    typedef double value_type;

    Point(const double& x = T(), const double& y = T());
    Point(const Point&);
    template<class X> Point(const Point<X>&);

    double abs() const;
    double ord() const;

    void abs(double);
    void ord(double);

    Point& operator=(const Point&);
    template<class X> Point<double>& operator= (const Point<X>&);
    template<class X> Point<double>& operator+=(const Point<X>&);
    template<class X> Point<double>& operator+(const Point<X>&);
    template<class X> Point<double>& operator-=(const Point<X>&);
    template<class X> Point<double>& operator-(const Point<X>&);

    template<class X> X operator*(const Point<X>&);
    template<class X> X operator%(const Point<X>&);

    Point<double>& operator*=(const T&);
    Point<double>& operator/=(const T&);

    T length2();
};
*/

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <ios>
const static double e = 1E-9;
template<class T>
class Point
{
public:
    typedef T value_type;

    Point(const value_type& _x = value_type(), const value_type& _y = value_type()):x(_x), y(_y){}
    Point(const Point& p):x(p.abs()), y(p.ord()){}
    template<class X> Point(const Point<X>& p):x(p.abs()), y(p.ord()){}
    
    T abs() const {return x;}
    T ord() const {return y;}
    
    void abs(T _x){x = _x;}
    void ord(T _y){y = _y;}
    
    Point& operator=(const Point&);
    template<class X> Point& operator= (const Point<X>& p)
    {
        x = p.abs();
        y = p.ord();
        return *this;
    }
    template<class X> Point& operator+=(const Point<X>& p)
    {
        x += p.abs();
        y += p.ord();
        return *this;
    }
    template<class X> Point operator+(const Point<X>& p) const
    {
        return Point(x + p.abs(), y + p.ord());
    }
    template<class X> Point& operator-=(const Point<X>& p)
    {
        x -= p.abs();
        y -= p.ord();
    }
    template<class X> Point operator-(const Point<X>& p) const
    {
        return Point(x - p.abs(), y - p.ord());
    }
    template<class X> T operator*(const Point<X>& p) const
    {
        return x * p.abs() + y * p.ord();
    }
    template<class X> T operator%(const Point<X>& p) const
    {
        if (x * p.ord() > y * p.abs()){
            return 1;
        }
        if (x * p.ord() < y * p.abs()){
            return -1;
        }
        return 0;
    }
    
    template<class X> Point& operator*=(const X& p)
    {
        x *= p;
        y *= p;
        return *this;
    }
    template<class X> Point& operator/=(const X& p)
    {
        x /= p;
        y /= p;
        return *this;
    }
    
    T length2() const
    {
        return x * x + y * y;
    }
    
    bool operator ==(const Point& p) const
    {
        return x == p.x && y == p.y;
    }
    
    void rotate()
    {
        std::swap(x, y);
        x *= -1;
    }
    
private:
    value_type x, y;
};

template<>
class Point<double>
{
public:
    typedef double value_type;
    
    Point(const value_type& _x = value_type(), const value_type& _y = value_type()):x(_x), y(_y){}
    Point(const Point& p):x(p.abs()), y(p.ord()){}
    template<class X> Point(const Point<X>& p):x(p.abs()), y(p.ord()){}
    
    double abs() const {return x;}
    double ord() const {return y;}
    
    void abs(double _x){x = _x;}
    void ord(double _y){y = _y;}
    
    Point& operator=(const Point&);
    template<class X> Point& operator= (const Point<X>& p)
    {
        x = p.abs();
        y = p.ord();
        return *this;
    }
    template<class X> Point& operator+=(const Point<X>& p)
    {
        x += p.abs();
        y += p.ord();
        return *this;
    }
    template<class X> Point operator+(const Point<X>& p) const
    {
        return Point(x + p.abs(), y + p.ord());
    }
    template<class X> Point& operator-=(const Point<X>& p)
    {
        x -= p.abs();
        y -= p.ord();
    }
    template<class X> Point operator-(const Point<X>& p) const
    {
        return Point(x - p.abs(), y - p.ord());
    }
    template<class X> double operator*(const Point<X>& p) const
    {
        return x * p.abs() + y * p.ord();
    }
    template<class X> int operator%(const Point<X>& p) const
    {
        if (x * p.ord() - y * p.abs() > e){
            return 1;
        }
        if (x * p.ord() - y * p.abs() < e){
            return -1;
        }
        return 0;
    }
    
    template<class X> Point& operator*=(const X& p)
    {
        x *= p;
        y *= p;
        return *this;
    }
    template<class X> Point& operator/=(const X& p)
    {
        x /= p;
        y /= p;
        return *this;
    }
    
    double length2() const
    {
        return x * x + y * y;
    }
    
    void rotate()
    {
        std::swap(x, y);
        x *= -1;
    }
    
private:
    value_type x, y;
};


#endif /* Point_hpp */

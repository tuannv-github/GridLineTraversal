#ifndef _POINT_H_
#define _POINT_H_

#include <math.h>
#include <iostream>

template <class T>
struct Point{
	inline Point():x(0),y(0) {}
	inline Point(T _x, T _y):  x(_x),  y(_y) {}
	// inline Point(Point<T>& p): x(p.x), y(p.y){}
	T x, y;
};

template <class T>
inline Point<T> operator + (const Point<T>& p1, const Point<T>& p2){
	return Point<T>(p1.x+p2.x, p1.y+p2.y);
}

template <class T>
inline Point<T> operator - (const Point<T>& p1, const Point<T>& p2){
	return Point<T>(p1.x-p2.x, p1.y-p2.y);
}

template <class T>
inline Point<T> operator * (const Point<T>& p, const T& v){
	return Point<T>(p.x*v, p.y*v);
}

template <class T>
inline Point<T> operator * (const T& v, const Point<T>& p){
	return Point<T>(p.x*v, p.y*v);
}

template <class T>
inline T operator * (const Point<T>& p1, const Point<T>& p2){
	return p1.x*p2.x+p1.y*p2.y;
}

template <class T>
inline Point<T> max(const Point<T>& p1, const Point<T>& p2){
	Point<T> p=p1;
	p.x=p.x>p2.x?p.x:p2.x;
	p.y=p.y>p2.y?p.y:p2.y;
	return p;
}

template <class T>
inline Point<T> min(const Point<T>& p1, const Point<T>& p2){
	Point<T> p=p1;
	p.x=p.x<p2.x?p.x:p2.x;
	p.y=p.y<p2.y?p.y:p2.y;
	return p;
}

template <class T, class F>
inline Point<T> interpolate(const Point<T>& p1,  const F& t1, const Point<T>& p2, const F& t2, const F& t3){
	F gain=(t3-t1)/(t2-t1);
	Point<T> p3=p1+(p2-p1)*gain;
	return p3;
}

template <class T>
inline double euclidian_distance(const Point<T>& p1, const Point<T>& p2){
  return hypot(p1.x-p2.x, p1.y-p2.y);
}

template <class T>
std::ostream & operator << (std::ostream &out, const Point<T>& p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

typedef Point<int> IPoint;
typedef Point<double> DPoint;

#endif

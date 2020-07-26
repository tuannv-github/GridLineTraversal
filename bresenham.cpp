#include "bresenham.h"

std::vector<IPoint> bresenham(IPoint start, IPoint stop){
    std::vector<IPoint>points;

    int dx = abs(start.x - stop.x); 
    int dy = abs(start.y - stop.y);

    if(dx > dy){
        int inc1 = 2*dy;
        int inc2 = 2*(dy-dx);
        points.push_back(IPoint(start.x, start.y));

        int x = start.x;
        int y = start.y;
        int d = 2*dy - dx;

        if(start.x < stop.x){
            if(start.y < stop.y){
                while (x < stop.x) {
                    x++;
                    if (d<0) {
                        d+=inc1;
                    } else {
                        y++; d+=inc2;
                    }
                    points.push_back(IPoint(x, y));
                }
            }
            else{
                while (x < stop.x) {
                    x++;
                    if (d<0) {
                        d+=inc1;
                    } else {
                        y--; d+=inc2;
                    }
                    points.push_back(IPoint(x, y));
                }
            }
        }
        else{
            if(start.y < stop.y){
                while (x > stop.x) {
                    x--;
                    if (d<0) {
                        d+=inc1;
                    } else {
                        y++; d+=inc2;
                    }
                    points.push_back(IPoint(x, y));
                }
            }
            else{
                while (x > stop.x) {
                    x--;
                    if (d<0) {
                        d+=inc1;
                    } else {
                        y--; d+=inc2;
                    }
                    points.push_back(IPoint(x, y));
                }
            }
        }
    }
    else{
        int inc1 = 2*dx;
        int inc2 = 2*(dx-dy);
        points.push_back(IPoint(start.x, start.y));

        int x = start.x;
        int y = start.y;
        int d = 2*dx - dy;

        if(start.y < stop.y){
            if(start.x < stop.x){
                while (y < stop.y) {
                    y++;
                    if (d<0) {
                        d+=inc1;
                    } else {
                        x++; d+=inc2;
                    }
                    points.push_back(IPoint(x, y));
                }
            }
            else{
                while (y < stop.y) {
                    y++;
                    if (d<0) {
                        d+=inc1;
                    } else {
                        x--; d+=inc2;
                    }
                    points.push_back(IPoint(x, y));
                }
            }
        }
        else{
            if(start.x < stop.x){
                while (y > stop.y) {
                    y--;
                    if (d<0) {
                        d+=inc1;
                    } else {
                        x++; d+=inc2;
                    }
                    points.push_back(IPoint(x, y));
                }
            }
            else{
                while (y > stop.y) {
                    y--;
                    if (d<0) {
                        d+=inc1;
                    } else {
                        x--; d+=inc2;
                    }
                    points.push_back(IPoint(x, y));
                }
            }
        }
    }

    return points;
}
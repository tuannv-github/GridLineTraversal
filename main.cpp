#include <iostream>
#include <GridLineTraversal.h>

#include "bresenham.h"
#include "Points.h"

#define  START_POINT IPoint(0,0)   
#define  END_POINT IPoint(-6,10)

int main(void){
    GridLineTraversalLine line;
    line.points = new IPoint[100];
    GridLineTraversal::grid_line(START_POINT, END_POINT, &line);

    std::cout << "START POINT: " << START_POINT << std::endl;
    std::cout << "END POINT: " << END_POINT << std::endl;
    std::cout << "Point list: " << std::endl;
    for(int i = 0; i < line.num_points; i++){
        std::cout << line.points[i] << std::endl;
    }

    std::vector<IPoint> points = bresenham(START_POINT, END_POINT);

    std::cout << "START POINT: " << START_POINT << std::endl;
    std::cout << "END POINT: " << END_POINT << std::endl;
    std::cout << "Point list: " << std::endl;
    for(int i = 0; i < points.size() ; i++){
        std::cout << points[i] << std::endl;
    }

    return 0;
}
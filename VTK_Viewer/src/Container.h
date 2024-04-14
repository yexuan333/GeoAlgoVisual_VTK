#pragma once

#include <vector>
#include "Point3d.h"
class Container
{
private:
    std::vector<Point3d> points;
public:
    Container(/* args */);
    ~Container();
    void AddPoint(const Point3d& point){
        points.push_back(point);
    }
};
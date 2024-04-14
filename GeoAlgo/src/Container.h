#pragma once

#include "Stdafx.h"
#include "Point3d.h"
class Container
{
public:
    Container() {}
    ~Container() {}
void AddPoint3d (const Point3d& S);
void Wirte(std::string&& filename);
void Read(std::string&& file);
GETTER(std::vector<Point3d>, Points, m_points)
private:
    std::vector<Point3d> m_points;
};
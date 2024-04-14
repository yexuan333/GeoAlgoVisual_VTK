#pragma once
#include "Stdafx.h"
#include "Point3d.h"
class Line
{
public:
    Line(){}
    Line(const Point3d start, const Point3d end) : m_start(start), m_end(end){}
    SETTERANDGETTER(Point3d, Start, m_start)
    SETTERANDGETTER(Point3d, End, m_end)
private:
    Point3d m_start;
    Point3d m_end;
};
#pragma once

#include "Stdafx.h"
#include "MathPoint.h"
class Container
{
public:
    Container() {}
    ~Container() {}
void AddMathPoint (const MathPoint& S);
void Wirte(std::string&& filename);
void Read(std::string&& file);
GETTER(std::vector<MathPoint>, Points, m_points)
private:
    std::vector<MathPoint> m_points;
};
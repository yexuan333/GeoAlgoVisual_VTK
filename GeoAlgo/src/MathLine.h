#pragma once
#include "Stdafx.h"
#include "MathPoint.h"
class MathLine
{
public:
    MathLine(){}
    MathLine(const MathPoint start, const MathPoint end) : m_start(start), m_end(end){}
    SETTERANDGETTER(MathPoint, Start, m_start)
    SETTERANDGETTER(MathPoint, End, m_end)
private:
    MathPoint m_start;
    MathPoint m_end;
};
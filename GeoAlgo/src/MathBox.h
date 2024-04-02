#pragma once
#include "Stdafx.h"
#include "MathPoint.h"

class MathBox{
public:
    MathBox(){}
    MathBox(MathPoint low, MathPoint high) : m_low(low), m_high(high){}
    SETTERANDGETTER(MathPoint, Low, m_low)
    SETTERANDGETTER(MathPoint, High, m_high)
    MathPoint* CalculateVertex(){
        MathPoint vertexes[8];
        vertexes[0] = m_low;
        vertexes[1] = MathPoint(m_high.getX(), m_low.getY(),  m_low.getZ());
        vertexes[2] = MathPoint(m_high.getX(), m_high.getY(),  m_low.getZ());
        vertexes[3] = MathPoint(m_low.getX(), m_high.getY(),  m_low.getZ());
        vertexes[4] = MathPoint(m_low.getX(), m_low.getY(),  m_high.getZ());
        vertexes[5] = MathPoint(m_high.getX(), m_low.getY(),  m_high.getZ());
        vertexes[6] = m_high;
        vertexes[7] = MathPoint(m_low.getX(), m_high.getY(),  m_high.getZ());
        return vertexes;
    }
    void unionBox(const MathBox& b) {
        m_low.setX(std::min(m_low.getX(), b.getLow().getX()));
        m_low.setY(std::min(m_low.getY(), b.getLow().getY()));
        m_low.setZ(std::min(m_low.getZ(), b.getLow().getZ()));
        m_high.setX(std::max(m_high.getX(), b.getHigh().getX()));
        m_high.setY(std::max(m_high.getY(), b.getHigh().getY()));
        m_high.setZ(std::max(m_high.getZ(), b.getHigh().getZ()));
    }
    void unionPoint(const MathPoint& p) {
        m_low.setX(std::min(m_low.getX(), p.getX()));
        m_low.setY(std::min(m_low.getY(), p.getY()));
        m_low.setZ(std::min(m_low.getZ(), p.getZ()));
        m_high.setX(std::max(m_high.getX(), p.getX()));
        m_high.setY(std::max(m_high.getY(), p.getY()));
        m_high.setZ(std::max(m_high.getZ(), p.getZ()));
    }
    double halfArea() const{
        auto xlen = m_high.getX() - m_low.getX();
        auto ylen = m_high.getY() - m_low.getY();
        auto zlen = m_high.getZ() - m_low.getZ();
        return (xlen + ylen)* zlen + xlen * ylen;
    }
    MathPoint getBoxCenter() {
        return (m_high + m_low) / 2;
    }
    MathVector getDiagonal() {
        return m_high - m_low;
    }
private:
    MathPoint m_low;
    MathPoint m_high;
};
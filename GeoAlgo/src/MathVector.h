#pragma once
#include "Stdafx.h"
#include <stdexcept>

class MathVector{
public:
  MathVector() : x(0.),y (0.),z (0.){}
  MathVector (const double theX, const double theY, const double theZ) : x (theX), y (theY), z (theZ){}
  SETTERANDGETTER(double, X, x)
  SETTERANDGETTER(double, Y, y)
  SETTERANDGETTER(double, Z, z)
  double getCoor(int index) {
      if (index == 0) {
          return x;
      }
      else if (index == 1) {
          return y;
      }
      else if(index == 2)
      {
          return z;
      }
      throw std::runtime_error("getCoor index only be 1 to 3");
  }

  friend MathVector operator / (double factor, const MathVector& other) {
      return MathVector(factor / other.getX(), factor / other.getY(), factor / other.getZ());
  }
  MathVector operator / (const MathVector& other) {
      return MathVector(x / other.getX(), y / other.getY(), z / other.getZ());
  }
  MathVector operator + (const MathVector& other) {
      return MathVector(x + other.getX(), y + other.getY(), z + other.getZ());
  }
  MathVector operator * (double factor) {
      return MathVector(x * factor, y * factor, z * factor);
  }
  friend MathVector operator * (double factor, const MathVector& other) {
      return MathVector(factor * other.getX(), factor * other.getY(), factor * other.getZ());
  }
private:
  double x;
  double y;
  double z;
};
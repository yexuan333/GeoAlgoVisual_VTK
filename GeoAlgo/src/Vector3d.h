#pragma once
#include "Stdafx.h"
#include <stdexcept>

class Vector3d{
public:
  Vector3d() : x(0.),y (0.),z (0.){}
  Vector3d (const double theX, const double theY, const double theZ) : x (theX), y (theY), z (theZ){}
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

  friend Vector3d operator / (double factor, const Vector3d& other) {
      return Vector3d(factor / other.getX(), factor / other.getY(), factor / other.getZ());
  }
  Vector3d operator / (const Vector3d& other) {
      return Vector3d(x / other.getX(), y / other.getY(), z / other.getZ());
  }
  Vector3d operator + (const Vector3d& other) {
      return Vector3d(x + other.getX(), y + other.getY(), z + other.getZ());
  }
  Vector3d operator * (double factor) {
      return Vector3d(x * factor, y * factor, z * factor);
  }
  friend Vector3d operator * (double factor, const Vector3d& other) {
      return Vector3d(factor * other.getX(), factor * other.getY(), factor * other.getZ());
  }
private:
  double x;
  double y;
  double z;
};
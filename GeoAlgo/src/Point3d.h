#pragma once
#include "Stdafx.h"
#include "Vector3d.h"
#include <fstream>
#include "StreamUtil.h"

class Point3d 
{
public:
  Point3d() : x(0.),y (0.),z (0.){}
  Point3d (const double theX, const double theY, const double theZ) : x (theX), y (theY), z (theZ){}
  SETTERANDGETTER(double, X, x)
  SETTERANDGETTER(double, Y, y)
  SETTERANDGETTER(double, Z, z)
  explicit operator Vector3d() const {
	  return Vector3d(x, y, z);
  }
  double getCoor(int index) {
      if (index == 0) {
          return x;
      }
      else if (index == 1) {
          return y;
      }
      else if (index == 2)
      {
          return z;
      }
      throw std::runtime_error("getCoor index only be 1 to 3");
  }


  void serialise(std::ofstream& stream) {
	  stream << x << ' ' << y << ' ' << z << '\n';
  }
  void deserialise(std::ifstream& stream) {
	  stream >> x >> y >> z;
  }
  Point3d operator +(const Point3d& other) {
	  return Point3d(x + other.x, y + other.y, z + other.z);
  }
  Point3d operator /(double factor) {
	  return Point3d(x / factor, y / factor, z / factor);
  }
  Vector3d operator -(const Point3d& other) {
	  return Vector3d(x - other.x, y - other.y, z - other.z);
  }
private:
  double x;
  double y;
  double z;
};
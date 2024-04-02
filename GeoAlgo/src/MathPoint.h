#pragma once
#include "Stdafx.h"
#include "MathVector.h"
#include <fstream>
#include "StreamUtil.h"

class MathPoint 
{
public:
  MathPoint() : x(0.),y (0.),z (0.){}
  MathPoint (const double theX, const double theY, const double theZ) : x (theX), y (theY), z (theZ){}
  SETTERANDGETTER(double, X, x)
  SETTERANDGETTER(double, Y, y)
  SETTERANDGETTER(double, Z, z)
  explicit operator MathVector() const {
	  return MathVector(x, y, z);
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
  MathPoint operator +(const MathPoint& other) {
	  return MathPoint(x + other.x, y + other.y, z + other.z);
  }
  MathPoint operator /(double factor) {
	  return MathPoint(x / factor, y / factor, z / factor);
  }
  MathVector operator -(const MathPoint& other) {
	  return MathVector(x - other.x, y - other.y, z - other.z);
  }
private:
  double x;
  double y;
  double z;
};
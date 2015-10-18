#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3d.h"
#include <iostream>
#include <cmath>

class Quaternion {
public:
  Quaternion(const float x, const float y, const float z, const float w);
  Quaternion(const Quaternion& rhs);
  ~Quaternion();
  Quaternion& operator=(const Quaternion& rhs);
  bool operator==(const Quaternion& rhs);
  float get_x() const;
  float get_y() const;
  float get_z() const;
  float get_w() const;
  void set_x(const float x);
  void set_y(const float y);
  void set_z(const float z);
  void set_w(const float w);
  float magnitude() const;
  friend std::ostream& operator<<(std::ostream& ostr, const Quaternion& quaternion);
  Quaternion add(const Quaternion& rhs) const;
  Quaternion operator+(const Quaternion& rhs) const;
  Quaternion subtract(const Quaternion& rhs) const;
  Quaternion operator-(const Quaternion& rhs) const;
  Quaternion multiply(const Quaternion& rhs) const;
  Quaternion operator*(const Quaternion& rhs) const;
private:
  float* w, *x, *y, *z;
};

#endif
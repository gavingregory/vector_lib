#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3d.h"
#include <iostream>
#include <cmath>

/**
 * Defines a quaternion, and provides basic quaternion math operations.
 */
class Quaternion {
public:
  Quaternion();
  Quaternion(const float x, const float y, const float z, const float w);
  Quaternion(const int w);
  Quaternion(const Quaternion& rhs);
  ~Quaternion();
  Quaternion& operator=(const Quaternion& rhs);
  bool operator==(const Quaternion& rhs);
  bool operator!=(const Quaternion& rhs);
  float get_x() const;
  float get_y() const;
  float get_z() const;
  float get_w() const;
  float magnitude() const;
  friend std::ostream& operator<<(std::ostream& ostr, const Quaternion& quaternion);
  friend std::istream& operator>>(std::istream& input, Quaternion& quaternion);
  Quaternion operator+(const Quaternion& rhs) const;
  Quaternion operator-(const Quaternion& rhs) const;
  Quaternion operator*(const Quaternion& rhs) const;
  Quaternion operator+=(const Quaternion& rhs);
  Quaternion operator-=(const Quaternion& rhs);
  Quaternion operator*=(const Quaternion& rhs);
  Quaternion operator--();
  Quaternion operator--(int);
  Quaternion operator++();
  Quaternion operator++(int);
private:
  float *a;
};

#endif
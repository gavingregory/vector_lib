#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <cmath>
#include <assert.h>

/**
 * Defines a Vector, and provides basic Vector math operations.
 */
class Vector3dStack {
public:
  Vector3dStack();
  Vector3dStack(const float x, const float y, const float z);
  Vector3dStack(const Vector3dStack& rhs);
  ~Vector3dStack();
  Vector3dStack& operator=(const Vector3dStack& rhs);
  bool operator==(const Vector3dStack& rhs);
  float get_x() const;
  float get_y() const;
  float get_z() const;
  void set_x(const float x);
  void set_y(const float y);
  void set_z(const float z);
  float magnitude() const;
  friend std::ostream& operator<<(std::ostream& ostr, const Vector3dStack& vector);
  friend std::istream& operator>>(std::istream& input, Vector3dStack& vector);
  Vector3dStack add(const Vector3dStack& rhs) const;
  Vector3dStack operator+(const Vector3dStack& rhs) const;
  Vector3dStack operator-(const Vector3dStack& rhs) const;
  Vector3dStack operator*(const float scalar) const;
  Vector3dStack operator/(const float scalar) const;
  Vector3dStack vector_product(const Vector3dStack& rhs) const;
  Vector3dStack operator%(const Vector3dStack& rhs) const;
  float scalar_product(const Vector3dStack& rhs) const;
  float operator*(const Vector3dStack& rhs) const;
  Vector3dStack unit_vector() const;
  Vector3dStack unit_vector_orthogonal(const Vector3dStack& rhs) const;

private:
  float x, y, z;
};

#endif
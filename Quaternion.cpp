#include "Quaternion.h"
#include <iostream>

Quaternion::Quaternion(const float x, const float y, const float z, const float w):
x(new float(x)), y(new float(y)), z(new float(z)), w(new float(w)) {

}

/**
 * copy constructor ensures that all referenced objects get copied correctly
 */
Quaternion::Quaternion(const Quaternion& copy_from) {
  w = new float(copy_from.get_w());
  x = new float(copy_from.get_x());
  y = new float(copy_from.get_y());
  z = new float(copy_from.get_z());
}

Quaternion::~Quaternion() {
  std::cout << "deleting quaternion (" << *w << "," << *x 
    << "," << *y << "," << *z << ")" << std::endl;
  delete w;
  delete x;
  delete y;
  delete z;
  w = x = y = z = NULL;
}

float Quaternion::get_x() const {
  return *x;
}

float Quaternion::get_y() const {
  return *y;
}

float Quaternion::get_z() const {
  return *z;
}

float Quaternion::get_w() const {
  return *w;
}

void Quaternion::set_x(const float x) {
  *(this->x) = x;
}

void Quaternion::set_y(const float y) {
  *(this->y) = y;
}

void Quaternion::set_z(const float z) {
  *(this->z) = z;
}

void Quaternion::set_w(const float w) {
  *(this->w) = w;
}

float Quaternion::magnitude() const {
  static const int POWER = 2;
  // no need to guard against negative input for sqrt, result of n^2 always positive
  return sqrt(pow(*x, POWER) + pow(*y, POWER)
    + pow(*z, POWER) + pow(*w, POWER));
}

Quaternion Quaternion::add(const Quaternion& rhs) const {
  return Quaternion(
    *x + rhs.get_x(),
    *y + rhs.get_y(),
    *z + rhs.get_z(),
    *w + rhs.get_w());
}

Quaternion Quaternion::operator+(const Quaternion& rhs) const {
  return add(rhs);
}

Quaternion Quaternion::subtract(const Quaternion& rhs) const {
  return Quaternion(
    *x - rhs.get_x(),
    *y - rhs.get_y(),
    *z - rhs.get_z(),
    *w - rhs.get_w());
}

Quaternion Quaternion::operator - (const Quaternion& rhs) const {
  return subtract(rhs);
}

Quaternion Quaternion::multiply(const Quaternion& rhs) const {
  return Quaternion(
    *w * rhs.get_z() + *x * rhs.get_y() - *y * rhs.get_x() + *z * rhs.get_w(),
    *w * rhs.get_w() - *x * rhs.get_x() - *y * rhs.get_y() - *z * rhs.get_z(),
    *w * rhs.get_x() + *x * rhs.get_w() + *y * rhs.get_z() - *z * rhs.get_y(),
    *w * rhs.get_y() - *x * rhs.get_z() + *y * rhs.get_w() + *z * rhs.get_x()
    );
}

Quaternion Quaternion::operator*(const Quaternion& rhs) const {
  return multiply(rhs);
}

// normalise ??? = x/magnitude, y/magnitude, z/magnitude, w/magnitude
// SAME AS NORMALISING A VECTOR <-- google


/* 
  q.w component = cos(angle of rotation / 2)
  q.x           = axis.x * sin (angle of rot / 2)
  q.y           = axis.y * sin (angle of rot / 2)
  q.z           = axis.z * sin (angle of rot / 2)
 
 to rotate by a q:
  v = q * w * invQ
 
 */
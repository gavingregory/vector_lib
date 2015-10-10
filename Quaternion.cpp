#include "Quaternion.h"
#include <iostream>

Quaternion::Quaternion(const float x, const float y, const float z, const float w):
v(new Vector3dStack(x,y,z)), w(new float(w)) {

}

Quaternion::Quaternion(const Vector3dStack& vector, const float w):
v(new Vector3dStack(vector.get_x(), vector.get_y(), vector.get_z())), w(new float(w)) {
  
}

/**
 * copy constructor ensures that all referenced objects get copied correctly
 */
Quaternion::Quaternion(const Quaternion& copy_from) {
  w = new float(copy_from.get_w());
  v = new Vector3dStack(copy_from.get_x(), copy_from.get_y(), copy_from.get_z());
}

Quaternion::~Quaternion() {
  std::cout << "deleting quaternion (" << *w << "," << v->get_x() 
    << "," << v->get_y() << "," << v->get_z() << ")" << std::endl;
  delete w;
  delete v;
  w = NULL;
  v = NULL;
}

float Quaternion::get_x() const {
  return v->get_x();
}

float Quaternion::get_y() const {
  return v->get_y();
}

float Quaternion::get_z() const {
  return v->get_z();
}

float Quaternion::get_w() const {
  return *w;
}

void Quaternion::set_x(const float x) {
  this->v->set_x(x);
}

void Quaternion::set_y(const float y) {
  this->v->set_y(y);
}

void Quaternion::set_z(const float z) {
  this->v->set_z(z);
}

void Quaternion::set_w(const float w) {
  *(this->w) = w;
}

float Quaternion::magnitude() const {
  static const int POWER = 2;
  // no need to guard against negative input for sqrt, result of n^2 always positive
  return sqrt(pow(v->get_x(), POWER) + pow(v->get_y(), POWER)
    + pow(v->get_z(), POWER) + pow(*w, POWER));
}

Quaternion Quaternion::add(const Quaternion& rhs) const {
  return Quaternion(
    v->get_x() + rhs.get_x(),
    v->get_y() + rhs.get_y(),
    v->get_z() + rhs.get_z(),
    get_w() + rhs.get_w());
}

Quaternion Quaternion::operator+(const Quaternion& rhs) const {
  return add(rhs);
}

Quaternion Quaternion::subtract(const Quaternion& rhs) const {
  return Quaternion(
    v->get_x() - rhs.get_x(),
    v->get_y() - rhs.get_y(),
    v->get_z() - rhs.get_z(),
    *w - rhs.get_w());
}

Quaternion Quaternion::operator - (const Quaternion& rhs) const {
  return subtract(rhs);
}

Quaternion Quaternion::multiply(const Quaternion& rhs) const {
  return Quaternion(
    get_w() * rhs.get_w() - v->get_x() * rhs.get_x() - v->get_y() * rhs.get_y() - v->get_z() * rhs.get_z(),
    get_w() * rhs.get_x() + v->get_x() * rhs.get_w() + v->get_y() * rhs.get_z() - v->get_z() * rhs.get_y(),
    get_w() * rhs.get_y() - v->get_x() * rhs.get_z() + v->get_y() * rhs.get_w() + v->get_z() * rhs.get_x(),
    get_w() * rhs.get_z() + v->get_x() * rhs.get_y() - v->get_y() * rhs.get_x() + v->get_z() * rhs.get_w()
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
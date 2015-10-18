#include "Quaternion.h"
#include <iostream>

Quaternion::Quaternion(const float x, const float y, const float z, const float w):
x(new float(x)), y(new float(y)), z(new float(z)), w(new float(w)) {

}

/**
 * Copy constructor is called when assigning to a new instance of object from another instance.
 * This means it needs to create NEW variables instead of updating the old ones (as you would do
 * overloading = operator
 */
Quaternion::Quaternion(const Quaternion& rhs) {
  w = new float(rhs.get_w());
  x = new float(rhs.get_x());
  y = new float(rhs.get_y());
  z = new float(rhs.get_z());
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


Quaternion& Quaternion::operator=(const Quaternion& rhs) {
  if (this == &rhs) return (*this);

  // release old memory
  delete w;
  delete x;
  delete y;
  delete z;
  // assign new data
  w = new float(rhs.get_w());
  x = new float(rhs.get_x());
  y = new float(rhs.get_y());
  z = new float(rhs.get_z());
  return *this;
}

bool Quaternion::operator==(const Quaternion& rhs) {
  if (this == &rhs) return true;

  if (this->get_x() == rhs.get_x() &&
    this->get_y() == rhs.get_y() &&
    this->get_z() == rhs.get_z() &&
    this->get_w() == rhs.get_w())
    return true;
  return false;
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

std::ostream& operator<<(std::ostream& ostr, const Quaternion& quaternion) {
  ostr << "(w,x,y,z): (" << quaternion.get_w() << "," << quaternion.get_x() << "," << quaternion.get_y() << "," << quaternion.get_z() << ")";
  return ostr;
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
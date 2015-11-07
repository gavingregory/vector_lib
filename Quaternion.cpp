#include "Quaternion.h"

#pragma region Constructors_Destructors

// default constructor
Quaternion::Quaternion(): x(new float(0.0f)), y(new float(0.0f)), z(new float(0.0f)), w(new float(0.0f)) { }

// constructor that takes x,y,z,w parameters
Quaternion::Quaternion(const float x, const float y, const float z, const float w):
x(new float(x)), y(new float(y)), z(new float(z)), w(new float(w)) { }

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

Quaternion::Quaternion(const int w):
  x(new float(0.0f)), y(new float(0.0f)), z(new float(0.0f)), w(new float((float)w)){}

Quaternion::~Quaternion() {
  // uncomment the following line to observe when quaternions are being deconstructed:
  std::cout << "deleting quaternion" << *this << std::endl;
  delete w;
  delete x;
  delete y;
  delete z;
  w = x = y = z = NULL;
}

#pragma endregion Constructors_Destructors

#pragma region Operator_Overloads

// assignment operator
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

// equality operator overload
bool Quaternion::operator==(const Quaternion& rhs) {
  if (this == &rhs) return true;

  if (this->get_x() == rhs.get_x() &&
    this->get_y() == rhs.get_y() &&
    this->get_z() == rhs.get_z() &&
    this->get_w() == rhs.get_w())
    return true;
  return false;
}

std::ostream& operator<<(std::ostream& ostr, const Quaternion& quaternion) {
  ostr << "(w,x,y,z): (" << *quaternion.w << "," << *quaternion.x << "," << *quaternion.y << "," << *quaternion.z << ")";
  return ostr;
}

std::istream& operator>>(std::istream& input, Quaternion& quaternion) {
  input >> (*quaternion.w) >> (*quaternion.x) >> (*quaternion.y) >> (*quaternion.z);
  return input;
}

Quaternion Quaternion::operator+(const Quaternion& rhs) const {
  return Quaternion(
    *x + rhs.get_x(),
    *y + rhs.get_y(),
    *z + rhs.get_z(),
    *w + rhs.get_w());
}

Quaternion Quaternion::operator - (const Quaternion& rhs) const {
  return Quaternion(
    *x - rhs.get_x(),
    *y - rhs.get_y(),
    *z - rhs.get_z(),
    *w - rhs.get_w());
}

Quaternion Quaternion::operator*(const Quaternion& rhs) const {
  return Quaternion(
    *w * rhs.get_z() + *x * rhs.get_y() - *y * rhs.get_x() + *z * rhs.get_w(),
    *w * rhs.get_w() - *x * rhs.get_x() - *y * rhs.get_y() - *z * rhs.get_z(),
    *w * rhs.get_x() + *x * rhs.get_w() + *y * rhs.get_z() - *z * rhs.get_y(),
    *w * rhs.get_y() - *x * rhs.get_z() + *y * rhs.get_w() + *z * rhs.get_x()
    );
}

#pragma endregion Operator_Overloads

#pragma region Getter_Setters

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

#pragma endregion Getter_Setters

#pragma region Functions

float Quaternion::magnitude() const {
  static const int POWER = 2;
  // no need to guard against negative input for sqrt, result of n^2 always positive
  return sqrt(pow(*x, POWER) + pow(*y, POWER)
    + pow(*z, POWER) + pow(*w, POWER));
}

#pragma endregion Functions
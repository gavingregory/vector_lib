#include "Quaternion.h"
#define SIZE 4
#define X 0
#define Y 1
#define Z 2
#define W 3

#pragma region Constructors_Destructors

// default constructor
Quaternion::Quaternion():
  a(new float[SIZE]{0.0f, 0.0f, 0.0f, 0.0f}) { }

// constructor that takes x,y,z,w parameters
Quaternion::Quaternion(const float x, const float y, const float z, const float w):
  a(new float[SIZE]{x,y,z,w}) { }

// copy constructor that copies the values from the rhs Quaternion
Quaternion::Quaternion(const Quaternion& rhs):
  a(new float[SIZE] {rhs.a[X], rhs.a[Y], rhs.a[Z], rhs.a[W]}) { }

// constructor that takes an integer and initialises w with that value
Quaternion::Quaternion(const int w):
  a(new float[SIZE] {0.0f, 0.0f, 0.0f, (float)w}) { }

// destructor
Quaternion::~Quaternion() {
  // uncomment the following line to observe when quaternions are being deconstructed:
  std::cout << "deleting quaternion" << *this << std::endl;
  delete[] a;
  // usually assign a pointer to null when deleting, but commented out for performance reasons.
  // this pointer will not exist after this line anyways.
  //a = NULL; 
}

#pragma endregion Constructors_Destructors

#pragma region Operator_Overloads

// assignment operator
Quaternion& Quaternion::operator=(const Quaternion& rhs) {
  if (this == &rhs) return (*this);

  // release old memory
  delete[] a;
  // assign new data
  a = new float[SIZE] {rhs.a[X], rhs.a[Y], rhs.a[Z], rhs.a[W]};
  return *this;
}

// equality operator overload
bool Quaternion::operator==(const Quaternion& rhs) {
  if (this == &rhs) return true;

  if (this->a[X] == rhs.a[X] &&
    this->a[Y] == rhs.a[Y] &&
    this->a[Z] == rhs.a[Z] &&
    this->a[W] == rhs.a[W])
    return true;
  return false;
}

// inequality operator overload
bool Quaternion::operator!=(const Quaternion& rhs) {
  if (this == &rhs) return false;

  if ((this->a[X] == rhs.a[X]) &&
      (this->a[Y] == rhs.a[Y]) &&
      (this->a[Z] == rhs.a[Z]) &&
      (this->a[W] == rhs.a[W]))
    return false;
  return true;
}

// reduce each value by 1
Quaternion Quaternion::operator--() {
  (a[X])--; (a[Y])--; (a[Z])--; (a[W])--;
  return *this;
}

// reduce each value by 1 (post decrement)
Quaternion Quaternion::operator--(int) {
  Quaternion tmp(*this);
  operator--();
  return tmp;
}

// increment each value by 1
Quaternion Quaternion::operator++() {
  (a[X])++; (a[Y])++; (a[Z])++; (a[W])++;
  return *this;
}

// increment each value by 1 (pre increment)
Quaternion Quaternion::operator++(int) {
  Quaternion tmp(*this);
  operator++();
  return tmp;
}

// output stream overload
std::ostream& operator<<(std::ostream& ostr, const Quaternion& quaternion) {
  ostr << "(w,x,y,z): (" << quaternion.a[W] << "," << quaternion.a[X] << "," << quaternion.a[Y] << "," << quaternion.a[Z] << ")";
  return ostr;
}

// input stream overload
std::istream& operator>>(std::istream& input, Quaternion& quaternion) {
  input >> (quaternion.a[W]) >> (quaternion.a[X]) >> (quaternion.a[Y]) >> (quaternion.a[Z]);
  return input;
}

// addition overload
Quaternion Quaternion::operator+(const Quaternion& rhs) const {
  return Quaternion(
    a[X] + rhs.a[X],
    a[Y] + rhs.a[Y],
    a[Z] + rhs.a[Z],
    a[W] + rhs.a[W]);
}

// subtraction overload
Quaternion Quaternion::operator-(const Quaternion& rhs) const {
  return Quaternion(
    a[X] - rhs.a[X],
    a[Y] - rhs.a[Y],
    a[Z] - rhs.a[Z],
    a[W] - rhs.a[W]);
}

// multiplication overload
Quaternion Quaternion::operator*(const Quaternion& rhs) const {
  return Quaternion(
    a[W] * rhs.a[Z] + a[X] * rhs.a[Y] - a[Y] * rhs.a[X] + a[Z] * rhs.a[W],
    a[W] * rhs.a[W] - a[X] * rhs.a[X] - a[Y] * rhs.a[Y] - a[Z] * rhs.a[Z],
    a[W] * rhs.a[X] + a[X] * rhs.a[W] + a[Y] * rhs.a[Z] - a[Z] * rhs.a[Y],
    a[W] * rhs.a[Y] - a[X] * rhs.a[Z] + a[Y] * rhs.a[W] + a[Z] * rhs.a[X]
    );
}

// addition and assignment overload
Quaternion Quaternion::operator+=(const Quaternion& rhs) {
  *this = ((*this) + rhs);
  return *this;
}

// subtraction and assignment overload
Quaternion Quaternion::operator-=(const Quaternion& rhs) {
  *this = ((*this) - rhs);
  return *this;
}

// multiplication and assignment overload
Quaternion Quaternion::operator*=(const Quaternion& rhs) {
  *this = ((*this) * rhs);
  return *this;
}

#pragma endregion Operator_Overloads

#pragma region Getter_Setters

float Quaternion::get_x() const {
  return a[X];
}

float Quaternion::get_y() const {
  return a[Y];
}

float Quaternion::get_z() const {
  return a[Z];
}

float Quaternion::get_w() const {
  return a[W];
}

#pragma endregion Getter_Setters

#pragma region Functions

float Quaternion::magnitude() const {
  // no need to guard against negative input for sqrt, result of n^2 always positive
  // could use pow() function, but it's faster to state x*x rather than pow(x,2)
  return sqrt((a[X]* a[X]) + (a[Y] * a[Y])
    + (a[Z] * a[Z]) + (a[W] * a[W]));
}

#pragma endregion Functions
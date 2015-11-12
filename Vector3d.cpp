#include "Vector3d.h"

#pragma region Constructors_Destructors

// default constructor
Vector3dStack::Vector3dStack():
  x(0.0), y(0.0), z(0.0) { }

// constructor that takes 3 float paremeters
Vector3dStack::Vector3dStack(float x, float y, float z):
  x(x), y(y), z(z) { }

// copy constructor
Vector3dStack::Vector3dStack(const Vector3dStack& rhs):
  x(rhs.x), y(rhs.y), z(rhs.z) { }

// destructor
Vector3dStack::~Vector3dStack() { }

#pragma endregion Constructors_Destructors

#pragma region Operator_Overloads

// assignment operator overload
Vector3dStack& Vector3dStack::operator=(const Vector3dStack& rhs) {
  if (this == &rhs) return (*this);

  // assign new data
  x = rhs.x;
  y = rhs.y;
  z = rhs.z;
  return *this;
}

// equality overload
bool Vector3dStack::operator==(const Vector3dStack& rhs) {
  if (this == &rhs) return true;

  if (this->x == rhs.x &&
    this->y == rhs.y &&
    this->z == rhs.z)
    return true;
  return false;
}

// inequality overload
bool Vector3dStack::operator!=(const Vector3dStack& rhs) {
  if (this == &rhs) return false;

  if (this->x == rhs.x &&
    this->y == rhs.y &&
    this->z == rhs.z)
    return false;
  return true;
}

// operator-- overload
Vector3dStack Vector3dStack::operator--() {
  x--; y--; z--;
  return *this;
}

// operator-- overload (post decrement)
Vector3dStack Vector3dStack::operator--(int) {
  Vector3dStack tmp(*this);
  operator--();
  return tmp;
}

// operator++ overload
Vector3dStack Vector3dStack::operator++() {
  x++; y++; z++;
  return *this;
}

// operator++ overload (post increment)
Vector3dStack Vector3dStack::operator++(int) {
  Vector3dStack tmp(*this);
  operator++();
  return tmp;
}

// output stream overload
std::ostream& operator<<(std::ostream& ostr, const Vector3dStack& vector) {
  ostr << "(x,y,z): (" << vector.x << "," << vector.y << "," << vector.z << ")";
  return ostr;
}

// input stream overload
std::istream& operator>>(std::istream& input, Vector3dStack& vector) {
  input >> (float)vector.x >> (float)vector.y >> (float)vector.z;
  return input;
}

// addition overload
Vector3dStack Vector3dStack::operator+(const Vector3dStack& rhs) const {
  return Vector3dStack(x + rhs.x, y + rhs.y, z + rhs.z);
}

// subtraction overload
Vector3dStack Vector3dStack::operator-(const Vector3dStack& rhs) const {
  return Vector3dStack(x - rhs.x, y - rhs.y, z - rhs.z);
}

// multiplication overload
Vector3dStack Vector3dStack::operator*(const float scalar) const {
  return Vector3dStack(x*scalar, y*scalar, z*scalar);
}

// division overload
Vector3dStack Vector3dStack::operator/(const float scalar) const {
  // check for divide by 0, arguable whether we would do this for performance reasons:
  assert(scalar != 0.0f);
  return Vector3dStack(x / scalar, y / scalar, z / scalar);
}

// vector product overload
Vector3dStack Vector3dStack::operator%(const Vector3dStack& rhs) const {
  return vector_product(rhs);
}

// addition and assignment overload
Vector3dStack Vector3dStack::operator+=(const Vector3dStack& rhs) {
  *this = ((*this) + rhs);
  return *this;
}

// subtraction and assignment overload
Vector3dStack Vector3dStack::operator-=(const Vector3dStack& rhs) {
  *this = ((*this) - rhs);
  return *this;
}

// multiplication and assignment overload
Vector3dStack Vector3dStack::operator*=(const float scalar) {
  *this = ((*this) * scalar);
  return *this;
}

// division and assignment overload
Vector3dStack Vector3dStack::operator/=(const float scalar) {
  *this = ((*this) / scalar);
  return *this;
}

// vector product and assigment overload
Vector3dStack Vector3dStack::operator%=(const Vector3dStack& rhs) {
  *this = ((*this) % rhs);
  return *this;
}

// scalar product overload
float Vector3dStack::operator*(const Vector3dStack& rhs) const {
  return scalar_product(rhs);
}

#pragma endregion Operator_Overloads

#pragma region Getter_Setters

float Vector3dStack::get_x() const {
  return x;
}

float Vector3dStack::get_y() const {
  return y;
}

float Vector3dStack::get_z() const {
  return z;
}

#pragma endregion Getter_Setters

#pragma region Functions

// returns the magnitude of a vector
float Vector3dStack::magnitude() const {
  static const int POWER = 2;
  // no need to guard against negative input for sqrt, result of n^2 always positive
  return sqrt(pow(x, POWER) + pow(y, POWER) + pow(z, POWER));
}

// returns the vector product of two vectors. This will be orthogonal
Vector3dStack Vector3dStack::vector_product(const Vector3dStack& rhs) const {
  return Vector3dStack(
    y*rhs.z - z*rhs.y,
    z*rhs.x - x*rhs.z,
    x*rhs.y - y*rhs.x
    );
}

// returns the scalar product of two vectors
float Vector3dStack::scalar_product(const Vector3dStack& rhs) const {
  return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z));
}

// a unit vector is a vector in the same direction of magnitude 1
Vector3dStack Vector3dStack::unit_vector() const {
  // TODO: guard against divide by 0?
  return Vector3dStack(
    x / magnitude(),
    y / magnitude(),
    z / magnitude()
    );
}

// a unit vector that is orthogonal to the two given vectors. note there are two possible
// orthogonal unit vectors
Vector3dStack Vector3dStack::unit_vector_orthogonal(const Vector3dStack& rhs) const {
  Vector3dStack v = vector_product(rhs);
  std::cout << v << std::endl;
  
  return v.unit_vector();
}

#pragma endregion Functions


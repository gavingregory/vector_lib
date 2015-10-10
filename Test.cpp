#include <iostream>
#include "Vector3d.h"

using namespace std;

void output(Vector3dStack& vector) {
  cout << "v (" << vector.get_x() << "," << vector.get_y() << "," << vector.get_z() << ") " <<
    vector.get_magnitude() << endl;
}

int main() {

  cout << "Executing tests.." << endl;
  Vector3dStack v(9, 8, 7);
  output(v);

  Vector3dStack v2(12, 2, 3);
  output(v2);
  
  // Addition
  Vector3dStack v3 = v.add(v2);
  Vector3dStack v4 = v + v2;
  cout << "v.add(v2)" << endl;
  output(v3);
  cout << "v + v2" << endl;
  output(v4);

  // Subtraction
  v3 = v.subtract(v2);
  v4 = v - v2;
  cout << "v.subtract(v2)" << endl;
  output(v3);
  cout << "v - v2" << endl;
  output(v4);

  // Multiplication
  v3 = v.multiply(2);
  v4 = v * 2;
  cout << "v.multiply(2)" << endl;
  output(v3);
  cout << "v * 2" << endl;
  output(v4);

  // Division
  v3 = v.divide(2);
  v4 = v / 2;
  cout << "v.divide(2)" << endl;
  output(v3);
  cout << "v / 2" << endl;
  output(v4);

  // Vector Product
  v3 = v.vector_product(v2);
  v4 = v % v2;
  cout << "v.vector_product(v2)" << endl;
  output(v3);
  cout << "v % v2" << endl;
  output(v4);

  // Scalar Product
  float f = v.scalar_product(v2);
  float f2 = v * v2;
  cout << "v.scalar_product(v2)" << endl;
  cout << f << endl;
  cout << "v * v2" << endl;
  cout << f2 << endl;

  // Unit Vector
  v3 = v.unit_vector();
  cout << "v.unit_vector()" << endl;
  output(v3);
  
  // Unit Vector Orthogonal
  v4 = v.unit_vector_orthogonal(v2);
  cout << "v.unit_vector_orthogonal(v2)" << endl;
  output(v4);
  
  cout << "If unit_vector_orthogonal is correct, the following should be 0: ";
  cout << v3.scalar_product(v4) << endl;

  return 0;
}

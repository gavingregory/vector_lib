#include <iostream>
#include "Vector3d.h"
#include "Quaternion.h"

using namespace std;

/*
void output(Vector3dStack& vector) {
  cout << "v (" << vector.get_x() << "," << vector.get_y() << "," << vector.get_z() << ") " <<
    vector.magnitude() << endl;
}

*/


int main() {

  cout << "Executing tests.." << endl;
  
  Quaternion* q1 = new Quaternion(1, 2, 3, 4);
  Quaternion* q2 = new Quaternion(5, 4, 3, 2);
  Quaternion q3 = (*q1) * (*q2);
  Quaternion q4 = (*q2) * (*q1);
  cout << q3.get_x() << " " << q3.get_y() << " " << q3.get_z() << " " << q3.get_w() << endl;
  cout << q4.get_x() << " " << q4.get_y() << " " << q4.get_z() << " " << q4.get_w() << endl;

  /*
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
  */

  Quaternion* q = new Quaternion(1,1,1,1);
  Quaternion* q_from_vector = new Quaternion(Vector3dStack(2, 2, 2), 2);
  q->set_w(5);
  q->set_x(6);
  q->set_y(7);
  q->set_z(8);
  delete q;
  delete q_from_vector;

  return 0;
}

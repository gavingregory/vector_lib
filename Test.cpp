#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
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

  Vector3dStack v = Vector3dStack(0.0, 0.0, -5.0);
  float theta = (float)M_PI / 2.0f;
  
  Vector3dStack axis = Vector3dStack(1, 0, 0);
  
  Quaternion q = Quaternion(
    axis.get_x() * sin(theta / 2.0f),
    axis.get_y() * sin(theta / 2.0f),
    axis.get_z() * sin(theta / 2.0f),
    cos(theta / 2.0f)
  );

  Quaternion w = Quaternion(
    v.get_x(),
    v.get_y(),
    v.get_z(),
    0
    );

  Quaternion qinv = Quaternion(
    -q.get_x(),
    -q.get_y(),
    -q.get_z(),
    q.get_w()
    );
  
  Quaternion vRot = q * w * qinv;
  
  cout << "x:" << vRot.get_x() << " y:" << vRot.get_y() << " z:" << vRot.get_z() << " w:" << vRot.get_w() << endl;
  
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

  return 0;
}

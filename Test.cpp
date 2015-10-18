#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include "Vector3d.h"
#include "Quaternion.h"
#include <assert.h>

using namespace std;

/*
void output(Vector3dStack& vector) {
  cout << "v (" << vector.get_x() << "," << vector.get_y() << "," << vector.get_z() << ") " <<
    vector.magnitude() << endl;
}

*/

void testVectorClass();
void testQuaternionClass();

int main() {

  testVectorClass();

  Vector3dStack a(0.0f, 1.0f, 0.0f);

  cout << a << endl;
  Vector3dStack b(1.0f, 0.0f, 0.0f);
  Vector3dStack c = a + b;
  cout << c.get_x() << " " << c.get_y() << " " << c.get_z() << endl;

  Vector3dStack v = Vector3dStack(0.0, 0.0, -5.0);
  float theta = (float)M_PI / 2.0f;

  Vector3dStack axis = Vector3dStack(1, 0, 0);

  Quaternion q = Quaternion(
    axis.get_x() * sin(theta / 2.0f),
    axis.get_y() * sin(theta / 2.0f),
    axis.get_z() * sin(theta / 2.0f),
    cos(theta / 2.0f)
    );

  cout << "QUaternion COUT " << q << endl;

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


void testVectorClass() {
  
  /**
   * Test that the Vector class constructor correctly accepts 3 float values
   */
  Vector3dStack v = Vector3dStack(1.0f, 2.0f, 3.0f);
  assert(v.get_x() == 1.0f);
  assert(v.get_y() == 2.0f);
  assert(v.get_z() == 3.0f);

  /**
   * Test that the Vector class constructor correctly accepts a copy Vector
   */
  Vector3dStack v2(v);
  assert(v2.get_x() == 1.0f);
  assert(v2.get_y() == 2.0f);
  assert(v2.get_z() == 3.0f);

  /**
   * Test get_x(), get_y(), get_z()
   */
  assert(v.get_x() == 1.0f);
  assert(v.get_y() == 2.0f);
  assert(v.get_z() == 3.0f);

  /**
   * Test set_x(), set_y(), set_z()
   */
  v2.set_x(4.0f);
  assert(v2.get_x() == 4.0f);
  v2.set_y(5.0f);
  assert(v2.get_y() == 5.0f);
  v2.set_z(6.0f);
  assert(v2.get_z() == 6.0f);

  /**
   * As v2 was constructed from v, test that a modified value of v2 does not modify
   * value of v (ie values *copied* correctly!)
   */
  assert(v2.get_x() == 4.0f && v.get_x() == 1.0f);

  /**
   * Test that operator= copies values correctly
   */
  v2 = v;
  assert(v2.get_x() == 1.0f);
  assert(v2.get_y() == 2.0f);
  assert(v2.get_z() == 3.0f);

  /**
   * Test that modified v2 values do not affect v (as copy constructor copies ALL private
   * variables, any pointers NOT copied correctly would yield errors here).
   */
  v2.set_x(4.0f);
  assert(v.get_x() == 1.0f);
  v2.set_y(5.0f);
  assert(v.get_y() == 2.0f);
  v2.set_z(6.0f);
  assert(v.get_z() == 3.0f);

  /**
   * Test add() correctly adds two vectors
   * Test operator+ override correctly adds two vectors
   */
  Vector3dStack v3 = v.add(v2);
  assert(v3.get_x() == (v.get_x() + v2.get_x()));
  assert(v3.get_y() == (v.get_y() + v2.get_y()));
  assert(v3.get_z() == (v.get_z() + v2.get_z()));
  Vector3dStack v4 = v + v2;
  assert(v4.get_x() == (v.get_x() + v2.get_x()));
  assert(v4.get_y() == (v.get_y() + v2.get_y()));
  assert(v4.get_z() == (v.get_z() + v2.get_z()));

  /**
   * Test the magnitude() of a Vector is correctly computed
   */
  float x = 3.0f;
  float y = 4.0f;
  float z = 5.0f;
  v.set_x(x); // reset x
  v.set_y(y); // reset y
  v.set_z(z); // reset z
  assert(v.magnitude() == sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));




}

void testQuaternionClass() {

}
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


  Vector3dStack a(1.0f, 2.0f, 1.0f);

  cout << a << endl;
  Vector3dStack b(2.0f, 1.0f, 1.0f);

  Vector3dStack c = a.vector_product(b);
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
  
  float x, y, z, x2, y2, z2, scalar;

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
   * Test operator== is correctly overriden
   */
  assert(Vector3dStack(1.0f, 1.0f, 1.0f) == Vector3dStack(1.0f, 1.0f, 1.0f));
  assert(!(Vector3dStack(1.0f, 1.0f, 1.0f) == Vector3dStack(5.5f, 3.3f, 9.9f)));


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
  Vector3dStack vAdd = v.add(v2);
  assert(vAdd.get_x() == (v.get_x() + v2.get_x()));
  assert(vAdd.get_y() == (v.get_y() + v2.get_y()));
  assert(vAdd.get_z() == (v.get_z() + v2.get_z()));
  Vector3dStack v4 = v + v2;
  assert(vAdd.get_x() == (v.get_x() + v2.get_x()));
  assert(vAdd.get_y() == (v.get_y() + v2.get_y()));
  assert(vAdd.get_z() == (v.get_z() + v2.get_z()));

  /**
   * Test the magnitude() of a Vector is correctly computed
   */
  x = 3.0f;
  y = 4.0f;
  z = 5.0f;
  v.set_x(x); // reset x
  v.set_y(y); // reset y
  v.set_z(z); // reset z
  assert(v.magnitude() == sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

  /**
   * Test subtract() correctly subtracts two vectors
   * Test operator- override correctly subtracts two vectors
   */
  Vector3dStack vSubtract = v.subtract(v2);
  assert(vSubtract.get_x() == (v.get_x() - v2.get_x()));
  assert(vSubtract.get_y() == (v.get_y() - v2.get_y()));
  assert(vSubtract.get_z() == (v.get_z() - v2.get_z()));
  vSubtract = v - v2;
  assert(vSubtract.get_x() == (v.get_x() - v2.get_x()));
  assert(vSubtract.get_y() == (v.get_y() - v2.get_y()));
  assert(vSubtract.get_z() == (v.get_z() - v2.get_z()));

  /**
   * Test multiply() correctly computes a vector multiplied by a scalar value
   * Test operator* override correctly computes a vector multiplied by a scalar value
   */
  scalar = 2.0f;
  Vector3dStack vMultiply = v.multiply(scalar);
  assert(vMultiply.get_x() == (v.get_x() * scalar));
  assert(vMultiply.get_y() == (v.get_y() * scalar));
  assert(vMultiply.get_z() == (v.get_z() * scalar));
  vMultiply = v * scalar;
  assert(vMultiply.get_x() == (v.get_x() * scalar));
  assert(vMultiply.get_y() == (v.get_y() * scalar));
  assert(vMultiply.get_z() == (v.get_z() * scalar));

  /**
   * Test divide() correctly computes a vector divided by a scalar value
   * Test operator/ override correctly computes a vector divided by a scalar value
   */
  scalar = 2.0f;
  Vector3dStack vDivide = v.divide(scalar);
  assert(vDivide.get_x() == (v.get_x() / scalar));
  assert(vDivide.get_y() == (v.get_y() / scalar));
  assert(vDivide.get_z() == (v.get_z() / scalar));
  vDivide = v / scalar;
  assert(vDivide.get_x() == (v.get_x() / scalar));
  assert(vDivide.get_y() == (v.get_y() / scalar));
  assert(vDivide.get_z() == (v.get_z() / scalar));

  /**
   * Test vector_product() correctly computes a vector product  of two vectors
   * Test operator% override correctly computes a vector product of two vectors
   */
  Vector3dStack vProduct = v.vector_product(v2);
  assert(vProduct.get_x() == (v.get_y() * v2.get_z()) - (v.get_z() * v2.get_y()));
  assert(vProduct.get_y() == (v.get_z() * v2.get_x()) - (v.get_x() * v2.get_z()));
  assert(vProduct.get_z() == (v.get_x() * v2.get_y()) - (v.get_y() * v2.get_x()));
  vProduct = v % v2;
  assert(vProduct.get_x() == (v.get_y() * v2.get_z()) - (v.get_z() * v2.get_y()));
  assert(vProduct.get_y() == (v.get_z() * v2.get_x()) - (v.get_x() * v2.get_z()));
  assert(vProduct.get_z() == (v.get_x() * v2.get_y()) - (v.get_y() * v2.get_x()));

  /**
   * Test scalar_product() correctly computes a scalar product  of two vectors
   * Test operator* override correctly computes a scalar product of two vectors
   */
  float result = v.scalar_product(v2);
  assert(result ==
    (v.get_x() * v2.get_x()) +
    (v.get_y() * v2.get_y()) +
    (v.get_z() * v2.get_z())
    );
  result = v * v2;
  assert(result ==
    (v.get_x() * v2.get_x()) +
    (v.get_y() * v2.get_y()) +
    (v.get_z() * v2.get_z())
    );

  /**
  * Test unit_vector() correctly returns a valid unit vector
  */
  Vector3dStack unitVector = v.unit_vector();
  assert(unitVector.get_x() == v.get_x() / v.magnitude());
  assert(unitVector.get_y() == v.get_y() / v.magnitude());
  assert(unitVector.get_z() == v.get_z() / v.magnitude());
  assert(unitVector.magnitude() == 1.0f); // a unit vector must == 1.0f!


  /**
   * Test unit_vector_orthogonal() correctly returns a valid unit vector which is orthogonal
   */
  Vector3dStack vOrthogonal = v.unit_vector_orthogonal(v2);
  assert(v.scalar_product(vOrthogonal) == 0); // scalar product should be 0 if orthogonal!
  assert(v2.scalar_product(vOrthogonal) == 0); // scalar product should be 0 if orthogonal!
  assert(vOrthogonal.magnitude() >= 0.00009f && vOrthogonal.magnitude() <= 1.00001f); // magnitude should be 1 as it's a unit vector!
}

void testQuaternionClass() {

  float x, y, z, x2, y2, z2, scalar;

  /**
  * Test that the Quaternion class constructor correctly accepts 4 float values
  */
  Quaternion q = Quaternion(1.0f, 2.0f, 3.0f, 1.0f);
  assert(q.get_x() == 1.0f);
  assert(q.get_y() == 2.0f);
  assert(q.get_z() == 3.0f);
  assert(q.get_w() == 1.0f);

  /**
  * Test that the Quaternion class constructor correctly accepts a copy Quaternion
  */
  Quaternion q2(q);
  assert(q2.get_x() == 1.0f);
  assert(q2.get_y() == 2.0f);
  assert(q2.get_z() == 3.0f);
  assert(q.get_w() == 1.0f);

  /**
  * Test get_x(), get_y(), get_z(), get_w()
  */
  assert(q.get_x() == 1.0f);
  assert(q.get_y() == 2.0f);
  assert(q.get_z() == 3.0f);
  assert(q.get_w() == 1.0f);

  /**
  * Test set_x(), set_y(), set_z(), set_w()
  */
  q2.set_x(4.0f);
  assert(q2.get_x() == 4.0f);
  q2.set_y(5.0f);
  assert(q2.get_y() == 5.0f);
  q2.set_z(6.0f);
  assert(q2.get_z() == 6.0f);
  q2.set_w(0.0f);
  assert(q2.get_w() == 0.0f);

  /**
  * Test operator== is correctly overriden
  */
  assert(Quaternion(1.0f, 1.0f, 1.0f, 1.0f) == Quaternion(1.0f, 1.0f, 1.0f, 1.0f));
  assert(!(Quaternion(1.0f, 1.0f, 1.0f, 1.0f) == Quaternion(5.5f, 3.3f, 9.9f, 1.0f)));


  /**
  * As q2 was constructed from q, test that a modified value of q2 does not modify
  * value of v (ie pointer values *copied* correctly!)
  */
  assert(q2.get_x() == 4.0f && q.get_x() == 1.0f);

  /**
  * Test that operator= copies values correctly
  */
  q2 = q;
  assert(q2.get_x() == 1.0f);
  assert(q2.get_y() == 2.0f);
  assert(q2.get_z() == 3.0f);
  assert(q2.get_w() == 1.0f);

  /**
  * Test that modified q2 values do not affect q (as copy constructor copies ALL private
  * variables, any pointers NOT copied correctly would yield errors here).
  */
  q2.set_x(4.0f);
  assert(q.get_x() == 1.0f);
  q2.set_y(5.0f);
  assert(q.get_y() == 2.0f);
  q2.set_z(6.0f);
  assert(q.get_z() == 3.0f);
  q2.set_w(5.0f);
  assert(q.get_w() == 1.0f);

  /**
  * Test add() correctly adds two quaternions
  * Test operator+ override correctly adds two quaternions
  */
  Quaternion add = q.add(q2);
  assert(add.get_x() == (q.get_x() + q2.get_x()));
  assert(add.get_y() == (q.get_y() + q2.get_y()));
  assert(add.get_z() == (q.get_z() + q2.get_z()));
  assert(add.get_w() == (q.get_w() + q2.get_w()));
  add = q + q2;
  assert(add.get_x() == (q.get_x() + q2.get_x()));
  assert(add.get_y() == (q.get_y() + q2.get_y()));
  assert(add.get_z() == (q.get_z() + q2.get_z()));
  assert(add.get_w() == (q.get_w() + q2.get_w()));

  /**
  * Test subtract() correctly subtracts two quaternions
  * Test operator- override correctly subtracts two quaternions
  */
  Quaternion sub = q.subtract(q2);
  assert(sub.get_x() == (q.get_x() - q2.get_x()));
  assert(sub.get_y() == (q.get_y() - q2.get_y()));
  assert(sub.get_z() == (q.get_z() - q2.get_z()));
  assert(sub.get_w() == (q.get_w() - q2.get_w()));
  sub = q - q2;
  assert(sub.get_x() == (q.get_x() - q2.get_x()));
  assert(sub.get_y() == (q.get_y() - q2.get_y()));
  assert(sub.get_z() == (q.get_z() - q2.get_z()));
  assert(sub.get_w() == (q.get_w() - q2.get_w()));

  /**
  * Test multiply() correctly computes a quaternion multiplied by another quaternion
  * Test operator* override correctly computes a quaternion multiplication
  */
  Quaternion multiply = q.multiply(q2);
  assert(multiply.get_x() == (q.get_w() * q2.get_z()) +
                             (q.get_x() * q2.get_y()) -
                             (q.get_y() * q2.get_x()) +
                             (q.get_z() * q2.get_w()));

  assert(multiply.get_y() == (q.get_w() * q2.get_w()) -
                             (q.get_x() * q2.get_x()) -
                             (q.get_y() * q2.get_y()) -
                             (q.get_z() * q2.get_z()));

  assert(multiply.get_z() == (q.get_w() * q2.get_x()) +
                             (q.get_x() * q2.get_w()) +
                             (q.get_y() * q2.get_z()) -
                             (q.get_z() * q2.get_y()));

  assert(multiply.get_w() == (q.get_w() * q2.get_y()) -
                             (q.get_x() * q2.get_z()) +
                             (q.get_y() * q2.get_w()) +
                             (q.get_z() * q2.get_x()));
  multiply = q * q2;
  assert(multiply.get_x() == (q.get_w() * q2.get_z()) +
                             (q.get_x() * q2.get_y()) -
                             (q.get_y() * q2.get_x()) +
                             (q.get_z() * q2.get_w()));

  assert(multiply.get_y() == (q.get_w() * q2.get_w()) -
                             (q.get_x() * q2.get_x()) -
                             (q.get_y() * q2.get_y()) -
                             (q.get_z() * q2.get_z()));

  assert(multiply.get_z() == (q.get_w() * q2.get_x()) +
                             (q.get_x() * q2.get_w()) +
                             (q.get_y() * q2.get_z()) -
                             (q.get_z() * q2.get_y()));

  assert(multiply.get_w() == (q.get_w() * q2.get_y()) -
                             (q.get_x() * q2.get_z()) +
                             (q.get_y() * q2.get_w()) +
                             (q.get_z() * q2.get_x()));

}
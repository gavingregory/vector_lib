#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <assert.h>
#include "Vector3d.h"
#include "Quaternion.h"

using namespace std;

void testVectorClass();
void testQuaternionClass();

/**
 * Main method, calls test functions and tests stream input to both Vector and Quaternion objects.
 *
 * NOTE REGARDING BOTTLENECKS
 * Quaternions will likely be much slower to instantiate than Vector objects as variables for
 * Quaternions are stored on the heap, and require a system call to instantiate.
 * In fact, this could be optimised slightly by creating a single array of floats on the heap 
 * per Quaternion object, limiting the system calls to ONE. x,y,z,w could then reference an
 * element of this array.
 */
int main() {

  cout << "Commencing testing ..." << endl;

  testVectorClass();
  cout << "Vector tests completed successfully" << endl;
  testQuaternionClass();
  cout << "Quaternion tests completed successfully" << endl;

  // And finally ....

  // Test input stream
  cout << "Please enter 3 float values for a vector (x,y,z):" << endl;
  Vector3dStack vec = Vector3dStack(1,1,1);
  cin >> vec;
  cout << vec.get_x() << " " << vec.get_y() << " " << vec.get_z() << endl;

  // Test output stream
  cout << "Please enter 4 float values for a quaternion (x,y,z,w):" << endl;
  Quaternion quat = Quaternion(1, 1, 1, 1);
  cin >> quat;
  cout << quat << endl;

  cout << "Please see testVectorClass() and testQuaternionClass() for all tests." << endl
    << "Any failed tests will produce an error when the program is executed." << endl
    << "Seeing this message means that all tests completed successfully!" << endl
    << "Please note, destructor console messages for Quaternion have been left in to" << endl
    << "assure the marker that the destructors are being called when objects go out of" << endl
    << "scope, and therefore all heap objects are being deleted." << endl;

  return 0;
}

/**
 * Contains all tests for the Vector class
 */
void testVectorClass() {

  float x, y, z, scalar;

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
   * Test operator+ override correctly adds two vectors
   */
  Vector3dStack vAdd = v + v2;
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
   * Test operator- override correctly subtracts two vectors
   */
  Vector3dStack vSubtract = v - v2;
  assert(vSubtract.get_x() == (v.get_x() - v2.get_x()));
  assert(vSubtract.get_y() == (v.get_y() - v2.get_y()));
  assert(vSubtract.get_z() == (v.get_z() - v2.get_z()));

  /**
   * Test operator* override correctly computes a vector multiplied by a scalar value
   */
  scalar = 2.0f;
  Vector3dStack vMultiply = v * scalar;
  assert(vMultiply.get_x() == (v.get_x() * scalar));
  assert(vMultiply.get_y() == (v.get_y() * scalar));
  assert(vMultiply.get_z() == (v.get_z() * scalar));

  /**
   * Test operator/ override correctly computes a vector divided by a scalar value
   */
  scalar = 2.0f;
  Vector3dStack vDivide = v / scalar;
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

/**
 * Contains all tests for the Quaternion class
 */
void testQuaternionClass() {

  float x, y, z, w;

  /**
   * Test that the Quaternion class constructor correctly accepts 4 float values
   */
  Quaternion q = Quaternion(1.0f, 2.0f, 3.0f, 1.0f);
  assert(q.get_x() == 1.0f);
  assert(q.get_y() == 2.0f);
  assert(q.get_z() == 3.0f);
  assert(q.get_w() == 1.0f);

  Quaternion qInt = Quaternion(5);
  assert(qInt.get_x() == 0.0f);
  assert(qInt.get_y() == 0.0f);
  assert(qInt.get_z() == 0.0f);
  assert(qInt.get_w() == 5.0f);

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
   * Test operator+ override correctly adds two quaternions
   */
  Quaternion add = q + q2;
  assert(add.get_x() == (q.get_x() + q2.get_x()));
  assert(add.get_y() == (q.get_y() + q2.get_y()));
  assert(add.get_z() == (q.get_z() + q2.get_z()));
  assert(add.get_w() == (q.get_w() + q2.get_w()));

  /**
  * Test the magnitude() of a Quaternion is correctly computed
  */
  x = 3.0f;
  y = 4.0f;
  z = 5.0f;
  w = 1.0f;
  q = Quaternion(x, y, z, w);
  assert(q.magnitude() == sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2)));

  /**
   * Test operator- override correctly subtracts two quaternions
   */
  Quaternion sub = q - q2;
  assert(sub.get_x() == (q.get_x() - q2.get_x()));
  assert(sub.get_y() == (q.get_y() - q2.get_y()));
  assert(sub.get_z() == (q.get_z() - q2.get_z()));
  assert(sub.get_w() == (q.get_w() - q2.get_w()));

  /**
   * Test operator* override correctly computes a quaternion multiplication
   */
  Quaternion multiply = q * q2;

  assert(multiply.get_x() ==
    (q.get_w() * q2.get_z()) +
    (q.get_x() * q2.get_y()) -
    (q.get_y() * q2.get_x()) +
    (q.get_z() * q2.get_w()));

  assert(multiply.get_y() ==
    (q.get_w() * q2.get_w()) -
    (q.get_x() * q2.get_x()) -
    (q.get_y() * q2.get_y()) -
    (q.get_z() * q2.get_z()));

  assert(multiply.get_z() ==
    (q.get_w() * q2.get_x()) +
    (q.get_x() * q2.get_w()) +
    (q.get_y() * q2.get_z()) -
    (q.get_z() * q2.get_y()));

  assert(multiply.get_w() ==
    (q.get_w() * q2.get_y()) -
    (q.get_x() * q2.get_z()) +
    (q.get_y() * q2.get_w()) +
    (q.get_z() * q2.get_x()));

  /**
   * Test that quaternion multiplication is not commutative
   */
  Quaternion commutative1 = q * q2;
  Quaternion commutative2 = q2 * q;
  assert(!(commutative1 == commutative2));

}
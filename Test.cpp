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

  cout << "adding v and v2.." << endl;

  Vector3dStack v3 = v.add(v2);
  output(v3);

  cout << "subtracting v2 from v.." << endl;

  v3 = v.subtract(v2);
  output(v3);

  v3 = v.multiply(2.0);
  cout << "multiplying v by 2" << endl;
  output(v3);

  v3 = v.divide(2);
  cout << "dividing v by 2" << endl;
  output(v3);

  v3 = v.vector_product(v2);
  cout << "vector product and scalar product" << endl;
  output(v3);
  cout << v.scalar_product(v2) << endl;

  cout << "unit vector of v" << endl;
  v3 = v.unit_vector();
  output(v3);

  cout << "unit vector orthogonal v and v2" << endl;
  Vector3dStack v4 = v.unit_vector_orthogonal(v2);
  output(v4);

  cout << v3.scalar_product(v4) << endl;

  cout << "original v, v2 should be unchanged:" << endl;

  output(v);
  output(v2);

  return 0;
}

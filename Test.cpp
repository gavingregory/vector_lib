#include <iostream>
#include "Vector3d.h"

using namespace std;

void output(Vector3dStack& vector) {
  cout << "v (" << vector.get_x() << "," << vector.get_y() << "," << vector.get_z() << ") " <<
    vector.get_magnitude() << endl;
}

int main() {

  cout << "Executing tests.." << endl;

  Vector3dStack v(6, -2, 0.0);
  output(v);

  Vector3dStack v2(-4, 4, 0.0);
  output(v2);

  cout << "adding v and v2.." << endl;

  v.add(v2);
  output(v);

  Vector3dStack v3(1, 1, 0);
  output(v3);

  cout << "subtracting v3 from v.." << endl;

  v.subtract(v3);
  output(v);

  v.multiply(2.0);
  cout << "multiplying v by 2" << endl;
  output(v);

  v.divide(2);
  cout << "dividing v by 2" << endl;
  output(v);

  return 0;
}

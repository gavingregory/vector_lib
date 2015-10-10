#include <iostream>
#include "Vector3d.h"

using namespace std;

int main() {

  cout << "Executing tests.." << endl;

  Vector3dStack v(6, -2, 0.0);
  cout << "v (" << v.get_x() << "," << v.get_y() << "," << v.get_z() << ") " <<
    v.get_magnitude() << endl;

  Vector3dStack v2(-4, 4, 0.0);
  cout << "v2 (" << v2.get_x() << "," << v2.get_y() << "," << v2.get_z() << ") " <<
    v2.get_magnitude() << endl;

  cout << "adding v and v2.." << endl;

  v.add(v2);
  cout << "new v (" << v.get_x() << "," << v.get_y() << "," << v.get_z() << ") " <<
    v.get_magnitude() << endl;

  Vector3dStack v3(1, 1, 0);
  cout << "v3 (" << v3.get_x() << "," << v3.get_y() << "," << v3.get_z() << ") " <<
    v3.get_magnitude() << endl;

  cout << "subtracting v3 from v.." << endl;

  v.subtract(v3);
  cout << "new v(" << v.get_x() << "," << v.get_y() << "," << v.get_z() << ") " <<
    v.get_magnitude() << endl;


  return 0;
}

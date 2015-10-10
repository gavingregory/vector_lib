//TODO: override * and % operators for scalar and vector products
//TODO: constructor
//TODO: copy constructor
//TODO: destructor
//TODO: assignment operator

//TODO: either optimise code for performance or document bottlenecks in code!

class Vector3dStack {
public:
  int get_x() const;
  int get_y() const;
  int get_z() const;
  void set_x(const int v);
  void set_y(const int v);
  void set_z(const int v);
  float get_magnitude() const;
  void add(Vector3dStack rhs);
  void subtract(Vector3dStack rhs);
  void multiply(float scalar);
  void divide(float scalar);
  //TODO: scalar_product();
  //TODO: vector_product();
  //TODO: unit_vector();
  //TODO: unit_vector_orthogonal(); // use vector product!

private:
  float x, y, z;
};

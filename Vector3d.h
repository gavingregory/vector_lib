//TODO: override * and % operators for scalar and vector products
//TODO: constructor
//TODO: copy constructor
//TODO: destructor
//TODO: assignment operator

//TODO: either optimise code for performance or document bottlenecks in code!

class Vector3dStack {
public:
  Vector3dStack(const float x, const float y, const float z);
  Vector3dStack(const Vector3dStack& copy_from);
  ~Vector3dStack();
  float get_x() const;
  float get_y() const;
  float get_z() const;
  void set_x(const float x);
  void set_y(const float y);
  void set_z(const float z);
  float get_magnitude() const;
  Vector3dStack add(const Vector3dStack& rhs) const;
  Vector3dStack subtract(const Vector3dStack& rhs) const;
  Vector3dStack multiply(const float scalar) const;
  Vector3dStack divide(const float scalar) const;
  Vector3dStack vector_product(const Vector3dStack& rhs) const;
  float scalar_product(const Vector3dStack& rhs) const;
  Vector3dStack unit_vector() const;
  Vector3dStack unit_vector_orthogonal(const Vector3dStack& rhs) const;

private:
  float x, y, z;
};


#include <cmath>
#include <string>
#include <tuple>
#include <geometry.hpp>
namespace SimpleObject {
Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

tuple<double, double, double> Vector3D::get_coordinates() {
  return tuple<double, double, double>(this->x, this->y, this->z);
};

std::string Vector3D::convert_to_string() {
  std::string str = "< ";
  str += std::to_string(this->x) + ", ";
  str += std::to_string(this->y) + ", ";
  str += std::to_string(this->z) + " >";
  return str;
};

Vector3D Vector3D::operator+(const Vector3D &v) {
  return Vector3D(this->x + v.x, this->y + v.y, this->z + v.z);
};

Vector3D Vector3D::operator-(const Vector3D &v) {
  return Vector3D(this->x - v.x, this->y - v.y, this->z - v.z);
};
Vector3D Vector3D::operator^(const Vector3D &v) {
  // implement vector cross
  double ux = this->x, uy = this->y, uz = this->z;
  double vx = v.x, vy = v.y, vz = v.z;
  return Vector3D(uy * vz - uz * vy, uz * vx - ux * vz, ux * vy - uy * vx);
};
double Vector3D::operator*(const Vector3D &v) {
  return this->x * v.x + this->y * v.y + this->z * v.z;
};
double Vector3D::size() { return sqrt(*this * *this); };
Vector3D operator*(const Vector3D &vec, double scalar) {
  return Vector3D(vec.x * scalar, vec.y * scalar, vec.z * scalar);
};
Vector3D operator*(double scalar, const Vector3D &vec) { return vec * scalar; };
/*
Point3D operator*(const Point3D& vec, double scalar) {
    return Point3D(vec.x * scalar, vec.y * scalar, vec.z * scalar);
};
Point3D operator*(double scalar, const Point3D& vec){
  return vec * scalar;
};
*/
Point3D::Point3D(double x, double y, double z) : Vector3D(x, y, z){};

Point3D::Point3D(const Vector3D &vec) : Point3D(vec.x, vec.y, vec.z){};

Line3D::Line3D(Point3D start, Point3D end) : start(start), end(end){};

Triangle3D::Triangle3D(Point3D origin_point, Point3D left_point,
                       Point3D right_point, double texture)
    : origin_point(origin_point), left_point(left_point),
      right_point(right_point), texture(texture) {
  get_normal_vector();
};
double Triangle3D::size() {
  Vector3D vr = right_point - origin_point;
  Vector3D vl = left_point - origin_point;
  return (vr ^ vl).size() / 2.0;
}

Vector3D Triangle3D::get_normal_vector() {
  auto _normal = (this->right_point - this->origin_point) ^
                 (this->left_point - this->origin_point);

  if (_normal.size() != 0.0) {
    _normal = _normal * (1.0 / _normal.size());
    this->normal_vector = _normal;
    return _normal;
  }
  return Vector3D(0.0, 0.0, 0.0);
};

Point3D origin_point(0.0, 0.0, 0.0);
Triangle3D null_triangle(origin_point, origin_point, origin_point, 0.0);
}; // namespace SimpleObject

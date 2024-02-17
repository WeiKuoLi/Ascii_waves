#ifndef __PHYSICS_H_
#define __PHYSICS_H_

#include <geometry.hpp>
#include <utility>
#include <vector>
SimpleObject::Triangle3D project_triangle_to_canvas(
    SimpleObject::Triangle3D triangle) {
  // only support canvas sitting on the xz plane facing +y
  // light coming from +z and -z
  if (triangle.normal_vector.y > 0) return SimpleObject::null_triangle;
  SimpleObject::Point3D origin_point = triangle.origin_point;
  SimpleObject::Point3D left_point = triangle.left_point;
  SimpleObject::Point3D right_point = triangle.right_point;

  origin_point.y = 0.0;
  left_point.y = 0.0;
  right_point.y = 0.0;
  SimpleObject::Vector3D vec_r = triangle.right_point - triangle.origin_point;
  SimpleObject::Vector3D vec_l = triangle.left_point - triangle.origin_point;
  vec_l.z = 0.0;
  vec_r.z = 0.0;
  double texture = (vec_r ^ vec_l).size() / 2.0 / triangle.size();
  SimpleObject::Triangle3D projected_triangle(
      origin_point, left_point, right_point, triangle.texture * texture);
  return projected_triangle;
}

#endif

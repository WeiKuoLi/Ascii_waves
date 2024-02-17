#include <cmath>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include <physics.h>
#include <geometry.h>
#include <test.h>
#include <util.h>

int test(void) {
  SimpleObject::Point3D pt(0.1, 0.2, 0.4);
  SimpleObject::Vector3D v(0.4, 0.02, -0.3);
  std::vector<SimpleObject::Point3D> line(10, pt);

  double _t = 1.0;
  for (auto &_p : line) {
    _p = SimpleObject::Point3D(_p * _t);
    _t += 0.01;
  }
  for (auto &_p : line) {
    std::cout << _p.convert_to_string() << endl;
  }
  std::cout << " test add/substract vector" << endl;
  std::cout << (pt + v).convert_to_string() << endl;

  std::cout << (pt - v).convert_to_string() << endl;
  std::cout << " test cross product" << endl;
  std::cout << pt * (pt ^ v) << endl;
  std::cout << v * (v ^ pt) << endl;
  std::cout << " test size" << endl;
  std::cout << pt.size() << endl;

  std::cout << " test triangle" << endl;
  SimpleObject::Point3D origin_pt(0.0, 0.0, 0.0);
  SimpleObject::Point3D left_pt(0.0, 1.0, 1.0);
  SimpleObject::Point3D right_pt(1.0, 0.0, 0.0);
  SimpleObject::Triangle3D triangle(origin_pt, left_pt, right_pt, 1.0);
  std::cout << triangle.normal_vector.convert_to_string() << endl;
  std::cout << "length is ~1: " << triangle.normal_vector.size() << endl;

  print("test print\n");
  std:cout << " test triangle projection" << endl;
  SimpleObject::Triangle3D project_triangle=project_triangle_to_canvas(triangle);
  cout<< project_triangle.origin_point.convert_to_string()<<endl;
  cout<< project_triangle.left_point.convert_to_string()<<endl;
  cout<< project_triangle.right_point.convert_to_string()<<endl;
  cout<< project_triangle.texture<<endl;
  cout<<triangle.size()<<endl;
  cout<<project_triangle.size()<<endl;
  return 0;
};

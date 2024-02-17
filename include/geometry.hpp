#ifndef __GEOMETRY_H_
#define __GEOMETRY_H_
using namespace std;
#include <tuple>
#include <string>

namespace SimpleObject{
  class Vector3D{
  public:
    double x, y, z;
    Vector3D(double x, double y, double z);
     
    tuple<double, double, double> get_coordinates();
    string convert_to_string();
    double size();

    Vector3D operator+(const Vector3D &v);
    Vector3D operator-(const Vector3D &v);
    //cross
    Vector3D operator^(const Vector3D &v);
    // dot
    double operator*(const Vector3D &v);
  };
  
  Vector3D operator*(const Vector3D& vec, double scalar); 
  Vector3D operator*(double scalar, const Vector3D& vec);
  
  class Point3D : public Vector3D {
  public:
      Point3D(double x_val, double y_val, double z_val);
      Point3D(const Vector3D& vec);
  };
  /*
  Point3D operator*(const Point3D& vec, double scalar);
  Point3D operator*(double scalar, const Point3D& vec);
*/
  class Line3D{
  public:
    Point3D start, end;
    Line3D(Point3D start, Point3D end);
  };

  class Triangle3D{
  public:
    Point3D origin_point, left_point, right_point;
    Vector3D normal_vector=Vector3D(0.0, 0.0, 0.0);
    //0.0 to 1.0 for how bright the triangle is
    double texture;
    double size();
  
    // chirality matter the direction the Triangle is facing
  
    Triangle3D(Point3D origin_point, Point3D left_point, Point3D right_point, double texture);

    Vector3D get_normal_vector();

  };
  extern Point3D origin_point;
  extern Triangle3D null_triangle;
  
};


#endif

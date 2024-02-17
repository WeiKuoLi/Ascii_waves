#include <test.hpp>
#include <animation.hpp>
#include <iostream>

#include <Eigen/Dense>
int main(void) {
  std::cout << "Hello World Eigen" << std::endl;
  

  Eigen::MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << "Here is the matrix m:\n" << m << std::endl;
  std::cout << "start test" << std::endl;
  test();

  std::string user_input;
  std::cout << "continue ?"<<std::endl;
  std::getline(std::cin, user_input);
  if (user_input != "no") AsciiGui::run_animation();
  return 0;
};

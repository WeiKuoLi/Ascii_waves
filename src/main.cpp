#include <test.hpp>
#include <animation.hpp>
#include <iostream>
int main(void) { 
  std::cout << "start test" << std::endl;
  test();

  std::string user_input;
  std::cout << "continue ?"<<std::endl;
  std::getline(std::cin, user_input);
  if (user_input != "no") AsciiGui::run_animation();
  return 0;
};

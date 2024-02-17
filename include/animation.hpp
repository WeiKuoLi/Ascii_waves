#ifndef __ANIMATION_H_
#define __ANIMATION_H_
#include <map>
#include <string>
#include <vector>

namespace AsciiGui {
extern std::string ascii_sample;
extern std::vector<double> brightness_sample;
std::map<double, char> create_map(std::vector<double> nums, std::string str);
extern std::map<double, char> ascii_map;

std::string render_image(std::vector<std::vector<double>>* mp);
std::vector<std::vector<double>>* make_waves(int n, int m, double k, double w,
                                             double t);
int run_animation();
}  // namespace AsciiGui
#endif

#include "sys.h"
#include "Color.h"

Eigen::Vector3f const Color::s_color[number_of_vertices] = {
  { 1.0f, 0.0f, 0.0f },  // A
  { 0.0f, 1.0f, 0.0f },  // B
  { 0.0f, 0.0f, 1.0f },  // C
};

#include "sys.h"
#include "Triangle.h"

Eigen::Vector2f const Triangle::s_position[number_of_vertices] = {
  { 0.0f, -0.5f },      // A
  { -0.5f, 0.5f },      // B
  { 0.5f, 0.5f },       // C
};

Eigen::Vector3f const Triangle::s_color[number_of_vertices] = {
  { 1.0f, 0.0f, 0.0f },  // A
  { 0.0f, 1.0f, 0.0f },  // B
  { 0.0f, 0.0f, 1.0f },  // C
};

#include "sys.h"
#include "Position.h"

Eigen::Vector2f const Position::s_position[number_of_vertices] = {
  { 0.0f, -0.5f },      // A
  { -0.5f, 0.5f },      // B
  { 0.5f, 0.5f },       // C
};

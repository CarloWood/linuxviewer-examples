#include "sys.h"
#include "Triangle.h"

Eigen::Vector2f const Triangle::position[batch_size] = {
  { 0.0f, -0.5f },      // A
  { -0.5f, 0.5f },      // B
  { 0.5f, 0.5f },       // C
};

Eigen::Vector3f const Triangle::color[batch_size] = {
  { 1.0f, 0.0f, 0.0f },  // A
  { 0.0f, 1.0f, 0.0f },  // B
  { 0.0f, 0.0f, 1.0f },  // C
};

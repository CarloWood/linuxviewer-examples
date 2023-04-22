#pragma once

#include "VertexData.h"
#include "vulkan/shader_builder/VertexShaderInputSet.h"
#include <Eigen/Geometry>

class Triangle final : public vulkan::shader_builder::VertexShaderInputSet<VertexData>
{
  using Vector2f = Eigen::Vector2f;

  // A batch exists of one triangle.
  //
  //                 A
  //               /   \
  //              /     \
  //             B-------C
  //
  static constexpr int batch_size = 3;

  static Vector2f const offset[3];

 public:
  // Constructor.
  Triangle() {}

 private:
  // Convert xy to one of the three corners of the triangle.
  // Here `vertex` runs from 0 till batch_size ([0, batch_size>).
  auto position_at(int vertex)
  {
    glsl::vec4 position;
    position << offset[vertex], 0.0f, 1.0f;     // Homogeneous coordinates.
    return position;
  }

  // Returns the number of vertices.
  int chunk_count() const override
  {
    return 3;
  }

  // Returns the number of vertices that a single call to create_entry produce.
  int next_batch() override
  {
    return batch_size;
  }

  // Fill the next batch_size VertexData objects.
  void create_entry(VertexData* input_entry_ptr) override
  {
    for (int vertex = 0; vertex < batch_size; ++vertex)
      input_entry_ptr[vertex].m_position = position_at(vertex);
  }
};
#pragma once

#include "VertexData.h"
#include "vulkan/shader_builder/VertexShaderInputSet.h"
#include <Eigen/Geometry>

class Triangle final : public vulkan::shader_builder::VertexShaderInputSet<VertexData>
{
  // A batch exists of one triangle.
  //
  //                 A
  //                / \
  //               /   \
  //              /     \
  //             B-------C
  //
  static constexpr int batch_size = 3;

  // The positions of the triangle corners are stored as 2D vectors; the z and w value are set in the shader.
  static Eigen::Vector2f const position[batch_size];
  // Colors are stored as a triplet of three float values for Red, Green and Blue respectively.
  static Eigen::Vector3f const color[batch_size];

 private:
  // Returns the total number of VertexData objects in the vertex buffer.
  int chunk_count() const override
  {
    return batch_size;
  }

  // Returns the number of VertexData objects that are initialized by a single call to create_entry.
  int next_batch() override
  {
    return batch_size;
  }

  // Initialize the next `batch_size` VertexData objects.
  void create_entry(VertexData* input_entry_ptr) override
  {
    for (int vertex = 0; vertex < batch_size; ++vertex)
    {
      input_entry_ptr[vertex].m_position = position[vertex];
      input_entry_ptr[vertex].m_color = color[vertex];
    }
  }
};

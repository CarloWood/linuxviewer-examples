#pragma once

#include "VertexData.h"
#include "vulkan/shader_builder/VertexShaderInputSet.h"

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
  static constexpr int number_of_vertices = 3;

  // The positions of the triangle corners are stored as 2D vectors; the z and w value are set in the shader.
  static Eigen::Vector2f const s_position[number_of_vertices];
  // Colors are stored as a triplet of three float values for Red, Green and Blue respectively.
  static Eigen::Vector3f const s_color[number_of_vertices];

 private:
  // Returns the total number of VertexData objects in the vertex buffer.
  int chunk_count() const override
  {
    return number_of_vertices;
  }

  // Returns the number of VertexData objects that are initialized by a single call to create_entry.
  int next_batch() override
  {
    return number_of_vertices;
  }

  // Initialize the next `number_of_vertices` VertexData objects.
  void create_entry(VertexData* input_entry_ptr) override
  {
    for (int vertex = 0; vertex < number_of_vertices; ++vertex)
    {
      input_entry_ptr[vertex].m_position = s_position[vertex];
      input_entry_ptr[vertex].m_color = s_color[vertex];
    }
  }
};

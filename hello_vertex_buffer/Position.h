#pragma once

#include "VertexPosition.h"
#include "vulkan/shader_builder/VertexShaderInputSet.h"

// Vertex buffer generator for the position of a vertex.
class Position final : public vulkan::shader_builder::VertexShaderInputSet<VertexPosition>
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

 private:
  // Returns the total number of VertexPosition objects in the vertex buffer.
  int chunk_count() const override
  {
    return number_of_vertices;
  }

  // Returns the number of VertexPosition objects that are initialized by a single call to create_entry.
  int next_batch() override
  {
    return number_of_vertices;
  }

  // Initialize the next `number_of_vertices` VertexPosition objects.
  void create_entry(VertexPosition* input_entry_ptr) override
  {
    for (int vertex = 0; vertex < number_of_vertices; ++vertex)
    {
      input_entry_ptr[vertex].m_position = s_position[vertex];
    }
  }
};

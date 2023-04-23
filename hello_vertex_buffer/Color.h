#pragma once

#include "VertexColor.h"
#include "vulkan/shader_builder/VertexShaderInputSet.h"

// Vertex buffer generator for the color of a vertex.
class Color final : public vulkan::shader_builder::VertexShaderInputSet<VertexColor>
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

  // Colors are stored as a triplet of three float values for Red, Green and Blue respectively.
  static Eigen::Vector3f const s_color[number_of_vertices];

 private:
  // Returns the total number of VertexColor objects in the vertex buffer.
  int chunk_count() const override
  {
    return number_of_vertices;
  }

  // Returns the number of VertexColor objects that are initialized by a single call to create_entry.
  int next_batch() override
  {
    return number_of_vertices;
  }

  // Initialize the next `number_of_vertices` VertexColor objects.
  void create_entry(VertexColor* input_entry_ptr) override
  {
    for (int vertex = 0; vertex < number_of_vertices; ++vertex)
    {
      input_entry_ptr[vertex].m_color = s_color[vertex];
    }
  }
};

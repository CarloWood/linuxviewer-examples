#pragma once

#include <vulkan/shader_builder/VertexAttribute.h>

struct VertexData;

LAYOUT_DECLARATION(VertexData, per_vertex_data)
{
  static constexpr auto struct_layout = make_struct_layout(
    LAYOUT(vec2, m_position),
    LAYOUT(vec3, m_color)
  );
};

// Struct describing data type and format of vertex attributes.
struct VertexData
{
  glsl::vec2 m_position;
  glsl::vec3 m_color;
};

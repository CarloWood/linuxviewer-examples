#pragma once

#include <vulkan/shader_builder/VertexAttribute.h>

struct VertexPosition;

LAYOUT_DECLARATION(VertexPosition, per_vertex_data)
{
  static constexpr auto struct_layout = make_struct_layout(
    LAYOUT(vec2, m_position)
  );
};

// Struct describing data type and format of vertex attributes.
struct VertexPosition
{
  glsl::vec2 m_position;
};

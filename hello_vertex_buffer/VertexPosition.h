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
STRUCT_DECLARATION(VertexPosition)
{
  MEMBER(0, vec2, m_position);
};

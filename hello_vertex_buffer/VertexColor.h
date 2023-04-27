#pragma once

#include <vulkan/shader_builder/VertexAttribute.h>

struct VertexColor;

LAYOUT_DECLARATION(VertexColor, per_vertex_data)
{
  static constexpr auto struct_layout = make_struct_layout(
    LAYOUT(vec3, m_color)
  );
};

// Struct describing data type and format of vertex attributes.
STRUCT_DECLARATION(VertexColor)
{
  MEMBER(0, vec3, m_color);
};

project(linux_vulkan_engine
  LANGUAGES CXX
  DESCRIPTION "Implementation of Hello Triangle with vertex buffers."
)

include(AICxxProject)

#==============================================================================

add_executable(hello_vertex_buffer
  HelloTriangle.cxx
  HelloTriangle.h
  Window.cxx
  Window.h
  TrianglePipelineCharacteristic.h
  LogicalDevice.h
  Position.cxx
  Position.h
  Color.cxx
  Color.h
  VertexPosition.h
  VertexColor.h
)

target_include_directories(hello_vertex_buffer
  PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(hello_vertex_buffer
  PRIVATE
    LinuxViewer::vulkan
    LinuxViewer::shader_builder
    AICxx::xcb-task
    AICxx::xcb-task::OrgFreedesktopXcbError
    AICxx::resolver-task
    AICxx::block-task
    ImGui::imgui
    ${AICXX_OBJECTS_LIST}
    dns::dns
)

cmake_minimum_required(VERSION 3.20)
project(GraphiLite)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем поддиректорию с исходниками ImGui
add_subdirectory(external/imgui)

# Пути к исходным файлам проекта
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Создание исполняемого файла
add_executable(GraphiLite ${SOURCES})

# Пути к заголовочным файлам
target_include_directories(GraphiLite PRIVATE src)

# Линковка библиотек
find_package(Vulkan REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

target_link_libraries(GraphiLite PRIVATE Vulkan::Vulkan ${GLFW_LIBRARIES} imgui)
target_include_directories(GraphiLite PRIVATE ${GLFW_INCLUDE_DIRS})
# Указываем директории с заголовочными файлами ImGui
target_include_directories(GraphiLite PRIVATE external/imgui)
target_include_directories(GraphiLite PRIVATE external/imgui/backends)

# Добавляем исходные файлы ImGui
target_sources(GraphiLite PRIVATE
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/imgui_demo.cpp
    external/imgui/backends/imgui_impl_glfw.cpp
    external/imgui/backends/imgui_impl_vulkan.cpp
)

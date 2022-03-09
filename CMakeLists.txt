cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCES "src/*.cpp")
set(ExeName "AphroditesRenderingEngineDemo")

project(${ExeName} VERSION 1.0)

# Add AphroditesRenderingEngine
SET(BUILD_SHARED_LIBS OFF)
add_subdirectory(ThirdParties/AphroditesRenderingEngine)

# Add vulkan
add_subdirectory(ThirdParties/vulkan)
include_directories(AFTER ${VULKAN_INCLUDE_PATH})
link_directories(${VULKAN_LINK_PATH})

# Add GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only")
add_subdirectory(ThirdParties/glfw)

# Add Assimp
SET(BUILD_SHARED_LIBS OFF)
SET(ASSIMP_BUILD_TESTS OFF)
SET(ASSIMP_BUILD_ALL_EXPORTERS_BY_DEFAULT OFF)
SET(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT OFF)
SET(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
SET(ASSIMP_BUILD_FBX_IMPORTER ON)
SET(ASSIMP_BUILD_OBJ_IMPORTER ON)
add_subdirectory(ThirdParties/assimp)

add_executable(${ExeName} ${SOURCES})
target_link_libraries(${ExeName} PUBLIC AphroditesRenderingEngine assimp glfw ${VULKAN_LIB_LIST})
target_include_directories(${ExeName} PUBLIC "${PROJECT_SOURCE_DIR}/include/")


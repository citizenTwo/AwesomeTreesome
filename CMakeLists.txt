cmake_minimum_required(VERSION 3.6)
project(AwesomeTreesome_v2_0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lopengl32 -lfreeglut")

find_package(GLUT)
find_package(OpenGL)

set(SOURCE_FILES main.c)
#set(SOURCE_FILES Temporary.cpp)
add_executable(AwesomeTreesome_v2_0 ${SOURCE_FILES})

target_link_libraries(
        AwesomeTreesome_v2_0
        ${OPENGL_gl_LIBRARY}
        ${OPENGL_glu_LIBRARY}
        ${GLUT_LIBRARIES})
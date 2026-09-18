cmake_minimum_required(VERSION 3.16)

project(Script1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(Script1
    Script1.cpp
)

target_include_directories(Script1 PRIVATE
    ${OpenCV_INCLUDE_DIRS}
    ${GLUT_INCLUDE_DIRS}
)

target_link_libraries(Script1 PRIVATE
        ${OpenCV_LIBS}
        ${GLUT_LIBRARIES}
        OpenGL::GL
        GLU
)
cmake_minimum_required(VERSION 3.16)

project(Script2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(Script2
    Script2.cpp
)
target_include_directories(Script2 PRIVATE
    ${OpenCV_INCLUDE_DIRS}
    ${GLUT_INCLUDE_DIRS}
)

target_link_libraries(Script2 PRIVATE
    ${OpenCV_LIBS}
    ${GLUT_LIBRARIES}
    OpenGL::GL
)
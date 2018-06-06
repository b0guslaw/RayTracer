cmake_minimum_required(VERSION 3.10)
project(RayTracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(RayTracer src/main.cpp src/pugixml.hpp lib/pugixml.cpp lib/pugiconfig.hpp src/Camera.cpp src/Camera.h src/Background.cpp src/Background.h src/XMLParser.h src/RGB_Space.h src/Sphere.cpp src/Sphere.h src/Light.h)
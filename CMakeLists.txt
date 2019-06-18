cmake_minimum_required(VERSION 3.5)
project(RayTracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(RayTracer src/main.cpp src/pugixml.hpp lib/pugixml.cpp lib/pugiconfig.hpp lib/OBJ_Loader.h src/Camera.cpp src/Camera.h src/Background.h src/XMLParser.h src/Color.h src/Sphere.cpp src/Sphere.h src/Light.h src/Ray.h src/Vec3.h)

install (TARGETS RayTracer DESTINATION bin)
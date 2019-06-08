This is my Lab4a from summer semester of 2018 which I modified slightly to fix issues that I had last year.

The program was written in C++11, build system used is CMake. Resources used for this program outside of the
usual lecture slides were "Fundamentals of Computer Graphics 4th Edition" by Steve Marschner and Peter Shirley, as well
as the website www.scratchapixel.com which is an excellent resource for computer graphics. Additionally I borrowed the
conversion from a 0-1 float to a 1-255 number from StackOverflow.

Usage: ./RayTracer <path to XML>
without <>

Building:
cd into root directory
cmake CMakeLists.txt
make

Additional libraries used are as following:
PugiXML for parsing XML files
GLM for matrix calculations (not used in this version, kept around for Lab4b)

Known issues:
camera setup: fov not converted to radians, up-Vector treated as y-axis
parallel light: wrong direction;
phong illumination wrong: specular highlights are tinted with object's color

Task list (completed tasks are marked)


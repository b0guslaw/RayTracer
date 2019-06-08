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
[x] Output a valid black image file (you will get many of them when continuing and this will be the only time you need them).
[x] Be able to read in the xml file of the specification.
[x] Output an image with spheres on it after ray tracing them.
[x] Be able to read in geometry from the specified xml files. (example1.xml)
[-] Implement basic Phong illumination and shading. (example2.xml)

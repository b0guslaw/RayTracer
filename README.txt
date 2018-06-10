The program was written in C++11, build system used is CMake. Resources used for this program outside of the
usual lecture slides were "Fundamantals of Computer Graphics 4th Edition" by Steve Marschner and Peter Shirley, as well
as the website www.scratchapixel.com which is an excellent resource for computer graphics. Additionally I borrowed the
conversion from a 0-1 float to a 1-255 number from StackOverflow.

Limitations: Since the .xml files only specify .png files my XML parser has issues creating the correct file name.
To mitigate this issue one can either change the output file name to end in .ppm or rename the output file.

Usage: ./RayTracer <path to XML>
without <>

Building:
cd into root directory
cmake CMakeLists.txt
make

Additional libraries used are as following:
PugiXML for parsing XML files
GLM for matrix calculations (not used in this version, kept around for Lab4b)

Task list (completed tasks are marked)
[X] Output a valid black image file
[X] Be able to read in the xml file of the specification.
[X] Output an image with spheres on it after ray tracing them.
[X] Be able to read in geomtery from the specified xml files. (example1.xml)
[X] Implement basic Phong illumination and shading. (example2.xml)


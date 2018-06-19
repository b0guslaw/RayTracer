The program was written in C++11, build system used is CMake. Resources used for this program outside of the
usual lecture slides were "Fundamentals of Computer Graphics 4th Edition" by Steve Marschner and Peter Shirley, as well
as the website www.scratchapixel.com which is an excellent resource for computer graphics. Additionally I borrowed the
conversion from a 0-1 float to a 1-255 number from StackOverflow.

Limitations: Since the .xml files only specify .png files my XML parser has issues creating the correct file name.
To mitigate this issue one can either change the output file name to end in .ppm (in the xml file) or
rename the output file after running the program. The content of the data is not affected.

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


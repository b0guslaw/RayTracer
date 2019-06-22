Lab 4b:
This program is an expanded version of my Raytracer from Lab4a. In this version I used specific features only present
in C++11 such as the mersenne twister, which I need for supersampling.
Additionally this version of my raytracer comes with added terminal output, which shows a rough estimation of how far
the Raytracer engine is in generating the image. I also implemented special commands you can pass to the engine which
enables or enhances certain features. Below is an explanation of each feature and (if applicable) the added argument

Supersampling:
Supersampling is enabled by default and shoots 20 rays per pixel each offset by a randomization. This is the default,
setting. It is possible to adjust the amount of rays per pixel by providing an additional argument
--supersample-high will send 100 rays per pixel
--supersample-off turns the effect off

.obj Loading:
Since I was not able to get around to Field Test my Triangle intersection test, I included a parameter that prints the
contents of each mesh in a pretty format, mostly for debugging purposes, but also to show that my object loading works
--obj-print enables this feature, by default it is off.


New in this release are error codes:
-1 Path to XML File Wrong
-2 XML File exists but could not be loaded

Lab 4a:
The program was written in C++11, build system used is CMake. Resources used for this program outside of the
usual lecture slides were "Fundamentals of Computer Graphics 4th Edition" by Steve Marschner and Peter Shirley, as well
as the website www.scratchapixel.com which is an excellent resource for computer graphics. Additionally I borrowed the
conversion from a 0-1 float to a 1-255 number from StackOverflow.


Requirements:
Linux like operating system (needs to understand bash)
G++ version that supports C++11

Building:
cd into root directory
sh compile.sh
(Takes up to a minute to build)

Usage: ./ray <path to XML> <optional commands>
without <>

Example:
./ray res/example1.xml
or
./ray res/example1.xml --supersample-extreme

Additional libraries used are as following:
PugiXML for parsing XML files

Known issues:
UP-vector upside down
FOV not calculated appropriately, which means the image is slightly cut off

Completed Tasks:
Supersampling
Object Loading and Parsing into custom data structure

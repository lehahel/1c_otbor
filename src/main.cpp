#include <png.h>
#include <finder.h>

#include <string>
#include <iostream>

int main(int argc, char **argv) {
    CSegmentFinder finder("tmp_file");
    std::cout << finder.FindIntersections() << std::endl;
    return 0;
}
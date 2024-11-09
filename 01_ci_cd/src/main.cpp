#include <iostream>
#include <unistd.h>

//----------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    std::cout << "Build " << BUILD_NUMBER << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return EXIT_SUCCESS;
}

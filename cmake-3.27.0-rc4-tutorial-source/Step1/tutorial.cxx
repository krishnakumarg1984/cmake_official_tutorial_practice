// A simple program that computes the square root of a number
#include <cmath>
// #include <cstdlib>  // TODO 5: Remove this line
#include <iostream>
#include <string>

// TODO 11: Include TutorialConfig.h
#include "TutorialConfig.h"

int main(int argc, const char* argv[]) {
    if ( argc < 2 ) {
        // TODO 12: Create a print statement using Tutorial_VERSION_MAJOR and Tutorial_VERSION_MINOR
        std::cout << argv[0] << " Version: " << Tutorial_VERSION_MAJOR << '.' << Tutorial_VERSION_MINOR << '\n';

        std::cout << "Usage: " << argv[0] << " number\n";
        return 1;
    }

    // convert input to double
    // TODO 4: Replace atof(argv[1]) with std::stod(argv[1])
    // const double inputValue  = atof(argv[1]);
    const double inputValue { std::stod(argv[1]) };

    // calculate square root
    const double outputValue = sqrt(inputValue);
    std::cout << "The square root of " << inputValue << " is " << outputValue << '\n';

    return 0;
}

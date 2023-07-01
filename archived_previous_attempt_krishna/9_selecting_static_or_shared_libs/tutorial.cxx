// A simple program that computes the square root of a number
#include <iostream>
#include <string>

#include "MathFunctions.h"
#include "TutorialConfig.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << '\n';
        std::cout << "Usage: " << argv[0] << " number" << '\n';
        return 1;
    }

    // convert input to double
    const double inputValue = std::stod(argv[1]);

    // calculate square root
    const double outputValue { mathfunctions::sqrt(inputValue) };

    std::cout << "The square root of " << inputValue << " is " << outputValue << '\n';
    return 0;
}

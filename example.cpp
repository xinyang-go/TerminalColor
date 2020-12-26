#include <iostream>
#include "TerminalColor.hpp"

using namespace tc;

int main() {
    std::cout << "Hello, World!"_black << std::endl;
    std::cout << "Hello, World!"_red << std::endl;
    std::cout << "Hello, World!"_green << std::endl;
    std::cout << "Hello, World!"_yellow << std::endl;
    std::cout << "Hello, World!"_blue << std::endl;
    std::cout << "Hello, World!"_purple << std::endl;
    std::cout << "Hello, World!"_cyan << std::endl;
    std::cout << "Hello, World!"_white << std::endl;

    std::cout << "Hello, World!"_cyan.highlight() << std::endl;
    std::cout << "Hello, World!"_cyan.underline() << std::endl;
    std::cout << "Hello, World!"_cyan.inverse() << std::endl;
    std::cout << "Hello, World!"_cyan.underline().highlight() << std::endl;


    std::cout << "Hello, World!"_cyan.back(ColorCode::black) << std::endl;
    std::cout << "Hello, World!"_cyan.back(ColorCode::red) << std::endl;
    std::cout << "Hello, World!"_cyan.back(ColorCode::green) << std::endl;
    std::cout << "Hello, World!"_cyan.back(ColorCode::yellow) << std::endl;
    std::cout << "Hello, World!"_cyan.back(ColorCode::blue) << std::endl;
    std::cout << "Hello, World!"_cyan.back(ColorCode::purple) << std::endl;
    std::cout << "Hello, World!"_cyan.back(ColorCode::cyan) << std::endl;
    std::cout << "Hello, World!"_cyan.back(ColorCode::white) << std::endl;

    return 0;
}

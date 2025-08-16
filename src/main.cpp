#include <iostream>
#include <sstream>
#include <string>
#include "token/token.h"

int main() {
    std::string input = "INSERT INTO orders VALUES (123, 'john doe')";
    std::istringstream iss(input);

    std::string token;
    while (std::getline(iss, token, ' ')) {
        if (!token.empty()) {
            std::cout << token << std::endl;
        }
    }

    return 0;
}



#include <iostream>
#include <unordered_map>

#pragma once

// First define Tuple
class Tuple {
public:
    Tuple(std::initializer_list<std::pair<const std::string, std::string>> values)
            : data(values) {}

    const std::unordered_map<std::string, std::string>& get_data() const {
        return data;
    }

private:
    std::unordered_map<std::string, std::string> data;
};
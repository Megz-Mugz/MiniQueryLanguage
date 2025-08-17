#include <iostream>
#include <unordered_map>
#include "tuple.h"
#include <vector>

// Then define Table
class Table {
public:
    void insert(const Tuple& tuple) {
        rows.push_back(tuple);
    }

    const std::vector<Tuple>& get_rows() const {
        return rows;
    }

private:
    std::vector<Tuple> rows;
};
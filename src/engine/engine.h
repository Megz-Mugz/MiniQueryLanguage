#include <iostream>
#include <unordered_map>
#include "table.h"
#include <string>


class Engine {

public:



    void create_engine(){

    }

    std::size_t table_size(){ return tables.size(); }

    bool is_empty() { return tables.size() == 0; }


private:
    std::vector<Table> tables;
};

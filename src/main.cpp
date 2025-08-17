#include <sstream>
#include <string>
#include "lexer/lexer.h"
#include "engine/engine.h"

int main() {

    std::string input = "INSERT INTO Persons (PersonID, LastName, FirstName, Address, City)\n"
                        "VALUES (1, \"Doe\", \"John\", \"123 Main St\", \"New York\");";

    // give input to the lexer
    Engine db;

    Lexer lexer;
    lexer.tokenize(input);
    lexer.get_lexins();


    return 0;
}



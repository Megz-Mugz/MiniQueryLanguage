#include <string>


// TODO Add more later if needed
enum class TokenType {
    // Keywords
    CREATE, INSERT, UPDATE, DESTROY, TABLE, SET, WHERE,

    // Identifiers & literals
    IDENTIFIER, NUMBER, STRING,

    // Symbols & Operators
    LEFT_PARENTHESIS, RIGHT_PARENTHESIS, COMMA, SEMICOLON, EQUAL,

    // End
    END_OF_FILE
};

std::string_view to_string(TokenType t) {
    switch (t) {
        // Keywords
        case TokenType::CREATE:           return "CREATE";
        case TokenType::INSERT:           return "INSERT";
        case TokenType::UPDATE:           return "UPDATE";
        case TokenType::DESTROY:          return "DESTROY";
        case TokenType::TABLE:            return "TABLE";
        case TokenType::SET:              return "SET";
        case TokenType::WHERE:            return "WHERE";

            // Identifiers & literals
        case TokenType::IDENTIFIER:       return "IDENTIFIER";
        case TokenType::NUMBER:           return "NUMBER";
        case TokenType::STRING:           return "STRING";

            // Symbols & Operators
        case TokenType::LEFT_PARENTHESIS:  return "LEFT_PARENTHESIS";
        case TokenType::RIGHT_PARENTHESIS: return "RIGHT_PARENTHESIS";
        case TokenType::COMMA:             return "COMMA";
        case TokenType::SEMICOLON:         return "SEMICOLON";
        case TokenType::EQUAL:             return "EQUAL";

            // End
        case TokenType::END_OF_FILE:      return "END_OF_FILE";
    }
    return "UNKNOWN_TOKEN";
}


using Value = std::string;
using Line = int;
using Column = int;

struct Token {
    TokenType type;
    Value _value;
    Line _line;
    Column _column;

    Token(TokenType type, Value value)
            : type(type), _value(std::move(value)) {}

    Token(TokenType type, Value value, Line line, Column column)
            : type(type), _value(std::move(value)), _line(line), _column(column) {}

    [[nodiscard]] std::string display_meta_data() const{

        auto line_str = (_line > 0) ? std::to_string(_line) : "N/A";
        auto column_str = (_column > 0) ? std::to_string(_column) : "N/A";

        std::cout << "Token Type: " << to_string(type)
                  << " Value: " << _value
                  << " Line: " << line_str
                  << " Column: " << column_str;
    }
};
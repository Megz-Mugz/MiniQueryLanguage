#pragma once
#include <string>

//
#define TOKEN_LIST \
  X(CREATE) \
  X(INSERT) \
  X(UPDATE) \
  X(DESTROY) \
  X(TABLE)         \
  X(IDENTIFIER) \
  X(WHERE) \
  X(NUMBER) \
  X(TABLE_NAME) \
  X(STRING) \
  X(LEFT_PARENTHESIS) \
  X(RIGHT_PARENTHESIS) \
  X(COMMA) \
  X(SEMICOLON) \
  X(EQUAL)         \
  X(INTO)  \
  X(END_OF_FILE)

enum class TokenType {
#define X(name) name,
    TOKEN_LIST
#undef X
};

// 3) token_type_to_string (no string_view if you don't want it)
inline const char* token_type_to_string(TokenType t) {
    switch (t) {
#define X(name) case TokenType::name: return #name;
        TOKEN_LIST
#undef X
    }
    return "UNKNOWN_TOKEN";
}

using Value = std::string;
using Line = int;
using Column = int;

struct Token {
    TokenType type;
    Value _value;
    Line _line{};
    Column _column{};

    Token(TokenType type, Value value)
            : type(type), _value(std::move(value)) {}

    Token(TokenType type, Value value, Line line, Column column)
            : type(type), _value(std::move(value)), _line(line), _column(column) {}

    [[nodiscard]] void display_meta_data() const{

        auto line_str = (_line > 0) ? std::to_string(_line) : "N/A";
        auto column_str = (_column > 0) ? std::to_string(_column) : "N/A";

        std::cout << "Token Type: " << token_type_to_string(type)
                  << " Value: " << _value <<  "\n";
    }
};
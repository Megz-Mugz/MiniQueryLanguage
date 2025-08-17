#pragma once

#include <iostream>
#include <unordered_map>
#include "token/token.h"

namespace Grammar {

    using keywordMap = std::unordered_map<std::string, TokenType>;
    using symbolMap = std::unordered_map<char, TokenType>;

    static keywordMap keywords = {
            {"CREATE", TokenType::CREATE},
            {"INSERT", TokenType::INSERT},
            {"INTO", TokenType::INTO},
            {"UPDATE", TokenType::UPDATE},
            {"DESTROY", TokenType::DESTROY},
            {"TABLE", TokenType::TABLE},
            {"WHERE", TokenType::WHERE}
    };

    static symbolMap symbols = {
            {'(', TokenType::LEFT_PARENTHESIS},
            {')', TokenType::RIGHT_PARENTHESIS},
            {',', TokenType::COMMA},
            {';', TokenType::SEMICOLON},
            {'=', TokenType::EQUAL}
    };
}

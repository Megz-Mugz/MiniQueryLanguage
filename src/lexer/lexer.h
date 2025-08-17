#include <iostream>
#include "../token/token.h"
#include <vector>
#include <unordered_map>


/*
 * Purpose of this class is to take each of the
 * words in the input do a few things with it:
 * 1. Turn the word into a token
 * 2. Give the token object to the parser &
 *    verify the token fits the rules of the grammar from the DFA
 * 3. repeat this process until the line is complete
 * 4. once line is finished, you will have list of Tokens
 * */

static std::unordered_map<std::string, TokenType> keywords = {
        {"CREATE", TokenType::CREATE},
        {"INSERT", TokenType::INSERT},
        {"INTO", TokenType::INTO},
        {"UPDATE", TokenType::UPDATE},
        {"DESTROY", TokenType::DESTROY},
        {"TABLE", TokenType::TABLE},
        {"WHERE", TokenType::WHERE}
};

static std::unordered_map<char, TokenType> symbols = {
        {'(', TokenType::LEFT_PARENTHESIS},
        {')', TokenType::RIGHT_PARENTHESIS},
        {',', TokenType::COMMA},
        {';', TokenType::SEMICOLON},
        {'=', TokenType::EQUAL}
};


class Lexer{

public:
    Lexer() {}

    // input cannot be modified inside this method
    void tokenize(const std::string& input) {
        std::string word;

        // go letter by letter & build out a word
        for (int i = 0; i < input.length(); i++){

            char current_letter = input[i];

            // whitespace/newline -> flush current word (if any), then skip
            if (current_letter == ' ' || current_letter == '\n' || current_letter == '\t' || current_letter == '\r') {

                if (!word.empty()){
                    auto keyword_it = keywords.find(word);

                    if (keyword_it != keywords.end()){ // keyword
                        Tokens.emplace_back(keyword_it->second, word);
                    } else { // identifier
                        Tokens.emplace_back(TokenType::IDENTIFIER, word); // use TABLE_NAME if you don't have IDENTIFIER
                    }
                    word.clear();
                }
                continue;
            }

            // symbols -> flush current word (if any), then emit symbol token
            auto symbols_it = symbols.find(current_letter);

            if (symbols_it != symbols.end()){

                if (!word.empty()){

                    auto keyword_it = keywords.find(word);

                    if (keyword_it != keywords.end()){
                        Tokens.emplace_back(keyword_it->second, word);
                    } else {
                        Tokens.emplace_back(TokenType::IDENTIFIER, word); // or TABLE_NAME
                    }
                    word.clear();
                }
                Tokens.emplace_back(symbols_it->second, std::string(1, current_letter));
                continue;
            }

            // otherwise keep building the word
            word += current_letter;
        }

        // flush trailing word at EOF
        if (!word.empty()){
            std::string upper = word;
            std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);

            auto keyword_it = keywords.find(upper);
            if (keyword_it != keywords.end()){
                Tokens.emplace_back(keyword_it->second, word);
            } else {
                Tokens.emplace_back(TokenType::IDENTIFIER, word); // or TABLE_NAME
            }
        }
    }


    // okay for testing purposes
    void get_lexins(){
        for (Token token : Tokens){
            token.display_meta_data();
        }
    }
private:
    std::vector<Token> Tokens;
};


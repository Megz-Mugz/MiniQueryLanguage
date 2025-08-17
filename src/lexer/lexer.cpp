#include <iostream>
#include "../token/token.h"
#include <vector>


/*
 * Purpose of this class is to take each of the
 * words in the input do a few things with it:
 * 1. Turn the word into a token
 * 2. Give the token object to the parser &
 *    verify the token fits the rules of the grammar from the DFA
 * 3. repeat this process until the line is complete
 * 4. once line is finished, you will have list of Tokens
 * */
class Lexer{

public:
    Lexer() {}

private:
    std::vector<Token> Tokens;

};


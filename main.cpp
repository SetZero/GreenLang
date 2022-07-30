#include <iostream>
#include "src/parser.h"

void mainLoop(Parser &p);
int main() {
    Parser p;
    // Prime the first token.
    std::cout << "ready> ";
    p.getNextToken();

    mainLoop(p);

    p.output();
}
void mainLoop(Parser &p) {
    while (true) {
        std::cout << "ready> ";
        switch (p.getCurrentToken()) {
            case Token::tok_eof:
                return;
            case static_cast<Token>(';'): // ignore top-level semicolons.
                p.getNextToken();
                break;
            case Token::tok_def:
                p.HandleDefinition();
                break;
            case Token::tok_extern:
                p.HandleExtern();
                break;
            default:
                p.HandleTopLevelExpression();
                break;
        }
    }
}

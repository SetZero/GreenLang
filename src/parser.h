//
// Created by Sebastian on 31.07.2022.
//

#pragma once

//
// Created by Sebastian on 31.07.2022.
//
#include "AST.h"
#include "lexer.h"
#include <cctype>
#include <map>
#include <memory>

class Parser {
public:
    [[nodiscard]] constexpr Token getCurrentToken() const noexcept {
        return CurTok;
    }

    Token getNextToken();

    /// numberexpr ::= number
    std::unique_ptr<ExprAST> ParseNumberExpr();

    /// parenexpr ::= '(' expression ')'
    std::unique_ptr<ExprAST> ParseParenExpr();

    /// identifierexpr
    ///   ::= identifier
    ///   ::= identifier '(' expression* ')'
    std::unique_ptr<ExprAST> ParseIdentifierExpr();

    /// primary
    ///   ::= identifierexpr
    ///   ::= numberexpr
    ///   ::= parenexpr
    std::unique_ptr<ExprAST> ParsePrimary();

    /// BinopPrecedence - This holds the precedence for each binary operator that is
    /// defined.

    /// GetTokPrecedence - Get the precedence of the pending binary operator token.
    int GetTokPrecedence();

    /// binoprhs
    ///   ::= ('+' primary)*
    std::unique_ptr<ExprAST> ParseBinOpRHS(int ExprPrec,
                                           std::unique_ptr<ExprAST> LHS);

    /// expression
    ///   ::= primary binoprhs
    ///
    std::unique_ptr<ExprAST> ParseExpression();

    /// prototype
    ///   ::= id '(' id* ')'
    std::unique_ptr<PrototypeAST> ParsePrototype();

    /// definition ::= 'def' prototype expression
    std::unique_ptr<FunctionAST> ParseDefinition();

    /// external ::= 'extern' prototype
    std::unique_ptr<PrototypeAST> ParseExtern();

    /// toplevelexpr ::= expression
    std::unique_ptr<FunctionAST> ParseTopLevelExpr();

    void HandleDefinition();

    void HandleExtern();

    void HandleTopLevelExpression();

    void output();
private:
    Token CurTok;
    std::map<char, int> BinopPrecedence = {
            {'<', 10},
            {'+', 20},
            {'-', 30},
            {'*', 40},
    };
};
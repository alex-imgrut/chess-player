#include "ChessGame.h"
#include <cstddef>
#include <ctype.h>
#include <iostream>
#include <stdexcept>
#include <regex>
#include <queue>

// --------------------------------------------------------------------------------------------------------------------
// Lexeme and token types
// --------------------------------------------------------------------------------------------------------------------
enum lexemeType { UNDEF, STRING, BRACE_COMMENT, SEMICOLON_COMMENT, SYMBOL };
enum tokenType { OPEN_BRACKET, CLOSE_BRACKET, TAG_NAME, TAG_VALUE, COMMENT, MOVE_NUMBER, MOVE, RESULT };
struct token {
    tokenType type;
    std::string value;
};

// --------------------------------------------------------------------------------------------------------------------
// Print token
// Helper function to debug (cout print)
// --------------------------------------------------------------------------------------------------------------------
static std::string token2string(token token) {
    std::string string = "type [";
    switch (token.type) {
        case OPEN_BRACKET:
            string += "OPEN_BRACKET";
            break;
        case CLOSE_BRACKET:
            string += "CLOSE_BRACKET";
            break;
        case TAG_NAME:
            string += "TAG_NAME";
            break;
        case TAG_VALUE:
            string += "TAG_VALUE";
            break;
        case COMMENT:
            string += "COMMENT";
            break;
        case MOVE_NUMBER:
            string += "MOVE_NUMBER";
            break;
        case MOVE:
            string += "MOVE";
            break;
        case RESULT:
            string += "RESULT";
            break;
        default:
            string += "UNKNOWN";
    }
    string += "], value [" + token.value + "]";
    return string;
}

// --------------------------------------------------------------------------------------------------------------------
// Error formatting function
// --------------------------------------------------------------------------------------------------------------------
static std::string formatErrorMessage(unsigned int lineNumber, unsigned int charPosition, std::string error, std::string diagnostic) {
    return error + " at line [" + std::to_string(lineNumber) + "] position [" + std::to_string(charPosition) + "], " + diagnostic;
}

// --------------------------------------------------------------------------------------------------------------------
// Evaluation function
// Maps TOKEN type on LEXEME type
// --------------------------------------------------------------------------------------------------------------------
static tokenType evaluate(lexemeType lexemeType, std::string lexemeValue) {

    // Regexes used to validate and categorize symbols
    std::regex move("^(O-O|O-O-O|[BKNPQR]?[a-h]?[1-8]?x?[a-h][1-8](=[BKNPQR])?[+#]?)$");
    std::regex moveNumber("^\\d+\\.+$");
    std::regex tagName("^\\w+$");
    std::regex result("^(0-1|1-0|1/2-1/2)$");

    tokenType tokenType;
    switch (lexemeType) {

        // For delimited tokens, lexeme type => token type is univoque
        case STRING:
            tokenType = TAG_VALUE;
            break;
        case BRACE_COMMENT:
        case SEMICOLON_COMMENT:
            tokenType = COMMENT;
            break;

        // For symbols, lexeme type => token type mapping depends on lexeme value
        case SYMBOL:
            if (std::regex_match(lexemeValue, result)) {
                tokenType = RESULT;
            }
            else if (std::regex_match(lexemeValue, moveNumber)) {
                tokenType = MOVE_NUMBER;
            }
            else if (std::regex_match(lexemeValue, move)) {
                tokenType = MOVE;
            }
            else if (std::regex_match(lexemeValue, tagName)) {
                tokenType = TAG_NAME;
            }
            else {
                throw std::runtime_error("Unknown token [" + lexemeValue + "]");
            }
            break;
        default:
            throw std::runtime_error("Unknown token [" + lexemeValue + "]");
    }
    return tokenType;
}

// --------------------------------------------------------------------------------------------------------------------
// Tokenizer function
// Standard: Portable Game Notation Specification and Implementation Guide (revised: 1994.03.12)
// --------------------------------------------------------------------------------------------------------------------
static std::queue<token> tokenize(std::string text) {

    // Variable used to track current character's position (needed for error messages)
    unsigned int lineNumber = 1;
    unsigned int charPosition = 0;

    // Variables and types used for text scanning
    lexemeType currentLexeme = UNDEF;
    token currentToken;
    std::regex rSymbolCharacter("^[\\w\\+\\-\\.:#=/]$");

    // Variable used to store execution result
    std::queue<token> tokenQueue;

    for (unsigned int i = 0; i < text.size(); i++) {

        charPosition++;

        // PGN text shall be made of ASCII characters only (not printable excluded with exception of space characters)
        if (!isascii(text[i]) || (!isprint(text[i]) && !isspace(text[i]))) {
            throw std::runtime_error(formatErrorMessage(lineNumber, charPosition, "syntax error", "invalid character (not ASCII or not printable nor space)"));
        }

        switch (currentLexeme) {

            case UNDEF: // Outisde of any lexeme, looking for lexeme start

                switch (text[i]) {

                    // Single character tokens detection
                    case '[':
                        currentToken.type = OPEN_BRACKET;
                        currentToken.value = "[";
                        tokenQueue.push(currentToken);
                        break;

                    case ']':
                        currentToken.type = CLOSE_BRACKET;
                        currentToken.value = "]";
                        tokenQueue.push(currentToken);
                        break;

                    case '*':
                        currentToken.type = RESULT;
                        currentToken.value = "*";
                        tokenQueue.push(currentToken);
                        break;

                    // Delimited tokens detection (string, comments)
                    case '"':
                        currentLexeme = STRING;
                        currentToken.value = "";
                        break;

                    case '{':
                        currentLexeme = BRACE_COMMENT;
                        currentToken.value = "";
                        break;

                    case ';':
                        currentLexeme = SEMICOLON_COMMENT;
                        currentToken.value = "";
                        break;

                    // Complex tokens detection (symbols, starting with a letter or a digit)
                    default:
                        if (isalnum(text[i])) {
                            currentLexeme = SYMBOL;
                            currentToken.value = text[i];
                        }
                        else if (isspace(text[i])) {
                            // Do nothing, ignore white spaces
                        }
                        else {
                            throw std::runtime_error(formatErrorMessage(lineNumber, charPosition, "syntax error", "invalid character to start a token"));
                        }
                }
                break;

            case STRING: // Inside a string, looking for end of the string
                if ((text[i] == '"') && ((i == 0) || (text[i - 1] != '\\'))) {
                    currentToken.type = evaluate(currentLexeme, currentToken.value);
                    tokenQueue.push(currentToken);
                    currentLexeme = UNDEF;
                }
                else {
                    currentToken.value += text[i];
                }
                break;

            case BRACE_COMMENT: // Inside a comment, looking for end of the comment
                if (text[i] == '}') {
                    currentToken.type = evaluate(currentLexeme, currentToken.value);
                    tokenQueue.push(currentToken);
                    currentLexeme = UNDEF;
                }
                else {
                    currentToken.value += text[i];
                }
                break;

            case SEMICOLON_COMMENT: // Inside a comment, looking for end of the comment
                if (text[i] == '\n') {
                    currentToken.type = evaluate(currentLexeme, currentToken.value);
                    tokenQueue.push(currentToken);
                    currentLexeme = UNDEF;
                }
                else {
                    currentToken.value += text[i];
                }
                break;
    
            case SYMBOL: // Inside a symbol, looking for end of the symbol
                if (!std::regex_match(std::string(1, text[i]), rSymbolCharacter)) {
                    currentToken.type = evaluate(currentLexeme, currentToken.value);
                    tokenQueue.push(currentToken);
                    currentLexeme = UNDEF;
                }
                else {
                    currentToken.value += text[i];
                }
                break;

            default: // Should be impossible to end here
                throw std::runtime_error(formatErrorMessage(lineNumber, charPosition, "syntax error", "inside unknown token"));
        }
        
        // When a new line character is encountered, increment line number and reset character position
        if (text[i] == '\n') {
            lineNumber++;
            charPosition = 0;
        }
    }

    // EOF was reached and last toekn has not ended
    if (currentLexeme != UNDEF) {
        throw std::runtime_error(formatErrorMessage(lineNumber, charPosition, "syntax error", "missing terminator ('\"', '}' or '\n'"));
    }

    return tokenQueue;
}


// --------------------------------------------------------------------------------------------------------------------
// Temp stuff
// --------------------------------------------------------------------------------------------------------------------
// By default, FEN record matches standard starting position
// const std::string ChessGame::scDefaultFenRecord = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

// Constructor is building a PGN export format object
// Initialize mandatory tag pairs (STR = Seven Tag Roster) and add tags FEN and SetUp with default values
ChessGame::ChessGame(std::string pgnString)
{
    try {
        std::queue<token> tokenQueue = tokenize(pgnString);
        token token;
        while (!tokenQueue.empty()) {
            token = tokenQueue.front();
            std::cout << "TOKEN " << token2string(token) << std::endl;
            tokenQueue.pop();
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

// Build a PGN string (export format)
std::string ChessGame::toString()
{
    // Reverse operation from constructor
    // Shall we accept an optional parameter defining number of columns?
    return "";
}

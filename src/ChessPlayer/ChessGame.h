#pragma once
#include <string>

class ChessGame {
private:
    static const std::string scDefaultFenRecord;
public:
    ChessGame(std::string pgnString);
    std::string toString();
};

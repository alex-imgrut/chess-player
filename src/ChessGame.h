#pragma once

#include <map>
#include <string>

class ChessGame {

private:
    static const std::string scDefaultFenRecord;
    std::map<std::string, std::string> mTagPairs;
    std::string mMoveText;

public:
    ChessGame(std::string pgnString);
    std::string toString();

};

#pragma once
#include "string"

using namespace std;


class InputParser {
public:
    void parse(const string& command);
    string event;
    string date;
    string action;
    void clear();
};


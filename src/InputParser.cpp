#include "iostream"
#include "sstream"

#include "InputParser.h"

using namespace std;

enum InputTemplate {
    COMMAND,
    DATE,
    EVENT
};

void InputParser::parse(const string &command) {
    stringstream command_stream;
    command_stream << command;
    string command_part;
    int i = 0;
    while (getline(command_stream, command_part, ' ')) {
        switch (i) {
            case COMMAND:
                this->action = command_part;
                break;
            case DATE:
                this->date = command_part;
                break;
            case EVENT:
                this->event = command_part;
                break;
            default:
                break;
        }
        i++;
    }
}

void InputParser::clear() {
    this->action = "";
    this->date = "";
    this->event = "";
}
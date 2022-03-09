#include <iostream>
#include <string>

#include "DataBase.h"
#include "Event.h"
#include "Date.h"
#include "InputParser.h"

using namespace std;


int main() {
    DataBase db;
    string command;
    InputParser parser;


    while (getline(cin, command)) {
        parser.parse(command);
        Date date(parser.date);
        Event event(parser.event);

        Actions action = proceed(parser.action);
//        cout << date.ToStr() << endl;
        switch (action) {
            case ADD:
                db.AddEvent(date, event);
                break;
            case DEL:
                if (!event.name.empty()) {
                    db.DeleteEvent(date, event);
                } else {
                    db.DeleteEvent(date);
                }
                break;
            case FIND:
//                db.FindEvent(date);
                break;
            case PRINT:
                db.Print();
                break;
            default:
                break;
        }
        parser.clear();
    }
    return 0;
}

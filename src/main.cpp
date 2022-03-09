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
        switch (action) {
            case ADD:
                db.AddEvent(date, event);
                break;
            case DEL:
                if (!event.name.empty()) {
                    bool deletion_status = db.DeleteEvent(date, event);
                    if (deletion_status) {
                        cout << "Deleted successfully" << endl;
                    } else {
                        cout << "Event not found" << endl;
                    }
                } else {
                    cout << "Deleted "<< db.DeleteDate(date) << " events"<< endl;
                }
                break;
            case FIND:
                db.FindEvents(date);
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

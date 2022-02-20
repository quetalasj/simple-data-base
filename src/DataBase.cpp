#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#include "DataBase.h"

using namespace std;

map<string, Actions> actions_map = {{"Add",   ADD},
                                    {"Del",   DEL},
                                    {"Find",  FIND},
                                    {"Print", PRINT}};

Actions proceed(const string& action) {
    for (const auto& [key, value] : actions_map) {
        if (action == key) {
            return value;
        }
    }
    return DEFAULT;
}

void DataBase::AddEvent(const Date &date, const Event &event) {
    data_base[date].insert(event);
}

void DataBase::Print() const {
    for (const auto& [date, events] : data_base) {
        for (const auto& event : events) {
            cout << date.ToStr() << " " << event.name << endl;
        }
    }
}
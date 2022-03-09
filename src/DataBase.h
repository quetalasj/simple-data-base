#pragma once
#include <map>
#include <set>
#include "Date.h"
#include "Event.h"

using namespace std;

enum Actions {
    ADD,
    DEL,
    FIND,
    PRINT,
    DEFAULT
};


Actions proceed(const string& action);

class DataBase {
public:
    void AddEvent(const Date& date, const Event& event);
    bool DeleteEvent(const Date& date, const Event& event);
    int DeleteDate(const Date& date);
    void FindEvents(const Date& date) const;
    void Print() const;
private:
    map<Date, set<Event>> data_base;
};

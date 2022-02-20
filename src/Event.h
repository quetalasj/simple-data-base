#pragma once

#include <string>

using namespace std;

class Event {
public:
    explicit Event(const string& event);
    string name;
    bool operator<(const Event& other) const;
};

#include "Event.h"

Event::Event(const string &name) {
    this->name = name;
}

bool Event::operator<(const Event &other) const {
    return name < other.name;
}
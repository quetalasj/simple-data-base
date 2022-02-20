#include <string>
#include "iostream"
#include "sstream"

#include "Date.h"

using namespace std;


Date::Date(const std::string &date) {
    stringstream date_stream(date);
    string word;
    int i = 0;
    while (getline(date_stream, word, '-')) {
        switch (i) {
            case YEAR:
                SetYear(word);
                break;
            case MONTH:
                SetMonth(word);
                break;
            case DAY:
                SetDay(word);
                break;
            default:
                break;
        }
        i++;
    }
}

bool Date::operator<(const Date &other) const {
    bool equal_year = stoi(year) == stoi(other.year);
    bool equal_month = stoi(month) == stoi(other.month);
    if (!equal_year) {
        return stoi(year) < stoi(other.year);
    } else if (!equal_month) {
        return stoi(month) < stoi(other.month);
    } else {
        return stoi(day) < stoi(other.day);
    }
}

void Date::SetYear(const string& year) {
    this->year = year;
}

void Date::SetMonth(const string &month) {
    this->month = month;
}

void Date::SetDay(const string &day) {
    this->day = day;
}

string Date::GetYear() const {
    return year;
}

string Date::GetMonth() const {
    return month;
}

string Date::GetDay() const {
    return day;
}

string Date::ToStr() const {
    stringstream str_stream;
    str_stream << GetYear() << "-" << GetMonth() << "-" << GetDay();
    string str;
    str_stream >> str;
    return str;
}
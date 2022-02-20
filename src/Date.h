#pragma once
#include "string"

using namespace std;

enum DateTemplate {
    YEAR,
    MONTH,
    DAY
};


class Date {
public:
    explicit Date(const string& date);
    string GetYear() const;
    string GetMonth() const;
    string GetDay() const;
    void SetYear(const string& year);
    void SetMonth(const string& month);
    void SetDay(const string& day);
    bool operator<(const Date& other) const;
    string ToStr() const;
private:
    string year ;
    string month;
    string day;

};


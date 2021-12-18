//
// Created by Matilde on 19/11/2021.
//

#ifndef AED2122_G53_TIME_H
#define AED2122_G53_TIME_H
#include "iostream"
#include "string"


class Time {

    int day,month,year,hour,minute;

public:
    Time(int day, int month, int year);
    Time(int day, int month, int year, int hour, int minute);
    Time(int hour, int minute);

    int getday() {return day;}
    int getmonth(){return month;}
    int getyear(){return year;}
    int gethour(){return hour;}
    int getminute(){return minute;}

    std::string printDate(){
        return std::to_string(day)+"/"+ std::to_string(month)+"/"+ std::to_string(year);
    }

    std::string printhour(){
        return std::to_string(hour)+":"+ std::to_string(minute);
    }

    bool operator<(const Time& t1) const;
    bool operator==(const Time& t1) const;

};


#endif //AED2122_G53_TIME_H

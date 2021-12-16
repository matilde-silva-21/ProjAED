//
// Created by Matilde on 19/11/2021.
//

#ifndef AED2122_G53_TIME_H
#define AED2122_G53_TIME_H
#include "iostream"


class Time {

    int day,month,year,hour,minute;

public:
    Time(int day, int month, int year);
    Time(int day, int month, int year, int hour, int minute);
    Time(int hour, int minute);

    int getday(){return day;}
    int getmonth(){return month;}
    int getyear(){return year;}
    int gethour(){return hour;}
    int getminute(){return minute;}

    void printDate(){
        std::cout<<day<<"/"<<month<<"/"<<year;
    }

    void printhour(){
        std::cout<<hour<<":"<<minute;
    }

    bool operator<(Time& t1);
    bool operator==(Time& t1);

};


#endif //AED2122_G53_TIME_H

//
// Created by Matilde on 19/11/2021.
//

#ifndef AED2122_G53_TIME_H
#define AED2122_G53_TIME_H


class Time {

    int day,month,year,hour,minute;

public:
    Time(int day, int month, int year);
    Time(int day, int month, int year, int hour, int minute);
    Time(int hour, int minute);


    bool operator<(Time& t1);
    bool operator==(Time& t1);

};


#endif //AED2122_G53_TIME_H

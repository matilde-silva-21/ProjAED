//
// Created by Matilde on 19/11/2021.
//

#include "Time.h"



Time::Time(int day, int month, int year) {
    this -> day =day;
    this -> month = month;
    this -> year = year;
}

bool Time::operator<(const Time& t1) const{
    if(year<t1.year){return true;}
    else if(year>t1.year){return false;}
    else{
        if(month<t1.month){return true;}
        else if(month>t1.month){return false;}
        else{
            if(day<t1.day){return true;}
            else if(day>t1.day){return false;}
            else{
                if(hour<t1.hour){return true;}
                else if(hour>t1.hour){return false;}
                else{return minute<t1.minute;}
            }
        }
    }
}

bool Time::operator==(const Time& t1) const{
    return (day == t1.day && month==t1.month && year==t1.year && hour==t1.hour && minute==t1.minute);
}

Time::Time(int day, int month, int year, int hour, int minute) {
    this -> day =day;
    this -> month = month;
    this -> year = year;
    this-> minute=minute;
    this -> hour = hour;
}

Time::Time(int hour, int minute) {
    this-> minute=minute;
    this -> hour = hour;
}




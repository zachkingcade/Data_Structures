#pragma once
#include "Date.h"


Date::Date(){
	year = 0;
	month = 0;
	day = 0;
}

Date::Date(int YYYY, int MM, int DD){
	year = YYYY;
	month = MM;
	day = DD;
}

//setters

void Date::setYear(int YYYY){
	year = YYYY;
}

void Date::setMonth(int MM){
	month = MM;
}

void Date::setDay(int DD){
	day = DD;
}

//getters

int Date::getYear(){
	return year;
}

int Date::getMonth(){
	return month;
}

int Date::getDay(){
	return day;
}
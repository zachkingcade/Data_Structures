#pragma once

class Date {
	private:

	int year;
	int month;
	int day;

	public:

	Date();
	Date(int YYYY, int MM, int DD);

	//setters
	void setYear(int YYYY);
	void setMonth(int MM);
	void setDay(int DD);

	//getters
	int getYear();
	int getMonth();
	int getDay();
};
/* File: time24.cpp
The class time24 represents time on 24 hour clock

Times are written to a stream in the form hour:minute
When two times are added the minutes are added and if the sum is 60 or
more then 60 is subtracted from the sum but the the hour is increased by
1. If the hour is 24 or more then 24 is subtracted from the hour.

Programmer: Aparna Mohan 			Date: September 21, 2018 */

#include <iostream>
#include <fstream>

using namespace std;

class time24 {
private:
	int hour_; // hour between 0 and 23
	int minute_; // minute between 0 and 59
public:
	int hour(void) const; // return hour_
	int minute(void) const; // return minute_
	void hour(int h); // hour_ = h
	void minute(int m); // minute_ = m
};

void write(ostream &out, const time24 &x); // prints hour:minute
time24 add(const time24 &x, const time24 &y); // add x and y

int main(void) // test the class
{
	time24 x, y, z;
	x.hour(18);
	x.minute(34);
	y.hour(10);
	y.minute(56);
	cout << "The time x is: ";
	write(cout, x);
	cout << "\nThe time y is: ";
	write(cout, y);
	// try adding
	z = add(x, y);
	cout << "\nThe sum of ";
	write(cout, x);
	cout << " and ";
	write(cout, y);
	cout << " is ";
	write(cout, z);
	cout << endl;
	return 0;
}
//////////////////////// Methods of time24 ///////////////////////////
int time24::hour(void) const{ // return hour_
	return hour_;
} 
int time24::minute(void) const{ // return minute_
	return minute_;
} 
void time24::hour(int h){ // hour_ = h
	hour_ = h;
}
void time24::minute(int m){
	minute_ = m;
}
//////////////////////// time24 functions ////////////////////////

void write(ostream &out, const time24 &x){ // prints hour:minute
	out << x.hour() << ":" << x.minute();
}
time24 add(const time24 &x, const time24 &y){ // add x and y
	int h, m;
	time24 t;
	h = x.hour() + y.hour();
	m = x.minute() + y.minute();
	
	if (m>=60){
		m = m-60;
		h++;
	}
	if (h>=24){
		h = h - 24;
	}
	
	t.hour(h);
	t.minute(m);
	
	return t;
} 

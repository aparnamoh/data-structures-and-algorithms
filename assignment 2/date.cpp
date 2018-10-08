/* File: date.cpp
A class representing dates in the form: day, month and year
dates are written to a stream in the form day/month/year
day_number() returns the number of days since 1/1 of the current year
including the current day
days_between() returns the number of days between two dates not
including the firstday but including the last day.
Programmer: Aparna Mohan                Date: September 22, 2018 */

#include <iostream>
#include <fstream>
using namespace std;

class date {
private:
  int day;
  int month;
  int year;
public:
	date(int d, int m, int y);
	void write(ostream & out) const;
	int days_between(const date & e); 
	int day_number(void) const;
};

// number of days in each month
const int DAYS[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main(void)
{
  ofstream fout("date.txt");
  date d(12, 6, 2010);

  date e(14, 9, 2012);

  fout << "For the date is ";
  d.write(fout);
  fout << endl;

  fout << "Day number is " << d.day_number() << endl;

  fout << "\nFor the date is ";
  e.write(fout);
  fout << endl;

  fout << "Day number is " << e.day_number() << endl;

  fout << "\nDays between ";
  d.write(fout);
  fout << " and ";
  e.write(fout);
  fout << " = " << d.days_between(e) << endl;

  fout.close();
  system("date.txt");

  return 0;
}
///////////////////////// Methods of date ////////////////////////////

date::date(int d, int m, int y){
	day = d;
	month = m;
	year = y;
}
void date::write(ostream & out) const{
	out << day << "/" << month << "/" << year;
}

int date::day_number(void) const{
	int i, m, daynum = 0;
	
	m = month; //assigning to diff variable to prevent changing orig
	
	for (i=1; i<m; i++){ //count goes up to penultimate month
		daynum += DAYS[i];
	}
	
	daynum += day + 1; //add day+1 to include the day itself
	
	return daynum;
	}
	
int date::days_between(const date & e){
	int y=0, m=0, i=0, daybw = 0; //all these variables will be in unit days
	
	//get year difference
	if (e.year>year){
		y = e.year - year;
	}
	else if(year>e.year){
		y = year - e.year;
	}
	else{
		y = 0;
	}
	
	y = y*365; //convert y into days
	
	
	//get month difference
	if(e.month>month){ //start month = month, end month = e.month
		for(i=month; i<e.month; i++){ 
			m += DAYS[i]; //add all months except end month
		}
		m = m - day + e.day; //adjustment: subtract start month date and add end month date
		daybw = y + m; //if 2nd month is later, then month diff is added to the year diff
	}
	else if(month>e.month){ //start month = e.month, end month = month
		for(i=e.month; i<month; i++){
			m += DAYS[i]; 
		}
		m = m + day - e.day; 
		daybw = y - m; 
	}
	else{
		m = 0;
		daybw = y;
	}
	
	return daybw;
}
	
	

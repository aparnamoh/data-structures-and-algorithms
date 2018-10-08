/* 
File: polar.cpp

This is a driver program for the function polar which computes the
polar coordinates of a point in the plane

Programmer: Aparna Mohan Date: September 7, 2018 
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//function prototype
void polar(float x, float y, float& r, float& theta);

int main(void){
	float x, y, r, theta;
	//open input and output files
	
	ifstream fin("polar.txt");
	ofstream fout("polarout.txt");
	
	/* fin >> x >> y;
	
	cout << "x = " << x << "y = " << y << endl; */
	
	while(fin >> x >> y){ //read data from input file 2 at a time until end of file is reached
		//function call
		polar(x, y, r, theta); 
		fout << r << " "<< theta << endl;
	} 
	
	//close input and output files
	fin.close();
	fout.close();
	system("polarout.txt");
	
	return 0;	
}

//function definition

void polar(float x, float y, float &r, float &theta){
	r = sqrt(x*x + y*y);
	
	if(r > 0.0 && y > 0.0){
		theta = acos(x/r);
	}
	else if (r > 0.0 && y <= 0.0){
		theta = -acos(x/r);
	}
	else{
		theta = 0.0;
	}
	
	return;
} 

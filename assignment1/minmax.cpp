/*	File: minmax.cpp
	This program uses uses two functions to find the maximum and minimum 
	of a set of floats stored in minmax.txt
	
	Programmer: Aparna Mohan 	Date: Sept 14, 2018
*/

#include <iostream>
#include <fstream>

using namespace std;

const int N = 100; //maximum array size

void readdata(float x[N], int &n);
void minmax(float x[N], int &n, float &min, float &max);

int main(void){
	ofstream outfile("minmaxout.txt");
	
	float x[N]; //the array
	int n; //the actual array size
	float max; //the maximum
	float min; //the minimum
	 
	readdata(x, n);
	minmax(x, n, min, max);
	
	outfile << "The array has " << n << " elements\n";
	outfile << "The maximum value in the array is " << max << endl;
	outfile << "The minimum value in the array is " << min << endl;
	
	outfile.close();
	
	system("minmaxout.txt");
	return 0; 
}

void readdata(float x[N], int &n){
	ifstream fin("minmax.txt");
	fin >> n; // read working size of array x
	
	for (int i = 0; i < n; i++) {
		fin >> x[i];
	}
	fin.close();
	return;
}

void minmax(float x[N], int &n, float &min, float &max){
	min = x[0];
	max = x[0];
	int i;
	
	for (int i=0; i<n; i++){
		if (x[i]<min){
			min = x[i];
			}
		else if (x[i]>max){ 
			max = x[i];
		}}
	return;
	}
	



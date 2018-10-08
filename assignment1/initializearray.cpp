/* File: intializearray.cpp

This program uses a number of different functions to initialize an array
Programmer: Aparna Mohan 	Date: Sept 14, 2018

*/

#include <iostream>
#include <fstream>
using namespace std;

/* prototypes */
float * init();
float * init(int n);
float * init(int n, float val);

int main(void){
	float* x; //passing by reference
	float val;
	int n=1;
	
	x = init();
	cout << "\nx = \n";
	for(int i=0; i< n; i++){
		cout << x[i] << endl;
		}
	delete [] x;

	n = 4;
	x = init(n);
	cout << "\nx = \n";
	for(int i=0; i< n; i++) {
		cout << x[i] << endl;
		}
	delete [] x;
	
	n = 5;
	val = 1.27;
	x = init(n, val);
	cout << "\nx = \n";
	for(int i=0; i< n; i++) {
		cout << x[i] << endl;
		}
	delete [] x;
	return 0;
}

float * init(){
	int val = 0;
	int n = 1;
	float * x = new float[n];
	for (int i = 0; i<n; i++){
		x[i]= val;
	}
	return x;
}
float * init(int n){
	int val = 0;
	float * x = new float[n];
	for(int i=0; i<n; i++){
		x[i]= val;
	}
	return x;
}
float * init(int n, float val){
	float * x = new float[n];
	for (int i=0; i<n; i++){
		x[i]= val;
	}
	return x;
}
//NOTES: need to function definition, two function prototypes, etc.

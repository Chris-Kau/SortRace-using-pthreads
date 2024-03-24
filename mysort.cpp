// Author: Chris Kau
// CECS 325-02
// Sorting Contest Using Pthreads (Prog 4)
// Due 03/26/2024
// I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program.
#include <iostream>
#include <fstream>
#include <array>
#include <pthread.h>
using namespace std;
void bubble(int A[], int size)
{
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - i - 1; j++ )
		{
			if (A[j] > A[j+1])
			{
				swap(A[j], A[j+1]);
			}
		}
	}
}

int main(int argc, char*argv[])
{
	//split array in 8 sections for 8 threads
	int m0[125];
	int m1[125];
	int m2[125];
	int m3[125];
	int m4[125];
	int m5[125];
	int m6[125];
	int m7[125];
	ifstream file;
	file.open(argv[1]);
	string temp;
	int idx = 0;
	while (getline(file, temp))
	{
		if(idx < 125){
			m0[idx] = stoi(temp);
		}else if(idx < 250){
			m1[idx] = stoi(temp);
		}else if(idx < 375){
			m2[idx] = stoi(temp);
		}else if(idx < 500){
			m3[idx] = stoi(temp);
		}else if(idx < 625){
			m4[idx] = stoi(temp);
		}else if(idx < 750){
			m5[idx] = stoi(temp);
		}else if(idx < 875){
			m6[idx] = stoi(temp);
		}else if(idx < 1000){
			m7[idx] = stoi(temp);
		}	
		idx++;
	}

	file.close();
	//bubble(numbers, idx); 
	//ofstream fout(argv[2]);
	//for(int i = 0; i < idx; i++)
	//{
	//	fout  << numbers[i] << endl;
	//}
	return 0;
}

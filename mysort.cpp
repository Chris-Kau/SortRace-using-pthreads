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
	for(int i = 0; i <= size - 1; i++)
	{
		for(int j = 0; j <= size - i - 1; j++ )
		{
			if (A[j] > A[j+1])
			{
				swap(A[j], A[j+1]);
			}
		}
	}
}

struct sortStuff{
	int *start;
	int size;
};

void *bridge(void *ptr)
{
	sortStuff *arg = (sortStuff *)ptr;
	bubble(arg->start, arg->size);
}

int *merge(int A[], int B[], int size){
	int *temp = new int[size*2];
	int i, j, k;

	//compares values of array1 to array2 to append the lower value first to temp
	while(i < size && j < size)
	{
		if(A[i] <= B[i]){
			temp[k] = A[i];
			i++;
		}else{
			temp[k] = B[j];
			j++;
		}
		k++;
	}

	//get remaining nums we might have missed
	while(i < size){
		temp[k] = A[i];
		k++;
		i++;
	}
	//get remaining nums we might have missed
	while(j < size){
		temp[k] = B[j];
		k++;
		j++;
	}

	return temp;	
}
int main(int argc, char*argv[])
{
	int *numbers = new int[1000000];
	ifstream file;
	file.open(argv[1]);
	string temp;
	int idx = 0;
	while (getline(file, temp))
	{
		numbers[idx] = stoi(temp);
		idx++;
	}
	file.close();

	sortStuff ss0;
	ss0.start = &numbers[0];
	ss0.size = 125000;

	sortStuff ss1;
	ss1.start = &numbers[125000];
	ss1.size = 125000;

	sortStuff ss2;
	ss2.start = &numbers[250000];
	ss2.size = 125000;

	sortStuff ss3;
	ss3.start = &numbers[375000];
	ss3.size = 125000;

	sortStuff ss4;
	ss4.start = &numbers[500000];
	ss4.size = 125000;

	sortStuff ss5;
	ss5.start = &numbers[625000];
	ss5.size = 125000;

	sortStuff ss6;
	ss6.start = &numbers[750000];
	ss6.size = 125000;

	sortStuff ss7;
	ss7.start = &numbers[875000];
	ss7.size = 125000;

	pthread_t t0, t1, t2, t3, t4, t5, t6, t7;

	pthread_create(&t0, NULL, bridge, (void*)&ss0);
	pthread_create(&t1, NULL, bridge, (void*)&ss1);
	pthread_create(&t2, NULL, bridge, (void*)&ss2);
	pthread_create(&t3, NULL, bridge, (void*)&ss3);
	pthread_create(&t4, NULL, bridge, (void*)&ss4);
	pthread_create(&t5, NULL, bridge, (void*)&ss5);
	pthread_create(&t6, NULL, bridge, (void*)&ss6);
	pthread_create(&t7, NULL, bridge, (void*)&ss7);

	pthread_join(t0, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	pthread_join(t5, NULL);
	pthread_join(t6, NULL);
	pthread_join(t7, NULL);
	
	int *section1 = merge(ss0.start, ss1.start, 125000);
	int *section2 = merge(ss2.start, ss3.start, 125000);
	int *section3 = merge(ss4.start, ss5.start, 125000);
	int *section4 = merge(ss6.start, ss7.start, 125000);

	int *sec1sec2 = merge(section1, section2, 250000);
	int *sec3sec4 = merge(section1, section2, 250000);

	int *allsecs = merge(sec1sec2, sec3sec4, 500000);

	ofstream fout(argv[2]);
	for(int i = 0; i <= 1000000; i++){
		fout << allsecs[i] << endl;
	}

	delete[] section1;
	delete[] section2;
	delete[] section3;
	delete[] section4;
	delete[] sec1sec2;
	delete[] sec3sec4;
	delete[] allsecs;
	delete[] numbers;
	return 0;
}

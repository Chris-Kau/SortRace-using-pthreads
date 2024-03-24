// Author: Chris Kau
// CECS 325-02
// Sorting Contest Using pThreads (Prog 4)
// Due 03/26/2024
// I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program.
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
        if (argc != 4)
        {
                cout << "Example: %generate 10000000 100000 999999\n";
        }else{
                int count = stoi(argv[1]);
                int min = stoi(argv[2]);
                int max = stoi(argv[3]);
                ofstream fout("numbers.dat");
                srand(time(0));
                for(int i = 0; i < count; i++)
                {
                        fout << (rand() % (max-min+1)+min) << endl;
                }
        }
        return 0;
}

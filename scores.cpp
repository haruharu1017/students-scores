#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    ifstream f("scores.txt");
    vector<int> v;
    int number;
    while(f >> number) 
    { 
        v.push_back(number); 
    }


    int sum = 0;
    for(int i=0; i<v.size(); i++)
    {
        sum += v[i];
    }
    double ave = (1.0*sum) / v.size();
    cout << "average: " << ave << endl;

    ofstream file("scores.txt");
    if (f.is_open())
    {
    for(int i=0; i<v.size(); i++)
    {
        file << v[i] << endl;
    }   
    file << "Average of scores: " << ave << endl;
    file << "scores above the average: " << endl;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] > ave)
        {
            file << v[i] << endl;
        }
    }   
    }
    return 0;
}
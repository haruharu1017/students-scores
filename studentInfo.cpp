#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class StudentInfo
{
public:
    StudentInfo() : first(""), last(""), level(""), GPA(0.0){}
    StudentInfo(string f, string l, string lev, double gpa) : first(f), last(l), level(lev), GPA(gpa){}
    string firstName() {return first;}
    string lastName() {return last;}
    string classLevel() {return level;}
    double getGPA() {return GPA;}
private:
    string first, last, level;
    double GPA;
};

int main()
{
    ifstream f("studentlist1.txt");
    string first, last, level;
    double GPA;
    vector<StudentInfo> si;
    while (f >> first >> last >> level >> GPA)
    {
        StudentInfo s(first, last, level, GPA);
        si.push_back(s);
    }
    double gpaSum = 0;
    for (int i=0; i<si.size(); i++)
    {
        gpaSum += si[i].getGPA();
    }
    double gpaAve = gpaSum / si.size();
    cout << gpaAve << endl;

    ofstream file("studentScores.txt");
    file << "Average GPA: " << gpaAve << endl;
    file << "Students whose GPAs are above the average: " << endl;
    for (int i=0; i<si.size(); i++)
    {
        if (si[i].getGPA() > gpaAve)
        file << si[i].firstName() << " " << si[i].lastName() << endl;
    }
    return 0;
}
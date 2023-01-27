/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: karasia1
PROG: friday
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLeapYear(int year) {
    year+=1900;
    return ((year%4==0 && !(year%100==0)) || (year%400==0));
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int years;
    fin >> years;

    int days[] = {0,0,0,0,0,0,0};
    int day = 0;

    for (int year = 0; year<years; year++) {
        int daysPerMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (isLeapYear(year)) {daysPerMonth[1]=29;}

        for (int month = 0; month<12; month++) {
            days[(day+12)%7]++;
            day = (day+daysPerMonth[month])%7;
        }
    }

    fout << days[5] << ' ' << days[6] << ' ' << days[0] << ' ' << days[1] << ' ' << days[2] << ' ' << days[3] << ' ' << days[4] << endl;
    return 0;
}
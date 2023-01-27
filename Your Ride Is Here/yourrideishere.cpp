/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: your_id_here
PROG: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;

    int valComet = 1;
    for (int i = 0; i<a.length(); i++) {
        valComet *= (int(a[i])-64);
    }

    int valGroup = 1;
    for (int i = 0; i<b.length(); i++) {
        valGroup *= (int(b[i])-64);
    }

    string x;
    if (valComet%47==valGroup%47) {
        x = "GO";
    } else {
        x = "STAY";
    }

    fout << x << endl;
    return 0;
}
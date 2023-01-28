/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: karasia1
PROG: beads
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int length;
    string necklace;
    fin >> length >> necklace;
    necklace+= necklace;
    int out = 0;

    for (int i = 0; i<necklace.length()-1; i++) {
        int sum = 0;
        if (necklace[i]=='w') {
            for (int j = i; j<necklace.length(); j++) {
                if (necklace[j]=='w') {
                    sum++;
                } else {break;}
            }
        }
        
        if (sum==length) {
            out = length;
            break;
        }
        
        char begin = necklace[sum+i];
        for (int j = sum+i; j<i+length; j++) {
            if (necklace[j]==begin || necklace[j]=='w') {
                sum++;
            } else {
                break;
            }
        }
        
        if (sum==length) {
            out = length;
            break;
        }
        char end = necklace[sum+i];
        for (int j = sum+i; j<necklace.length(); j++) {
            if (necklace[j]==end || necklace[j]=='w') {
                sum++;
            } else {
                break;
            }
        }
        if (sum>out && !(sum>length)) {out=sum;}
    }

    fout << out << endl;
    return 0;
}
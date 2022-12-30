#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    ifstream infile;
    infile.open("input/day4.txt", ios::in);
    string cur;
    int count = 0, count2 = 0;
    while (getline(infile, cur)) {
        int a[4] = {0};
        int x = 0;
        for (int i = 0; i < cur.size(); i++) {
            if (cur[i] >= '0' && cur[i] <= '9') a[x] = a[x]*10 + (cur[i]-'0');
            else x++;
        }
        if ( (a[0] <= a[2] && a[1] >= a[3]) || (a[0] >= a[2] && a[1] <= a[3]) ) count++;
        if ( max(a[0], a[2]) <= min(a[1], a[3]) ) count2++;
    }
    cout << count << '\n';
    cout << count2 << '\n';
    return 0;
}
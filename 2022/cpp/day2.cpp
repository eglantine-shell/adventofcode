#include <vector>
#include <iostream>
#include <string>
#include <numeric>
#include <fstream>
using namespace std;

int main() {
    ifstream infile;
    infile.open("input/day2.txt", ios::in);
    string line;
    int score = 0, score2 = 0, a, x, x2;
    while (getline(infile, line)) {
        a = line[0]-'A', x = line[2]-'X';
        //part1
        if ((a-1) %3 == x || a+2 == x) x += 1;
        else if (a == x) x += 4;
        else x += 7;
        score += x;
        //part2
        x = line[2]-'X';
        if (x == 0) x2 = (a+2) % 3;
        else if (x == 1) x2 = a;
        else x2 = (a+1) % 3;
        score2 += x2+1 + x*3;
    }
    cout << score << '\n';
    cout << score2 << '\n';
    return 0;
}
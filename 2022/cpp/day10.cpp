#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int check[] = {20, 60, 100, 140, 180, 220};

int main() {
    ifstream infile;
    infile.open("input/day10.txt", ios::in);
    string cur, ins, line = "";
    int val, cycle = 1, x = 1, i = 0, ans = 0;
    while (getline(infile, cur)) {
        stringstream ss(cur);
        ss >> ins >> val;
        if ((cycle-1) % 40 == 0) line += '\n';
        if ((cycle-1) % 40 == x || (cycle-1) % 40 == x+1 || (cycle-1) % 40 == x-1) line += '#';
        else line += '.';
        if (cycle == check[i] || (cycle == check[i]-1 && ins == "addx")) ans += x * check[i++];
        if (ins == "noop") cycle++;
        else {
            if (cycle % 40 == 0) line += '\n';
            if (cycle % 40 == x || cycle % 40 == x+1 || cycle % 40 == x-1) line += '#';
            else line += '.';
            x += val;
            cycle += 2;
        }
    }
    cout << ans << '\n';
    cout << line << '\n';
    return 0;
}
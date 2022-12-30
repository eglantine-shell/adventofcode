#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

string stacks[20];

void act (int num, int from, int to) {
    string move = stacks[from].substr(0, num);
    reverse(move.begin(), move.end());
    stacks[to] = move + stacks[to];
    stacks[from] = stacks[from].substr(num);
}

void act2 (int num, int from, int to) {
    string move = stacks[from].substr(0, num);
    stacks[to] = move + stacks[to];
    stacks[from] = stacks[from].substr(num);
}

int main() {
    ifstream infile;
    infile.open("input/day5.txt", ios::in);
    string cur;
    int col, row;
    while (getline(infile, cur)) {
        if (cur[1] == '1') {
            col = cur[cur.size()-2]-'0';
            break;
        }
        for (int i = 1; i < cur.size(); i += 4) {
            if (cur[i] != ' ') stacks[(i-1)/4] += cur[i];
        }
    }
    while (getline(infile, cur)) {
        if (cur[0] != 'm') continue;
        stringstream ss(cur);
        string s[6];
        for (int j = 0; j < 6; j++) ss >> s[j];
        act(stoi(s[1]), stoi(s[3])-1, stoi(s[5])-1);
        // act2(stoi(s[1]), stoi(s[3])-1, stoi(s[5])-1);
    }
    for (int i = 0; i < col; i++) cout << stacks[i][0];
    cout << '\n';
    return 0;
}
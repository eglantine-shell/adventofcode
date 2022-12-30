#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream infile;
    infile.open("input/day8.txt", ios::in);
    string cur;
    vector<string> trees;
    int count = 0;
    while (getline(infile, cur)) trees.push_back(cur);
    int row = trees.size(), col = trees[0].size(), pre;
    //part1
    bool see[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)  see[i][j] = false;
    }
    for (int i = 0; i < row; i++) {
        pre = 0;
        for (int j = 0; j < col; j++) {
            if (pre == 9) break;
            if (pre < trees[i][j]-'0') {
                see[i][j] = true;
                pre = trees[i][j]-'0';
            }
        }
    }
    for (int i = 0; i < row; i++) {
        pre = 0;
        for (int j = col-1; j > 0; j--) {
            if (pre == 9) break;
            if (pre < trees[i][j]-'0'){
                see[i][j] = true;
                pre = trees[i][j]-'0';
            }
        }
    }
    for (int j = 0; j < col; j++) {
        pre = 0;
        for (int i = 0; i < row; i++) {
            if (pre == 9) break;
            if (pre < trees[i][j]-'0') {
                see[i][j] = true;
                pre = trees[i][j]-'0';
            }
        }
    }
    for (int j = 0; j < col; j++) {
        pre = 0;
        for (int i = row-1; i > 0; i--) {
            if (pre == 9) break;
            if (pre < trees[i][j]-'0') {
                see[i][j] = true;
                pre = trees[i][j]-'0';
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || i == row-1 || j == 0 || j == col-1) see[i][j] = true;
            if (see[i][j]) count++;
        }
    }
    cout << count << '\n';
    //part2
    int mx = 0;
    for (int i = 1; i < row-1; i++) {
        for (int j = 1; j < col-1; j++) {
            int up = 1, down = 1, left = 1, right = 1;
            while (i-up > 0 && trees[i-up][j] < trees[i][j]) up++;
            while (i+down < row-1 && trees[i+down][j] < trees[i][j]) down++;
            while (j-left > 0 && trees[i][j-left] < trees[i][j]) left++;
            while (j+right < col-1 && trees[i][j+right] < trees[i][j]) right++;
            mx = max(mx, up * down * left * right);
        }
    }
    cout << mx << '\n';
    return 0;
}
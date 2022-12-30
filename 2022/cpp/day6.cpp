#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int help (string s, int len) {
    int left = 0, right = 0, record[26] = {0};
    while (right - left < len) {
        record[s[right++]-'a']++;
        while (record[s[right-1]-'a'] > 1) record[s[left++]-'a']--;
    }
    return right;
}

int main() {
    ifstream infile;
    infile.open("input/day6.txt", ios::in);
    string cur;
    while (getline(infile, cur)) {
        cout << help(cur, 4) << '\n';
        cout << help(cur, 14) << '\n';
    }
    return 0;
}
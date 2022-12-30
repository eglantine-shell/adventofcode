#include <vector>
#include <iostream>
#include <string>
#include <numeric>
#include <fstream>
using namespace std;

int main() {
    vector<int> elf;
    ifstream infile;
    infile.open("input/day1.txt", ios::in);
    string cur;
    int c = 0;
    while (getline(infile, cur)) {
        bool digit = false;
        if (cur[0] >= '0' && cur[0] <= '9') digit = true;
        if (digit) c += stoi(cur);
        else {
            elf.push_back(c);
            c = 0;
        }
    }
    sort(elf.begin(), elf.end());
    cout << elf[elf.size() - 1] << '\n';
    cout << accumulate(elf.end()-3, elf.end(), 0) << '\n';
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int pri (char a) {
    if (a >= 'a' && a <= 'z') return a-'a'+1;
    return a-'A'+27;
}

int main() {
    ifstream infile;
    infile.open("input/day3.txt", ios::in);
    string cur;
    int sum = 0, sum2 = 0, l = 0;
    set<char> t;
    while (getline(infile, cur)) {
        // part1
        set<char> s1, s2, s3, t1;
        bool flag = false;
        int i = 0, j = cur.size()-1;
        while (i < j) {
            s1.insert(cur[i++]);
            s2.insert(cur[j--]);
            if (flag) continue;
            if (s2.count(cur[i-1])) {
                sum += pri(cur[i-1]);
                flag = true;
            }
            else if (s1.count(cur[j+1])) {
                sum += pri(cur[j+1]);
                flag = true;
            }
        }
        // part2
        set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
        if (l % 3 == 0) t = s3;
        else {
            set_intersection(s3.begin(), s3.end(), t.begin(), t.end(), inserter(t1, t1.begin()));
            if (l % 3 == 2) sum2 += pri(*t1.begin());
            else {
                t = t1;
                t1.clear();
            }
        }
        l++;
    }
    cout << sum << '\n';
    cout << sum2 << '\n';
    return 0;
}
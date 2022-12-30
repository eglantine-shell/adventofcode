#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector< queue<long long> > monkeys;

// for part 2
int M = 1;

long long operate (long long old, string operation) {
    old %= M;
    string s1, s2, s3;
    stringstream ss (operation);
    ss >> s1 >> s2 >> s3;
    if (s3 == "old") s3 = to_string(old);
    if (s2 == "+") old += stoll(s3);
    else old *= stoll(s3);
    old %= M;
    return old;
}

int main() {
    ifstream infile;
    infile.open("input/day11.txt", ios::in);
    string cur;
    queue<long long> monkey;
    vector<string> operations;
    vector<int> division, t, f;
    while (getline(infile, cur)) {
        if (cur[0] == 'M') monkey = queue<long long>();
        else if (cur == "") monkeys.push_back(monkey);
        else if (cur[2] == 'S') {
            int x = 0;
            for (int i = 18; i < cur.size(); i++) {
                if (cur[i] == ',') monkey.push(x);
                else if (cur[i] == ' ') x = 0;
                else x = x * 10 + (cur[i] - '0');
            }
            monkey.push(x);
        }
        else if (cur[2] == 'O') operations.push_back(cur.substr(19));
        else if (cur[2] == 'T') {
            stringstream ss (cur);
            string s;
            while (ss >> s) if (s[0] >= '0' && s[0] <= '9') {
                division.push_back(stoi(s));
                M *= stoi(s);
            }
        }
        else if (cur[7] == 't') t.push_back(cur[cur.size()-1]-'0');
        else f.push_back(cur[cur.size()-1]-'0');
    }
    monkeys.push_back(monkey);
    int n = monkeys.size();
    vector<int> inspect(n, 0);
    // for (int round = 0; round < 20; round++) {
    for (int round = 0; round < 10000; round++) {
        for (int i = 0; i < n; i++) {
            while (!monkeys[i].empty()) {
                long long item = monkeys[i].front();
                monkeys[i].pop();
                inspect[i]++;
                // item = operate(item, operations[i]) / 3;
                item = operate(item, operations[i]);
                if (item % division[i]) monkeys[f[i]].push(item);
                else monkeys[t[i]].push(item);
            }
        }
    }
    sort(inspect.begin(), inspect.end());
    cout << (long long)inspect[n-1] * inspect[n-2] << '\n'; 
    return 0;
}
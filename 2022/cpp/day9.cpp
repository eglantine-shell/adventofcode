#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
    ifstream infile;
    infile.open("input/day9.txt", ios::in);
    string cur;
    set< pair<int, int> > st, st2;
    vector< pair<int, int> > v;
    for (int i = 0; i < 10; i++) v.push_back(make_pair(0, 0));
    pair<int, int> tail(0, 0), head(0, 0), move;
    while (getline(infile, cur)){
        stringstream ss(cur);
        char act;
        int step;
        ss >> act >> step;
        switch (act) {
            case 'R': move = make_pair(1, 0); break;
            case 'U': move = make_pair(0, 1); break;
            case 'L': move = make_pair(-1, 0); break;
            case 'D': move = make_pair(0, -1); break;
        }
        while (step--) {
            // part 1
            head.first += move.first;
            head.second += move.second;
            if (head.first - tail.first > 1) {
                tail.first++;
                tail.second = head.second;
            }
            else if (head.first - tail.first < -1) {
                tail.first--;
                tail.second = head.second;
            }
            else if (head.second - tail.second > 1) {
                tail.second++;
                tail.first = head.first;
            }
            else if (head.second - tail.second < -1) {
                tail.second--;
                tail.first = head.first;
            }
            st.insert(tail);

            //part 2
            v[0] = head;
            for (int i = 0; i < 9; i++) {
                if (v[i].first - v[i+1].first > 1) {
                    v[i+1].first++;
                    if (v[i+1].second != v[i].second) {
                        if (v[i+1].second > v[i].second) v[i+1].second--;
                        else v[i+1].second++;
                    }
                }
                else if (v[i].first - v[i+1].first < -1) {
                    v[i+1].first--;
                    if (v[i+1].second != v[i].second) {
                        if (v[i+1].second > v[i].second) v[i+1].second--;
                        else v[i+1].second++;
                    }
                }
                else if (v[i].second - v[i+1].second > 1) {
                    v[i+1].second++;
                    if (v[i+1].first != v[i].first) {
                        if (v[i+1].first > v[i].first) v[i+1].first--;
                        else v[i+1].first++;
                    }
                }
                else if (v[i].second - v[i+1].second < -1) {
                    v[i+1].second--;
                    if (v[i+1].first != v[i].first) {
                        if (v[i+1].first > v[i].first) v[i+1].first--;
                        else v[i+1].first++;
                    }
                }
            }
            st2.insert(v[9]);
        }
    }
    cout << st.size() << '\n';
    cout << st2.size() << '\n';
    return 0;
}
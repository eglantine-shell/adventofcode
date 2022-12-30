#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct file {
    string name;
    vector<string> dir;
    int size;
    file(string name, vector<string> dir, int size): name(name), dir(dir), size(size){}
};

static bool cmp(const file& f1, const file& f2) {
    return f1.size < f2.size;
}

vector<file> files;
int findSize (string name) {
    for (int i = 0; i < files.size(); i++) {
        if (files[i].name == name) {
            int size = files[i].size;
            for (int j = 0; j < files[i].dir.size(); j++) size += findSize(files[i].dir[j]);
            return size;
        }
    }
    return 0;
}

int main() {
    ifstream infile;
    infile.open("input/day7.txt", ios::in);
    string cur, curfile;
    vector<string> dir;
    int size = 0;
    bool flag = false;
    while (getline(infile, cur)) {
        if (cur == "$ ls") flag = false;
        else if (cur[0] == '$') {
            if (!flag) {
                file f(curfile, dir, size);
                files.push_back(f);
                flag = true;
            }
            if (cur[5] == '.') {
                while (curfile.back() != '/') curfile.pop_back();
                curfile.pop_back();
            }
            else {
                curfile = curfile + '/' + cur.substr(5);
                size = 0;
                dir.clear();
            }
        }
        else if (cur[0] == 'd') dir.push_back(curfile + '/' + cur.substr(4));
        else {
            int cursize = 0, i = 0;
            while (cur[i] >= '0' && cur[i] <= '9') cursize = cursize*10 + cur[i++]-'0';
            size += cursize;
        }
    }
    file f(curfile, dir, size);
    files.push_back(f);
    int ans = 0;
    for (int i = 0; i < files.size(); i++) {
        int cursize = files[i].size;
        for (int j = 0; j < files[i].dir.size(); j++) cursize += findSize(files[i].dir[j]);
        files[i].size = cursize;
        files[i].dir.clear();
        if (cursize > -1 && cursize <= 100000) ans += cursize;
    }
    cout << ans << '\n';
    //part 2
    infile.close();
    infile.open("input/day7.txt", ios::in);
    int total = 0;
    while (getline(infile, cur)) {
        if (cur == "$ ls") continue;
        else if (cur[0] == '$' && cur[5] != '/') break;
        else if (cur[0] == 'd') total += findSize("///" + cur.substr(4));
        else {
            int cursize = 0, i = 0;
            while (cur[i] >= '0' && cur[i] <= '9') cursize = cursize*10 + cur[i++]-'0';
            total += cursize;
        }
    }
    sort(files.begin(), files.end(), cmp);
    for (int i = 0; i < files.size(); i++) {
        if (files[i].size > total - 40000000) {
            cout << files[i].name << files[i].size << '\n';
            break;
        }
    }
    return 0;
}
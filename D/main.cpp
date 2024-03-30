#include <set>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> names;
    map<string, int> count;
    for (int i = 0; i < n; i++) {
        string name; cin >> name;
        names.push_back(name);
        count[name]++;
    }

    set<string> processed;
    for (string& name : names) {
        if (processed.count(name)) continue;
        cout << name << " " << count[name] << endl;
        processed.insert(name);
    }
}
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;


int main() {

    cout.tie(nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;

    map<string, string> version;
    unordered_map<string, int> inDegree;
    unordered_map<string, vector<string>> graph;

    for (int i = 0; i < n; i++) {
        string dependency; cin >> dependency;
        version[dependency] = "0.0.0";
        graph[dependency] = vector<string>();
    }

    for (int i = 0; i < m; i++) {
        string depending, dependency, v;
        cin >> depending >> dependency >> v;
        version[dependency] = max(version[dependency], v);
        graph[dependency].push_back(depending);
        inDegree[depending]++;
    }

    auto cmp = [&](const string& a, const string& b) {
        return (inDegree[a] < inDegree[b]) || ((inDegree[a] == inDegree[b] && a < b));
    };

    set<string, decltype(cmp)> pq(cmp);

    for (auto [package, _] : graph) {
        pq.insert(package);
    }

    vector<string> order;

    while (!pq.empty()) {
        string package = *pq.begin(); // get the package with the least dependencies
        pq.erase(package); // and pop it since we're gonna install it

        // if this package still needs a dependency to install
        // it means we have a cyclic dependency
        // hence it's impossible to install anything in this cycle
        if (inDegree[package] != 0) {
            cout << "NO" << endl;
            return 0;
        }

        // put this package in the order list
        order.push_back(package);

        // decrement the inDegree of each package that depends on current packkge
        for (auto& dependant : graph[package]) {
            pq.erase(dependant);
            inDegree[dependant]--;
            pq.insert(dependant);
        }
    }

    cout << "YES" << endl;

    cout << n << endl;
    for (auto& package : order) {
        cout << package << " " << version[package] << endl;
    }

}
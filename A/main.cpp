#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        unordered_map<int, int> mp;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            ans += mp[a];
            if (a == 1) ans += mp[2];
            else if (a == 2) ans += mp[1];
            mp[a]++;
        }
        cout << ans << endl;
    }
}

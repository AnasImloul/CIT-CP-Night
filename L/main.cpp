#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using ll = long long;
using namespace std;

const int MAXN = 1e6 + 1;
bool prime[MAXN];

void buildSieve(){
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for(ll i = 2; i < MAXN; i++){
        if (!prime[i]) continue;
        for(ll j = i*i; j <= 1e6; j += i)
            prime[j] = false;
    }
}


int main(){
    buildSieve();

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pair<ll, ll>> ans;
        for(int i = 2; i <= n / 2; i++){
            if(prime[i] && prime[n - i]){
                ans.emplace_back(i, n - i);
            }
        }
        cout << ans.size() << "\n";
        for(auto& [a, b] : ans)
            cout << a << " " << b << "\n";
    }

    return 0;
}

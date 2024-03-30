#include <vector>
#include <iostream>
using namespace std;

using ll = long long;

vector<vector<ll>> multiply(vector<vector<ll>>& a, vector<vector<ll>>& b, ll mod = 1e9 + 7) {
    vector<vector<ll>> c(a.size(), vector<ll>(b[0].size(), 0));
    for (ll i = 0; i < a.size(); i++)
        for (ll j = 0; j < b[0].size(); j++)
            for (ll k = 0; k < b.size(); k++)
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
    return c;
}

vector<vector<ll>> power(vector<vector<ll>>& a, ll n, ll mod = 1e9 + 7) {
    vector<vector<ll>> res(a.size(), vector<ll>(a.size(), 0));
    for (ll i = 0; i < a.size(); i++)
        res[i][i] = 1;

    while (n > 0) {
        if (n & 1)
            res = multiply(res, a, mod);
        a = multiply(a, a, mod);
        n >>= 1;
    }

    return res;
}

int main() {
    vector<vector<ll>> mat = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 1, 1}
    };

    ll n; cin >> n;
    mat = power(mat, n);
    cout << (mat[0][1] + mat[0][2]) % ((ll)1e9 + 7) << endl;

}
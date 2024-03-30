#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> road(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a--, road[i] = a;
    }

    int ans = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        ans++;
        int j = i;
        do {
            visited[j] = true;
            j = road[j];
        } while (j != i);
    }

    cout << ans << endl;

}
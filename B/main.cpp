#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int index(char letter) {
    switch (letter) {
        case 'L': return 0;
        case 'U': return 1;
        case 'C': return 2;
        case 'K': return 3;
        case 'Y': return 4;
        default: return 5; // irrelevant letters
    }
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> count(6, 0);
    for (int i = 0; i < n; i++) {
        count[index(s[i])]++;
    }
    // sort only the count of 'LUCKY' letters
    sort(count.begin(), count.begin() + 5);

    // it can be proven that the most optimal solution is
    // to make each frequency equal to the median of the five frequencies
    // median -> number in the middle after sorting
    // if median is zero, the constraints force us to have at least one occurrence
    // in this case the optimal solution is to make all the frequencies equal to one
    count[2] = max(count[2], 1);
    int ans = 0;
    for (int i = 0; i < 5; i++)
        ans += abs(count[i] - count[2])
    cout << ans << endl;
}

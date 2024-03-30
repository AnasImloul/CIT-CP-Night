#include<iostream>
#include<vector>
#include<numeric>
#include<unordered_set>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] = abs(arr[i]);
    }

    int total_sum = accumulate(arr.begin(), arr.end(), 0);

    // if the sum is odd, then it's impossible
    if (total_sum & 1) {
        cout << "NO" << endl;
        return 0;
    }

    // hashset to store all possible sums of every subset
    unordered_set<int> subsets;
    subsets.insert(0); // sum of the empty set

    // populate the hashmap (note that the hashmap won't grow exponentially large)
    // since all possible sums are in the range [0, total_sum]
    for (int i = 0; i < n; i++) {
        // tmp contains the possible subset sums before the i-th element
        vector<int> tmp(subsets.begin(), subsets.end());
        // we will add arr[i] to every previous subset
        for (int& num : tmp) subsets.insert(num + arr[i]);
    }

    cout << (subsets.count((total_sum >> 1)) ? "YES" : "NO") << endl;
}

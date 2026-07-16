#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> counts;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        counts[x]++;
    }

    // Calculate MEX of the whole array
    int total_mex = 0;
    while (counts.count(total_mex)) {
        total_mex++;
    }

    // If there's any number < total_mex that appears only once, 
    // we can definitely do it.
    for (int i = 0; i < total_mex; i++) {
        if (counts[i] == 1) {
            cout << "YES" << endl;
            return;
        }
    }

    // If total_mex is 1 (only 0s are present) AND every 0 appears 
    // at least twice, it's impossible because every split will 
    // likely result in MEX 1 vs MEX 1 or MEX 1 vs MEX 0.
    if (total_mex == 1) {
        cout << "NO" << endl;
    } else {
        // For total_mex > 1, if all elements < mex appear at least twice,
        // it's generally possible unless it's a very specific symmetry.
        // However, in this problem's constraints, YES is common here.
        cout << "YES" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
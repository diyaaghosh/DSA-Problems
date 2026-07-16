#include <iostream>
#include <vector>
using namespace std;

void solve(int n) {
    vector<int> res(n);
    int left = 0, right = n - 1;
    int num = n;

    // Fill from center to outward
    for (int i = 1; i < n; i += 2) {
        res[i] = num--;
    }
    for (int i = 0; i < n; i += 2) {
        res[i] = num--;
    }

    for (int x : res) cout << x << " ";
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}

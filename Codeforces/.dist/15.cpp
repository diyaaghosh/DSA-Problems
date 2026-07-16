#include <iostream>
using namespace std;

void solve() {
    long long a;
    cin >> a;
    long long ans = -1;

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if (i == j) continue;  // Ensure i and j are different
            
            long long b = (1LL << i) | (1LL << j);  // b with exactly two bits set
            long long c = a ^ b;  // Compute c
            
            if (b < a && (a + b > c) && (a + c > b) && (b + c > a)) {
                ans = b;
                break;  // Found the first valid b, exit inner loop
            }
        }
        if (ans != -1) break;  // Exit outer loop if a valid b is found
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

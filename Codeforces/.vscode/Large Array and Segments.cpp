#include <iostream>
#include <vector>
using namespace std;

void solve() {
    long long n, k, x;
    cin >> n >> k >> x;

    vector<long long> a(n);
    for (long long j = 0; j < n; j++) {
        cin >> a[j];
    }

    long long m = n * k;
    long long count = 0;
    long long sum = 0, left = 0;

    // Sliding window to find valid starting positions `l`
    for (long long right = 0; right < m; right++) {
        sum += a[right % n];  // Expand right pointer

       if (sum >x) {  // Ensure sum does not exceed x
            sum -= a[left % n]; // Shrink window
            left++;
            count++;
        }
       if(sum==x){
        sum -= a[left % n]; // Shrink window
        left++;
        count++;

       }
        
    }

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

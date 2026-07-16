#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int>& a, int n) {
    // Try to find x and y using i=1 and i=2
    long long A1 = 1, B1 = n;
    long long A2 = 2, B2 = n - 1;
    long long C1 = a[0], C2 = a[1];

    long long det = A1 * B2 - A2 * B1;
    if (det == 0) return false;

    // Use Cramer's Rule to solve for x and y
    long long detX = C1 * B2 - C2 * B1;
    long long detY = A1 * C2 - A2 * C1;

    if (detX % det != 0 || detY % det != 0) return false;

    long long x = detX / det;
    long long y = detY / det;

    // Check if the same x and y satisfy all other equations
    for (int i = 0; i < n; i++) {
        long long val = x * (i + 1) + y * (n - i);
        if (val != a[i]) return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        if (check(a, n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

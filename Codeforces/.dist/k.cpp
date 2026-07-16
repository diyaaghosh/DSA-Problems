#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX_N = 500000;  // Maximum sum of all ci over test cases

vector<long long> fact(MAX_N + 1), inv_fact(MAX_N + 1);

// Fast exponentiation: (x^y) % MOD
long long power_mod(long long x, long long y, int mod) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) res = res * x % mod;
        x = x * x % mod;
        y /= 2;
    }
    return res;
}

// Precompute factorials and modular inverses
void precompute_factorials() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[MAX_N] = power_mod(fact[MAX_N], MOD - 2, MOD);  // Fermat's theorem
    for (int i = MAX_N - 1; i >= 1; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

// Compute nCr % MOD
long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        vector<int> c(26);
        int total_chars = 0, odd_count = 0;
        
        for (int i = 0; i < 26; i++) {
            cin >> c[i];
            total_chars += c[i];
            if (c[i] % 2 == 1) odd_count++;
        }
        
        // If there are odd occurrences, we must split them into even/odd indices
        int even_count = total_chars / 2;
        
        // Compute number of ways to distribute even and odd characters
        long long result = nCr(even_count, odd_count);
        cout << result << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute_factorials();
    solve();
    
    return 0;
}

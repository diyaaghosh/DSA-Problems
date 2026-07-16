#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;

    long long sum = 0;
    long long p = 1;

    while (x >= 10) {
        long long rem = x % 10;
        if (rem >= 5)
            rem = 9 - rem;

        sum += p * rem;
        p *= 10;
        x /= 10;
    }

    if (x == 9)
        sum += p * x;
    else {
        if (x >= 5)
            sum += p * (9 - x);
        else
            sum += p * x;
    }

    cout << sum << '\n';
}
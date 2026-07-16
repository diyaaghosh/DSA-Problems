#include <iostream>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
 
        if (2 <= n && n <= 100)
        {
            cout << n-1 << endl;
        }
    }
}
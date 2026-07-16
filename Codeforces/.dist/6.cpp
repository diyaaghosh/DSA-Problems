#include <iostream>
#include <string>
using namespace std;

void convertToPlural(int t) {
    while (t--) {
        string W;
        cin >> W;

        // Remove "us" from the end and append "i"
        string pluralForm = W.substr(0, W.size() - 2) + "i";

        cout << pluralForm << endl;
    }
}

int main() {
    int t;
    cin >> t; // Number of test cases
    convertToPlural(t);
    return 0;
}

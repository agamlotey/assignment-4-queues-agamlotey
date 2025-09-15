#include <iostream>
using namespace std;

#define MAX 50

int main() {
    char stream[MAX];
    int freq[26] = {0};
    char q[MAX];
    int f = 0, r = -1;

    cout << "Enter stream (lowercase letters only): ";
    cin >> stream;
    

    for (int i = 0; stream[i] != '\0'; i++) {
        char c = stream[i];
        freq[c - 'a']++;
        q[++r] = c;

        while (f <= r && freq[q[f] - 'a'] > 1) f++;

        if (f > r) cout << "-1 ";
        else cout << q[f] << " ";
    }
    return 0;
}

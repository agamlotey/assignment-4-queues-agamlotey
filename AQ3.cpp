#include <iostream>
using namespace std;

#define MAX 50

int main() {
    int q[MAX], n;
    cout << "Enter even number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) cin >> q[i];

    int first[MAX], second[MAX];
    int k = 0;
    for (int i = 0; i < n/2; i++) first[i] = q[i];
    for (int i = n/2; i < n; i++) second[i - n/2] = q[i];

    cout << "Interleaved Queue: ";
    for (int i = 0; i < n/2; i++) {
        cout << first[i] << " " << second[i] << " ";
    }
    cout << endl;
    return 0;
}

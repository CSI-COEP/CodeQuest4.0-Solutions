#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int I, J;
    cin >> I >> J;

    int y = (J - I) / S.length() * count(S.begin(), S.end(), 'B');
    int initial_index = (I - 1) % S.length();
    int final_index = (J - 1) % S.length();

    if (final_index >= initial_index) {
        y += count(S.begin() + initial_index, S.begin() + final_index + 1, 'B');
    } else {
        y += count(S.begin(), S.begin() + final_index + 1, 'B') +
             count(S.begin() + initial_index, S.end(), 'B');
    }

    cout << y << endl;

    return 0;
}

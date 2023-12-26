#include "bits/stdc++.h"
using namespace std;
long long max_goldbars() {
    long long N;
    cin >> N;
    vector<long long> A(N);
    for (long long i = 0; i < N; ++i) {
        cin >> A[i];
    }
    long long La, Ra, Lb, Rb;
    cin >> La >> Ra >> Lb >> Rb;
    --La; --Ra; --Lb; --Rb;

    if (Ra < Lb) {
        long long sum = 0;
        for (long long i = 0; i <(Ra + Lb) / 2+1; i++) {
            sum += A[i];
        }
        return sum;
    }
    if (Rb < La) {
        long long  sum = 0;
        for (long long i = (Rb + La + 1) / 2; i < N; i++) {
            sum += A[i];
        }
        return sum;
    }

    long long result = 0, total = 0, curr = 0;
    total = accumulate(A.begin(), A.end(), 0);
    for (long long i=0; i<max(La, Lb); i++) {
        curr += A[i];
    }
    for (long long i = max(La, Lb); i < min(Ra, Rb)+1; i++) {
        curr += A[i];
        if (Lb <= i + 1 && i + 1 <= Rb && Lb <= i - 1 && i - 1 <= Rb) {
            result = max(result, min(curr, total - (curr - A[i])));
        } else if (Lb <= i + 1 && i + 1 <= Rb) {
            result = max(result, curr);
        } else if (Lb <= i - 1 && i - 1 <= Rb) {
            result = max(result, total - (curr - A[i]));
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    vector<long long> answer;
    for (int caseNum = 0; caseNum < T; ++caseNum) {
        answer.push_back(max_goldbars());
    }
    cout << "Answers" << endl;
    for (long long ans : answer) {
        cout << ans << endl;
    }
    return 0;
}

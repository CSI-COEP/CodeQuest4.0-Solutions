#include <bits/stdc++.h>
using namespace std;
using li = long long; // long long integers are used for avoiding overflow errors
int main() {
  int t; // taking input of the number of testcases
  cin >> t;
  while (t--) {
    int n;
    li h;
    cin >> n >> h;

    // taking input for the attack strikes
    vector<li> a(n);
    for (li &x : a) cin >> x;

    // setting limits for binary search between maximum limit and minimum limit for the value of poison damage (according to constraints)
    li l = 1, r = 1e18;
    while (l <= r) {
      li m = (l + r) / 2;
      li sum = m;
      for (int i = 0; i < n - 1; ++i) 
        sum += min(m, a[i + 1] - a[i]);
      if (sum < h) l = m + 1;
      else r = m - 1;
    }
    cout << r + 1 << '\n';
  }
}
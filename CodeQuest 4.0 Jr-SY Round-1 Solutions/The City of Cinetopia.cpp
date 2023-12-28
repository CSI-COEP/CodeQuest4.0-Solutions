#include <bits/stdc++.h>
using namespace std;
#define int long long
int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        set<pair<int, int>> s;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int cur = sum + a[i] - d * (i + 1);
            ans = max(ans, cur);
            if (a[i] > 0) {
                s.insert({a[i], i});
                sum += a[i];
                if (s.size() >= m) {
                    sum -= (s.begin()->first);
                    s.erase(s.begin());
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
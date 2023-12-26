#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> answers;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> dp(n + 2);
        for (int i = 0; i <= n; i++)
        {
            dp[i] = i;
        }
        for (int i = 2; i <= n; i++)
        {
            dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
            int cur = dp[i] + 4;
            for (int j = i + i; j <= n; j += i)
            {
                cur += 2;
                dp[j] = min(dp[j], cur);
            }
        }
        answers.push_back(dp[n]);
    }
    cout << "Answers" << endl;
    for (auto ans : answers)
    {
        cout << ans << endl;
    }
}
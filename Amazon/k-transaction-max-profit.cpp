#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    int k;
    cin >> k;
    vector<vector<int>> dp(k + 1, vector<int>(n));
    for (int i = 1; i <= k; i++)
    {
        int maxim = INT_MIN;
        for (int j = 1; j < n; j++)
        {
            if (dp[i - 1][j - 1] - price[j - 1] > maxim)
                maxim = dp[i - 1][j - 1] - price[j - 1];
            dp[i][j] = max(dp[i][j - 1], maxim + price[j]);
        }
    }
    cout << dp[k][n - 1];
    return 0;
}
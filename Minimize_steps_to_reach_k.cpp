#include<iostream>
#include<vector>
using namespace std;

int minOperation(int k, vector<int> &dp)
{
    for (int i = 1; i <= k; i++)
    {

        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }
    return dp[k];
}

int main()
{
    int k = 12;
    vector<int> dp(13, 0);
    int ans = minOperation(k, dp);
    for(auto i:dp)
    {
        cout<<i<<" ";
    }
    return 0;
}
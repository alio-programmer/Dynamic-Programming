#include<iostream>
#include<vector>
using namespace std;

signed main(){
    vector<int> height = {30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = dp[0]+abs(height[1]-height[0]);
    for(int i=2; i<n; i++){
        dp[i] = min(dp[i-1]+abs(height[i]-height[i-1]), dp[i-2]+abs(height[i]-height[i-2]));
    }
    for(auto i: dp){
        cout<<i<<" ";
    }
    return 0;
}
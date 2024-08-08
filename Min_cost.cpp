#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> cost = {2, 5, 3, 1, 7, 3, 4 };
    int n = cost.size();
    cost.push_back(0);
    vector<int> dp(n+1, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i=2; i<n+1; i++){
        dp[i] = min(dp[i-1]+cost[i], dp[i-2]+cost[i]);
    }
    for(auto i: dp){
        cout<<i<<" ";
    }cout<<endl;
    cout<<"minimum cost to climb stairs isL:"<<dp[n];
    return 0;
}
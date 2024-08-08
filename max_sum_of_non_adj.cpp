#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> A = {3, 2, 5, 10, 7};
    int n = A.size();
    A.push_back(0);
    vector<int> dp(n+1);
    dp[0] = A[0];
    dp[1] = A[1];
    for(int i=2; i<n+1; i++){
        dp[i] = max(dp[i-1], dp[i-2]+A[i]);
    }
    for(auto i: dp){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}
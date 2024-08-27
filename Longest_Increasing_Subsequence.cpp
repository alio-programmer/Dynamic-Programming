#include<iostream>
#include<vector>
using namespace std;

signed main(){
    vector<int> A = {7,7,7,7,7,7,7};
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        dp[i][i] = 1;
    }
    int maxi = -1e9;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(A[j-1]<A[j]){
                dp[i][j] = 1+dp[i][j-1];
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
        maxi = max(maxi, dp[i][n-1]);
    }
    cout<<"length of longest increasing subsequence in given array A is:"<<maxi<<endl;
    return 0;
}
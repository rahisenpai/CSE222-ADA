//rahisenpai's implementation/code
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> A = {0, 4,3,-6,-5,-1,-2,0,7,8,9,1,2,-2,1,0};
    int n = A.size()-1;
    vector<vector<int>> dp(2, vector<int>(n+1, 0));
    //0 - ring, 1 - ding
    for (int i : A){
        cout << i << " ";
    }
    cout << "\n";

    dp[0][0] = dp[1][0] = 0;

    if(A[1] == 0){
        dp[0][1] = max(dp[0][0],dp[1][0]);
        dp[1][1] = dp[0][1];
    }
    else{
        dp[0][1] = A[1];
        dp[1][1] = -A[1];
    }

    if (A[2] == 0){
        dp[0][2] = max(dp[0][1], dp[1][1]);
        dp[1][2] = dp[0][2];
    }
    else{
        dp[0][2] = A[2] + max(dp[0][1], dp[1][1]);
        dp[1][2] = -A[2] + max(dp[0][1], dp[1][1]);
    }

    if (A[3] == 0){
        dp[0][3] = max(dp[0][2], dp[1][2]);
        dp[1][3] = dp[0][3];
    }
    else{
        dp[0][3] = A[3] + max(dp[0][2], dp[1][2]);
        dp[1][3] = -A[3] + max(dp[0][2], dp[1][2]);
    }

    for (int i=4; i<=n; i++){
        if (A[i] == 0){
            dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
            dp[1][i] = dp[0][i];
        }
        else {
            dp[0][i] = A[i] + max(dp[1][i-1], max(A[i-1]+dp[1][i-2], A[i-1]+A[i-2]+dp[1][i-3]));
            dp[1][i] = -A[i] + max(dp[0][i-1], max(-A[i-1]+dp[0][i-2], -A[i-1]-A[i-2]+dp[0][i-3]));
        }
    }

    for (auto i : dp){
        for (int j : i){
            cout << j << " ";
        }
        cout << "\n";
    }

    cout << "\n" << max(dp[0][n],dp[1][n]);

    return 0;
}

auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
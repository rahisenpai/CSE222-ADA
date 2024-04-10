//rahisenpai's implementation/code
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto __untie_cin = std::cin.tie(nullptr);
auto __untie_cout = std::cout.tie(nullptr);
auto __unsync_ios_stdio = std::ios_base::sync_with_stdio(false);

const int mod = 1000000007;

void OrSumSubseq(const vector<int> &arr, const int len, const int target, vector<long long> &dp, unordered_map<int, long long> &map){
    const int n = arr.size();
    int temp;
    for(int i=len; i<n; i++) {//if arr is empty, loop won't execute and return
        for(int sum=0; sum<1024; sum++) {
            //check for all sums if they exist, take bitwise or and update dp
            if(map.find(sum) != map.end()) {
                temp = sum|arr[i];
                dp[temp] += map[sum];
                dp[temp] %= mod;//ensure modulo
            }
            //at last update map values as well
            if(dp[sum]!=0) map[sum] = dp[sum];
        }
    }
}

int main() {
    //initialize vars, take input
    int q,m,x,len=0;
    vector<int> arr;
    unordered_map<int, long long> map;//map to store all possible bitwise or sums and their freq
    vector<long long> dp(1024,0);
    dp[0]=1; map[0]=1;//base case
    cin>>q;

    while(q--) {
        cin>>m>>x;
        if(m==1) arr.emplace_back(x);
        else {
            OrSumSubseq(arr, len, x, dp, map);//update dp array
            cout<<dp[x]<<"\n";
            len=arr.size();
        }
    }
    return 0;
}
//rahisenpai's implementation/code
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto __untie_cin = std::cin.tie(nullptr);
auto __untie_cout = std::cout.tie(nullptr);
auto __unsync_ios_stdio = std::ios_base::sync_with_stdio(false);

int n, dp[10005][105];

struct container{
    int amt, cap;
} arr[105];

bool comparator(container x,container y){
    return x.cap > y.cap;
}

int main() {
    cin>>n;
    int suma=0;
    for(int i=1; i<=n; i++) {
        cin>>arr[i].amt;
        suma += arr[i].amt;
    }
    for(int i=1; i<=n; i++) {
        cin>>arr[i].cap;
    }

    sort(arr+1, arr+n+1, comparator);
    int k=0, sumb=0;
    while(sumb<suma) {
        sumb = sumb+arr[++k].cap;
    }

    memset(dp, -1, sizeof(dp));
    cout<<dp[0][0]<<"   ";
    dp[0][0] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=sumb; j>=arr[i].cap; j--){
            for(int l=k; l>=1; l--) {
                dp[j][l] = max(dp[j][l], dp[j-arr[i].cap][l-1]+arr[i].amt);
            }
        }
    }

    int nmax=-1;
    for(int i=suma; i<=sumb; i++) {
        nmax = max(nmax, dp[i][k]);
    }
    cout<<k<<" "<<suma-nmax;
    return 0;
}
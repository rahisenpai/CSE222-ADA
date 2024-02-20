//rahisenpai's implementation/code
#include <bits/stdc++.h>
using namespace std;

int main(){
    int m = 4;
    int n = 4;
    int spotprices[m][n] = {{0,0,0,0},{2,4,1,6},{4,1,3,2000},{8,1,4,5}};
    int dp[m][n];

    //preprocessing
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            dp[i][j] = -1;
        }
    }

    for (int height = 0; height < m; height++){
        for (int width = 0; width < n; width ++){
            int a = spotprices[height][width];
            int b = INT16_MIN, c = INT16_MIN;
            for (int k = 0; k < height; k ++){
                b = max(b, dp[height - k - 1][width] + dp[k][width]);
            }
            for (int k = 0; k < width; k ++){
                c = max(c, dp[height][width - k - 1] + dp[height][k]);
            }
            dp[height][width] = max(a,max(b,c));
        }
    }
    cout << dp[m-1][n-1] << endl;

}

auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
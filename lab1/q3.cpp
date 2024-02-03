//rahisenpai's implementation/code
#include <bits/stdc++.h>
using namespace std;

int perfect_string_solver(string s, int n, char ch){
    //base cases
    if (n == 1){
        if (s[0] == ch){
            return 0;
        }
        return 1;
    }
    //if len>1 and char 'z' is reached
    if (ch == 'z'){
        //return less than -1*n
        return -131100;
    }

    //check count of ch in left and right substring
    int left=0, right=0;
    for(int i=0; i<n/2; i++){
        if (s[i] == ch){
            left++;
        }
    }
    for(int i=n/2; i<n; i++){
        if (s[i] == ch){
            right++;
        }
    }

    //return min energy of both sides of computation
    return min((n/2-right)+perfect_string_solver(s.substr(0,n/2), n/2, ch+1), (n/2-left)+perfect_string_solver(s.substr(n/2,n/2), n/2, ch+1));
}

int main(){
    int t,n,temp;
    string s;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;

        //call to the recursive solver
        temp = perfect_string_solver(s,n,'a');
        if (temp < 0){
            cout << -1 << "\n";
        }
        else{
            cout << temp << "\n";
        }
    }
    return 0;
}

auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
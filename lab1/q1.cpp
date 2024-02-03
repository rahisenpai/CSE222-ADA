//rahisenpai's implementation/code
#include <bits/stdc++.h>
using namespace std;

bool valid_subseq(vector<int> &arr, int len, int key){
    //iterative approach for getting all subsequences
    int sum,temp;
    //starting from 1 as null subsequence is not allowed acc to question
    for(int i=1; i<(1<<len); i++){
        sum=0;
        temp = min(i+1,len);
        for (int j=0; j<temp; j++){
            //check whether to include an element or not
            if (i & (1<<j)){
                sum += arr[j];
            }
        }
        //return if sum is divisible by n
        if (sum%key == 0){
            return true;
        }
    }
    return false;
}

int main(){
    int t,m,n,temp;
    bool check;
    vector<int> arr;
    cin >> t;
    while(t--){
        //take input
        cin >> m >> n;
        arr.resize(m);
        for (int i=0; i<m; i++){
            cin >> arr[i];
        }
        check = true;

        auto it = arr.begin();
        //removing every element one by one
        for (int i=0; i<m; i++){
            temp = *(it+i);
            arr.erase(it+i);
            //checking for valid subsequence
            if (!valid_subseq(arr,m-1,n)){
                cout << "NO\n";
                check = false;
                break;
            }
            arr.insert(it+i,temp);
        }
        if (check){
            cout << "YES\n";
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
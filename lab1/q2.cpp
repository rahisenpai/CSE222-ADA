//rahisenpai's implementation/code
#include <bits/stdc++.h>
using namespace std;

int binary_count(vector<pair<int,int>> &v, int key){
    //returns the number of elements less than or equal to key
    int mid,low,high,count;
    low=0; high=v.size()-1; count=0;
    while (low <= high){
        mid = low + (high-low)/2;
        if (v[mid].first > key){
            high = mid-1;
        }
        else{
            low = mid + 1;
            count = mid + 1;
        }
    }
    return count;
}

int main(){
    int n,b,count,temp;
    cin >> n >> b;
    vector<int> hary(n);
    vector<pair<int,int>> vold(b, pair<int,int>());
    for (int i=0; i<n; i++){
        cin >> hary[i];
    }
    for (int i=0; i<b; i++){
        cin >> vold[i].first >> vold[i].second;
    }

    //sort wrt defenses
    sort(vold.begin(), vold.end());

    //cumulate wizard count
    count = vold[0].second;
    for (int i=1; i<b; i++){
        count += vold[i].second;
        vold[i].second = count;
    }

    for (int it : hary){
        //find the largest number less than or equal to iterator
        temp = binary_count(vold,it);
        if ( temp > 0){
            cout << vold[temp-1].second << " ";
        }
        else{
            cout << 0 << " ";
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
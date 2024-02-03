//rahisenpai's implementation/code
#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &v, int key){
    //simple binary search function
    int mid, low=0, high=v.size()-1;
    while (low<=high){
        mid = low + (high-low)/2;
        if (v[mid] > key){
            high = mid-1;
        }
        else if (v[mid] < key){
            low = mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int binary_count(vector<int> &v, int key){
    //returns the number of elements less than or equal to key
    int mid,low,high,count;
    low=0; high=v.size()-1; count=0;
    while (low <= high){
        mid = low + (high-low)/2;
        if (v[mid] > key){
            high = mid-1;
        }
        else{
            low = mid + 1;
            count = mid + 1;
        }
    }
    return count;
}

//saves all possible friendliness sum acc to question, ig this is dp
void get_possible_friendliness(vector<int> &v, vector<int> &res){
    //base cases
    if (v.size() <= 0){
        return;
    }
    if (v.size() == 1){
        res.emplace_back(v[0]);
        return;
    }

    //add current sum
    int count, sum=0, mid=(v[0]+v[v.size()-1])/2;
    for (int it : v){
        sum += it;
    }
    res.emplace_back(sum);

    //break according to question
    count = binary_count(v, mid);
    if (count > 0){
        //edge case
        if (count == v.size()){
            return;
        }
        //call again over left and right segments of array
        vector<int> left(v.begin(), v.begin()+count);
        get_possible_friendliness(left, res);
        vector<int> right(v.begin()+count, v.end());
        get_possible_friendliness(right, res);
    }
}

int main(){
    int t,n,q;
    vector<int> stat,test,res;
    cin >> t;
    while(t--){
        //take input
        cin >> n >> q;
        stat.resize(n); test.resize(q);
        for (int i=0; i<n; i++){
            cin >> stat[i];
        }
        for (int i=0; i<q; i++){
            cin >> test[i];
        }

        //sort friendliness stat for binary_count
        sort(stat.begin(), stat.end());

        //get all possible values for friendliness
        get_possible_friendliness(stat,res);

        //sort friendliness values for binary_search
        sort(res.begin(), res.end());

        for (int it : test){
            if (binary_search(res,it) != -1){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
        res.clear();
    }
    return 0;
}

auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
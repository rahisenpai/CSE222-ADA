#include <bits/stdc++.h>
using namespace std;

int count_less_equal(int arr[], int len, int target) {
    int low = 0, high = len - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    // cout<<low<<" lmao  ";
    return low;
}

int div_conq(int arr1[], int arr2[], int arr3[], int len, int k) {
    int low = min({arr1[0], arr2[0], arr3[0]});
    int high = max({arr1[len - 1], arr2[len - 1], arr3[len - 1]});
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = count_less_equal(arr1, len, mid) + count_less_equal(arr2, len, mid) + count_less_equal(arr3, len, mid);
        // cout<<mid<<" "<<count<<"\n";
        if (count >= k)
            high = mid-1;
        else
            low = mid + 1;
        cout << low << " " << mid << " " << high << "\n";
    }
    return low;
}

int main(){
    int arr1[] = {1};
    int arr2[] = {2};
    int arr3[] = {3};
    int n=1, k=2;

    cout << div_conq(arr1, arr2, arr3, n, k);

    return 0;
}

auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
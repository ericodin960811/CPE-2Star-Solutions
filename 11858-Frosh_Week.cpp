#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right){
    long long counter = 0;
    int l = left; // left start
    int r = mid + 1; // right start
    int t = left; // temp start

    // both are not empty
    while (l <= mid && r <= right){
        if (nums[l] < nums[r]){
            temp[t] = nums[l];
            t++;
            l++;
        }else{
            temp[t] = nums[r];
            t++;
            r++;
            counter += (mid - l + 1);
        }
    }

    while (l <= mid) { // left is not empty
        temp[t] = nums[l];
        t++;
        l++;
    }

    while (r <= right) { // right is not empty
        temp[t] = nums[r];
        t++;
        r++;
    }

    for (int i = left; i <= right; i++) {
        nums[i] = temp[i];
    }

    return counter;
}

long long mergeSort(vector <int>& nums, vector <int>& temp, int left, int right){
    long long counter = 0;

    if (left < right){ // vector size > 1
        int mid = left + (right - left) / 2;
        counter += mergeSort(nums, temp, left, mid);
        counter += mergeSort(nums, temp, mid + 1, right);
        counter += merge(nums, temp, left, mid, right);
    }

    return counter;
}

int main(){
    int n, num;

    while (cin >> n){
        vector <int> Nums(n);
        vector <int> Temp(n);

        for (int i = 0; i < n; ++i){
            cin >> Nums[i];
        }

        long long counter = mergeSort(Nums, Temp, 0, n - 1);

        cout << counter << endl;
    }

    return 0;
}
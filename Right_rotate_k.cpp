#include <bits/stdc++.h>
using namespace std;

//Brute force
void right_rotate(vector<int> &arr, int k){
    int n = arr.size();
    k = k % n;
    
    int temp[k];
    
    for(int i=n-k; i<n; i++){
        temp[i-(n-k)] = arr[i];
    }
    
    for(int i=n-k-1; i>=0; i--){
        arr[i+k] = arr[i];
    }
    
    for(int i=0; i<k; i++){
        arr[i] = temp[i];
    }
    return;
}

//optimal
void rotate(vector<int>& nums, int k) {
      int n = nums.size();
      k = k % n;
      reverse(nums.begin(), nums.begin() + (n-k)); //reverse() only takes iterators, k (index = k-1)
      reverse(nums.begin() + (n-k), nums.end());
      reverse(nums.begin(), nums.end());

      // reverse(nums.begin(), nums.end()); //full reverse first
      // reverse(nums.begin(), nums.begin() + k);
      // reverse(nums.begin() + k, nums.end());

      return;
  }

int main() {
    vector<int> arr = {-1,8,6,13,12,18,1,4};
    cout<<"Original : ";
    for (auto it:arr) cout<<it<<" ";
    cout<<endl;
    right_rotate(arr, 2);
    cout<<"Rotated : ";
    for (auto it:arr) cout<<it<<" ";
    cout<<endl;
    cout << "\nTry programiz.pro\n";

    return 0;
}

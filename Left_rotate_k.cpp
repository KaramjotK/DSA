#include <bits/stdc++.h>
using namespace std;

//BRUTE FORCE (extra space)
//Learning - better index manipulation
void left_rotate(vector<int> &arr, int k){
    int n = arr.size();
    k = k % n;
    int temp[k];
    
    for (int i=0; i<k; i++){
        temp[i] = arr[i];
    }

    for (int j=k; j<n; j++){
        arr[j-k] = arr[j];
    }
    
    for(int i=n-k; i<n; i++){
        arr[i] = temp[i - (n-k)];
    }
    
}

//Learning - index manipulation
// void left_rotate(vector<int> &arr, int k){
//     int n = arr.size();
//     int temp[k];
    
//     for (int i=0; i<k; i++){
//         temp[i] = arr[i];
//     }
//     int j = k;
//     for (j; j<n; j++){
//         arr[j-k] = arr[j];
//     }
    
//     for(int i=0; i<k; i++){
//         arr[j-k] = temp[i];
//         j++;
//     }
    
// }

//OPTIMAL APPROACH
//pass arr by referance, otherwise modifies copy
void Reverse(vector<int> &arr, int start, int end){ 
    while (start<=end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

//pass arr by referance, otherwise modifies copy
void left_rotate(vector<int> &arr, int k){
    int n = arr.size();
    k = k % n;
    
    Reverse(arr, 0, k-1);
    Reverse(arr, k, n-1);
    Reverse(arr, 0, n-1);
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7};
    cout<<"Original : ";
    for (auto it: arr) cout<<it<<" ";
    cout<<endl;
    left_rotate(arr, 3);
    cout<<"Rotated : ";
    for (auto it: arr) cout<<it<<" ";

    return 0;
}

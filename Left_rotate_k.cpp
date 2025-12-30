// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

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

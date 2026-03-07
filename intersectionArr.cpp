// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

//brute force
void find_intersection_1(int arr1[], int n1, int arr2[], int n2){
    vector<int> i_s;
    vector<int> vis(n2, 0);
    
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j] && vis[j] == 0){
                    i_s.push_back(arr2[j]);
                    vis[j] = 1;
                    break; //if you find correspoding ele, just stop because sorted arrays, this break is for inner loop
            }
            if(arr2[j] > arr1[i]) break; //early stopping, break for outer loop
            //Existing break: stops inner loop only when a match is found. Second break (if(arr2[j] > arr1[i])): stops inner loop when no match is possible anymore because the sorted order tells you to quit early.
        }    
    }
    
    cout<<"intersection ";
    for(auto it:i_s) cout<<it<<" ";
    cout<<endl;
    
    return;
}

//optimal - 2 pointer approach
void find_intersection(int arr1[], int n1, int arr2[], int n2){
    vector<int> i_s;
    int i=0, j=0;
    while (i<n1 && j<n2){
        if (arr1[i]<arr2[j]){
            i++;
        }
        else if(arr1[i] == arr2[j]){
            i_s.push_back(arr1[i]);
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    
    cout<<"intersection ";
    for(auto it:i_s) cout<<it<<" ";
    cout<<endl;
    return;
}

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

int main() {
    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[] = {2,3,4,4,5,9,11,12};
    int n1 = 10;
    int n2 = 8;
    cout<<"arr1 ";
    print_arr(arr1, n1);
    cout << endl;
    cout<<"arr2 ";
    print_arr(arr2, n2);
    cout << endl;
    
    find_intersection(arr1, n1, arr2, n2);
    return 0;
}

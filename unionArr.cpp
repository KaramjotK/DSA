// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void find_union_map(int arr1[], int n1, int arr2[], int n2){
    map<int, int> mpp;
    vector<int> com;
    vector<int> dist;
    vector<int> unionn;
    
    for (int i = 0; i < n1; i++) mpp[arr1[i]]++;
    for (int i = 0; i < n2; i++) mpp[arr2[i]]++;
    
    for (auto it:mpp){
        if (it.second == 1) dist.push_back(it.first);
        else com.push_back(it.first);
        unionn.push_back(it.first);
    }
    
    cout<<"comm ";
    for(auto it:com) cout<<it<<" ";
    cout<<endl;
    
    cout<<"dist ";
    for(auto it:dist) cout<<it<<" ";
    cout<<endl;
    
    cout<<"union ";
    for(auto it:unionn) cout<<it<<" ";
    cout<<endl;
    
    return;
}

void find_union_set(int arr1[], int n1, int arr2[], int n2){
    // unordered_set<int> st; //need sorted union
    set<int> st;
    // vector<int> unionn;
    
    for (int i = 0; i < n1; i++) st.insert(arr1[i]);
    for (int i = 0; i < n2; i++) st.insert(arr2[i]);
    
    int unionn[st.size()];
    
    int i=0;
    cout<<"union ";
    for (auto it:st) unionn[i++] = it; //unionn.push_back(it);
    for (auto it:unionn) cout<<it<<" ";
    cout<<endl;
}

//changeeeeee
void find_union(int arr1[], int n1, int arr2[], int n2){
    vector<int> unionn;
    for(int i=0, j=0; i<n1, j<n2; i++, j++){
        if (arr1[i]<arr2[j]){
            unionn.push_back(arr1[i]);
        }
        else if(arr1[i] == arr2[j]){
            i++;
            j++;
        }
        else{
            unionn.push_back(arr2[i]);
        }
    }
    cout<<"union ";
    for(auto it:unionn) cout<<it<<" ";
    cout<<endl;
    return;
}

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

int main() {
    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[] = {2,3,4,4,5,11,12};
    int n1 = 10;
    int n2 = 7;
    cout<<"arr1 ";
    print_arr(arr1, n1);
    cout << endl;
    cout<<"arr2 ";
    print_arr(arr2, n2);
    cout << endl;
    
    find_union(arr1, n1, arr2, n2);
    return 0;
}

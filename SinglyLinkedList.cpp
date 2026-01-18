#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    //constructors
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

//for vectors or array based function we return full array but for LL we return head
Node* convertarr_LL(vector<int> &arr){ 
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

//with LL, always only head is given
int length_LL(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

int check_node(Node* head, int val){
    Node* temp = head;
    while(temp){
        if (temp->data == val) return 1;
        temp=temp->next;
    }
    return 0;
}

int main() {
    vector<int> arr = {11,3,2,4,6};
    
    Node* head = convertarr_LL(arr);
    cout<<"Array to LL "<<head->data<<endl;
    //Traversal LL
    Node* temp = head; //never tamper head
    cout<<"Traversing ";
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

    cout<<"Length "<<length_LL(head)<<endl;
    
    cout<<"Present or not "<<check_node(head, 7)<<endl;
    
    //Learning
    Node v = Node(arr[1],nullptr);
    // cout << v; //just an object gives error
    cout<<v.data<<endl; //data is attribute of object
    cout<<v.next<<endl;
    
    Node* y = new Node(arr[0],nullptr);
    cout << y<<endl;  //memory location of first element in linked list
    cout << y->data<<endl; //data is thing of Node (linked list class)
    cout << y->next;

    return 0;
}

/*
Output:
Array to LL 11
Traversing 11 3 2 4 6 
Length 5
Present or not 0
3
0
0x1db6c780
11
0
*/

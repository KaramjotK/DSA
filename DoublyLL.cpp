#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
    
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* convertarr_LL(vector<int> &arr){ 
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = prev->next; //prev = temp;
    }
    return head;
}

//deletion from LL
Node* removehead(Node* head){
    if (head == NULL || head->next == NULL) return head;
    Node* temp = head;
    head=head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}

Node* removetail(Node* head){
    if (head == NULL || head->next == NULL) return NULL; //LL empty so return NULL
    Node* temp = head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    Node* back = temp->prev;
    back->next = NULL;
    temp->prev = nullptr;
    delete temp;
    return head;
}

//k = 1 to length of LL
Node* delete_pos_k(Node* head, int k){
    if (head == NULL) return head;
    Node* temp = head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp->next;
    }
    Node* back = temp->prev;
    Node* front = temp->next;
    if(back == NULL && front == NULL) return NULL;
    else if(back == NULL) return removehead(head);
    else if(front == NULL) return removetail(head);
    back->next = front;
    front->prev = back;
    
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
    return head;
}

//Node to be deleted will never be head because that means moving head in original LL (more if-else)
void delete_node(Node* temp){
    Node* back = temp->prev;
    Node* front = temp->next;
    
    if(front == NULL) {
        back->next = nullptr;
        temp->prev = nullptr;
        free(temp);
        return;
    }
    back->next = front;
    front->prev = back;
    
    temp->next = temp->prev = nullptr;
    free(temp);
}

//insertion into LL
Node* insert_head(Node* head, int val){

}

Node* insert_tail(Node* head, int val){
    
}

Node* insert_k(Node* head, int val, int k){
    
}

//guarnteed that x is always present, otherwise set some flag to check it
Node* insert_el_before_x(Node* head, int el, int x){
    
}

Node* printt(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {78, 90, 15, 34, 12};
    Node* hd = convertarr_LL(arr);
    printt(hd); cout<<endl;
    
    // Node* newk = delete_pos_k(hd,3);
    delete_node(hd);
    printt(hd);

    return 0;
}

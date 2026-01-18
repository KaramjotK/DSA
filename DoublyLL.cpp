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
    if (head == NULL) return head;
    Node* temp = head;
    head=head->next;
    head->prev = NULL;
    delete temp;
    return head;
}

Node* removetail(Node* head){
    if (head == NULL || head->next == NULL) return NULL; //LL empty so return NULL
    Node* temp = head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* delete_pos_k(Node* head, int k){
    if (head == NULL) return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev=NULL;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* delete_val(Node* head, int val){
    if (head == NULL) return head;
    if(head->data==val){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data == val){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

//insertion into LL
// Node* insert_head(Node* head, int val){
//     // Node* x = new Node(val, head);
//     // head = x;
//     // return head;
    
//     return new Node(val, head);
// }

Node* insert_tail(Node* head, int val){
    Node* nn = new Node(val);
    if (head == NULL) {
        head = nn;
        // return head;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = nn;
    return head;
}

Node* insert_k(Node* head, int val, int k){
    Node* nn = new Node(val);
    if (head == NULL) {
        if (k==1) head = nn;
        else return head;
    }
    if (k==1){
        nn->next = head;
        head = nn;
    }
    int cnt=0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt == k-1){
            nn->next = temp->next;
            temp->next = nn;
            break;
        }
        temp = temp->next;
    }
    return head;
}

//guarnteed that x is always present, otherwise set some flag to check it
Node* insert_el_before_x(Node* head, int el, int x){
    Node* nn = new Node(el);
    if (head == NULL) {
        return NULL;
    }
    if (head->data==x){
        nn->next = head;
         return nn; //head = nn; causes infinite loop
    }
    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->next->data == x){
            nn->next = temp->next;
            temp->next = nn;
            break;
        }
        temp = temp->next;
    }
    return head;
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
    
    // Node* jk = NULL; 
    
    Node* newk = removehead(hd);
    printt(newk);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

//deletion from LL
Node* removehead(Node* head){
    if (head == NULL) return head;
    Node* temp = head;
    head=head->next;
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
Node* insert_head(Node* head, int val){
    // Node* x = new Node(val, head);
    // head = x;
    // return head;
    
    return new Node(val, head);
}

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
    Node* z = new Node(12);
    Node* v = new Node(34, z);
    Node* a = new Node(15, v);
    Node* b = new Node(90, a);
    Node* k = new Node(78, b);
    
    printt(k); cout<<endl;
    // Node* jk = NULL; 
    Node* newk = insert_el_before_x(k, 100, 78);
    printt(newk);

    return 0;
}

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
    Node* newk = delete_val(k, 78);
    printt(newk);

    return 0;
}

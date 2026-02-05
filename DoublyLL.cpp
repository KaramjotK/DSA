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
Node* insert_before_head(Node* head, int val){
    Node* temp = new Node(val, head, nullptr);
    if (head == NULL) return NULL;
    
    head->prev = temp;
    // temp->next = head;
    head = head->prev;
    
    return head; //or temp
}

Node* insert_after_head(Node* head, int val){
    // Node* temp = new Node(val, nullptr, head);
    if (head == NULL) return NULL;
    // if (head->next == NULL){
    //     head->next = temp;
    //     // temp->prev = head;
    // }
    // else{
    //     temp->next = head->next;
    //     head->next = temp;
    //     temp->next->prev = temp;
    //     // temp->prev = head;
    // }
    // Create new node
    Node* newNode = new Node(val);

    // Step 1: connect new node to head's next
    newNode->next = head->next;
    newNode->prev = head;

    // Step 2: if there is a node after head, update its prev
    if (head->next != NULL) {
        head->next->prev = newNode;
    }

    // Step 3: connect head to new node
    head->next = newNode;
    return head;    
}

Node* insert_before_tail(Node* head, int val){
    if (head == NULL) return NULL;
    if (head->next == NULL) return insert_before_head(head, val);
    Node* tail = head;
    while (tail->next != NULL){
        tail = tail->next;
    }
    Node* back = tail->prev;
    Node* newNode = new Node(val, tail, back);
    back->next = newNode;
    tail->prev = newNode;
    return head;
}

Node* insert_after_tail(Node* head, int val){
    if (head == NULL) {
        return new Node(val);
    }

    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node* newNode = new Node(val, nullptr, tail);
    tail->next = newNode;

    return head;
}

//k is position, k = 1 to N (length of LL)
Node* insert_before_k(Node* head, int val, int k){
    if (head == NULL) return NULL;
    if (k == 1) return insert_before_head(head, val);
    Node* temp = head;
    int cnt = 1;
    while(temp != NULL && cnt < k){
        temp = temp->next;
        cnt++;
    }
    Node* back = temp->prev;
    Node* newNode = new Node(val, temp, back);
    back->next = newNode;
    temp->prev = newNode;

    return head;
}

Node* insert_after_k(Node* head, int val, int k){
    if (head == NULL) return NULL;
    Node* temp = head;
    int cnt = 1;
    while (temp != NULL && cnt < k) {
        temp = temp->next;
        cnt++;
    }
    
    // if k is at tail
    if (temp->next == NULL) {
        return insert_after_tail(head, val);
    }
    // insert in between
    Node* front = temp->next;
    Node* newNode = new Node(val, front, temp);
    temp->next = newNode;
    front->prev = newNode;
    
    //following also works for all cases
    // assuming k is always valid
    // Node* front = temp->next;
    // Node* newNode = new Node(val, front, temp);
    // temp->next = newNode;
    // if (front != NULL) {
    //     front->prev = newNode;
    // }

    return head;
}


//guarnteed that x is always present, otherwise set some flag to check it, x is node and x!=head, otherwise head changed
void insert_el_before_x(Node* node, int el){
    Node* back = node->prev;
    Node* newNode = new Node(el, node, back);
    back->next = newNode;
    node->prev = newNode;
}

//x could be head, x couldn't be tail gives segmentation fault
void insert_el_after_x(Node* node, int el){
    Node* front = node->next;
    Node* newNode = new Node(el, front, node);
    node->next = newNode;
    front->prev = newNode;
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
    vector<int> arr = {78,8,12,13,56};
    Node* hd = convertarr_LL(arr);
    printt(hd); cout<<endl;
    
    Node* newk = insert_after_k(hd,6,3);
    // // delete_node(hd->next);
    printt(newk);
    // insert_el_after_x(hd->next->next->next,0);
    // printt(hd);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
void insert_at_tail(Node* &head, Node* &tail, int val){
    Node *newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
void reverse_linked_list(Node* &head, Node* &tail, Node* tmp){
    if(tmp->next == NULL){
        head = tmp;
        return;
    }
    reverse_linked_list(head,tail,tmp->next);
    tmp->next->next = tmp;
    tmp->next = NULL;
    tail = tmp;
}
void print_list(Node* head){
    while(head != NULL){
        cout << head->val;
        if(head->next != NULL) cout << " ";
        head = head->next;
    }
    cout << endl;
}
int main(){
    int n = 4; 
    Node* l1_head = NULL; Node* l1_tail = NULL;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        insert_at_tail(l1_head, l1_tail, x);
    }
    Node* l2_head = NULL; Node* l2_tail = NULL;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        insert_at_tail(l2_head, l2_tail, x);
    }
    Node* l3_head = NULL; Node* l3_tail = NULL;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        insert_at_tail(l3_head, l3_tail, x);
    }
    Node* tmp1 = l1_head;
    Node* first4_head = NULL, *first4_tail = NULL;
    int count = 0;
    while(tmp1 && count < n){
        insert_at_tail(first4_head, first4_tail, tmp1->val);
        tmp1 = tmp1->next;
        count++;
        if(count == 4) break;
    }
    Node* rev_head = NULL;
    Node* rev_tail = NULL;
    reverse_linked_list(rev_head, rev_tail, first4_head);
    Node* result_head = NULL;
    Node* result_tail = NULL;
    Node* p = rev_head;
    while(p != NULL){
        insert_at_tail(result_head, result_tail, p->val);
        p = p->next;
    }
    Node* p2 = l2_head;
    Node* p3 = l3_head;
    count = 0;
    while(p2 && p3 && count<4){
        int sum = p2->val + p3->val;
        if(sum >= 10) sum %= 10;
        insert_at_tail(result_head, result_tail, sum);
        p2 = p2->next;
        p3 = p3->next;
        count++;
    }
    print_list(result_head);
    return 0;
}

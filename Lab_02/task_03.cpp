#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->next = NULL;
        this->val = val;
    }
};
void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}
void print_linked_list(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->val << " " ;
        temp = temp->next;
    }
    cout << "None" << endl;
}
void alternate_merge(Node* head1, Node* head2){
    Node* curr = head1;
    Node* temp = head2;
    while (curr && temp){
        Node* save = temp->next;
        temp->next = curr->next;
        curr->next = temp;

        curr = temp->next;
        temp = save;
    }
}
int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int val1;
        cin >> val1;
        insert_at_tail(head1,tail1,val1);
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int val2;
        cin >> val2;
        insert_at_tail(head2,tail2,val2);
    }
    alternate_merge(head1,head2);
    print_linked_list(head1);
    return 0;
}

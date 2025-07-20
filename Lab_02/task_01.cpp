#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    string col;
    Node* next;
    Node(string col){
        this->col = col;
        this->next = NULL;
    }
};
void insert_at_tail(Node* &head,Node* &tail, string col){
    Node* newNode = new Node(col);
    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}
void createList(Node*& head, Node*& tail, string in){
    istringstream ss(in);
    string color;
    while (ss >> color){
        if(!color.empty() && color.back() == '+'){
            color.pop_back();
        }
        insert_at_tail(head, tail, color);
    }
}
bool areSimilar(Node* head1, Node* head2){
    while(head1 != NULL && head2 != NULL){
        if (head1->col != head2->col) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1 == NULL && head2 == NULL;
}
int main(){
    string input1, input2;
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;
    cout << "Enter blocks for first building: ";
    getline(cin, input1);
    cout << "Enter blocks for second building: ";
    getline(cin, input2);
    createList(head1, tail1, input1);
    createList(head2, tail2, input2);
    if(areSimilar(head1, head2)){
        cout << "Similar" << endl;
    } 
    else{
        cout << "Not Similar" << endl;
    } 
    return 0;
}

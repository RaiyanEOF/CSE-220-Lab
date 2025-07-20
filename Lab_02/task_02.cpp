#include<bits/stdc++.h>
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
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<n;i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    int m;
    cin >> m;
    int distance[m];
    for(int i=0;i<m;i++){
        cin >> distance[i];
    }
    int sum = 0;
    for(int i=0;i<m;i++){
        Node* temp = head;
        int cnt = 0;
        while(temp != NULL && cnt < distance[i]){
            temp = temp->next;
            cnt++;
        }
        if(temp != NULL){
            sum += temp->val;
        }
    }
    cout << sum << endl;
    return 0;
}

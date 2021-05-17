#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node * Next;
    Node(int val){
        data=val;
        Next=NULL;
    }
};
void insertattail(Node * &head,int val){
    Node* n=new Node(val);
    if(head==NULL){
        head=n;
        return;
    }
    Node *temp=head;
    while(temp->Next!=0){
        temp=temp->Next;
    }
    temp->Next=n;
    return;
    
}
void insertathead(Node* &head,int val){
    Node* n= new Node(val);
    if(head==NULL){
        head=n;
        return;
    }
    n->Next=head;
    head=n;
    return;
}
void Display(Node * head){
    if(head==NULL){
        cout<<"empty";
        return;
    }
    Node* temp=head;
    while (temp!=0){
        cout<<temp->data<<"->";
        temp=temp->Next;
    }
    cout<<"NULL"<<endl;
    return;
}
int NumberofNodes(Node* head){
    int count=0;
    Node* temp=head;
    while(temp!=0) {
        temp=temp->Next;
        count++;
    }
     return count;
}
Node* AppendK(Node* &head,int k){
    int total=NumberofNodes(head);
    Node* newtail=head;
    Node* newhead=head;
    Node* tail=head;
    k=k%total;
    for(int c=1;c<total;c++){
        if (c==total-k){
            newtail=tail;
        }
        if(c==total-k+1)
        {
            newhead=tail;
        }
        
        tail=tail->Next;
    }
    newtail->Next=NULL;
    tail->Next=head;
    
    return newhead;
}
int main(){
    Node* head=NULL;
    insertattail(head,2);
    insertattail(head,4);
    insertattail(head,6);
    insertattail(head,8);
    insertattail(head,10);
    insertattail(head,12);
    insertattail(head,14);
    insertattail(head,16);
    insertathead(head,0);
    Display(head);
    cout<<NumberofNodes(head)<<endl;
    Node* Newhead=AppendK(head,3);
    Display(Newhead);
}
#include <bits/stdc++.h>
using namespace std;
class node{
 public:
 int data;
 node *next;
 
 node(int a){
   data=a;
   next=NULL;
 }
};

void insertAthead(node *&head, int val){
    node *n= new node(val);
    n->next=head;
    head=n;
}
void insertattail(node *&head,int val){
    node *n=new node(val);
    if(head==NULL){
        head=n;
        return ;
    }
    node *temp=head;
    while(temp->next!=NULL){
    
        temp=temp->next;
    }
    temp->next=n;

   

}
void display(node *head){
    node *temp=head;
    while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
    }
     cout<<"NULL"<<endl;
}
int main(){
    node *head=NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertAthead(head,6);
    display(head);
    return 0;
}
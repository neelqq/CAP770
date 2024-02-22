#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(){}
    node(int d){
        data=d;
        next=NULL;
    }
};

void addHead(node* &head,int data)
{
    node* temp=new node();
    temp->data=data;
    temp->next=head;
    head=temp;
}
void addData(node* &head,int data)
{
    node* temp=new node();
    node* temp2=new node(data);
    temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=temp2;
}

void display(node* &head)
{
    node* temp=new node();
    temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }   
    cout<<"NULL"<<endl;
    
}
void findNumPrim(node* &head)
{
    int c,data,p=0;
    node* temp=new node();
    temp=head;
    data=temp->data;
    while(temp!=NULL)
    {
        c=0;
        for(int i=1;i<=temp->data;i++)
        {
            if(temp->data%i==0){
                c++;
                
            }
        }
        if(c==2){
            p++;
        }
        temp=temp->next;
    }
    cout<<"The Number of primes is "<<p<<endl;
}
void deleteHead(node* &head){
    node* temp=new node();
    temp=head;
    head=head->next;
    free(temp);

}

void deleteTail(node* &head){
    node* temp=new node();
    temp=head;
    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
   
}
void deleteN(node* &head,int n){
    int c=0,size=0;
    node* temp=new node();
    node* temp2=new node();
    temp=head;

    while(temp!=NULL)
    {
        temp=temp->next;
        size++;
    }
    temp=head;
    if(size>=n){
        for(int i=0;i<n-1;i++){
            temp->next;
        }
        temp2=temp->next;
        temp->next=temp->next->next;
        free(temp2);
    }
    else{cout<<"the number is cout of the range"<<endl;}

}
void shortLink(node* &head){
    node* temp=head;
    node* temp2=new node();
    int n=0;
    while (temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    for(int i=0;i<n;i++){
    temp=head;
        for(int j=0;j<n-1;j++){
            if(temp->data > temp->next->data){
                swap(temp->data,temp->next->data);
            }
            temp = temp->next;
        }
    }
    display(head);
}
int main(){
    node* head=NULL;
    int input=0,c=0;
    int data;
    while (input!=8)
    {
        cout<<"Enter 1 to add data: "<<endl<<"Enter 2 to display data: "<<endl
        <<"Enter 3 to find Number of prime Numbers: "<<endl<<"Enter 4 for sorting: "<<endl<<"enter 5 for delete node for the head"<<endl
        <<"enter 6 for delete the node for the tail"<<endl<<"enter 7 for delete n'th node"<<endl<<"Enter 8 to exit: "<<endl;
        cin>>input;
        switch(input)
        {
            case 1:
                cout<<"Enter the data: "<<endl;
                cin>>data;
                if(c==0){addHead(head,data);}
                else{addData(head,data);}
                c++;
                break;
            case 2:
                display(head);
                break; 
            case 3:
                findNumPrim(head);
                break;
            case 4:
                shortLink(head);
                break;
            case 5:
                deleteHead(head);
                break;
            case 6:
                deleteTail(head);
                break;
            case 7:
                cout<<"enter the place"<<endl;
                int place;
                cin>>place;
                deleteN(head,place);
                break;
        }
    }
    
}
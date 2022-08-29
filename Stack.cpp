#include<iostream>
using namespace std;

template  <class Item_Type>
struct Node{  
	Item_Type data;
    Node<Item_Type> *next;
};

template<class List_ItemType>
class Stack{
public:
    Stack();
    ~Stack();
    void Push(List_ItemType dataIn);
    int	Pop(List_ItemType &dataOut);
    int	GetStackTop(List_ItemType &dataOut);
    void Clear();
    int	IsEmpty();
    int	IsFull();
    int	GetSize();
    Stack<List_ItemType>cClone();
    void Print2Console();
    private:
    Node<List_ItemType>*top;
    int count;
};

template<class List_ItemType>
Stack<List_ItemType>::Stack(){
    this->top=NULL;
    this->count=0;
}

template<class List_ItemType>
Stack<List_ItemType>::~Stack(){
    this->Clear();
}

template<class List_ItemType>
void Stack<List_ItemType>::Push(List_ItemType value){
    Node <List_ItemType> *pNew=new Node<List_ItemType>();
    pNew->data=value;
    pNew->next=this->top;
    this->top=pNew;
    this->count++;
}

template<class List_ItemType>
int Stack<List_ItemType>::Pop(List_ItemType &dataOut){
    if(this->GetSize()==0)
    return 0;
    Node <List_ItemType>*dltPtr=this->top;
    dataOut=dltPtr->data;
    this->top=dltPtr->next;
    this->count--;
    delete dltPtr;
    return 1;
}

template<class List_ItemType>
int Stack<List_ItemType>::GetStackTop(List_ItemType&dataOut){
    if(this->GetSize()==0)
    return 0;

    dataOut=this->top->data;
    return 1;
}
template<class List_ItemType>
void Stack<List_ItemType>::Clear(){
    Node<List_ItemType>*temp;
    while(this->top!=NULL){
        temp=this->top;
        this->top=this->top->next;
        delete temp;
    }
    this->count=0;
}

template<class List_ItemType>
int Stack<List_ItemType>::IsEmpty(){
    return(count==0);
}

template<class List_ItemType>
int Stack<List_ItemType>::GetSize(){
    return count;
}
template<class List_ItemType>
int Stack<List_ItemType>::IsFull(){
	Node<List_ItemType>*pNew=new Node<List_ItemType>();

    if(pNew!=NULL){
        delete pNew;
        return 0;
    }
    else{
        return 1;
    }
}
template<class List_ItemType>
void Stack<List_ItemType>::Print2Console(){
    Node<List_ItemType>*p;
    p=this->top;
    while(p!=NULL){
        cout<<p->data<<"+";
        p=p->next;
    }
    cout<<endl;
}
int main(int argc,char*argv[]){
	Stack<int> *myStack=new Stack<int>();
	int val;
    myStack->Push(7);
    myStack->Push(9);
    myStack->Push(10);
    myStack->Push(8);
    myStack->Print2Console();
    myStack->Pop(val);
    myStack->Print2Console();
    delete myStack;
    return 0;
}

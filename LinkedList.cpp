#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct Node
{
    int data;
    struct Node *pnext;
};
typedef struct Node node;

struct List
{
    node *phead;
    node *ptail;
};
typedef struct List LIST;

void taonode(LIST &l)
{
    l.phead = l.ptail = NULL;
}
node* taonode(int x)
{
    node *p = new node;
    if(p == NULL)
    {
        return NULL;
    }
    p->data = x;
    p->pnext = NULL;
    return p;
}
void addhead(LIST &l,node *p)
{
    if(l.phead == NULL)
    {
        l.phead = l.ptail = p;
    }
    else
    {
        p ->pnext = l.phead;
        l.phead = p;
    }
}
void input(LIST &l,int n)
{
    taonode(l);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cout<<"Nhap vao data: ";
        cin>>x;
        node *p = taonode(x);
        addhead(l, p);
    }
}
void output(LIST l)
{
    for(node *p = l.phead; p != NULL; p = p ->pnext)
    {
        cout<<p->data<<" ";
    }
}
int timkiem(LIST l)
{
    int x;
    node *p=l.phead;
    for (int i=0; p; p=p->pnext, i++)
        if(p->data==x)
            return 1;
    return 0;
}
int xoapt(LIST &l)
{
   if (l.phead!=NULL)
   {
       l.phead=l.phead->pnext;
   }
}
void hoanvi(int &a, int&b)
{
    int t=a;
    a=b;
    b=t;
}
void sapxep(LIST l)
{
    node *p, *q;
    for (p=l.phead; p!=l.ptail; p=p->pnext)
        for (q=p->pnext; q!=NULL; q=q->pnext)
        {
            if (p->data>q->data)
                hoanvi(p->data, q->data);
        }
}
int main()
{
    LIST l;
    int n, x;
    cout<<"Nhap so node can tao: ";
    cin>>n;
    input(l,n);
    output(l);
    node *phead=NULL;
    cout<<"Nhap so x can tim: ";
    cin>>x;
    if (timkiem(l)==1)
    {
        cout<<"Co gia tri x trong danh sach";
    }
    else
        cout<<"Khong co gia tri x trong danh sach";
        cout<<endl;
    cout<<"Danh sach sau khi xoa: ";
    xoapt(l);
    output(l);
    cout<<endl;
    cout<<"Danh sach sau khi sap xep:";
    sapxep(l);
    output(l);
    return 0;
}

#include<iostream>

using namespace std;

class DynamicArray{
private:
    int size;
    int capacity;
    int *storage;

public:DynamicArray(){
    capacity= 10;size = 0;
    storage = new int[capacity];
    }
    DynamicArray(int capacity){
	this->capacity=capacity;
	size=0;
    storage=new int[capacity];
}

~DynamicArray(){
    delete[]storage;
}
void setCapacity(int);
void ensureCapacity(int);
void pack();
void trim();

void rangeCheck(int);
void set(int,int);
int	get(int);
void removeAt(int);
void insertAt(int,int);

void print();
};

void DynamicArray::setCapacity(int newCapacity){
    int *newStorage=new int[newCapacity];
    memcpy(newStorage,storage,sizeof(int)*size);
    capacity=newCapacity;
    delete[]storage;
    storage=newStorage;
}
void DynamicArray::ensureCapacity(int minCapacity){
    if(minCapacity>capacity){
        int newCapacity=(capacity*3)/2+1;
        if(newCapacity<minCapacity)
            newCapacity=minCapacity;
        setCapacity(newCapacity);
    }
}
void DynamicArray::pack(){
    if(size<=capacity/2){
        int newCapacity=(size*3)/2+1;
        setCapacity(newCapacity);
    }
}

void DynamicArray::trim(){
    int newCapacity=size;
    setCapacity(newCapacity);
}
void DynamicArray::rangeCheck(int index){
    if(index<0||index>=size)
        throw"Indexoutofbounds!";
}

void DynamicArray::set(int index,int value){
    rangeCheck(index);
    storage[index]=value;
}

int DynamicArray::get(int index){
    rangeCheck(index);
    return storage[index];
}
void DynamicArray::insertAt(int index,int value){
    if(index<0||index>size)
        throw"Indexoutofbounds!";
    ensureCapacity(size+1);

int moveCount=size-index;
    if(moveCount!=0)
        memmove(storage+index+1,storage+index,sizeof(int)*moveCount);
    storage[index]=value;
    size++;
}

void DynamicArray::removeAt(int index){
	rangeCheck(index);
    int moveCount=size-index-1;
    if(moveCount>0)
        memmove(storage+index,
        storage+(index+1),
        sizeof(int)*moveCount);
    size--;
    pack();
}
void DynamicArray::print(){
for(int i=0;i<this->size;i++){
	cout<<storage[i]<<"";
}
}

int main(){
cout<<"DynamicArray"<<endl;
DynamicArray*da=new DynamicArray(10);
da->insertAt(0,55);
//...
da->print();
return 0;
}

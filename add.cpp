#include <iostream>
#include <string.h>

using namespace std;

bool isPalindromeRecursion(char str[], int s, int e)
{
    if (s == e)
        return true;
    if (str[s] != str[e])
        return false;

    if (s < e + 1)
        return isPalindromeRecursion(str, s + 1, e - 1);

    return true;
}

bool isPalindrome(char str[])
{
    int n = strlen(str);
    if (n == 0)
        return true;

    return isPalindromeRecursion(str, 0, n - 1);
}

int main()
{
    char str[] = "atta";

    if (isPalindrome(str))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}


#include <iostream>
#include <cstring>

using namespace std;

char* useSpell(char **spell, int nSpells, int totalMana){
    char* rune[]={"a","b","c","d"};
    int totalManaSpell[nSpells];
    for (int i=0; i<nSpells; i++){
        totalManaSpell[i]=0;
    }
    for (int i=0; i<nSpells; i++){
        for (size_t j=0; j<strlen(spell[i]); j++){
            if (spell[i][j]==*rune[0]){
                totalManaSpell[i]+=1;
            }
            if (spell[i][j]==*rune[1]){
                totalManaSpell[i]+=2;
            }
            if (spell[i][j]==*rune[2]){
                totalManaSpell[i]+=3;
            }
            if (spell[i][j]==*rune[3]){
                totalManaSpell[i]+=4;
            }
        }
    }
    for (int i=0; i<nSpells; i++){
        if (totalManaSpell[i]>=totalMana){
            totalManaSpell[i]=0;
        }
    }
    int max=totalManaSpell[0];
    int indexMax=0;
    for (int i=1; i<nSpells; i++){
        if (totalManaSpell[i]>=max){
            max=totalManaSpell[i];
            indexMax=i;
        }
    }
    for (size_t i=0; i<strlen(spell[indexMax]); i++){
        if (spell[indexMax][i]==*rune[0]){
            cout << "a";
        }
        if (spell[indexMax][i]==*rune[1]){
            cout << "b";
        }
        if (spell[indexMax][i]==*rune[2]){
            cout << "c";
        }
        if (spell[indexMax][i]==*rune[3]){
            cout << "d";
        }
    }
}

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LList
{
    Node *head;

public:
    LList() : head(nullptr){};
    Node *getHead()
    {
        if (head != nullptr)
        {
            return head;
        }
    }
    void insert(int data[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (head == nullptr)
            {
                *(head) = data[i];
            }
            else
            {
                *(head + i) = *(head + i - 1);
                *(head + i) = data[i];
            }
        }
    };
    int countPeak(Node *head)
    {
        int count = 1;
        int ifsmaller = 0;
        Node *f = head;
        for (Node *k = head; k != NULL; k = k->next)
        {
            Node *q = k->next;
            if (k->next == NULL)
            {
                count++;
            }
            else if (k->data < q->data && ifsmaller == 0) {
                ifsmaller == 1;
            }
            else if (k->data < q->data && ifsmaller == 1) {
                count++;
            }
            else if (k->data > q->data)
            {
                ifsmaller = 0;
            }
        }
        return count;
    }
};

int main()
{
    int arr[] = {8, 2, 3, 5, 3, 2, 1, 7, 5, 9};
    LList SLL;
    SLL.insert(arr, sizeof(arr) / sizeof(arr[0]));
    cout << SLL.countPeak(SLL.getHead());
}

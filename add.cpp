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

using namespace std;

char *useSpell(char **spell, int nSpells, int totalMana)
{
    int manaUse;
    char *arr;
    int j = 0;
    for (int i = 0; i < totalMana; i++)
    {
        while (j < nSpells)
        {
            if (spell[i][j] == 'a')
            {
                if (manaUse < totalMana)
                {
                    manaUse = manaUse + 1;
                    *(arr + i) = 'a';
                }
            }
            if (spell[i][j] == 'b')
            {
                if (manaUse < totalMana)
                {
                    manaUse = manaUse + 2;
                    *(arr + i) = 'b';
                }
            }
            if (spell[i][j] == 'c')
            {
                if (manaUse < totalMana)
                {
                    manaUse = manaUse + 3;
                    *(arr + i) = 'c';
                }
            }
            if (spell[i][j] == 'd')
            {
                if (manaUse < totalMana)
                {
                    manaUse = manaUse + 4;
                    *(arr + i) = 'd';
                }
            }
            j++;
        }
    }
    return arr;
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
    }
};

int main()
{
    int arr[] = {8, 2, 3, 5, 3, 2, 1, 7, 5, 9};
    LList SLL;
    SLL.insert(arr, sizeof(arr) / sizeof(arr[0]));
    cout << SLL.countPeak(SLL.getHead());
}

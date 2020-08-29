#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node *reverse(Node *root)
{
    Node *prev = NULL, *next, *curr = root;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node *addTwoLists(Node *first, Node *second)
{
    Node *result = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL)
    {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);

        carry = (sum >= 10) ? 1 : 0;

        sum = sum % 10;

        temp = newNode(sum);

        if (result == NULL)
            result = temp;
        else
            prev->next = temp;

        prev = temp;

        if (first)
            first = first->next;

        if (second)
            second = second->next;
    }

    if (carry > 0)
        temp->next = newNode(carry);

    return result;
}

void Print(Node *root)
{
    while (root)
    {
        cout << root->data << " ";
        root = root->next;
    }
    cout << "\n";
}

int main()
{
    Node *root = newNode(1);
    root->next = newNode(2);
    root->next->next = newNode(3);
    root->next->next->next = newNode(4);
    root->next->next->next->next = newNode(5);
    root = reverse(root);

    Node *root1 = newNode(6);
    root1->next = newNode(7);
    root1->next->next = newNode(9);
    root1->next->next->next = newNode(4);
    root1->next->next->next->next = newNode(4);
    root1 = reverse(root1);

    Print(root);

    Node *result = addTwoLists(root, root1);

    Print(result);

    return 0;
}
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

Node *Merge(Node *root1, Node *root2)
{
    if (root1 == NULL)
        return root2;
    if (root2 == NULL)
        return root1;

    Node *result = NULL;

    if (root1->data <= root2->data)
    {
        result = root1;
        result->next = Merge(root1->next, root2);
    }
    else
    {
        result = root2;
        result->next = Merge(root1, root2->next);
    }

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
    Print(root);

    Node *root1 = newNode(1);
    root1->next = newNode(2);
    root1->next->next = newNode(3);
    root1->next->next->next = newNode(4);
    root1->next->next->next->next = newNode(5);
    Print(root);

    Node *result = Merge(root, root1);

    Print(result);

    return 0;
}
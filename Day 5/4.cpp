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

void Print(Node *root)
{
    while (root)
    {
        cout << root->data << " ";
        root = root->next;
    }
    cout << "\n";
}

Node *Nthremove(Node *root, int n)
{
    int count = n;
    Node *slow, *fast;
    slow = fast = root;
    while (count)
    {
        fast = fast->next;
        count--;
    }

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *temp = slow->next;
    slow->next = temp->next;
    delete temp;

    return root;
}

int main()
{
    Node *root = newNode(1);
    root->next = newNode(2);
    root->next->next = newNode(3);
    root->next->next->next = newNode(4);
    root->next->next->next->next = newNode(5);
    Print(root);
    root = Nthremove(root, 1);
    Print(root);

    return 0;
}
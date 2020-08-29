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

bool isPaliindrome1(Node *root)
{
    Node *slow = root;

    stack<int> s;

    while (slow)
    {
        s.push(slow->data);
        slow = slow->next;
    }

    while (root)
    {
        if (root->data != s.top())
            return false;
        s.pop();
        root = root->next;
    }

    return true;
}

bool isPallindrome(Node **root, Node *root1)
{
    if (root1 == NULL)
    {
        return true;
    }

    bool cond1 = isPallindrome(root, root1->next);
    if (cond1 == false)
    {
        return false;
    }

    bool cond2 = (*root)->data == root1->data;

    (*root) = (*root)->next;

    return cond2;
}

int main()
{
    Node *root = newNode(0);
    root->next = newNode(-1);
    root->next->next = newNode(0);
    cout << isPaliindrome1(root) << "\n";
    cout << isPallindrome(&root, root) << "\n";
    return 0;
}
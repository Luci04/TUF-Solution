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
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void LOL(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        auto temp = q.front();

        cout << temp->data << " ";
        q.pop();

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    cout << "\n";
}

void Spiral_Lol(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        Node *temp;
        while (!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            cout << temp->data << " ";

            if (temp->left)
                s2.push(temp->left);

            if (temp->right)
                s2.push(temp->right);
        }

        while (!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            cout << temp->data << " ";

            if (temp->right)
                s1.push(temp->right);

            if (temp->left)
                s1.push(temp->left);
        }
    }
}

int main()
{
    struct Node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);

    LOL(root);

    Spiral_Lol(root);

    return 0;
}
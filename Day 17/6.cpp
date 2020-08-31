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

void Top(Node *root)
{
    if (root == NULL)
        return;
    map<int, int> mp;

    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        int hori = temp.second;

        Node *node = temp.first;

        if (mp.find(hori) == mp.end())
            mp[hori] = node->data;

        if (node->left)
            q.push({node->left, hori - 1});

        if (node->right)
            q.push({node->right, hori + 1});
    }

    for (auto it : mp)
    {
        cout << it.second << " ";
    }
    cout << "\n";
}

int main()
{
    Node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    Top(root);

    return 0;
}
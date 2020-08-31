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

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    if (left > right)
    {
        return left + 1;
    }

    return right + 1;
}

int height2(Node *root)
{
    if (root == NULL)
        return 0;
    int height = 0;

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
        height++;
    }

    return height;
}

int main()
{
    struct Node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);

    cout << height(root) << "\n";
    cout << height2(root) << "\n";

    return 0;
}
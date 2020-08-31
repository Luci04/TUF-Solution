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
    struct Node *left;
    struct Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void inorder1(Node *root)
{
    stack<Node *> st;
    Node *cur = root;

    while (cur != NULL || !st.empty())
    {
        while (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }

        cur = st.top();
        st.pop();

        cout << cur->data << " ";

        cur = cur->right;
    }

    cout << "\n";
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inorder(root);
    cout << "\n";

    inorder1(root);
    return 0;
    return 0;
}
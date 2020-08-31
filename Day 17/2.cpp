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
    Node *right;
    Node *left;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void Preorder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Preorder1(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *temp = st.top();
        cout << temp->data << " ";
        st.pop();

        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
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
    Preorder(root);
    cout << "\n";
    Preorder1(root);

    return 0;
}
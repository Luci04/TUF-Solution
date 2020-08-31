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

Node *newNode(int c)
{
    Node *temp = new Node;
    temp->data = c;
    temp->left = temp->right = NULL;
    return temp;
}

void printInorder(Node *root)
{
    if (root)
    {
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}

int search(int arr[], int start, int end, int key)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
}

Node *buildTree(int in[], int post[], int inStrt,
                int inEnd)
{
    static int pIndex = inEnd;

    if (inStrt > inEnd)
        return NULL;

    Node *node = newNode(post[pIndex--]);

    if (inStrt == inEnd)
        return node;

    int iIndex = search(in, inStrt, inEnd, node->data);

    node->right = buildTree(in, post, iIndex + 1, inEnd);
    node->left = buildTree(in, post, inStrt, iIndex - 1);

    return node;
}

void postOrder(Node *root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(in) / sizeof(in[0]);

    Node *root = buildTree(in, post, 0, n - 1);

    cout << "postOrder of the constructed tree : \n";
    postOrder(root);
}
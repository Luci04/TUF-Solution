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
    char data;
    Node *left;
    Node *right;
};

Node *newNode(char c)
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

int search(char in[], int start, int end, int key)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == key)
        {
            return i;
        }
    }
}

Node *buildTree(char in[], char pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;

    if (inStrt > inEnd)
        return NULL;

    Node *tNode = newNode(pre[preIndex++]);

    if (inStrt == inEnd)
        return tNode;

    int inIndex = search(in, inStrt, inEnd, tNode->data);

    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);
    Node *root = buildTree(in, pre, 0, len - 1);

    printInorder(root);
}
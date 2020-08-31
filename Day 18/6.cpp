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

bool isIdentical(Node *a, Node *b)
{
    if (a == NULL && b == NULL)
        return true;
    if (a != NULL & b == NULL)
        return false;
    if (a == NULL & b != NULL)
        return false;
    return (a->data == b->data) && isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
}

int main()
{
    struct Node *root1 = newNode(5);
    struct Node *root2 = newNode(5);
    root1->left = newNode(3);
    root1->right = newNode(8);
    root1->left->left = newNode(2);
    root1->left->right = newNode(4);

    root2->left = newNode(3);
    root2->right = newNode(8);
    root2->left->left = newNode(2);
    root2->left->right = newNode(4);

    if (isIdentical(root1, root2))
        cout << "Both BSTs are identical";
    else
        cout << "BSTs are not identical";

    return 0;
}
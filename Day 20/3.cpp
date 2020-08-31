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
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->left = temp->right = NULL;
    temp->data = data;
    return temp;
}

void Inorder(Node *root)
{
    if (root)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

Node *build(int arr[], int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    Node *temp = newNode(arr[mid]);

    if (start == end)
    {
        return temp;
    }

    temp->left = build(arr, start, mid - 1);

    temp->right = build(arr, mid + 1, end);

    return temp;
}

Node *convert(int arr[], int n)
{
    sort(arr, arr + n);

    return build(arr, 0, n - 1);
}

int main()
{
    int keys[] = {15, 10, 20, 8, 12, 16, 25};
    int n = sizeof(keys) / sizeof(keys[0]);

    Node *root = convert(keys, n);

    Inorder(root);

    cout << "\n";

    return 0;
}
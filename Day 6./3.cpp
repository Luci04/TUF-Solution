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

Node *reverse(Node *head, int k)
{
    //O(N) Time
    //O(1) Space

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    int count = 0;

    while (curr != NULL & count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
        head->next = reverse(next, k);

    return prev;
}

Node *reverse2(Node *head, int k)
{

    //O(N) Time
    //O(k) Space

    stack<Node *> st;

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        int count = 0;

        while (curr != NULL && count < k)
        {
            st.push(curr);
            curr = curr->next;
            count++;
        }

        while (!st.empty())
        {
            if (prev == NULL)
            {
                prev = st.top();
                head = prev;
            }
            else
            {
                prev->next = st.top();
                prev = prev->next;
            }
            st.pop();
        }
    }
    prev->next = NULL;

    return head;
}

void Print(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    Node *root = newNode(1);
    root->next = newNode(2);
    root->next->next = newNode(3);
    root->next->next->next = newNode(4);
    root->next->next->next->next = newNode(5);
    root->next->next->next->next->next = newNode(6);

    Print(root);

    root = reverse(root, 3);
    root = reverse2(root, 3);

    Print(root);

    return 0;
}
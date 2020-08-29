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

bool Detect(Node *head)
{
    //O(N) Time
    //O(N) Space
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        if (slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

Node *Detect_and_Remove(Node *head)
{
    Node *slow = head, *fast = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = head;
    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    fast->next = NULL;

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

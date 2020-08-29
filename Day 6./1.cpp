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

int length(Node *a)
{
    int count = 0;
    while (a)
    {
        count++;
        a = a->next;
    }

    return count;
}

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node *findPoint(Node *a, Node *b)
{
    //O(N*M) Time
    //O(1) Space

    int m = length(a);
    int n = length(b);

    Node *head2 = b;

    for (int i = 0; i < m; i++)
    {
        b = head2;
        for (int j = 0; j < n; j++)
        {
            if (a == b)
            {
                return a;
            }
            b = b->next;
        }
        a = a->next;
    }

    return NULL;
}

Node *findPoint2(Node *a, Node *b)
{
    //O(N*log(N)) Time
    //O(N) Space

    int m = length(a);
    int n = length(b);

    set<Node *> s;

    for (int i = 0; i < m; i++)
    {
        s.insert(a);
        a = a->next;
    }

    for (int i = 0; i < n; i++)
    {
        if (s.find(b) != s.end())
        {
            return b;
        }
        b = b->next;
    }

    return NULL;
}

Node *findPoint3(Node *a, Node *b)
{
    //O(N) Time
    //O(1) Space

    int m = length(a);
    int n = length(b);

    Node *curr1 = a;
    Node *curr2 = b;

    while (curr1 != curr2)
    {
        if (curr1 == NULL)
        {
            curr1 = b;
        }
        else
        {
            curr1 = curr1->next;
        }

        if (curr2 == NULL)
        {
            curr2 = a;
        }
        else
        {
            curr2 = curr2->next;
        }
    }

    return curr1;
}

int main()
{

    Node *newNode;
    Node *head1 = new Node();
    head1->data = 10;
    Node *head2 = new Node();
    head2->data = 3;
    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;
    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;
    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;
    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;
    head1->next->next->next = NULL;

    cout << (findPoint(head2, head1))->data << "\n";
    cout << (findPoint2(head2, head1))->data << "\n";
    cout << (findPoint3(head2, head1))->data << "\n";
    return 0;
}
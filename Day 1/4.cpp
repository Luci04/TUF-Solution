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

void Merge(vector<int> &A, vector<int> &B)
{
    //O(N+M) Time
    //O(1) Space

    vector<int> ans;
    int n = A.size();
    int m = B.size();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (A[i] <= B[j])
        {
            ans.push_back(A[i]);
            i++;
        }
        else
        {
            ans.push_back(B[j]);
            j++;
        }
    }

    while (i < n)
    {
        ans.push_back(A[i]);
        i++;
    }

    while (j < m)
    {
        ans.push_back(B[j]);
        j++;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> A = {1, 2, 3, 4, 5, 6};
    vector<int> B = {1, 2, 3, 4, 5, 6};
    Merge(A, B);
    return 0;
}
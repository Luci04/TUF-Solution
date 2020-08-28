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

void solve(vector<vector<int>> v)
{
    //O(N^2) Time
    //(O(N)) Space
    int n = v.size();

    vector<int> row(n);
    vector<int> col(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] || col[j])
            {
                v[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

void solve2(vector<vector<int>> v)
{

    //O(N^2) Time
    //(O(1)) Space

    bool col = false;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i][0] == 0)
        {
            col = true;
        }
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 0)
            {
                v[i][0] = 0;
                v[0][j] = 0;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (v[i][0] == 0 || v[0][j] == 0)
                v[i][j] = 0;
        }
        if (col)
            v[i][0] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> v = {{1, 1, 1},
                             {1, 0, 1},
                             {1, 1, 1}};
    solve(v);
    solve2(v);
    return 0;
}
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

int fact(int n)
{
    if (n == 0)
        return 1;
    int result = 1;
    while (n)
    {
        result = result * n;
        n = n - 1;
    }
    return result;
}

void solve(int row, int col)
{
    cout << fact(row - 1) / (fact(col - 1) * fact(row - col)) << "\n";
}

void solve1(int n)
{
    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++)
    {
        v[i].resize(i + 1);
        v[i][0] = v[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "If the Row and Col is Given\n";
    solve(5, 3);
    cout << "To Print  Pascal Triangle\n";
    solve1(5);
    cout << "To Print A single Row\n";
    solve(5, 3);

    return 0;
}
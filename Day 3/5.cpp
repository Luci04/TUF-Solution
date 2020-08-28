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

void solve(int m, int n)
{
    int arr[m][n];

    for (int i = 0; i < m; i++)
    {
        arr[i][0] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        arr[0][i] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }

    cout << arr[m - 1][n - 1] << "\n";
}

int main()
{
    int m, n;
    cin >> m >> n;
    solve(m, n);
    return 0;
}
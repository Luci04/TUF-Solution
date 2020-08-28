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

void solve(int n)
{
    int count = 0;

    for (int i = 5; n / i >= 1; i *= 5)
    {
        count += n / i;
    }

    cout << count << "\n";
}

int main()
{
    solve(100);
    return 0;
}
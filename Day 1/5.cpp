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

void solve(vector<int> v)
{
    //O(N) Time
    //O(1) Space

    int ans = 0;
    int maxi = 0;
    for (int i = 0; i < v.size(); i++)
    {
        maxi += v[i];

        if (maxi < 0)
            maxi = 0;
        else if (maxi > ans)
        {
            ans = maxi;
        }
    }

    cout << ans << "\n";
}

int main()
{
    vector<int> v = {1, 2, -3, 4, -10};
    solve(v);
    return 0;
}
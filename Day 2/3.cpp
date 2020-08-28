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

void solve(vector<int> &v)
{
    //O(N) Time
    //O(1) Space
    int i = v.size() - 2;

    while (i >= 0 && v[i] >= v[i + 1])
        i--;

    if (i >= 0)
    {
        int j = v.size() - 1;
        while (v[j] <= v[i])
            j--;
        swap(v[i], v[j]);
    }

    reverse(v.begin() + i + 1, v.end());

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

int main()
{
    vector<int> v = {1, 3, 2, 4, 5};
    solve(v);
    return 0;
}
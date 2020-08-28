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
    string str;
    while (n > 0)
    {
        int rem = n % 26;
        if (rem == 0)
        {
            str.push_back('Z');
            n = n / 26 - 1;
        }
        else
        {
            n = n / 26;
            str.push_back(rem - 1 + 'A');
        }
    }

    reverse(str.begin(), str.end());

    cout << str << "\n";
}

void solve1(string str)
{
    int result = 0;

    for (auto c : str)
    {
        result = result * 26;
        result += c + 1 - 'A';
    }

    cout << result << "\n";
}

int main()
{
    int n;
    cin >> n;
    solve(n);
    solve1("AA");
    return 0;
}
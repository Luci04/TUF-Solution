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

void solve(string str)
{
    //O(N^2) Time
    //O(N) Space
    int max_len = 0;

    for (int i = 0; i < str.length(); i++)
    {
        vector<bool> visited(256);
        for (int j = i; j < str.length(); j++)
        {
            if (visited[str[j]] == true)
                break;
            else
            {
                visited[str[j]] = true;
                max_len = max(max_len, j - i + 1);
            }
        }
        visited[str[i]] = false;
    }

    cout << max_len << "\n";
}

void solve1(string str)
{
    //O(N) Time
    //O(N) Space

    int n = str.size();

    int res = 0;

    vector<int> last(256, -1);

    int i = 0;

    for (int j = 0; j < n; j++)
    {
        i = max(i, last[str[j]] + 1);

        res = max(res, j - i + 1);

        last[str[j]] = j;
    }

    cout << res << "\n";
}

int main()
{
    string str = "Avinash";
    solve(str);
    solve1(str);
    return 0;
}
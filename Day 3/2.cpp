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

void power(int x, int n)
{
    int result = 1;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            x *= x;
            n = n / 2;
        }
        else
        {
            result *= x;
            n--;
        }
    }

    cout << "x ^ n = " << result << "\n";
}

void power2(int x, int n, int p)
{
    int result = 1;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            x = (x % p) * (x % p);
            n = n / 2;
        }
        else
        {
            result = ((result % p) * (x % p) % p);
            n--;
        }
    }

    cout << "x ^ n = " << result << "\n";
}

int main()
{
    power(2, 5);
    power2(2, 5, 3);
    return 0;
}
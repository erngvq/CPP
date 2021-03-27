#include <iostream>
#include <vector>
using namespace std;

double fib(int n)
{
    vector<double> dp(n + 1);
    dp[1] = 1;

    for (int i = 0; i < dp.size() - 2; i++)
        dp[i + 2] = dp[i] + dp[i + 1];

    return dp[n];
}

int main()
{
    vector<int> tests{6, 7, 8, 9, 10, 50};
    for (int test : tests) cout << fib(test) << endl;
}

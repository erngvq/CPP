#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

double fib(int n, unordered_map<int, double> &memo)
{
    if (n <= 2) return 1;
    if (memo[n]) return memo[n];

    memo[n] = fib(n - 2, memo) + fib(n - 1, memo);
    return memo[n];
}

int main()
{
    unordered_map<int, double> memo;
    vector<int> tests{6, 7, 8, 9, 10, 50};
    for (int test : tests) cout << fib(test, memo) << endl;
}

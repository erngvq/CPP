#include <iostream>
#include <map>
#include <vector>
using namespace std;

double gridTraveler(int m, int n, map<pair<int, int>, double> &memo)
{
    if (m == 0 || n == 0) return 0;
    if (m == 1 && n == 1) return 1; 

    if (memo[{m, n}]) return memo[{m, n}];
    
    memo[{m, n}] = gridTraveler(m - 1, n, memo) + gridTraveler(m, n - 1, memo);
    
    // Interestingly, gridTraveler(m, n) == gridTraveler(n, m)
    memo[{n, m}] = memo[{m, n}];
    return memo[{m, n}];
}

int main()
{
    map<pair<int, int>, double> memo;
    vector<pair<int, int>> tests{{1, 1}, {2, 3}, {3, 2}, {3, 3}, {18, 18}};
    for (auto test : tests)
        cout << gridTraveler(test.first, test.second, memo) << endl;
}

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> recurse(int amount, vector<int> coins, unordered_map<int, vector<int>> &memo)
{
    if (memo.find(amount) != memo.end())
        return memo[amount];

    if (amount == 0) return {};
    if (amount < 0) return {-1};

    vector<int> shorter = {-1};

    for (int coin : coins)
    {
        int diff = amount - coin;
        vector<int> combination = recurse(diff, coins, memo);

        if (combination.size() == 0 || combination[0] != -1)
        {
            combination.push_back(coin);
            if (shorter[0] == -1 || combination.size() < shorter.size())
                shorter = combination;
        }
    }
    memo[amount] = shorter;
    return shorter;
}

int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0) return 0;
    sort(coins.begin(), coins.end(), greater<int>());

    unordered_map<int, vector<int>> memo;
    vector<int> ret = recurse(amount, coins, memo);

    return ret[0] == -1 ? -1 : ret.size();
}

int main()
{
    vector<pair<vector<int>, int>> tests = {
        {{1, 2, 5}, 11},
        {{2}, 3},
        {{1}, 0},
        {{1}, 2},
        {{259, 78, 94, 130, 493, 4, 168, 149}, 4769}
    };

    for (auto test : tests)
        cout << coinChange(test.first, test.second) << endl;
}

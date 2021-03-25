#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool canSum(int target, vector<int> numbers, unordered_map<int, bool> &memo)
{
    if (target < 0) return false;
    if (target == 0) return true;
    if (memo.find(target) != memo.end()) return memo[target];

    for (int num : numbers)
    {
        int remainder = target - num;
        if (canSum(remainder, numbers, memo))
        {
            memo[target] = true;
            return true;
        }
    }
    memo[target] = false;
    return false;
}

int main()
{
    vector<pair<int, vector<int>>> tests{{7, {2, 3}},
                                         {7, {5, 3, 4, 7}},
                                         {7, {2, 4}},
                                         {7, {2, 3, 5}},
                                         {300, {7, 14}}};
    for (pair<int, vector<int>> test : tests)
    {
        unordered_map<int, bool> memo;
        cout << boolalpha << canSum(test.first, test.second, memo) << endl;
    }
}

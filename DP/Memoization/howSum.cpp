#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> howSum(int target, vector<int> numbers, unordered_map<int, vector<int>> &memo)
{
    if (memo.find(target) != memo.end()) return memo[target];

    if (target < 0) return {-1};
    if (target == 0) return {};

    for (int num : numbers)
    {
        int remainder = target - num;
        vector<int> ret = howSum(remainder, numbers, memo);
        if (ret.size() == 0 || ret[0] != -1)
        {
            ret.push_back(num);
            memo[target] = ret;
            return ret;
        }
    }
    memo[target] = {-1};
    return {-1};
}

void print(vector<int> vec)
{
    for (int i : vec) cout << i << " ";
    cout << endl;
}

int main()
{
    vector<pair<int, vector<int>>> tests{{7, {2, 3}},           // [3, 2, 2]
                                         {7, {5, 3, 4, 7}},     // [4, 3]
                                         {7, {2, 4}},           // [-1]
                                         {8, {2, 3, 5}},        // [2, 2, 2, 2]
                                         {300, {7, 14}}};       // [-1]
    for (pair<int, vector<int>> test : tests)
    {
        unordered_map<int, vector<int>> memo;
        print(howSum(test.first, test.second, memo));
    }
}

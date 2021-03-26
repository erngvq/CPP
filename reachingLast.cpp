/*
 * Given an array of non-negative integers, you are initially positioned
 * at the first index of the array. Each element in the array represents
 * your maximum jump length at that position. Determine if you are able
 * to reach the last index.
 */

#include <iostream>
#include <vector>
using namespace std;

bool reachingLast(vector<int> vec)
{
    int last_idx = vec.size() - 1;
    int before_last = vec.size() - 2;

    for (int i = before_last; i >= 0; i--)
        if (last_idx <= vec[i] + i) last_idx = i;
    return !last_idx;
}

int main()
{
    vector<int> vec1 = {2, 0, 1, 1, 4}; // returns true
    vector<int> vec2 = {0, 1, 1, 1, 1}; // returns false
    vector<int> vec3 = {1, 0, 1, 1, 4}; // returns false
    vector<int> vec4 = {1, 1, 1, 1, 1}; // returns true

    cout << boolalpha << reachingLast(vec1) << endl;
    cout << boolalpha << reachingLast(vec2) << endl;
    cout << boolalpha << reachingLast(vec3) << endl;
    cout << boolalpha << reachingLast(vec4) << endl;
    
    return 0;
}

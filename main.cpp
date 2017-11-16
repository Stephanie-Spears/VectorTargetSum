#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <tuple>
#include <functional>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort (nums.begin(), nums.end());
        vector <pair <int, int>> v;
        pair<int, int> p1;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
            int x = target - nums[*it];
            if (find (nums.begin(), nums.end(), x ) != nums.end()){
                p1 = make_pair(x, nums[*it]);
                v.push_back(p1);
            }
            nums.pop_back();
        }
        nums.clear();
        for (const auto& p : v)
        {
            cout << "[" << p.first << ", " << p.second << "] \n" ;
            nums.push_back(p.first);
            nums.push_back(p.second);

        }
        return nums;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    /*7 + 2, 8 + 1, 0 + 9*/
    vector<int> nums = {2, 7, 11, 15, 0, 1, 9, 8};
    int target = 9;
    vector<int> ret = Solution().twoSum(nums, target);

    string out = integerVectorToString(ret);
    cout << out << endl;
    return 0;

}

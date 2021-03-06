#include <iostream>
#include <cmath>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;

class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target){
        int result = 0;
        int min_gap = INT_MAX;

        sort(nums.begin(), nums.end());

        for(auto a = nums.begin(); a != prev(nums.end(),2); ++a){
            auto b = next(a);
            auto c = prev(nums.end());

            while(b<c){
                const int sum = *a + *b + *c;
                const int gap = abs(sum-target);
                if(gap < min_gap){
                    result = sum;
                    min_gap = gap;
                }

                if(sum < target){
                    ++b;
                }else{
                    --c;
                }
            }
            
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    Solution solver;
    cout << solver.threeSumClosest(nums,target) << endl;
    return 0;
}

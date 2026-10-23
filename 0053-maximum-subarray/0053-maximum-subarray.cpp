#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max_so_far = nums[0];
        int current_max = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            // Decide whether to add the current element to the existing subarray 
            // or start a new subarray from the current element.
            current_max = std::max(nums[i], current_max + nums[i]);
            
            // Keep track of the best sum seen so far.
            max_so_far = std::max(max_so_far, current_max);
        }
        
        return max_so_far;
    }
};

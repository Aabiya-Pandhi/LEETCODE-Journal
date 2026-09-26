class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int k = 0; // Points to the last unique element
        
        for (int j = 1; j < nums.size(); j++) {
            // If we find a new unique element
            if (nums[j] != nums[k]) {
                k++;
                nums[k] = nums[j]; // Move it to the next unique position
            }
        }
        
        return k + 1; // k is an index, so count is k + 1
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int l = -1, r = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(l == -1)
            {
                if(temp[i] != nums[i])
                    l = i;
            }
            if(r == -1)
            {
                if(temp[nums.size() - i - 1] != nums[nums.size() - i - 1])
                    r = nums.size() - i - 1;
            }
            if(l != -1 && r != -1)
                return r - l + 1;
        }
        return 0;
    }
};
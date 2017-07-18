class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxl = 0;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                maxl = max(maxl, temp);
                temp = 0;
                if(maxl >= nums.size() - i)
                    break;
            }
            else
                temp++;

        }
        maxl = max(maxl, temp);
        return maxl;
    }
};
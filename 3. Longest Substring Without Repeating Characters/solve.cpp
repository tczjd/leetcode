class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> vec(256,-1) ;
        int start = 0;
        int maxl = 0;
        int temp = 0;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            if(start <= vec[s[i]])
            {
                maxl = max(maxl, temp);
                start = vec[s[i]] + 1;
                temp = i - start +1;
                if(len - start < maxl)
                    break;
            }
            else
                temp++;
            
            vec[s[i]] = i;
        }
        maxl = max(maxl, temp);
        return maxl;
    }
};
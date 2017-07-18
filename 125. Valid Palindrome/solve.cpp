class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        for(int l = 0, r = s.size() - 1; l < r; l++, r--)
        {
            while(!isalnum(s[l]) && l < r)
                l++;
            while(!isalnum(s[r]) && l < r)
                r--;
            if(toupper(s[l]) != toupper(s[r]))
                return false;
        }
        return true;
    }
};
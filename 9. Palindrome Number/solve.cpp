//������ת��Ϊ�ַ��� �ж��Ƿ����
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        string resp = to_string (x);
        for(int i = 0; i < resp.size() / 2; i++)
        {
            if(resp[i] != resp[resp.size() - 1 - i])
                return false;
        }
        return true;
    }
};

//�����ֵ�����ԭ�����ֱȽ��ж��Ƿ����
class Solution{
public:
	bool isPalindrome(int x){
		if(x < 0)
			return false;
		int temp = x;
		int resp = 0;
		while(1)
		{
			if(x == 0)
				break;
			resp = resp*10+ x%10;
			x /= 10;
		}
		return resp==temp?true:false;
	}
}
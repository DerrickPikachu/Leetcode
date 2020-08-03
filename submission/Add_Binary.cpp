class Solution {
public:
    string addBinary(string a, string b) {
        string&big = a.length()>=b.length()?a:b;
        string&small = a.length()<b.length()?a:b;
        int blen = a.length()>=b.length()?a.length():b.length();
        int slen = a.length()<b.length()?a.length():b.length();
        
        //fill '0' in front of the smaller binary number so that both becomes equal.
        for(int i=0;i<blen-slen;++i)
            small.insert(small.begin(),'0');
        
        int carry=0;
        for(int i=big.length()-1;i>=0;--i)
        {
            int sum=(big[i]-'0')+(small[i]-'0')+carry;
            carry=sum>>1;
            sum%=2;
            big[i]=sum+'0';
        }
        
        if(carry)
            big.insert(big.begin(),'1');
        return big;
    }
};

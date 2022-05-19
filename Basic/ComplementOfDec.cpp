class Solution {
public:
    int bitwiseComplement(int n) {
        
        int m =n;
        int mask=0;
        int ans;
        if(n==0){
            
            return 1;
        }
        while(m != 0){
            
            mask= (mask << 1) |1;
            m = m >>1;
        }
        
        ans = (~n) & mask;
        return ans;
    }
};
//ip=5, o/p=2
// not or invert 5, but we need only last digits of the 32 bit number
//therefore first we invert 5 and then and with a mask 
//which gives us only the needed bits and not 111111110101
//ip=5= 000000000000000101
//inverted 5 = 11111111111111 010
//mask = 000000000000 111
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0;
        int prod =1;
        int a;
        while(n!=0){
            
            a = n%10;
            sum=sum+a;
            prod=prod*a;
            
            n=n/10;
        }
        return prod - sum;
    }
};
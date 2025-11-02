// Last updated: 11/2/2025, 10:27:26 PM
class Solution {
            int mod = (int) 1e9 + 7;

    public int countGoodNumbers(long n) {
        long oddIdx = 0;
        long evenIdx = 0;
        if(n%2==0){
            evenIdx = n/2;
            oddIdx = n/2;
            return( (int)(pow(5, evenIdx)%mod * pow(4, oddIdx)%mod )%mod);
    }
    else{
        evenIdx = (n+1)/2;
        oddIdx = (n-1)/2;
        return((int) (pow(5, evenIdx) % mod * pow(4, oddIdx) % mod)%mod);

    }
    }

    public long pow(int x, long y){
        if(y == 0){
            return 1;
        }
        if(y==1){
            return x;
        }
        long temp = pow(x, y/2);
        if(y%2 == 0){
            return (temp%mod * temp%mod) % mod;
        }
        else{
            return (temp%mod * temp%mod*x%mod)%mod;
        }
    }
}
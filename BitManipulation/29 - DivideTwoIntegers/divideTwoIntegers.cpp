class Solution {

   public:
    int divide(int dividend, int divisor) {
        // your code goes here

        if (dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == 1) return dividend;

        bool isPositive = true;

        if (dividend >= 0 && divisor < 0)
            isPositive = false;
        else if (dividend < 0 && divisor > 0)
            isPositive = false;

        long long n = dividend;
        long long d = divisor;

        n = abs(n);
        d = abs(d);

        long long ans = 0;
        while (n >= d) {
            int count = 0;
            //finding the power of 2 for which it gives the largest multiple of d less than n
            while (n >= (d << (count + 1))) count++;

            ans += (1 << count);
            n -= d * (1 << count);
        }

        if(ans == (1<<31) && isPositive) return INT_MAX;
        if(ans == (1<<31) && !isPositive) return INT_MIN;

        return isPositive ? ans : -ans;
    }
};
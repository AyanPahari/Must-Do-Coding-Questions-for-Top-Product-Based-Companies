class Solution
{
public:
    //here the value of n can be both positive as well as negative
    double myPow(double x, int n)
    {
        //Binary exponentiation
        //time:O(logn)
        //space:O(1)
        double res = 1.0;
        long pos = abs(n); //if value of n is INT_MIN then to avoid overflow long is used
        while (pos > 0)
        {
            if (pos % 2 == 0)
            {
                x *= x;
                pos /= 2;
            }
            else
            {
                res *= x;
                pos--;
            }
        }
        if (n >= 0)
            return res;
        else
            return 1 / res; //if n is negative
    }
};
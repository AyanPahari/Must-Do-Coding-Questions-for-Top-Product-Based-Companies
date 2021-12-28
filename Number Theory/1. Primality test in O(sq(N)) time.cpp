bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        { //naive approach O(n)
            return false;
        }
    }
    return true;
}

bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        { //optimised approach O(sq(n))
            return false;
        }
    }
    return true;
}
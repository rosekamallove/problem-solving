const int N = 1000000;
bool prime[1000001];

void sieve()
{
    for (int i = 2; i <= N; i++)
    {
        prime[i] = 1;
    }
    for (int i = 2; i * i <= N; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

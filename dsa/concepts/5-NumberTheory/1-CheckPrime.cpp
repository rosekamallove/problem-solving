#include <bits/stdc++.h>
using namespace std;

/*
 * => Facts about prime numbers:
 *
 *  ->  2 is the only even prime number
 *
 *  ->  Every prime number can be written as:
 *          - 6n + 1 | n being a natural number
 *          - 6n - 1 | except 2 & 3
 *
 *  ->  GoldBachs Conjecture: Every even int > 2 can be written as a sum of
 *      two prime nums
 *
 *  ->  Wilson's Throrem: (p-1)! === (p-1) mod p
 *
 *  ->  2 and 3 are the only consecutive numbers that are prime
 */

/*
 * A Pime number is a number with havin exactly two factors (1 and itself)
 *
 * So, what we can do is count the number of factors of a number in order
 * to check if the numebr is prime or not
 */
bool naive(int n)
{
    int cnt(0);
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            cnt++;
    return cnt == 2;
}

/* A reversal in the factors start after sqrt(n) */
bool optimized(int n)
{
    int cnt(0);
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            cnt++;
        if ((n / i) != i) /* for ex: 6x6 */
            cnt++;
    }
    return cnt == 2;
    /*
     * sqrt(n) makes the complexity => O(sqrt(n) x log(n)),
     * hence, we use ixi instead;
     */
}

int sumOfPrimeFactor(int n)
{
    int sum(0);
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            sum += i;
        if ((n / i) != i)
            sum += n / i;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    cout << sumOfPrimeFactor(n) << endl;
}

#include <iostream>
using namespace std;

void prime_factors(int n)
{
    if (n <= 1)
        return;

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            std::cout << i << " ";
            n /= i;
        }
    }

    if (n > 1)
    {
        std::cout << n << endl;
    }
}

int main()
{
    int n;
    std::cin >> n;
    prime_factors(n);
    return 0;
}
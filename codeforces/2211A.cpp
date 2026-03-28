#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        vector<int> p;
        for (int i = 0; i < n; i++)
        {
            int pi;
            std::cin >> pi;
            p.push_back(pi);
        }

        if (n == 1)
        {
            std::cout << 1 << "\n";
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                std::cout << 2 << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
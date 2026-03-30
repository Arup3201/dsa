#include <iostream>
using namespace std;

void rec_toh(int n, char src, char aux, char tar)
{
    if (n == 1)
    {
        std::cout << "Disk 1 moved from " << src << " to " << tar << "\n";
        return;
    }
    else if (n == 2)
    {
        std::cout << "Disk 1 moved from " << src << " to " << aux << "\n";
        std::cout << "Disk 2 moved from " << src << " to " << tar << "\n";
        std::cout << "Disk 1 moved from " << aux << " to " << tar << "\n";
        return;
    }

    rec_toh(n - 1, src, tar, aux);
    std::cout << "Disk " << n << " moved from " << src << " to " << tar << "\n";
    rec_toh(n - 1, aux, src, tar);
}

void toh(int disks)
{
    rec_toh(disks, 'A', 'B', 'C');
}

int main()
{
    int n;
    std::cin >> n;
    toh(n);
    return 0;
}
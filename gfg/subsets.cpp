#include <iostream>
using namespace std;

void rec_generate_subsets(string s, string sub, int i)
{
    if (i == s.length())
    {
        std::cout << sub << " ";
        return;
    }

    rec_generate_subsets(s, sub, i + 1);
    rec_generate_subsets(s, sub + s[i], i + 1);
}

void generate_subsets(string s)
{
    rec_generate_subsets(s, "", 0);
    std::cout << endl;
}

int main()
{
    string s;
    std::cin >> s;
    generate_subsets(s);
    return 0;
}
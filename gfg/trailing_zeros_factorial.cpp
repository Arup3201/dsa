#include <bits/stdc++.h>
using namespace std;

int count_trailing_zeros(int n)
{
    int tens = 0, fives = 0, twos = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        while (temp % 10 == 0)
        {
            tens++;
            temp /= 10;
        }
        while (temp % 5 == 0)
        {
            fives++;
            temp /= 5;
        }
        while (temp % 2 == 0)
        {
            twos++;
            temp /= 2;
        }
    }

    return tens + min(fives, twos);
}

// ---------------- RUN SOLUTION ----------------
vector<int> runSolution(istream &in)
{
    int t;
    in >> t;

    vector<int> results;

    while (t--)
    {
        int n;
        in >> n;

        results.push_back(count_trailing_zeros(n));
    }

    return results;
}

// ---------------- READ EXPECTED OUTPUT ----------------
vector<int> readExpected(const string &filename)
{
    ifstream file(filename);
    vector<int> expected;
    string line;

    while (getline(file, line))
    {
        if (!line.empty())
            expected.push_back(stoi(line));
    }

    return expected;
}

// ---------------- COMPARE OUTPUT ----------------
void compareOutputs(const vector<int> &actual, const vector<int> &expected)
{
    int n = max(actual.size(), expected.size());

    for (int i = 0; i < n; i++)
    {
        int a = (i < actual.size()) ? actual[i] : -1;
        int e = (i < expected.size()) ? expected[i] : -1;

        if (a == e)
        {
            cout << "Test " << i + 1 << ": PASS\n";
        }
        else
        {
            cout << "Test " << i + 1 << ": FAIL\n";
            cout << "  Expected: " << e << "\n";
            cout << "  Got     : " << a << "\n";
        }
    }
}

// ---------------- MAIN ----------------
int main()
{
    // Redirect input from file
    ifstream inputFile("input.txt");

    if (!inputFile)
    {
        cerr << "Error opening input.txt\n";
        return 1;
    }

    // Run solution
    vector<int> actualOutput = runSolution(inputFile);

    // Read expected output
    vector<int> expectedOutput = readExpected("output.txt");

    // Compare
    compareOutputs(actualOutput, expectedOutput);

    return 0;
}
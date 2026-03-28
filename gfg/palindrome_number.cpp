#include <bits/stdc++.h>
using namespace std;

// ---------------- SOLUTION FUNCTION ----------------
bool isPalindrome(int n)
{
    int t = n;
    int rev = 0;

    while (t > 0)
    {
        rev = rev * 10 + t % 10;
        t /= 10;
    }

    return rev == n;
}

// ---------------- RUN SOLUTION ----------------
vector<string> runSolution(istream &in)
{
    int t;
    in >> t;

    vector<string> results;

    while (t--)
    {
        int n;
        in >> n;

        if (isPalindrome(n))
            results.push_back("YES");
        else
            results.push_back("NO");
    }

    return results;
}

// ---------------- READ EXPECTED OUTPUT ----------------
vector<string> readExpected(const string &filename)
{
    ifstream file(filename);
    vector<string> expected;
    string line;

    while (getline(file, line))
    {
        if (!line.empty())
            expected.push_back(line);
    }

    return expected;
}

// ---------------- COMPARE OUTPUT ----------------
void compareOutputs(const vector<string> &actual, const vector<string> &expected)
{
    int n = max(actual.size(), expected.size());

    for (int i = 0; i < n; i++)
    {
        string a = (i < actual.size()) ? actual[i] : "MISSING";
        string e = (i < expected.size()) ? expected[i] : "MISSING";

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
    vector<string> actualOutput = runSolution(inputFile);

    // Read expected output
    vector<string> expectedOutput = readExpected("output.txt");

    // Compare
    compareOutputs(actualOutput, expectedOutput);

    return 0;
}
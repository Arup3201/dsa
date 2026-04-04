#include <bits/stdc++.h>
using namespace std;

// ---------------- SOLUTION FUNCTION ----------------
int second_largest(vector<int> arr)
{
    int ans = -1, l = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[l] < arr[i])
        {
            ans = l;
            l = i;
        }
        else if (arr[l] > arr[i] && (ans == -1 || arr[ans] < arr[i]))
        {
            ans = i;
        }
    }

    if (ans == -1)
        return -1;

    return arr[ans];
}

// ---------------- RUN SOLUTION ----------------
vector<int> runSolution(istream &in)
{
    int t;
    in >> t;

    vector<int> results;

    int l;
    vector<int> a;
    while (t--)
    {
        in >> l;

        for (int i = 0; i < l; i++)
        {
            int v;
            in >> v;
            a.push_back(v);
        }

        results.push_back(second_largest(a));
        a.clear();
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
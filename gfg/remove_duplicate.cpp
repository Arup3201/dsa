#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[j])
        {
            j += 1;

            if (j != i)
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    for (int i = 0; i <= j; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
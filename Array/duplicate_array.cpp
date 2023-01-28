#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 6, 6};
    int n = sizeof(arr) / sizeof(n);

    for (int i = 0; i < n; i++)
    {
        arr[arr[i] % n] = arr[arr[i] % n] + n;
    }
    cout << "element is " << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= n * 2)
        {
            cout << i << " " << endl;
        }
    }
    return 0;
}
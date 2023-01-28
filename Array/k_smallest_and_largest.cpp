#include <bits/stdc++.h>
using namespace std;

int kSmallest(int *arr, int n, int K)
{
    sort(arr, arr + n);

    return arr[K - 1];
}

int main()
{
    int arr[] = {12, 3, 5, 6, 15};
    int n = sizeof(arr) / sizeof(n);
    int k = 2;

    cout << "K'th smallest Number " << kSmallest(arr, n, k);
}
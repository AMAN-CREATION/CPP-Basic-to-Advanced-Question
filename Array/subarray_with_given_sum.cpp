#include <bits/stdc++.h>
using namespace std;

void subArraySum(int *arr, int n, int sum)
{
    //*pick a starting point
    for (int i = 0; i < n; i++)
    {
        int currentSum = arr[i];

        if (currentSum == sum)
        {
            cout << "Sum found at indexes " << i << endl;
            return;
        }
        else
        {
            //*try all subarrays start with i;
            for (int j = i + 1; j < n; j++)
            {
                currentSum += arr[j];
                if (currentSum == sum)
                {
                    cout << "sum found between index " << i << " and " << j << endl;
                    return;
                }
            }
        }
    }
    cout << "No subarray found";
    return;
}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr) / sizeof(n);

    int sum = 100;
    subArraySum(arr, n, sum);
    return 0;
}
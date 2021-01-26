// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int findElement(int a[], int n) {
    vector<pair<int, int>>ma, mi;int max = a[0], min = a[n - 1];

    for (int i = 1;i < n - 1;i++)
    {
        if (a[i] >= max)
        {
            max = a[i];
            ma.push_back({ a[i],i });
        }
    }

    for (int i = n - 2;i > 0;i--)
    {
        if (a[i] <= min)
        {
            min = a[i];
            mi.push_back({ a[i],i });
        }
    }
    for (int i = 0;i < ma.size();i++)
    {
        pair<int, int> x = ma[i];
        for (int j = mi.size() - 1;j >= 0;j--)
        {
            if (x == mi[j])
            {
                return x.first;
            }
        }
    }
    return -1;

}
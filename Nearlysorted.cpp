//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the sorted array.
    vector<int> nearlySorted(int arr[], int n, int k)
    {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> sortedArr;
        for (int i = 0; i < n; i++)
        {
            minHeap.push(arr[i]);
            if (minHeap.size() > k)
            {
                sortedArr.push_back(minHeap.top());
                minHeap.pop();
            }
        }
        for (int i = 0; i < k; i++)
        {
            sortedArr.push_back(minHeap.top());
            minHeap.pop();
        }
        return sortedArr;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int num, K;
        cin >> num >> K;

        int arr[num];
        for (int i = 0; i < num; ++i)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res = ob.nearlySorted(arr, num, K);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<pi> maxHeap;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            maxHeap.push(make_pair(abs(x - arr[i]), arr[i]));
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        vector<int> ans(k);
        for (int i = k - 1; i >= 0; i--)
        {
            pi val = maxHeap.top();
            maxHeap.pop();
            ans[i] = val.second;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    Solution solution;
    vector<int> result = solution.findClosestElements(arr, k, x);

    cout << "Closest elements to " << x << " are: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

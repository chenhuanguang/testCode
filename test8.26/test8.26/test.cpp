class Solution {
public:

    int maxValue(string s, int k)
    {
        int start = 0;
        int end = 1;
        int cut = s.size() - k;
        int cnt = 0;
        if (k == s.size())
            return stoi(s);
        vector<int> arr(s.size() + 1);
        arr[0] = INT_MAX;
        for (int i = 1; i < arr.size(); ++i)
        {
            arr[i] = s[i - 1] - '0';
        }

        while (end <= arr.size() && cnt != cut)
        {
            if (arr[end] <= arr[start])
                arr[++start] = arr[end++];
            else
            {
                start--;
                cnt++;
            }
        }
        while (end <= arr.size())
        {
            arr[++start] = arr[end++];
        }
        int res = 0;
        for (int i = 1; i <= k; ++i)
        {
            res = res * 10 + arr[i];
        }
        return res;
    }
};
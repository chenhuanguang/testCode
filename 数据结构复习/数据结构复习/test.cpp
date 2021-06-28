#include <vector>
using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k)
{
    int idx = num.size() - 1;
    int step = 0;
    vector<int> res;
    while (idx >= 0 || k > 0)
    {
        int tmp = k % 10;
        k /= 10;
        int sum = 0;
        if (idx >= 0)
            sum = num[idx--] + tmp + step;
        else
            sum = tmp + step;
        if (sum > 9)
        {
            step = 1;
            sum -= 10;
        }
        res.push_back(sum);
    }
    if (step == 1)
        res.push_back(1);
    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    vector<int> vec = { 6 };

    addToArrayForm(vec, 809);
	return 0;
}
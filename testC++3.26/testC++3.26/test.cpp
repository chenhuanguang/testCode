#include <iostream>
#include <vector>
using namespace std;

void test()
{
	vector<int> v(5, 1);
	vector<int>::iterator it = v.begin();
	cout << *it << endl;
	v.erase(it);
	it = v.begin();
	cout << *it << endl;
}

int main()
{
	test();
	return 0;
}

//int removeDuplicates(vector<int>& nums)
//{
//
//    int pos = 1;
//
//    auto it = ++nums.begin();
//    while (it != nums.end())
//    {
//        if (*it == *(--it))
//        {
//            nums.erase(it);
//        }
//        else
//        {
//            ++it;
//        }
//    }
//
//    return nums.size();
//}

//void test()
//{
	//vector<int > v(10);
	//vector<vector<int>> vv(10);
	////vector<int>::const_iterator it = v.begin();
	//for (size_t i = 0; i < vv.size(); ++i)
	//{
	//	vv[i].resize(10);
	//}
	//for (size_t i = 0; i < vv.size(); ++i)
	//{
	//	for (size_t j = 0; j < vv[i].size(); ++j)
	//	{
	//		cout << vv[i][j] << " ";
	//	}
	//	cout << "--------------" << endl;
	//}

	//vector<int> v;
	//v.push_back(1);
	//v.push_back(1);
	//v.push_back(2);
	//removeDuplicates(v);

	//vector<int> v1(5, 5);
	//int arr[] = { 1,3,5,7,9,2,4,6,8 };
	//vector<int> v2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//vector<int> v3(v2.begin(), v2.end());
	//for (size_t i = 0; i < v3.size(); ++i)
	//{
	//	cout << v3[i] << " ";
	//}
	//cout << endl;
//
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	auto it = v.begin();
//	v.erase(it);
//	cout << *it << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}
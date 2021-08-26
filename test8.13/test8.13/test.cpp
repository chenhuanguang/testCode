#include <iostream>
#include <map>
using namespace std;
int main() {
    map<int, int> m;
    m[0] = 0;
    m[1] = 1;
    m[2] = 2;
    auto it = m.begin();
    for (; it != m.end();)
    {
        std::cout << "key: " << it->first << " value: " << it->second << endl;
        m.erase(it);
        it = m.begin();
    }
    //while (it != m.end())
    //{
    //    cout << it->first << " " << it->second << " ";
    //    m.erase(it++);
    //}

    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string findMax(const string& line)
{
    int div = line.find('-');
    string car1 = line.substr(0, div);
    string car2 = line.substr(div + 1);

    //获取两手牌的牌数
    int car1_cnt = count(car1.begin(), car1.end(), ' ') + 1;
    int car2_cnt = count(car2.begin(), car2.end(), ' ') + 1;

    if (car1_cnt != car2_cnt)//存在炸弹
    {
        if (car1 == "joker JOKER" || car2 == "joker JOKER")
            return "joker JOKER";
        if (car1_cnt == 4)
            return car1;
        else if (car2_cnt == 4)
            return car2;
        else
            return "ERROR";
    }
    else //牌数相同则比较第一张牌的大小
    {
        string tb = "345678910JQKA2";
        string car1_first = car1.substr(0, car1.find(' '));
        string car2_first = car2.substr(0, car2.find(' '));
        int car1_first_v = tb.find(car1_first);
        int car2_first_v = tb.find(car2_first);
        return car1_first_v > car2_first_v ? car1 : car2;
    }
}

int main()
{
    string line, res;
    while (getline(cin, line))
    {
        res = findMax(line);
        cout << res << endl;
    }
    return 0;
}
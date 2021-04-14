#include<stdio.h>
int main()
{
    while (1)
    {
        int x, y, z = 0;
        char c;
        printf("格式为：数据运算符数据\n");
        printf("请输入：");
        scanf_s("%d%c%d", &x, &c, &y);//在vs2017中输入字符型变量需要定义长度否则出错
        switch (c)
        {
        case '+':
            z = x + y;
            break;
        case '-':
            z = x - y;
            break;
        case '*':
            z = x * y;
            break;
        case '/':
            z = x / y;
            break;
        default:
            printf("erro!");
            break;
        }
        printf("%d\n", z);
    }
    
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

//公鸡一个五块钱，母鸡一个三块钱，小鸡三个一块钱，现在要用一百块钱买一百只鸡，问公鸡、母鸡、小鸡各多少只？
//int BuyChicken(int price, int num)
//{
//    int total = 0;
//    for (int x = 0; x < num / 5; ++x)
//    {
//        for (int y = 0; y < num / 3; ++y)
//        {
//            int z = num - x - y;
//            //15*x + 9*y + z = 3*price
//            if (14 * x + 8 * y == 2 * price)
//            {
//                ++total;
//                printf("公鸡：%d, 母鸡：%d, 小鸡：%d, \n", x, y, z);
//            }
//        }
//    }
//    return total;
//}
//
//int main()
//{
//    int price = 100;
//    int num = 100;
//    int res = BuyChicken(price, num);
//    printf("花%d块钱买%d只鸡共有%d中方案\n", price, num, res);
//    return 0;
//}

//有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子
//假如兔子都不死，问每个月的兔子总数为多少？
//size_t Rabbit(int count)
//{
//	if (count == 0)
//	{
//		return 0;
//	}
//	if (count == 1 || count == 2)
//	{
//		return 1;
//	}
//
//	int one = 1;
//	int two = 0;
//	int three = 0;
//	size_t total = 0;
//	while (--count)
//	{
//		three += two;
//		two = one;
//		one = three;
//	}
//	total = one + two + three;
//
//	return total;
//}
//
//int main()
//{
//	int count = 9;
//	size_t res = Rabbit(count);
//	printf("%d个月共可以产%u对兔子\n", count, res);
//
//	return 0;
//}

size_t Rabbit(int count)
{
	if (count == 1 || count == 2)
	{
		return 1;
	}
	return Rabbit(count - 1) + Rabbit(count - 2);
}

int main()
{
	int count = 40;
	size_t res = Rabbit(count);
	printf("%d个月共可以产%u对兔子\n", count, res);

	return 0;
}
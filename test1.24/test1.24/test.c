#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[] = { -4,-1,0,3,10 };
    int i;
    for (i = 0; i < 5; ++i)
    {
        if (nums[i] > 0)
            break;
    }

    int negativeEnd = i - 1;
    int positiveBegin = i;

    int* arr = (int*)malloc(sizeof(int) * 5);
    int idx = 0;
    while (negativeEnd >= 0 || positiveBegin < 5)
    {
        if (negativeEnd < 0)
        {
            arr[idx++] = nums[positiveBegin] * nums[positiveBegin];
            positiveBegin++;
        }
        else if (positiveBegin >= 5)
        {
            arr[idx++] = nums[negativeEnd] * nums[negativeEnd];
            negativeEnd--;
        }
        else if ((nums[negativeEnd] * nums[negativeEnd]) > (nums[positiveBegin] * nums[positiveBegin]))
        {
            arr[idx++] = nums[negativeEnd] * nums[negativeEnd];
            negativeEnd--;
        }
        else
        {
            arr[idx++] = nums[positiveBegin] * nums[positiveBegin];
            positiveBegin++;
        }
    }
	return 0;
}
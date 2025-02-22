#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 10001

int main()
{
    int testcase;
    scanf("%d", &testcase);

    int array[testcase];
    int square[testcase];

    for (int i=0; i < testcase; i++){
        int start, end;
        scanf("%d %d", &start, &end);
        array[i] = end - start;
        square[i] = sqrt(end - start);
    }

    for (int i=0; i < testcase; i++){
        if (array[i] == square[i] * square[i])
            printf("%d\n", 2 * square[i] - 1);
        else if (array[i] <= square[i] * (square[i] + 1))
            printf("%d\n", 2 * square[i]);
        else
            printf("%d\n", 2 * square[i] + 1);
    }

    return 0;
}
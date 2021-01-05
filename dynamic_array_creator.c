#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *resize(int *array, int limit);
void fillWithRandomNumbers(int *array, int startIndex, int limit, int stepCount);
void print(int *array, int limit);

int main()
{
    int *array;
    
    int choice = 1;
    int stepCount = 1;
    int startIndex = 0;
    int limit = 10;

    array = resize(NULL, limit);
    fillWithRandomNumbers(array, startIndex, limit, stepCount);
    print(array, limit);

    while(choice >= 1)
    {
        printf("Would you like to resize array? \n");
        scanf("%d", &choice);

        if(choice == 0)
        {
            break;
        }

        startIndex = limit;

        printf("Enter new size of array? \n");
        scanf("%d", &limit);
        
        array = resize(array, limit);
        stepCount++;
        fillWithRandomNumbers(array, startIndex, limit, stepCount);
        print(array, limit);
    }

    free(array);
    printf("Good bye...\n");
    return 0;
}

int *resize(int *array, int limit)
{
    if(limit < 0)
    {
        return NULL;
    }

    if(array == NULL)
    {
        array = (int *) malloc(limit * sizeof(int));
        return array;
    }

    array = (int *) realloc(array, (limit * sizeof(int)));
    return array;
}

void fillWithRandomNumbers(int *array, int startIndex, int limit, int stepCount)
{
    srand(time(0));

    printf("------- STEP-%d ------- \n", stepCount);
    for(int i = startIndex; i < limit; i++)
    {
        array[i] = rand() / 10000;
    }
}

void print(int *array, int limit)
{
    for(int i = 0; i < limit; i++)
    {
        printf("%d ", *(array + i));
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *resize(int *array, int limit);
void fill_with_random_numbers(int *array, int startIndex, int limit, int stepCount);
void print(int *array, int limit);

int main()
{
    int *array;
    
    int choice = 1;
    int step_count = 1;
    int start_index = 0;
    int limit = 10;

    array = resize(NULL, limit);
    fill_with_random_numbers(array, start_index, limit, step_count);
    print(array, limit);

    while(choice >= 1)
    {
        printf("Would you like to resize array? \n");
        scanf("%d", &choice);

        if(choice == 0)
        {
            break;
        }

        start_index = limit;

        printf("Enter new size of array? \n");
        scanf("%d", &limit);
        
        array = resize(array, limit);
        step_count++;

        fill_with_random_numbers(array, start_index, limit, step_count);
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

void fill_with_random_numbers(int *array, int start_index, int limit, int step_count)
{
    srand(time(0));

    printf("------- STEP-%d ------- \n", step_count);
    for(int i = start_index; i < limit; i++)
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
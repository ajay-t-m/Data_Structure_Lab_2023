#include <stdio.h>
int a[50], n, choice, i, j;
void bubble()
{
    int j, temp;
    for (i = 0; i < n; i++){
        for (j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("After Bubble sort Elements are : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}

void selection()
{
    int j, temp, small;
    for (i = 0; i < n; i++)
    {
        small=i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[small])
            {
                small=j;
            }
                temp = a[i];
                a[i] = a[small];
                a[small] = temp;
        }
    }
    printf("After Selection sort Elements are : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}

void insertion()
{
    int j, min;
    for (i = 1; i < n; i++)
    {
        min = a[i];
        j = i - 1;
        while (min < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = min;
    }
    printf("After Insertion sort Elements are : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}
int main()
{
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    while (choice != 4)
    {
        printf("\nEnter the choice (1.Bubble 2.Selection 3.Insertion 4.Exit): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bubble();
            break;
        case 2:
            selection();
            break;
        case 3:
            insertion();
            break;
        case 4:
            printf("\nExit\n");
            break;
        default:
            printf("Enter the invalid option");
        }}
    return 0;
}


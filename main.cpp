#include<stdio.h>
#define MAX_ARRAY_SIZE 50

float useInterpolation(int numPairs, float Xvalues[], float Yvalues[], float unknownX);

int main()
{
    int numPairs;
    float Xvalues[MAX_ARRAY_SIZE], Yvalues[MAX_ARRAY_SIZE], unknownX, finalResult;
    // printf("Hello World1");
    printf("How many x,y pairs are given in question : ");
    scanf("%d",&numPairs);

    for (int i=0; i<numPairs; i++)
    {
        printf("Enter the next x value : ");
        scanf("%f", &Xvalues[i]);
        printf("Enter the corresponding y value : ");
        scanf("%f", &Yvalues[i]);
        printf("\n\n");
    }

    printf("Now, Enter the x value for which you want to find the y value : ");
    scanf("%f",&unknownX);


    finalResult = useInterpolation(numPairs, Xvalues, Yvalues, unknownX);

    printf("\n\n>>After using Lagrange's method of interpolation,\n\tThe required value of y is : %f\n\n", finalResult);

    return 0;
}

float useInterpolation(int numPairs, float Xvalues[], float Yvalues[], float unknownX)
{
    float term, finalResult = 0.f;

    for (int i=0; i<numPairs; i++)
    {
        term = Yvalues[i];

        for (int j=0; j<numPairs; j++)
        {
            if (i==j) continue;
            term = term * (unknownX-Xvalues[j]) / (Xvalues[i] - Xvalues[j]);
        }

        finalResult += term;
    }

    return finalResult;
}
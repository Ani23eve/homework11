#include <stdio.h>
#include <stdlib.h>

int getNumber();

double randNumber(double min, double max);

void initializeSegment(double* arr, int start, int end, double randmin, double randmax);

void printArray(double* arr, size_t size);
typedef struct {
    double start;
    double end;
    double (*generator)(double, double); 
} randInitializer;


void initializeSegment2(double* arr, int start, int end, randInitializer* r)
{
    for(int i = start; i < end; i++)
    {
        arr[i] = r->generator(r->start, r->end);
    }
}


int main(){
    double* arr;
    int n = getNumber();
    randInitializer first;
    first.start = 0.0;
    first.end = 1.0;
    first.generator = randNumber;
    arr = (double*) malloc(n * sizeof(double));
    initializeSegment2(arr, 0, n, &first);
    printArray(arr, n);

    int m = getNumber();
    arr = (double*) realloc(arr, (m + n) * sizeof(double));
    initializeSegment(arr, n, n+m, 1.0, 2.0);
    printArray(arr, n + m);

    int p = getNumber();
    arr = (double*) realloc(arr, (m + n + p) * sizeof(double));
    initializeSegment(arr, n+m, n+m+p, 2.0, 3.0);
    printArray(arr, n + m + p);
    free(arr);

    return 0;
}


void printArray(double* arr, size_t size)
{
    for(size_t i = 0; i < size; i++){
        printf("%lf ", arr[i]);
    }
    printf("\n");
}

void initializeSegment(double* arr, int start, int end, double randmin, double randmax)
{
    for(int i = start; i < end; i++)
    {
        arr[i] = randNumber(randmin, randmax);
    }
}

double randNumber(double min, double max)
{
    return min + (max - min) * rand()/ (double) RAND_MAX;
}


int getNumber()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    return number;
}

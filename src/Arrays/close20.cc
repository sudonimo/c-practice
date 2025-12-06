// Find the element close to 0. if there are two elements equally close to 0, choose greater one.
#include<stdbool.h>
#include<malloc.h>

int Solve (int N, int* A) {
   // Write your code here
   int minor = A[0];

   printf("minor before loop = %d N=%d\n", minor, N);
   for(int i=0; i<N; i++) {
        printf("A[%d]=%d\n", i, A[i]);
        if((A[i]*A[i]) < (minor*minor)) {
            minor = A[i];
        }
    }
    printf("minor = %d\n", minor);
    return minor;
}
int main() 
{
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(N*sizeof(int));
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    int out_ = Solve(N, A);
    printf("%d\n", out_);
    return 0;
}

// to test it /a.out < input > output; input is a input file.
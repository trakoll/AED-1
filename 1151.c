/* Kauan Dias Caisley AED 1 Fibonacci*/

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    long long a = 0, b = 1;

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            printf("%lld", a);   // primeiro termo
        } else if (i == 1) {
            printf(" %lld", b);  // segundo termo
        } else {
            long long c = a + b;
            printf(" %lld", c);
            a = b;
            b = c;
        }
    }
    
    printf ("\n");

    return 0;
}

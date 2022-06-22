#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void) {
    double mX;
    scanf("%lf", &mX);
    
    int n;
    scanf("%d", &n);
    double sD = 0.0; 
    for(int i = 0; i < n; i++) {
        double num;
        scanf("%lf", &num);
        sD +=  (mX - num) * (mX - num);
    }
    sD /= (n -1);
    sD = sqrt(sD);
    printf ("%lf", sD);
    system("pause");
    return 0;
}

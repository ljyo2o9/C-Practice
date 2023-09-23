#include <stdio.h>

int main(void){
    int a, b, c, avg = 0;
    scanf("%d %d %d", &a, &b, &c);
    
    if(a > b){
        if(a < c) avg = a;
        else if (c > b) avg = c;
        else avg = b;
    } else {
        if(b < c) avg = b;
        else if (c > a) avg = c;
        else avg = a;
    }
    
    printf("%d\n", avg);
    
    return 0;
}

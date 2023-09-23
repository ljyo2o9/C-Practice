// 유한 소수 판별하기
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int sosu(int d){  //7 // 2 ~ 6 //
    int suu = 0;
    if(d == 2) return 0;
    if(d == 5) return 0;
    for(int i=2; i<d; i++){
        if(d % i == 0){
            if(i % 2 == 0){
                suu++;
            } else if (i % 5 == 0){
                suu++;
            } else {
                return 1;
            }
        }
    }
    
    if(suu > 0){
        return 0;
    } else {
        return 1;
    }
}

int solution(int a, int b) {
    int answer = 0;
    
    if(b % a == 0){
        b = b / a;
        a = 1;
    }
 
    for(int i = (a/2) + 1; i>1; i--){
        if(a == 1) break;
        else if(b % i == 0 && a % i == 0){
            a = a/i;
            b = b/i;
            
            i++;
        }
    }
    
    printf("--%d--%d--", a, b);
    
    if(a == b || a % b == 0) {
        answer = 1;
        return answer;
    }
    if(sosu(b) == 1){
        answer = 2;
    } else {
        answer = 1;
    }
    printf("---%d---", answer);
            
    return answer;
}

//전국 대회 선발 고사
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// rank_len은 배열 rank의 길이입니다.
// attendance_len은 배열 attendance의 길이입니다.
int solution(int rank[], size_t rank_len, bool attendance[], size_t attendance_len) {
    int answer = 0, suu = 0, sum = 0;
    int arr[5] = {0,};
    for(int i=0 ; i < rank_len; i++){
        if(suu == 3) break;
        for(int j=0; j < rank_len; j++){
            if(rank[j] == i+1){
                if(attendance[j] == true){
                    arr[suu] = j;
                    suu++;
                }
            }
        }
    }
    for(int i=0; i<3; i++)
        printf("%d\n", arr[i]);
    
    sum = 10000 * arr[0] + 100 * arr[1] + arr[2];
    
    answer = sum;
    
    return answer;
}

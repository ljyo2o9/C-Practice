#include<stdio.h>
#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE];
int top = -1;

//포화상태 확인
int is_full(void) {
    if(top >= 99){
        return  1;
    } else {
        return  0;
    }
}

//공백상태 확인
int is_empty(void) {
    if(top < 0){
        return  1;
    } else {
        return  0;
    }
}

void push(int n) {
    if(is_full()){
        printf("Stack이 가득 차있습니다");
    } else {
        top++;
        stack[top] = n;
    }
}

int pop(void) {
    int tmp;
    
    if(is_empty()){
        return 0;
    } else {
        tmp = stack[top];
        stack[top] = 0;
        top--;
        return tmp;
    }
}

int main(void) {
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    return 0;
}

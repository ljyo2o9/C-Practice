#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

struct stacks {
    int stack[MAX_SIZE];
    int top;
};

// 스택 초기화
void init_stack(struct stacks *st) {
    st->top = -1;
}

// 스택이 비어있는지 확인
int is_empty(struct stacks *st) {
    return (st->top == -1);
}

// 스택이 꽉 찼는지 확인
int is_full(struct stacks *st) {
    return (st->top == MAX_SIZE - 1);
}

// 스택에 원소 삽입
void push(struct stacks *st, int item) {
    if (is_full(st)) {
        printf("Stack is full.\n");
    } else {
        st->stack[++(st->top)] = item;
    }
}

// 스택에서 원소 제거 및 반환
int pop(struct stacks *st) {
    if (is_empty(st)) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        return st->stack[(st->top)--];
    }
}

// 후위표기식 계산
int calc_postfix(char exp[]) {
    struct stacks st;
    int first, second, value;
    long long int len = strlen(exp);
    char c;

    init_stack(&st);

    for (int i = 0; i < len; i++) {
        c = exp[i];

        if(c >= '0' && c <= '9') push(&st,c-'0');
        else{
            second = pop(&st);
            first = pop(&st) + 0.0;

            switch(c){
                case '+':
                    value = first + second;
                    break;

                case '-':
                    value = first - second;
                    break;

                case '*':
                    value = first * second;
                    break;

                case '/':
                    value = first / second;
                    break;
                default:
                    value = -999999;
                    return printf("식이 잘못되었습니다\n");
            }

            push(&st,value);
        }
    }

    return pop(&st); // 마지막 연산 결과 반환.

}


int main(void) {
    printf("후위표기식은 : 43+52-*2+\n");
    printf("결과값은 %d\n", calc_postfix("43+52-*2+"));

    return 0;
}

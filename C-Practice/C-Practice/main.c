
#include<stdio.h>
#include<string.h>
#define MAX_STACK_SIZE 100

struct stacks {
    char stack[MAX_STACK_SIZE];
    int top;
};

//스택 작성
void init_stacks(struct stacks* st){
    st->top = -1;
}

int is_empty(struct stacks* st){
    return (st->top == -1);
}

int is_full(struct stacks* st){
    return (st->top == MAX_STACK_SIZE - 1);
}

void push(struct stacks* st, int item){
    if(is_full(st)) printf("stacks is full");
    else {
        st->stack[++(st->top)] = item;
    }
}

int pop(struct stacks *st){
    if(is_empty(st)){
        printf("stacks is empty");
        return -99999;
    } else {
        return st->stack[(st->top)--];
    }
}


int is_match(char* c) {
    struct stacks st;
    char ch, open;
    long int length = strlen(c);
    init_stacks(&st);

    for (int i = 0; i < length; i++) {
        ch = c[i];
        //판별코드
        if(ch == '(' || ch == '{' || ch == '[') push(&st, ch);
        else if(ch == ')' || ch == '}' || ch == ']'){
            open = pop(&st);
            printf("%c %c\n", open, ch);
            if((open == '(' && ch == ')') || (open == '{' && ch == '}') || (open == '[' && ch == ']')) continue;
            else return 0;
        }
    }
    //스택이 비었는지 확인
    if (is_empty(&st) == 0) {
        return 0;
    }

    return 1; //괄호 검사가 모두 정상적으로 끝나면 1반환 -> 오류 없음
}

int main(void) {
    char* p = "{A[(i+1)]=0;}";
    if (is_match(p))
        printf("%s 괄호 검사 성공!\n", p);
    else
        printf("%s 괄호 검사 실패!\n", p);

    return 0;
}

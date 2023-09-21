#include<stdio.h>
#include<string.h>
#define MAX_STACK_SIZE 100

struct stacks {
    char stack[MAX_STACK_SIZE];
    int top;
};

void init_stack(struct stacks* s) {
    s->top = -1;
}

//스택과 관련된 함수 모두 작성
int is_full(struct stacks* s){
    return s->top == MAX_STACK_SIZE - 1;
}

int is_empty(struct stacks* s){
    return s->top == -1;
}

void push(struct stacks* s, char c){
    if(is_full(s)) return;
    s->stack[++(s->top)] = c;
}

char pop(struct stacks* s){
    if(is_empty(s)) return 0;
    return s->stack[(s->top)--];
}

char peek(struct stacks* s) {
    if (is_empty(s)){
        return 0;
    }
    else return s->stack[s->top];
}

//연산자 우선순위 결정하는 함수
int rank(char c) {
    if (c == '(' || c == ')')
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else return -1;
}

//중위 -> 후위
void infix_to_postfix(char* s) {
    struct stacks st;
    char ch, c;
    int length = strlen(s);
    init_stack(&st);
    for (int i = 0; i < length; i++) {
        ch = s[i];
        switch (ch){
            case '+':
            case '-':
            case '*':
            case '/':
                while(rank(peek(&st)) >= rank(ch)){
                    c = pop(&st);
                    printf("%c", c);
                }
                push(&st, ch);
                break;
            case '(':
                push(&st, ch);
                break;
            case ')':
                c = pop(&st);
                while(c != '('){
                    printf("%c", c);
                    c = pop(&st);
                }
                break;
            default:
                printf("%c", ch);
        }
    }
    //스택에 남아있는 것들 모두 출력
    while(!is_empty(&st)){
        printf("%c", pop(&st));
    }
}

int main(void) {
    char* s = "(2+3)*4+9";
    printf("중위표기수식 %s\n", s);
    printf("후위표기수식 ");
    infix_to_postfix(s);
    printf("\n");
    return 0;
}

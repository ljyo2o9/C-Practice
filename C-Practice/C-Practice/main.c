#include<stdio.h>
#define MAX_QUEUE_SIZE 5

struct Queue {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
};

void init_queue(struct Queue* q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(struct Queue* q) {
    return q->rear == q->front;
}

int is_full(struct Queue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void print_queue(struct Queue* q) {
    int i = q->front;
    if (!is_empty(q)) {
        while (i != q->rear) {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d | ", q->data[i]);
        }
    }
    printf("\n");
}

void enqueue(struct Queue* q, int item) {
    if (is_full(q)) printf("포화상태\n");
    else {
        if(q->rear != MAX_QUEUE_SIZE - 1) q->data[++q->rear] = item;
        else {
            q->rear = 0;
            q->data[q->rear] = item;
        }
    }
}

int dequeue(struct Queue* q) {
    if (is_empty(q)) {
        printf("공백상태\n");
        return -99999;
    }
    else {
        if(q->front != MAX_QUEUE_SIZE - 1) return q->data[++q->front];
        else {
            q->front = 0;
            return q->data[q->front];
        }
    }
}

int main(void) {
    struct Queue q;
    init_queue(&q);
//    enqueue(&q, 10);
//    printf("%d\n", dequeue(&q));
//    enqueue(&q, 10);
//    printf("%d\n", dequeue(&q));
//    enqueue(&q, 10);
//    printf("%d\n", dequeue(&q));
//    enqueue(&q, 10);
//    printf("%d\n", dequeue(&q));
//    enqueue(&q, 10);
//    printf("%d\n", dequeue(&q));
//    enqueue(&q, 10);
//    printf("%d\n", dequeue(&q));
//    enqueue(&q, 10);
//    printf("%d\n", dequeue(&q));
    
    enqueue(&q, 10);    print_queue(&q);
    enqueue(&q, 20);    print_queue(&q);
    enqueue(&q, 30);    print_queue(&q);
    dequeue(&q);    print_queue(&q);
    dequeue(&q);    print_queue(&q);
    dequeue(&q);    print_queue(&q);
    enqueue(&q, 30);    print_queue(&q);
    
    return 0;
}

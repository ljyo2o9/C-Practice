#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 50

struct Graph {
    int n; //정점의 수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
};

//초기화
void init(struct Graph* g) {
    g->n = 0;
    for (int r = 0; r < MAX_VERTICES; r++) {
        for (int c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

//정점 삽입
void insert_vertex(struct Graph* g, int v) {
    if ((g->n + 1) > MAX_VERTICES) {
        printf("그래프 : 정점 개수 초과\n");
        return;
    }
    g->n++;
}

//간선 삽입
void insert_edge(struct Graph* g, int start, int end) {
    if (g->n - 1 < start || g->n - 1 < end || start == end || start < 0 || end < 0) {//4. 그래프 정점 오류 조건은?
        printf("그래프 : 정점 번호 오류\n");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

//인접 행렬 출력
void print(struct Graph* g) {
    for(int i=0; i<g->n; i++){
        for(int j=0; j<g->n; j++){
            printf("%d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    struct Graph* g;
    g = (struct Graph*)malloc(sizeof(struct Graph));

    init(g);

    for (int i = 0; i < 4; i++) {
        insert_vertex(g, i);
    }

    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    print(g);

    free(g);

    return 0;
}

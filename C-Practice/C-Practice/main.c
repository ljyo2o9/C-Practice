#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50

int visited[MAX_VERTICES]; //정점을 방문했는지를 저장하는 배열

//인접리스트 코드 그대로!

struct Graphnode {
    int vertex;
    struct Graphnode* link;
};

struct Graph {
    int n; //정점의 수
    struct Graphnode* adj_list[MAX_VERTICES];
};

//초기화
void init(struct Graph* g){
    g->n = 0;
    for(int i=0; i<MAX_VERTICES; i++){
        g->adj_list[i] = NULL;
    }
}

//정점 삽입
void insert_vertex(struct Graph* g, int v){
    if(v > MAX_VERTICES){
        printf("error\n");
        return;
    }
    g->n++;
}

//간선 삽입 v를 u의 인접 리스트에 삽입한다. (연결 리스트 맨 앞에 삽입)
void insert_edge(struct Graph* g, int u, int v) {
    struct Graphnode* node;
    struct Graphnode* node_reverse;
    if (u >= g->n || v >= g->n) {
        printf("그래프 : 정점 번호 오류\n");
        return;
    }
    node = (struct Graphnode*)malloc(sizeof(struct Graphnode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
    
    node_reverse = (struct Graphnode*)malloc(sizeof(struct Graphnode));
    node_reverse->vertex = u;
    node_reverse->link = g->adj_list[v];
    g->adj_list[v] = node_reverse;
}

//dfs 출력
void dfs(struct Graph* g, int v) {
    struct Graphnode* p;
    visited[v] = 1;
    printf("정점 %d -> ", v);
    for (p = g->adj_list[v]; p; p = p->link) {
        if (visited[p->vertex] != 1)
            dfs(g, p->vertex);
    }
}

int main(void) {
    struct Graph* g;
    g = (struct Graph*)malloc(sizeof(struct Graph));
    init(g);
    
    for (int i = 0; i < 4; i++)
        insert_vertex(g, i);
    
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);
    
    dfs(g, 0);
    free(g);
    return 0;
}

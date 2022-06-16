#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int jmlVertex;

int jarakTerpendek(int dist[], bool sptSet[]);
void tampilHasil(int dist[]);
void dijkstraAlgo(int graphMatriks[jmlVertex][jmlVertex], int awal);

int main(){
    printf("Masukkan jumlah vertex : "); scanf("%d", &jmlVertex);
    int graphMatriks[jmlVertex][jmlVertex];
    int awal, akhir;

    for(int i = 0; i < jmlVertex; i++){
        for(int j = 0; j < jmlVertex; j++){
            graphMatriks[i][j] = -1;
        }
    }

    printf("Masukkan bobot vertex: \n");
    for(int i = 0; i < jmlVertex; i++){
        for(int j = 0; j < jmlVertex; j++){
            if(i == j){
                graphMatriks[i][j] = 0;
            } else {
                if(graphMatriks[i][j] == -1){
                    printf("%d -> %d : ", i + 1, j + 1); scanf("%d", &graphMatriks[i][j]);
                    graphMatriks[j][i] = graphMatriks[i][j];
                }
            }
        }
    }

    printf("\nGraph Matriks: \n");
    for(int i = 0; i < jmlVertex; i++){
        for(int j = 0; j < jmlVertex; j++){
            printf("%-5d ", graphMatriks[i][j]);
        }
        printf("\n");
    }

    dijkstraAlgo(graphMatriks, 0);

    return 0;
}

int jarakTerpendek(int dist[], bool visited[]){
    int min = INT_MAX, min_index;

    for(int i = 0; i < jmlVertex; i++){
        if(visited[i] == false && dist[i] <= min){
            min = dist[i], min_index = i;
        }
    }
    return min_index;
}

void tampilHasil(int dist[]){
    printf("Jarak vertex dari asal: \n");

    for(int i = 0; i < jmlVertex; i++){
        printf("%d    %d\n", i + 1, dist[i]);
    }
}

void dijkstraAlgo(int graphMatriks[jmlVertex][jmlVertex], int awal){
    int dist[jmlVertex];
    bool visited[jmlVertex];

    for(int i = 0; i < jmlVertex; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[awal] = 0;

    for(int i = 0; i < jmlVertex - 1; i++){
        int u = jarakTerpendek(dist, visited);

        visited[u] = true;

        for(int j = 0; j < jmlVertex; j++){
            if(!visited[j] && graphMatriks[u][j] && dist[u] != INT_MAX && dist[u] + graphMatriks[u][j] < dist[j]){
                dist[j] = dist[u] + graphMatriks[u][j];
            }
        }
    }

    tampilHasil(dist);
}
#include<stdio.h>
#include<stdlib.h>


struct Queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q){
    if(q->r == q->size-1){
        return 1;
    }
        return 0;
}

int isEmpty(struct Queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q , int val){
    if(isFull(q)){
        printf("No element to enqueue\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct Queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("No element to dequeue\n");
        return a;
    }
    else{
        q->f++;
        a = q->arr[q->f];
        return a;
    }
}

int main(){ 
    struct Queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    //BFS Implementation
    int i =1;
    int node;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,0,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    printf("%d " , i);
    visited[i] = 1;
    enqueue(&q , i); //for exploration

    while(!isEmpty(&q))
    {
            node = dequeue(&q);
        for(int j =0 ; j<7 ; j++)
        {
            if( a[node][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
            enqueue(&q , j);
            printf("%d " , j);
            }

        }
    }

   
     return 0;
}
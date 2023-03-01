#include<stdio.h>
#include<stdlib.h>


struct CircularQueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct CircularQueue *q){
    if(q->f == (q->r+1)%q->size){
        return 1;
    }
        return 0;
}

int isEmpty(struct CircularQueue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

void enCircularQueue(struct CircularQueue *q , int val){
    if(isFull(q)){
        printf("No element to enCircularQueue\n");
    }
    else{
       q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
    }
}

int deCircularQueue(struct CircularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("No element to deCircularQueue\n");
        return a;
    }
    else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
        return a;
    }
}

int main(){ 
    struct CircularQueue q;
    q.size = 5;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    printf("isEmpty %d\n" , isEmpty(&q));
    enCircularQueue(&q , 23);
    enCircularQueue(&q , 34);
    enCircularQueue(&q , 22);
    enCircularQueue(&q , 12);
    enCircularQueue(&q , 33);

    int a = deCircularQueue(&q);
    printf("%d\n" , a);
    int b =  deCircularQueue(&q);
    printf("%d\n" , b);
        int c =  deCircularQueue(&q);
    printf("%d\n" , c);
        int d =  deCircularQueue(&q);
    printf("%d\n" , d);
        int e =  deCircularQueue(&q);
    printf("%d\n" , e);
    

    enCircularQueue(&q , 33);
    enCircularQueue(&q , 33);
    enCircularQueue(&q , 33);
    enCircularQueue(&q , 33);
    enCircularQueue(&q , 33);



  
    printf("isFull %d\n" , isFull(&q));



    
     return 0;
}
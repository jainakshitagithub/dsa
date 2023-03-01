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
    q.size = 5;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    printf("isEmpty %d\n" , isEmpty(&q));
    enqueue(&q , 23);
    enqueue(&q , 34);
    enqueue(&q , 22);
    enqueue(&q , 12);
    enqueue(&q , 33);

    int a = dequeue(&q);
    printf("%d\n" , a);
    int b =  dequeue(&q);
    printf("%d\n" , b);
        int c =  dequeue(&q);
    printf("%d\n" , c);
        int d =  dequeue(&q);
    printf("%d\n" , d);
        int e =  dequeue(&q);
    printf("%d\n" , e);
        int f =  dequeue(&q);
    printf("%d\n" , f);

    enqueue(&q , 33);//The condition come here when after dequeuing all the elements
                    //we cannot do the enqueue , thus further go with the concept of circulat queue


  
    printf("isFull %d\n" , isFull(&q));



    
     return 0;
}
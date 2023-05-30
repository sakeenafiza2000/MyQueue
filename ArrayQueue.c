#include <stdio.h> 
#include <stdlib.h>


//DRAWBACKS: 
//1. Cannot reuse spaces of deleted elements
//2. Can only use space once
//3. Queue can be full and empty at the same time
//SOLUTIONS:
//1. Resetting Pointers - reinitialize them to -1 when front == rear (no guarantee of reusing spaces)
//2. Circular queue

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q; 
}; 

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1; 
    q->Q =(int*)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    if(q->rear == q->size-1)
    {
        printf("Queue id full\n");
    }
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1; 

    if(q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    for(int i = q.front+1; i<=q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q; 

    create(&q, 5); 

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    Display(q);

    printf("%d \n",dequeue(&q));
    
    Display(q);

    return 0; 
}
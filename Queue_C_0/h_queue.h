/*
*	作者：silverHugh
*	时间：2015年1月28日
*	内容：队列实现
*	语言：C语言
* */
#include <stdbool.h>
#include <stdio.h>

#define DATASIZE 1024

struct Queue{
    int top;
    int tail;
    int data[DATASIZE];

    int size;
    bool initalled;
};

typedef struct Queue Queue;

void init(Queue* queue);                    //初始化队列
bool enqueue(Queue *queue, int en_data);    //入队一个整型数
bool enqueue_array(Queue *queue,
        int en_data[],int array_size);      //入队一个整型数组
bool dequeue(Queue* queue);                 //出队
void print(Queue* queue);                   //格式化输出队列

/*
* queue         需要操作的队列指针
* */
void init(Queue* queue){
    queue->top=0;
    queue->tail=0;
    queue->size=0;
    queue->initalled=true;
}
/*
*  queue        需要操作的队列指针
*  en_data      需要入队的整型数
* */
bool enqueue(Queue* queue, int en_data){
    //判断队列是否已经初始化，若没有则初始化
    if (!queue->initalled){
        init(queue);
    }
    //入队会导致数据溢出时，入队失败
    if(queue->tail>= DATASIZE){
        return false;
    }
    //入队，tail+1，size+1
    queue->data[queue->tail++]=en_data;
    queue->size++;

    return true;
}
/*
*  queue            需要操作的队列指针
*  en_data          需要入队的整型数组
*  array_size       整型数组的大小
* */
bool enqueue_array(Queue *queue, int en_data[],
        int array_size){
    int i;

    //数组大小值作物，入队失败
    if (array_size<0){
        return false;
    }
    //判断队列是否已经初始化，若没有则初始化
    if (!queue->initalled){
        init(queue);
    }
    //入队会导致数据溢出时，入队失败
    if(queue->tail+array_size> DATASIZE){
        return false;
    }

    for (i = 0; i <array_size; i++) {
        enqueue(queue, en_data[i]);
    }
}
/*
*  queue						需要操作的队列指针
* */
bool dequeue(Queue* queue){
    //如果队列尚未初始化或者队列大小为0，则出队失败
    if((!queue->initalled)||queue->size==0){
        return false;
    }
    //队头top+1，size-1
    queue->top++;
    queue->size--;

    return true;
}
/*
*  queue						需要操作的队列指针
* */
void print(Queue* queue){
    int i;
    int serial_num;

    if(!queue->initalled){
        init(queue);
    }

    printf("Queue Print\n=================\n");
    printf("Queue Size: %d\n-----------------\n",
            queue->size);
    printf("Queue Data:\n");
    if (queue->size==0){
        printf("Data empty.\n");
    }else{
        printf(" No. |\tData\n------------\n");
        for (i=0;i<queue->size;i++){
            serial_num = i+1;
            printf("%4d |\t%d\n",serial_num,
                    queue->data[queue->top+i]);
        }
    }
    printf("=================\nEND\n");
}
/*
* ���ߣ�silverHugh
* ʱ�䣺2015��1��28��
*���ݣ�����ʵ��
* ���ԣ�C����
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

void init(Queue* queue);                                     //��ʼ������
bool enqueue(Queue *queue, int en_data);   //���һ��������
bool enqueue_array(Queue *queue,
        int en_data[],int array_size);               //���һ����������
bool dequeue(Queue* queue);                               //����
void print(Queue* queue);                                   //��ʽ���������

/*
* queue         ��Ҫ�����Ķ���ָ��
* */
void init(Queue* queue){
    queue->top=0;
    queue->tail=0;
    queue->size=0;
    queue->initalled=true;
}
/*
*  queue               ��Ҫ�����Ķ���ָ��
*  en_data          ��Ҫ ��ӵ�������
* */
bool enqueue(Queue* queue, int en_data){
    //�ж϶����Ƿ��Ѿ���ʼ������û�����ʼ��
    if (!queue->initalled){
        init(queue);
    }
    //��ӻᵼ���������ʱ�����ʧ��
    if(queue->tail>= DATASIZE){
        return false;
    }
    //��ӣ�tail+1��size+1
    queue->data[queue->tail++]=en_data;
    queue->size++;

    return true;
}
/*
*  queue               ��Ҫ�����Ķ���ָ��
*  en_data          ��Ҫ ��ӵ���������
*  array_size   ��������Ĵ�С
* */
bool enqueue_array(Queue *queue, int en_data[],
        int array_size){
    int i;

    //�����Сֵ������ʧ��
    if (array_size<0){
        return false;
    }
    //�ж϶����Ƿ��Ѿ���ʼ������û�����ʼ��
    if (!queue->initalled){
        init(queue);
    }
    //��ӻᵼ���������ʱ�����ʧ��
    if(queue->tail+array_size> DATASIZE){
        return false;
    }

    for (i = 0; i <array_size; i++) {
        enqueue(queue, en_data[i]);
    }
}
/*
*  queue               ��Ҫ�����Ķ���ָ��
* */
bool dequeue(Queue* queue){
    //���������δ��ʼ�����߶��д�СΪ0�������ʧ��
    if((!queue->initalled)||queue->size==0){
        return false;
    }
    //��ͷtop+1��size-1
    queue->top++;
    queue->size--;

    return true;
}
/*
*  queue               ��Ҫ�����Ķ���ָ��
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
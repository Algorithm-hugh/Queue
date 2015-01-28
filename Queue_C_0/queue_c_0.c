#include "h_queue.h"
void test();
void test_array();
void test_error();
void main(){
    test();
    test_array();
    test_error();
}

void test(){
    Queue queue;
    enqueue(&queue, 100);
    enqueue(&queue, 200);
    enqueue(&queue, 300);
    enqueue(&queue, 400);
    enqueue(&queue, 500);
    print(&queue);

    dequeue(&queue);
    print(&queue);
}

void test_array(){
    Queue queue;
    int array[16] = {1,2,3,4,5,6,7,8,9,10};

    enqueue_array(&queue, array, 10);
    print(&queue);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    print(&queue);
}

void test_error(){
    Queue queue;
    int array[DATASIZE],i;
    int num=1;

    //在未初始化情况下出列
    if (!dequeue(&queue)){
        printf("（未初始化情况下）出队失败！\n");
    }
    //获得一个大小为队列长度最大值的整型数组
    for ( i = 0; i < DATASIZE; i++) {
        array[i]=i;
    }
    //将这个数组入队，打印队列长度（大小）
    enqueue_array(&queue, array, 1024);
    printf("Queue Size: %d\n",queue.size);

    //在队列充满之后入列一个数
    if(!enqueue(&queue, num)){
        printf("（入队操作会导致数据溢出）入队失败\n");
    }

    //队列中数据全部出列,打印队列长度（大小）
    for (i = queue.size; i >0; i--) {
        dequeue(&queue);
    }
    printf("Queue Size: %d\n",queue.size);

    //数据全部出列后再次执行出列
    if (!dequeue(&queue)){
        printf("（队列中没有数据时出队）出队失败！\n");
    }
}
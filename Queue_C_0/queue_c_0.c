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

    //��δ��ʼ������³���
    if (!dequeue(&queue)){
        printf("��δ��ʼ������£�����ʧ�ܣ�\n");
    }
    //���һ����СΪ���г������ֵ����������
    for ( i = 0; i < DATASIZE; i++) {
        array[i]=i;
    }
    //�����������ӣ���ӡ���г��ȣ���С��
    enqueue_array(&queue, array, 1024);
    printf("Queue Size: %d\n",queue.size);

    //�ڶ��г���֮������һ����
    if(!enqueue(&queue, num)){
        printf("����Ӳ����ᵼ��������������ʧ��\n");
    }

    //����������ȫ������,��ӡ���г��ȣ���С��
    for (i = queue.size; i >0; i--) {
        dequeue(&queue);
    }
    printf("Queue Size: %d\n",queue.size);

    //����ȫ�����к��ٴ�ִ�г���
    if (!dequeue(&queue)){
        printf("��������û������ʱ���ӣ�����ʧ�ܣ�\n");
    }
}
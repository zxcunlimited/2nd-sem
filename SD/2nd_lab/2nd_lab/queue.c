#include <stdio.h>
#include <stdlib.h> //��� ��������� ������ ��� ����� ����
#include "queue.h"

int is_queue_empty(struct Queue* q) {
	return (q->front == NULL); //���� ����� - 1, ����� �������� 0
}

void init_queue(struct Queue* q) {
	q->front = NULL;
	q->rear = NULL;
}

void enqueue(struct Queue* q, double val) {

	struct QueueNode* new_node = malloc(sizeof(struct QueueNode));
	if (!new_node) return; //�������� �� ������ ��������� ������
	new_node->value = val;
	new_node->next = NULL;

	//������������� 2 ������: ������� ����� � new_node - ������ �� �������, � � ������� ��� ������� ���� �� ���� ����, ����� new_node ���������� �� ���

	if (q->rear == NULL) {
		q->front = new_node; //���� ������� ���� �����, �� new_node - ������ � ��������� �� �������
		q->rear = new_node;
	}
	else {
		q->rear->next = new_node; //�������, ������� � ����� ������� ������ ��������� �� ����� ������� ��� �� ���������� � �������
		q->rear = new_node; //rear ������ ��������� �� ���������, ������ ��� ��������� �������
	}

}

double dequeue(struct Queue* q) {
	//������ �������� - ��� ������� ���� ������� �����
	if (q->front == NULL) {
		return 0.0;
	}
	//����� - ���� ������� �� �����, �� ��� ����� 1) ������� �������� 2) ���������� �������, ������� ����� front �� front 3) ���� ������� ����� ������, �������� 4) ������� ����� ������ ������� � �������
	
	//1)
	double val = q->front->value;

	//2) ��������� temp ������ �� ������ �������, ����� ����� ��������� �� ����� ������
	struct QueueNode* temp = q->front;
	q->front = q->front->next; //��� ��� �� ������� �� ������� � ���� front -> a -> b -> c <- rear, �� ����� �������, ������� ����� ������� �������� ��� �� ����, ��� ���� �������� ��� ���� ���������� ����� next
	
	//3) ���� ������� ��������, �� �� �� ���� ��������� �������������
	if (q->front == NULL) q->rear = NULL;

	//4) 
	free(temp);
	return val;
}

void free_queue(struct Queue* q) {
	while (!(is_queue_empty(q))) {
		dequeue(q); 
	}
}
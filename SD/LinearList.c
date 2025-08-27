#include <stdio.h>
#include <stdlib.h>

//node realization
struct StackNode
{
	int value;
	struct StackNode* next;
};
//stack realization
struct Stack
{
	struct StackNode* top;
};
//stack initializing
void init_stack(struct Stack* s) {
	s->top = NULL;
}
//useful check 
int is_stack_empty(struct Stack* s) {
	if (s->top == NULL) return 1;
	return 0;
}

//pushing value in the stack
void push_to_stack(struct Stack* s, int value) {
//to push a value in the stack, we need to create a node in it, using malloc to create a place in memory for it
	struct StackNode* Node = (struct StackNode*)malloc(sizeof(struct StackNode));
	Node->value = value;
	Node->next = s->top;
//explanation: if we push a value in the stack, the top value becomes the NEXT to new node, and it becomes the TOP of our stack
	s->top = Node;
}

//taking a value from stack top
int pop_from_stack(struct Stack* s) {
//to pop a value from the stack at first we need to check it for emptiness, if its empty, we return error, if its not we do whar we need
	if (!(is_stack_empty(s))) {
//if stack isnt empty, we will use temp to get a value and free memory
		struct StackNode* temp = s->top;
		int value = temp->value;
		s->top = temp->next;
		free(temp);
		return value;
	}
	else {
		printf("Error! Stack is empty!");
		return -1;
	}
}

//function to free stack (for example after finishing the code)
void free_stack(struct Stack* s) {
	while (!(is_stack_empty(s))) {
		pop_from_stack(s);
	}
}

int main() {
	printf("Hello again!\n");
	struct Stack s;
	init_stack(&s);
	printf("is stack empty? answer:%d\n", is_stack_empty(&s));
	push_to_stack(&s, 30);
	printf("is stack empty? answer:%d\n", is_stack_empty(&s));
	printf("value on the top of the stack:%d\n", s.top->value);
	push_to_stack(&s, 50);
	printf("value on the top of the stack:%d\n", s.top->value);
	printf("let's pop value from the stack and we got:%d\n", pop_from_stack(&s));
	free_stack(&s);
	printf("is stack empty? answer:%d", is_stack_empty(&s));
}
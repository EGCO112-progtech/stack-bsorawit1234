
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;

void push(StackPtr s, char value) {
	NodePtr new_node = (NodePtr)malloc(sizeof(Node));
	if(new_node) {
		new_node->data = value;
		new_node->nextPtr = s->top;

		s->top = new_node;
		s->size += 1;
	}
}

char pop(StackPtr s) {
	NodePtr temp = s->top;
	if(temp == NULL) return NULL;

	char value = temp->data;

	s->top = s->top->nextPtr;
	free(temp);
	s->size -= 1;

	return value;
}

void pop_all(StackPtr s) {
	NodePtr temp;
	while(s->top != NULL) {
		temp = s->top;
		s->top = s->top->nextPtr;
		s->size -= 1;
		free(temp);
	}
}

void print_stack(Stack s) {
	NodePtr temp = s.top;

	printf("\n");
	while(temp != NULL) {
		printf("%c -> ", temp->data);
		temp = temp->nextPtr;
	}
	printf("NULL");
}

int isEmpty(Stack s) {
	return s.top == NULL;
}

char *isBalance(StackPtr s, char *str) {
	for(int i = 0; i < strlen(str); i++) {
		if(str[i] == '{' || str[i] == '[' || str[i] == '(') {
			push(s, str[i]);
		} else if(str[i] == '}' || str[i] == ']' || str[i] == ')') {
			if(isEmpty(*s)) {
				return "incorrect: too many closed parentheses";
			} else {
				char temp = pop(s);
				if(str[i] == '}' && temp != '{') {
					return "incorrect: mismatch";
				} else if(str[i] == ']' && temp != '[') {
					return "incorrect: mismatch";
				} else if(str[i] == ')' && temp != '(') {
					return "incorrect: mismatch";
				}
			}
		}
	}

	if(isEmpty(*s)) {
		return "correct";
	} else {
		return "incorrect: too many open parentheses";
	}
}

#endif

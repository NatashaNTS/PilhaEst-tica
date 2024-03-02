#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
	int items[MAX_SIZE];
	int top;
}Stack;

void init(Stack *stack){
	stack->top=-1;
}

int isEmpty(Stack *stack){
	return stack->top == -1;
}

int isFull(Stack *stack){
	return stack->top == MAX_SIZE -1;
}
	
	void push(Stack *stack, int value){
	if(isFull(stack)){
		printf("Erro: Pilha cheia.\n");
	}else{
		stack ->items[++stack->top]=value;
		printf("Valor inserido: %d \n",value);
	}
}

int pop(Stack *stack){
	if (isEmpty(stack)){
		printf("Erro: Pilha vazia.\n");
		return -1;
	}else {
		printf("Valor removido: %d\n",stack->items[stack->top]);
		return stack->items[stack->top--];
	}
}

void display(Stack *stack){
	if (isEmpty(stack)){
		printf("Erro: Pilha vazia.\n");
	}else{
		printf("Elementos da pilha:\n");
	for (int i=stack->top; i>=0;i--){
		printf("%d\n", stack->items[i]);
		}
	}
}

int main(){
	Stack stack;
	init(&stack);
	int choice,value;
	
	do {
		printf("\n1.Inserir\n2.Remover\n3.Exibir\n4.Sair\nEscolha uma opção: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Digite o valor a ser inserido: ");
				scanf("%d",&value);
				push(&stack, value);
				break;
			case 2:
				pop(&stack);
				break;
			case 3:
				display(&stack);
				break;
			case 4:
				printf("Saindo...\n");
				break;
			default:
				printf("Opção inválida.\n");
		}
	} while (choice!= 4);
	return 0;
}

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 20
struct stack
{
	int data[SIZE];
	int top;
};
typedef struct stack STACK;

void push(STACK *s, int n)
{
	if(s -> top == SIZE -1)
	{
		printf("Full");
	}
	else
	{
		s->data[++(s -> top)] = n;
	}
}

int pop(STACK *s)
{
	if(s -> top == -1 )
	{
		printf("nothing is there");
		return -1;
	}
	else
	{
		return s -> data [(s -> top)--];
	}
}

int preced(char x)
{
	switch(x)
	{
		case '$':
		return 5;
		case '/':
		case '*':
		return 3;
		case '+':
		case '-':
		return 1;
	}
}

void infixtopostifix(STACK *s,char infix[15])
{
	int i; 
	int j = 0;
	char symbol, postfix[15], temp;
	for(i = 0; infix[i] !='\0'; i++)
	{
		symbol = infix[i];
		if(isalnum(symbol))
		{
			postfix[j++] = symbol;
		}
		else
		{
			switch(symbol)
			{
			//	printf("Test!");
				case '(':
				push(s,symbol);
				break;
				case ')':
				temp = pop(s);
				while(temp != '(')
				{
					postfix[j++] = temp;
					temp = pop(s);
				}
				break;
				case '+':
				case '-':
				case '*':
				case '/':
				case '$':
				if((s -> top == -1) || (s-> data[(s-> top)] == '('))
				{
					push(s, symbol);
				}
				else
				{
					while(preced(s -> data[s->top])>= preced(symbol) && (s -> top != -1)&& (s-> data [s -> top] != '('))
					{
						postfix[j++] = pop(s);
						push(s, symbol);
					}
					
				}
				break;
				default:
				printf("Invalid expression");
				//exit(0);
				
			}
				while(s -> top != -1)
		{
			postfix[j++] = pop(s);
			postfix[j] = '\0';
			printf("\nThe postfix expression is %s", postfix );
		}
		
		}
		
	}
	
}

int main()
{
	STACK s1; 
	char infixa[15];
	s1.top = -1;
	printf("Please enter your infix expression\n");
	scanf("%s", infixa);
	infixtopostifix(&s1, infixa);
	return 0;

}
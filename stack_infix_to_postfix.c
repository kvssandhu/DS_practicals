// Exp 12 :  To convert infix to postfix using stack

// Date 11th October


/*

Test Cases :

Enter Infix expression : A+(B*C-(D/E^F)*G)*H
Postfix Expression: ABC*DEF^/G*-H*+

Enter Infix expression : (3^2*5)/(3*2-3)+5
Postfix Expression: 32^5*32*3-/5+

*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stack[100], infix_expression[100], postfix_expression[100], x;
int top=-1, max_size=100, item, ch, i;

int main()
{
    int i=0,j=0;
    printf("\n Enter the infix expression : \t"); // Input Infix Expression
    scanf("%s", infix_expression);

    push('('); // Add '(' to the stack
    strcat(infix_expression,")"); // Add ')' to the end of infix expression

    while(infix_expression[i] != '\0' ){  //loop for each character of infix expression

        if( infix_expression[i] == '(') { push(infix_expression[i]); }

        else if ( isdigit(infix_expression[i]) || isalpha(infix_expression[i]) ) {
                    // if the character is operand
                    postfix_expression[j] = infix_expression[i];
                    j++;

        }


        else if ( is_operator(infix_expression[i]) == 1 ) {
            // if the character is operator

            x = pop();

            while ( is_operator(x) == 1 && precedence(x) >= precedence(infix_expression[i])) {
                postfix_expression[j]=x;
                j++;
                x=pop();
            }
            push(x);

            push(infix_expression[i]);
        }


        else if ( infix_expression[i] == ')' ){
                x = pop();
                while(x != '(') {
                    postfix_expression[j] =x ;
                    j++;
                    x = pop();
                }


        }


        // Call this function to display status of conversion line by line
        //display_iteration_by_iteration(i);
        i++;

    }

    printf("\n Postfix Expression is : \t ");
    display_postfix_exp(i);

    return 0;
}

int push(item)
{

    if (top == max_size )
    {
        printf("\n Overflow Condition \n");
        return 0;
    }

    top = top + 1;
    stack[top] = item;

    return 0;
}


int pop()
{

    if (top == -1)
    {
        printf("\n Underflow \n");
        return 0;
    }
    item = stack[top];
    top = top-1;
    return item;
}

int display_stack()
{
    if (top == -1)
    {
        printf("\n Stack is Empty :  \n");
        return 0;
    }

    printf("\n Stack is : \t ");
    for(i=0; i<=top; i++)
    {
        printf("\t %c", stack[i]);
    }

    return 0;
}

int is_operator(symbol){
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int precedence(symbol){


	if(symbol == '^') // highest precedence
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);  //lowest precedence
	}
}

int display_postfix_exp(limit){
    int i=0;

    for(i=0; i<=limit; i++){
        printf("%c", postfix_expression[i]);
    }
    return 0;
}

void display_iteration_by_iteration(i){
        printf("\n Iteration No : %d", i);
        printf("\n Expression : %c", infix_expression[i]);
        display_stack();
        printf("\n Postfix Expression : ");
        display_postfix_exp(i);
        printf("\n ============================= \n ");
}

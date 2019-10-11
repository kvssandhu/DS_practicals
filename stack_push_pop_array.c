// Aim : to perform push and pop in stack using array

// Date 4th Oct
#include<stdio.h>

int main(){
int stack[20], top=-1, max_size=15, item, ch, i;

while (ch!=4){

        printf("\n \n Select the operation you want to perform : \n");
        printf("\n 1. Push \n 2. Pop \n 3.Display \n 4. Exit \n \n");
        scanf("%d", &ch);


        switch(ch){

            case 1 : printf("\n Enter the item you want to push: \t ");
                     scanf("%d", &item);
                     // Push Operation Starts

                     if (top == max_size ) {
                            printf("\n Overflow Condition \n");
                            return 0;
                        }

                     top = top + 1;
                     stack[top] = item;

                     // Push Operation Completed


                     break;

            case 2 : // Pop Operation Starts

                    if (top == -1) {
                        printf("\n Underflow \n");
                        return 0;
                    }
                    item = stack[top];
                    top = top-1;

                    // Push Operation Completed

                    break;

            case 3 :
                    if (top == -1) {
                        printf("\n Stack is Empty :  \n");
                        return 0;
                    }

                    printf("\n Stack is : \t ");
                    for(i=0; i<=top; i++){
                        printf("\t %d", stack[i]);
                    }

                     break;

            case 4 : exit(0);

        };

}

return 0;
}

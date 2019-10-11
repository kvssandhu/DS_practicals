// Aim : To implement sparse matrix using array

// Date : 4th October

#include<stdio.h>

int main(){

int m,n,t, i,j, q, A[50][50], B[50][50];

printf("Enter the number of rows , columns and non-zero values : \n ");
scanf("%d%d%d", &m, &n, &t);

printf("Enter the elements row-wise \n");
for(i=0;i<m;i++){
    for(j=0;j<n;j++){
                        scanf("%d",&A[i][j]);
    }
}

B[0][0]=m;B[0][1]=n; B[0][2]=t;

q=1;

for(i=0;i<m;i++){
    for(j=0;j<n;j++){

        if(A[i][j]!=0){ B[q][0] = i ;
                        B[q][1] = j ;
                        B[q][2] = A[i][j];
                        q++;
                      }


  }
}



//Print Matrix B
for(i=0;i<t+1;i++){
printf("\n");
    for(j=0;j<3;j++){
                        printf("%d \t", B[i][j]);
    }
}

return 0;
}

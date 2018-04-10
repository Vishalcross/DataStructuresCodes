
#include<stdio.h>
int n;
void strassen(int size,int a[][size], int b[][size], int c[][size]) {
int p1[size/2][size/2], p2[size/2][size/2], p3[size/2][size/2], p4[size/2][size/2], p5[size/2][size/2], p6[size/2][size/2], p7[size/2][size/2];
int temp1[size/2][size/2], temp2[size/2][size/2];
int  i, j;

//As in Strassan's matrix the order of matrix should be power of 2

if(size >=2){
	//To calculate part1 i.e. p1=(A00+A11)*(B00+B11)
    for(i=0;i<size/2;i++){
	for(j=0;j<size/2;j++){

	  temp1[i][j]=a[i][j]+a[i+size/2][j+size/2];//half sub part of p1
	}
}
	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){

		temp2[i][j]=b[i][j]+b[i+size/2][j+size/2];//Second sub part of p1
	}
}
//n =size/2;
strassen(size/2,temp1, temp2, p1);

	// To Calculate Part2 i.e. p2=(A10+A11)*B00

	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		temp1[i][j]=a[i+size/2][j]+a[i+size/2][j+size/2];
	}
}

	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		temp2[i][j]=b[i][j];
	}
}
//n =size/2;
strassen(size/2,temp1, temp2, p2);

	// To Calculate Part3 i.e. p3=A00*(B01-B11)

	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		temp1[i][j]=a[i][j];
	}
}
	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		temp2[i][j]=b[i][j+size/2]-b[i+size/2][j+size/2];
	}
}
//n=size/2;
strassen(size/2,temp1, temp2, p3);

		// To Calculate Part4 i.e. p4=A11*(B10-B00)

	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		temp1[i][j]=a[i+size/2][j+size/2];
	}
}
	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		temp2[i][j]=b[i+size/2][j]-b[i][j];
	}
}
//n=size/2;
strassen(size/2,temp1, temp2, p4);

	// To Calculate Part5 i.e. p5=(A00+A01)*B11

	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		temp1[i][j]=a[i][j]+a[i][j+size/2];
	}
}
	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		temp2[i][j]=b[i+size/2][j+size/2];
	}
}
//n=size/2;
strassen(size/2,temp1, temp2, p5);

	// To Calculate Part6 i.e. p6=(A10-A00)*(B00+B01)

for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		temp1[i][j]=a[i+size/2][j]-a[i][j];
	}
}
	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		temp2[i][j]=b[i][j]+b[i][j+size/2];
	}
}
//n=size/2;
strassen(size/2,temp1, temp2, p6);

		// To Calculate Part7 i.e. p7=(A01-A11)*(B10+B11)

	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		temp1[i][j]=a[i][j+size/2]-a[i+size/2][j+size/2];
	}
}
	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		temp2[i][j]=b[i+size/2][j]+b[i+size/2][j+size/2];
	}
}
//n=size/2;
strassen(size/2,temp1, temp2, p7);

//these value p1.....p7 are put in to following formula to get actual result here as product in matrix c

	//To Calculate C11=p1+p4-p5+p7

	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		c[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];
	}
}
	//To Calculate C12=p3+p5

	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		c[i][j+size/2] = p3[i][j] + p5[i][j];
	}
}
	//To Calculate C21=p2+p4

	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		c[i+size/2][j] = p2[i][j] + p4[i][j];
	}
}
	//To Calculate C22=p1+p3-p2+p6

	for(i=0;i<size/2;i++){
		for(j=0;j<size/2;j++){
		c[i+size/2][j+size/2] = p1[i][j] + p3[i][j] - p2[i][j] + p6[i][j];
	}
}
}
else if(size==1)
{
c[0][0]=a[0][0]*b[0][0];
  }
}
int main() {

	int i, j, temp;

	printf("Enter the size of nxn matrix:\n");

	scanf("%d", &temp);

	//temp = n;

	if(temp <= 0)

	return 0;



int a[n][n], b[n][n], c[n][n];

printf("Enter matrix a:\n"); //accept inputs for a and b from the user

	for(i = 0; i < temp; i++)
          {
         	for(j = 0; j < temp; j++)
                  {
			scanf("%d", &a[i][j]);
                  }
          }


	printf("\nEnter matrix b:\n");

	for(i = 0; i < temp; i++)
       {

   	  for(j = 0; j < temp; j++)
           {
         	 scanf("%d", &b[i][j]);
           }

      }


	printf("Matrix a:\n"); //printing the actual matrices for strassen's multiplication

	for(i = 0; i < temp; i++)
        {
	   for(j = 0; j < temp; j++)
            {

	     printf("%d ", a[i][j]);
             }

	   printf("\n");
        }


	printf("\nMatrix b:\n");

	for(i = 0; i < temp; i++)
         {
           for(j = 0; j < temp; j++)
            {
		printf("%d ", b[i][j]);
             }

	 printf("\n");
       }


	strassen(temp,a, b, c);

	printf("\nMatrix c is:\n");

	for(i = 0; i < temp; i++)
        {
	for(j = 0; j < temp; j++)
         {
         	printf("%d ", c[i][j]);
  	}
	printf("\n");
  }

return 0;
}

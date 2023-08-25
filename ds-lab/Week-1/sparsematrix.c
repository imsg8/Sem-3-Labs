#include<stdio.h>
int mat[10][10];
int i, j, flag1=0, flag2=0;
int testmat(mat[10][10], int size);
{
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
		{
			if(mat[i][j]==0)
				flag1+=1;
			else flag2+=1;
		}
	if(flag1>flag2)
		return printf("Sparse matrix \n");
	else return printf("Not a Sparse Matrix \n")
}
int main(){
	int testmat(mat[10][10], int size);
	printf("Enter the size of matrix - ");
	scanf("%d",&size);
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	testmat(mat[10][10], size);
	return 0;
}
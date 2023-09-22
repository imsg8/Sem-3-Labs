#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int val;
	char *sub;
} mark;

mark read_mark(){
	int val;
	char sub[20];
	printf("Enter the marks and subject: ");
	scanf("%d %s", &val, sub);

	mark *m = (mark *)malloc(sizeof(mark));
	m->val = val;
	m->sub = &sub[0];

	return *m;
}

int main(){

	printf("Enter the number of students: ");
	int n;
	scanf("%d", &n);

	mark **m = (mark **)malloc(n * sizeof(mark*));
	int *sub_count = (int *)malloc(n * sizeof(int));
	for (int t = 0; t < n; t++){
		m[t] = (mark *)malloc(sizeof(mark)*10);
		printf("\nEnter the number of subjects: ");
		scanf("%d", &sub_count[t]);
		for (int r = 0; r < sub_count[t]; r++){
		m[t][r] = read_mark();
		}
	}

	for (int t = 0; t < n; t++){
		int max = 0;
		char *sub = (char *)malloc(sizeof(char)*20);;
		for (int r = 0; r < sub_count[t]; r++){
			if (m[t][r].val > max){
				max = m[t][r].val;
			}
		}printf("student %d:- %d\n", t+1, max);
	}

	return 0;
}
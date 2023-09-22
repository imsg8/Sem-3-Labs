#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct PHONE{
    int no;
    char* name;
};
void addcontact(struct PHONE *ph){
    printf("\nEnter the number of the person - ");
    scanf("%d",&(ph->no));
    printf("\nEnter the name of the person - ");
    scanf("%s",(ph->name));
}
long find(struct PHONE *ph, int n, char str[]){
    long f = -1;
    for(int i = 0; i < n; i++){
        if(strcmp(ph[i].name, str)==0){
            f = ph[i].no;
            break;
        }
    }
    return f;
}
void resize(struct PHONE *ph, int n){
    ph = (struct PHONE *) realloc (ph,n);
    ph[n-1].no = (char *)malloc(10*sizeof(char));
    printf("Enter name - ");
    scanf("%s",&(ph[n-1].name));
    printf("Enter new number:\n");
    scanf("%ld", &ph[n-1].no);
}
int main(){
    int n;
    struct PHONE *ph;
    printf("Enter number of contacts you want to store - ");
    scanf("%d",&n);
    ph = (struct PHONE * ) malloc (n * sizeof(struct PHONE));
    for(int i = 0; i < n; i++){
        ph[i].name = (char * ) malloc (n * sizeof(char));
        addcontact(&ph[i]);
    }
    printf("\n\n");
    printf("Enter name to find - ");
    char name[10];
    scanf("%s",&name);
    long f = find(ph,n,name);
    if (f == -1){
        printf("Not found !\n");
        resize(ph, ++n);
    }
    else{
        printf("Number is %ld",f);
    }
    for(int i = 0; i < n; i++){
        free(ph);
    }
}
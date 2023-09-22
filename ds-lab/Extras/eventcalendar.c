#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct EVENT{
    int date;
    int month;
    char* event;
};

// function to add an event
void addevent(struct EVENT *eve){
    printf("Enter event - ");
    scanf("%s",&eve->event);
    printf("Enter date of the event - ");
    scanf("%d",&eve->date);
    printf("Enter month of the event - ");
    scanf("%d",&eve->month);
}

//modify yet unused
/* void modifyeve(struct EVENT *eve){
    printf("Enter new event - ");
    scanf("%s",&eve->event);
    printf("Enter new date of the event - ");
    scanf("%d",&eve->date);
    printf("Enter new month of the event - ");
    scanf("%d",&eve->month);
} */


void dispevent(struct EVENT *eve, int max){
    for(int i=0; i<max; i++){
    printf("Event is %s, on %d in the month of %d",eve->event,eve->date, eve->month);
    }
}

// spacing to beautify and make it east to navigate
// main functon starts

int main(){
    int max, choice, newsize;
    struct EVENT *eve;
    printf("Enter maximum number of events - ");
    scanf("%d",&max);
    if(max == 0 | max == 1){
        printf("Enter a bigger number!");
        return 1;
    }
    eve = (struct EVENT *) malloc (max * sizeof(struct EVENT));

    for (int j=0 ;j<max ;j++){
        addevent(&eve[j]);
    }

    printf("1. add event \n2. Display event\nChoice : ");
    scanf("%d",&choice); // asking user what to do, add or display events

    if (choice == 1){
        printf("Enter number of events you want to add - ");
        scanf("%d",&newsize);
        realloc (eve , newsize); //reallocate memory to adjust more events
        for (int i = 0; i < newsize; i++){
            addevent(&eve[i]);
        }
        printf("Displaying event : ");
        int new = newsize + max;
        for (int i = 0; i < new; i++){
            dispevent(&eve[i], new);
        }
    } // array to store moer events
    if (choice == 2){
        for(int j=0; j<newsize; j++){
            dispevent(&eve[j],max);
        }
    } // function to display events stored in structure
    return 0;
}
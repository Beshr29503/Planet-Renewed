//Ibrahim Mohamed Nabil Beshr
//01201117873_Task1_2.c
//14-8-2023
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int countdown,second;
    //Prompt user to enter a number to start countdown from
    printf("Please Enter Number To Start Countdown From: ");
    scanf("%d",&countdown);
    for(second=countdown;second>0;second--)
    {
        printf("%d\n",second);
        //delay of 1 second
        sleep(1);
    }
    printf("Blast off to the moon!");
    return 0;
}

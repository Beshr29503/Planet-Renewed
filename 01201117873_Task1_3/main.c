//Ibrahim Mohamed Nabil Beshr
//01201117873_Task1_3.c
//14-8-2023
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to hold task information
typedef struct {
    int id;
    char *description;
}task;

int main()
{
    int option = 0,index = 0,id,i;
    char *str;
    //Array of task to hold tasks added
    task t[100];
    printf("1.Add Task\n2.View Tasks\n3.Remove Task\n4.Mark Task As Completed\n5.Exit\n");
    while(option != 5)
    {
        printf("Select an Option: ");
        scanf("%d",&option);
        if(option == 1)
        {
            printf("Task Description: ");
            getchar();
            //Dynamic Memory allocation to prepare for storing task description in memory as it is of unknown size still
            t[index].description = malloc(1024*sizeof(char));
            gets(t[index].description);
            strcat(t[index].description," (incomplete)");
            //Dynamic Memory reallocation to store task description in memory with its exact size as it became known
            t[index].description = realloc(t[index].description,strlen(t[index].description)+1);
            t[index].id = index+1;
            printf("Task Added Successfully!\n");
            index++;
        }
        else if(option == 2)
        {
            printf("Current Tasks:\n");
            for(i=0;i<index;i++)
            {
                printf("Task ID: %d\n",t[i].id);
                printf("Task Description: %s\n",t[i].description);
            }
        }
        else if(option == 3)
        {
            printf("Enter Task ID To Remove: ");
            scanf("%d",&id);
            for(i=id-1;i<index-1;i++)
            {
                //Removing task by shifting and overwriting it then remove last task
                t[i].id = t[i+1].id-1;
                strcpy(t[i].description,t[i+1].description);
            }
            //Remove Last Task as it will be duplicated
            index--;
            printf("Task Removed Successfully!\n");
        }
        else if(option == 4)
        {
            printf("Enter Task ID To Mark As Completed: ");
            scanf("%d",&id);
            str = malloc(1024*sizeof(char));
            //Remove (incomplete) from end of task description
            for(i=0;i<strlen(t[id-1].description)-strlen(" (incomplete)");i++)
            {
                str[i] = t[id-1].description[i];
            }
            str = realloc(str,strlen(str)+1);
            //Add (complete) to end of task description
            strcpy(t[id-1].description,strcat(str," (complete)"));
            printf("Task Marked As Complete Successfully!\n");
        }
        else if(option == 5)
        {
            printf("Exiting Minions Task Manager. Have a Great Day!");
        }
    }
    return 0;
}

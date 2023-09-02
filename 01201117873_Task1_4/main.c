//Ibrahim Mohamed Nabil Beshr
//01201117873_Task1_4.c
//14-8-2023
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    //Variable that holds Average of each reading
    float average;
    float mpu6050[10] = {0.0,11.68,18.95,23.56,25.72,25.38,22.65,18.01,10.14,-0.26};
    float bno55[10] = {0.0,9.49,16.36,21.2,23.16,22.8,19.5,14.85,6.79,-2.69};
    //Array that holds Average readings according to approach used
    float result[10];
    printf("1.Fair:\n");
    //Approach 1 (Fair)
    for(i=0;i<10;i++)
    {
        //Method:(Reading_1+Reading_2)/2
        average = (mpu6050[i]+bno55[i])/2.0;
        result[i] = average;
        //To insert a comma after each reading except the last reading
        if(i != 9)
            printf("%.2f,",result[i]);
        else
            printf("%.2f\n",result[i]);
    }
    printf("2.Good:\n");
    //Approach 2 (Good)
    for(i=0;i<10;i++)
    {
        //Method: ((Reading_1*Accuracy_1)+(Reading_2*Accuracy_2))/(Accuracy_1+Accuracy_2)
        average = ((mpu6050[i]*0.78)+(bno55[i]*0.92))/(0.78+0.92);
        result[i] = average;
        //To insert a comma after each reading except the last reading
        if(i != 9)
            printf("%.2f,",result[i]);
        else
            printf("%.2f\n",result[i]);
    }
    printf("3.Hero:\n");
    //Approach 3 (Hero)
    float kalman_gain;
    kalman_gain = (0.08)/(0.22+0.08);
    for(i=0;i<10;i++)
    {
        //Method: Reading_highaccuracy + kalman_gain*(Reading_lowaccuracy-Reading_highaccuracy)
        average = bno55[i] + kalman_gain*(mpu6050[i]-bno55[i]);
        result[i] = average;
        //To insert a comma after each reading except the last reading
        if(i != 9)
            printf("%.2f,",result[i]);
        else
            printf("%.2f\n",result[i]);
    }
    return 0;
}

#include <stdio.h>

int main()
{
    int nn[3][12],n1_index = 0,n2_index = 0,n3_index = 0;
    int n[3] = {0};
    for(int i=0; i<12; i++)
    {
        int input;
        scanf("%d",&input);
        if(input >= 2000 && input <= 3000)
        {
            nn[0][n1_index] = input;
            n[0]++;
            n1_index++;
        } 
        else if(input > 3000 && input <= 4000)
        {
            nn[1][n2_index] = input;
            n[1]++;
            n2_index++;
        } 
        if(input > 4000 && input <= 5000)
        {
            nn[2][n3_index] = input;
            n[2]++;
            n3_index++;
        } 
    }
    for(int i=0; i<3; i++)
    {
        printf("group%d\t",i+1);
        for(int j=0; j<n[i]; j++)
        {
            printf("%d\t",nn[i][j]);
        }
        printf("people'snumber = %d\n",n[i]);
    }
    return 0;
}

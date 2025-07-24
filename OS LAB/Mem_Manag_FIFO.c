#include<stdio.h>

int main()
{
    int i, j, k, n, no, ref_string[50], frame[10], avail, fcount=0, hcount=0;

    printf("Enter the number of pages : ");
    scanf("%d", &n);

    printf("Enter the Page Numbers : ");
    for(i=1; i<=n; i++)
    {
        scanf("%d", &ref_string[i]);
    } 

    printf("Enter the Number of Frames : ");
    scanf("%d", &no);

    for(i=0; i<no; i++)
    {
        frame[i] = -1;  // initialising all frames to -1
    }

    j=0;
    printf("\nReference_String   \tPage_Frames \tHit/Faults\n");

    for(i=1; i<=n; i++)
    {
        printf("\t%d\t    ", ref_string[i]);

        avail = 0;
        for(k=0; k<no; k++)
        {
            if(ref_string[i] == frame[k])
            {
                hcount++;
                avail = 1;

                for(k=0; k<no; k++)
                {
                    printf(" %d\t", frame[k]);
                }
                printf("   H");
            }
        }

        if(avail == 0)
        {
            frame[j] = ref_string[i];
            j = (j+1) % no;
            fcount++;

            for(k=0; k<no; k++)
            {
                printf(" %d\t", frame[k]);
            }
            printf("   F");
        }
        printf("\n");
    }

    printf("\nNumber of Page Faults are %d", fcount);
    printf("\nNumber of Hit Counts are %d", hcount);
    return 0;
}
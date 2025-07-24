#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, j, k, n, no,max, pos, temp[30], ref_string[30], hcount=0, avail;
    int frames[10], fcount=0;

    printf("Enter the Number of Pages : ");
    scanf("%d", &n);
    printf("Enter the Number of Frames : ");
    scanf("%d", &no);
    printf("Enter the Page Numbers : ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &ref_string[i]);
    }

    printf("\n Reference String\t\t Page Frames\t\t Hit/Faults\n");

    for(i=0; i<n; i++)
    {
        printf("\t%d\t\t", ref_string[i]);
        avail = 0;

        for(j=0; j<no; j++)
        {
            if(frames[j] == ref_string[i])
            {
                hcount++;
                avail = 1;

                for(k=0; k<no; k++)
                {
                    printf("%d\t", frames[k]);
                }
                printf("\tH");
            }
        }

        if(avail == 0)
        {
            fcount++;

            if(i < no)
            {
                frames[i] = ref_string[i];
            }
            else
            {
                for(j=0; j<no; j++)
                {
                    temp[j] = -1;
                    for(k=i+1; k<n; k++)
                    {
                        if(frames[j] == ref_string[k])
                        {
                            temp[j] = k;
                            break;
                        }
                    }
                }

                avail = 0;
                for(j=0; j<no; j++)
                {
                    if(temp[j] == -1)
                    {
                        pos = j;
                        avail = 1;
                    }
                }

                if(avail == 0)
                {
                    max = temp[0];
                    pos = 0;
                    for(j=1; j<no; j++)
                    {
                        if(temp[j] > max)
                        {
                            max = temp[j];
                            pos = j;
                        }
                    }   
                }

                frames[pos] = ref_string[i];
                for(k=0; k<no; k++)
                {
                    printf("%d\t", frames[k]);
                }
                printf("\tF");
            }

        }
        printf("\n");
    }
    printf("Number of page faults: %d\n", fcount);
    printf("Number of Hit Counts are %d",hcount);

    return 0;
}
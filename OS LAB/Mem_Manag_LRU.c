#include <stdio.h>

int pageFaults(int pages[], int n, int capacity)
{
    int frames[100];
    int indexes[100];

    for (int i = 0; i < capacity; i++)
    {
        frames[i] = -1;
        indexes[i] = -1;
    }

    int page_faults = 0;

    for (int i = 0; i < n; i++)
    {
        int page = pages[i];
        int page_found = 0;

        for (int j = 0; j < capacity; j++)
        {
            if (frames[j] == page)
            {
                indexes[j] = i;
                page_found = 1;
                break;
            }
        }

        if (page_found == 0)
        {
            int lru = indexes[0];
            int lru_index = 0;

            for (int j = 1; j < capacity; j++)
            {
                if (indexes[j] < lru)
                {
                    lru = indexes[j];
                    lru_index = j;
                }
            }

            frames[lru_index] = page;
            indexes[lru_index] = i;
            page_faults++;
        }
    }

    return page_faults;
}

int main()
{
    int ref_string[30], frames[30], i, j, k, no, avail, temp[30];
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;

    printf("Number of page faults: %d\n", pageFaults(pages, n, capacity));

    return 0;
}

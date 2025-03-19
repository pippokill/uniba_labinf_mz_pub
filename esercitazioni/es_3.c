#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define N_SENT 20
#define GROUP_SIZE 5

int main()
{
    char *article[5] = {"the", "a", "one", "some", "any"};
    char *noun[5] = {"boy", "girl", "dog", "town", "car"};
    char *verb[5] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[5] = {"to", "from", "over", "under", "on"};

    char **groups[] = {article, noun, verb, preposition};
    char sentences[N_SENT][1024] = {""};
    int seed = time(NULL);
    srand(seed);

    int patten[7] = {0, 1, 2, 3, 0, 1, -1};
    for (int i = 0; i < N_SENT; i++)
    {
        int p = 0;
        do
        {
            int s = rand() % GROUP_SIZE;
            strcat(sentences[i], groups[patten[p]][s]);
            if (patten[p + 1] != -1)
            {
                strcat(sentences[i], " ");
            }
            else
            {
                strcat(sentences[i], ".");
            }
            p++;
        } while (patten[p] != -1);
        sentences[i][0] = toupper(sentences[i][0]);
    }
    for (int i = 0; i < N_SENT; i++)
    {
        printf("\nSENTENCE %d: %s\n", i + 1, sentences[i]);
    }
}

/*
PROBLEMA
===========

Scrivere un programma che usi la generazione di numeri casuali per creare frasi in inglese.
Il programma deve usare quattro array di char chiamati article, noun, verb, e preposition.
Deve poi creare una frase selezionando una parola a caso da ogni array nell’ordine seguente:
article, noun, verb, preposition, article e noun.
Ogni parola che viene scelta deve essere concatenata con le parole precedenti in un array grande abbastanza da contenere l’intera frase.
Le parole vanno separate da spazi, Quando viene inviata in uscita la frase finale, deve cominciare con una lettera maiuscola.
Il programma deve generare 20 frasi.

SUGGERIMENTI
===============

Utilizzare i seguenti valori:

article= "the", "a", "one", "some", "any"
noun = “boy", "girl", "dog", "town", "car"};
verb = “drove", "jumped", "ran", "walked", "skipped"
preposition = "to", "from", "over", "under", "on"

VARIANTI
===========

Partendo dal programma creato si può creare un programma per creare articoli o racconti in maniera casuale.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define NUM_SENTENCES 20 // Number of sentences to be created
#define NUM_WORDS 5      // Number of words in the array
#define WORDS_LEN 9      // Length of words

const char articles[NUM_WORDS][WORDS_LEN] = {"the", "a", "one", "some", "any"};          // array of the possible articles to use in the sentence
const char noun[NUM_WORDS][WORDS_LEN] = {"boy", "girl", "dog", "town", "car"};           // array of the possible nouns to use in the sentence
const char verb[NUM_WORDS][WORDS_LEN] = {"drove", "jumped", "ran", "walked", "skipped"}; // array of the possible verbs to use in the sentence
const char preposition[NUM_WORDS][WORDS_LEN] = {"to", "from", "over", "under", "on"};    // array of the possible prepositions to use in the sentence

void generate_sentence(char sentence[]);
void first_letter_uppercase(char *string);
int picks(int max);

int main()
{
    srand((unsigned int)time(NULL)); // Set the random seed
    int i = 0;
    char sentence[256]; // the sentence to be created

    for (i = 0; i < NUM_SENTENCES; i++)
    {
        // Generate and print a random sentence 20 times
        strcpy(sentence, ""); // ad ogni passo è necessario pulire la stringa
        generate_sentence(sentence);
        printf("Sentence No. %d: %s\n", i + 1, sentence);
    }
    return 0;
}

/*
 * Generates a new random sentence
 */
void generate_sentence(char sentence[])
{

    // Build the sentence
    strcat(sentence, articles[picks(NUM_WORDS)]);
    strcat(sentence, " ");
    strcat(sentence, noun[picks(NUM_WORDS)]);
    strcat(sentence, " ");
    strcat(sentence, verb[picks(NUM_WORDS)]);
    strcat(sentence, " ");
    strcat(sentence, preposition[picks(NUM_WORDS)]);
    strcat(sentence, " ");
    strcat(sentence, articles[picks(NUM_WORDS)]);
    strcat(sentence, " ");
    strcat(sentence, noun[picks(NUM_WORDS)]);
    strcat(sentence, ".");

    first_letter_uppercase(sentence);
}

/*
 * Picks a random word from the provided array
 */
int picks(int max)
{
    return (rand() % (max));
}

/*
 * Sets the first word of the provided string to uppercase
 */
void first_letter_uppercase(char *string)
{
    char first = string[0];
    first = (char)toupper(first);
    string[0] = first;
}

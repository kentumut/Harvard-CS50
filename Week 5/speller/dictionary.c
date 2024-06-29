// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

int word_count = 0;

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash = 0;
    // TODO: Improve this hash function
    for (int i = 0; i < strlen(word); i++)
    {
        hash += tolower(word[i]) - 'a';
    }
    return hash % N;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]) == 0 && word[i] != 39)
        {
            return false;
        }
    }
    if (word[0] == 39)
    {
        return false;
    }
    int hash_value = hash(word);
    node *node = table[hash_value];
    while (node != NULL)
    {
        if (strcasecmp(node->word, word) == 0)
        {
            return true;
        }
        node = node->next;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fclose(file);
        return false;
    }
    char buffer[LENGTH + 1];
    while (fscanf(file, "%s", buffer) != EOF)
    {
        int hash_value = hash(buffer);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload();
            return false;
        }
        n->next = table[hash_value];
        strcpy(n->word, buffer);
        table[hash_value] = n;
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *ptr = head;
        node *tmp = head;

        while (ptr != NULL)
        {
            ptr = ptr->next;
            free(tmp);
            tmp = ptr;
        }
    }
    return true;
}

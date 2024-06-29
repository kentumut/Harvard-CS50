#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Iterates through every name and if names match, sets the rank
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // Goes for every rank the lower ranks and increments
    for (int i = 0; i < candidate_count; i++)
    {
        for (int h = i + 1; h < candidate_count; h++)
        {
            preferences[ranks[i]][ranks[h]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Increments for every candidate throgh the list
    for (int i = 0; i < candidate_count; i++)
    {
        for (int h = 0; h < candidate_count; h++)
        {
            if (i == h)
            {
                continue;
            }
            if (preferences[i][h] > preferences[h][i])
                // If the candidate prefered more over the other candidate the pair is created
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = h;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Sorts pairs using buble sort
    pair temp;
    int pair_strength[pair_count];
    for (int h = 0; h < pair_count - 1; h++)
    {
        pair_strength[h] = preferences[pairs[h].winner][pairs[h].loser] - preferences[pairs[h].loser][pairs[h].winner];
        // MAGIC
        for (int e = 0; e < pair_count - 1; e++)
        {
            if (pair_strength[e] < pair_strength[e + 1])
            {
                temp = pairs[e];
                pairs[e] = pairs[e + 1];
                pairs[e + 1] = temp;
            }
        }
    }
    return;
}

bool cycle(int winner, int loser)
{
    // If the loser is locked on the winner there is a cycle
    if (locked[loser][winner] == true)
    {
        return true;
    }
    for (int i = 0; i < pair_count; i++)
    {
        if (locked[loser][i] && cycle(winner, i))
            // Using recursion tracks other locked pairs and if it finds pair locked on the winner it returns
        {
            return true;
        }
    }
    return false;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!cycle(pairs[i].winner, pairs[i].loser))
            // If there is no cycle, lock the pairs
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // A winner is someone who has noone locked in him
    int locked_times;
    for (int i = 0; i < candidate_count; i++)
    {
        // Iterates for every candidate and checks whether other candidates locked in him
        locked_times = 0;
        for (int h = 0; h < candidate_count; h++)
        {
            if (locked[h][i] == true)
            {
                locked_times++;
            }
        }
        if (locked_times == 0)
        {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}
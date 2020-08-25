#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    int  i;
    // While the candidates array is not at the end (null byte) 
    for (i = 0; candidates[i].name != '\0'; i++)
    {
        // compare the argument name to the candidates array
        if ((strcmp(name, candidates[i].name)) == 0)
        {
            // if a valid vote, update vote total and return true
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    string winners[MAX];
    int i, j, lead;
    lead = 0;
    j = 0;

    // First go through and find the max vote total
    for (i = 0; candidates[i].name != '\0'; i++)
    {
        if (candidates[i].votes > lead)
        {
            lead = candidates[i].votes;
        }
    }

    // Any candidate with the max vote total gets added to winners array
    for (i = 0; candidates[i].name != '\0'; i++)
    {
        if (candidates[i].votes == lead)
        {
            winners[j] = candidates[i].name;
            j++;
        }
    }

    // Print the winners array to display winners of the election
    for (i = 0; winners[i] != '\0'; i++)
    {
        printf("%s\n", winners[i]);
    }

    return;
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Create a datatype/data structure called candidate (to store candidate name and vote count)
typedef struct
{
    string name;
    int votes;
}
candidate;

// Declare array of candidates using our defined datatype (this would be max 10 as array is 0-9)
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Bubble sort variables
int bubble_sort();
string nameTemp;
int votesTemp = 0;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage (user didn't enter 2 or more arguments)
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates (-1 as program name is included by default with argument count)
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // this (and below) are only run if the above have passed, as otherwise the return code(?) will cause the program to terminate
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];  // plus one so we ignore the program name itself
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Vote ignored if name not found in candidates array
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
    for (int i = 0; i < candidate_count; i++)
    {
        // look for entered name in candidates array (zero means true in this instance!)
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            return 1;
        }
    }
    // 99% sure this is only returned if name not found
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    bubble_sort();

    int highestVoteCount = candidates[(candidate_count - 1)].votes;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == highestVoteCount)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    //return;
}

// see bubble sort code for comments
int bubble_sort()
{
    for (int i = 0; i < candidate_count-1; i++)
    {
        for (int j = 0; j < candidate_count-i-1; j++)
        {
            if (candidates[j].votes > candidates[j+1].votes)
            {
                // store the current candidate name and votes before swapping
                nameTemp = candidates[j].name;
                votesTemp = candidates[j].votes;

                // replace j location candidate name and votes with j+1
                candidates[j].name = candidates[j+1].name;
                candidates[j].votes = candidates[j+1].votes;

                // add original j candidate from temp to j+1 candidate
                candidates[j+1].name = nameTemp;
                candidates[j+1].votes = votesTemp;
            }
        }
    }
    return 0;
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define Max 9

//structures
typedef struct
{
    string name;
    int votes;
}
candidate;

//array of candidates
candidate candidates[Max];

//number of candidates
int candidate_count = 0;


//fucntion decleartion
bool vote(string);
void print_winner();


int main(int argc, string argv[])
{
    //check command arguments
    if (argc < 2)
    {
        return 1;
    }
    
    //passing number of candidate
    candidate_count = argc - 1;
    
    //passing cadidates names
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    
    //get number of votes from user    
    int votes_number = get_int("Number of voters: ");
    string name_voted ;
    
    while (votes_number > 0)
    {
        //get vote from user
        name_voted = get_string("Vote: ");
        
        //check if this vote is valid or not by calling vote function
        if (vote(name_voted) == false)
        {
            printf("Invalid vote.\n");
        }
        else
        {
            votes_number --;
        }
    }
    
    //calling print_winner function
    print_winner();
    
    
    return 0;
}



//********************************************************functions***************************************************

//      **vote function**
bool vote(string s)
{
    //checking if the vote is already exist or not
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, s) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    
    return false;
}


//      **print_winner**
void print_winner()
{
    //assume that first cadidate is winner
    int current, max = candidates[0].votes;
    
    //check if exist another cadidate has max votes than first cadidate
    for (int i = 1; i < candidate_count; i++)
    {
        current = candidates[i].votes;
        if (current > max)
        {
            max = current; 
        }
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    
    
}
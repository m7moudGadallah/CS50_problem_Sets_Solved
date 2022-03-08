#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


//function declearation
int num_letters(string s);
int num_words(string s);
int num_sentences(string s);



int main()
{
    //getting text from user
    string text = get_string("Text: ");

    //calling num_letters to get number of letters
    int l = num_letters(text);

    //calling num_words to get number of words
    int w = num_words(text);

    //calling num_sentences to get number of sentences
    int s = num_sentences(text);

    //calulating average of letters per 100 word
    float L = (l / (float) w) * 100.0;

    //calculating average of sentences per 100 word
    float S = (s / (float) w) * 100.0;

    //readability test is the Coleman-Liau index.
    float  index = 0.0588 * L - 0.296 * S - 15.8;
    
    //rounding index and put it in answer (ans) variable
    int ans = (int) round(index);
    
    //now we check ans to print out suitable result
    if (ans < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (ans > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", ans);
    }
    
    return 0;
}



//*****************************************************functions***************************************

//     **num_letters function**           to get number of letters
int num_letters(string s)
{
    int letters = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))          //check if it's letter incrementing letters
        {
            letters++;
        }
    }

    return letters;
}


//      **num_words function**                   to get number of words
int num_words(string s)
{
    int words = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')                //check if it's space incrementing words
        {
            words++;
        }
    }

    words++;

    return words;
}


//      **num_sentences**       to get number of sentences
int num_sentences(string s)
{
    int sentences = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}
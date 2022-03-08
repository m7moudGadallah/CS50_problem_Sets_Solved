#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



//function declearation
bool check_key(int n, string s);
string caeasr_encryption(int k, string s);


int main(int argc, string argv[])
{
    //calling check_key
    if (!check_key(argc, argv[1]))
    {
        return 1;
    }

    //converting key from stirng to int
    int key = atoi(argv[1]);

    //getting text from user
    string plaintext = get_string("plaintext:  ");

    //calling caeasr_encryption function to get ciphertex  
    string ciphertext = caeasr_encryption(key, plaintext);

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}


//**********************************functions***************************************

//          **check_key  function**       to check the key is valid or not
bool check_key(int num, string s)
{
    if (num != 2)
    {
        return false;
    }

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }

    return true;
}

//          **letter_encryption  function**  to encrypting letter by using key
char letter_encryption(int ky, char c)
{
    if (isalpha(c))
    {
        char ch;
        
        if (isupper(c))          //checking the char is upper or lower
        {
            /*subtracting from 'A' to make alphabet from 0 to 25 and getting moduls by 26 (number of alphabet) and
            after calculating ascii of letter adding it to 'A' to get letter*/
            ch = ((int)(c - 'A' + ky) % 26) + 'A';
            return ch;
        }
    
        ch = ((int)(c - 'a' + ky) % 26) + 'a';
        return ch;
    }
    return c;
}

//          **caeasr_encryption  function**          to get encrypte text
string caeasr_encryption(int k, string s)
{
    //variable t is to save ciphertext
    string t = s;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //calling letter_encryption function to encrypt char by using key and char
        t [i] = letter_encryption(k, s[i]);
    }

    return t;
}
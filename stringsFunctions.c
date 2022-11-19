/*
 * stringsFunctions.c
 *
 * An implementation of five functions for ILSE Assignment 3:
 *
 * 1. void reverse_in_place(char *str)
 * 2. void reverse_by_word(char *str)
 * 3. bool is_prefix(const char *prefix, const char *str)
 * 4. int remove_last_substr(char *str, const char *substr)
 * 5. int first_word(const char *input, char *word, int word_len)
 *
 * Author: Niyomwungeri Parmenide ISHIMWE <parmenin@andrew.cmu.edu>
 */

// HEADER FILES
#include <stdio.h>   // for inputs and outputs
#include <stdbool.h> // for using booleans
#include <string.h>  // For using string functions
#include <ctype.h>   // declares a set of functions to classify (and transform) individual characters. - tolower

/*
 * An implementation of the reverse_in_place function, as a class example
 *
 * Reverses a null-terminated string in place, converting it to all
 * lower case in the process.
 *
 * Examples:
 *
 *  "Carnegie Mellon"	"nollem eigenrac"
 *  "Four"            "ruof"
 *  " One"            "eno "
 *
 * Parameters:
 *   str   A null terminated string to reverse
 *
 * Returns:
 *   None
 */

void reverse_in_place(char *str)
{
    int f = 0;
    int b = 0;
    char temp;

    for (b = 0; str[b] != '\0'; ++b)
        ;

    --b;

    while (f < b)
    {
        temp = tolower(str[b]);
        str[b--] = tolower(str[f]);
        str[f++] = temp;
    }
}

/*
 * Tests the reverse_in_place function, once
 *
 * Parameters:
 *   input      The string to pass to reverse_in_place
 *   expected   The string expected out of reverse_in_place
 *
 * Returns:
 *   true if the test passes, false otherwise
 */
bool test_reverse_in_place_once(char *input, char *expected)
{
    char buffer[512];
    strcpy(buffer, input);
    reverse_in_place(buffer);

    if (strcmp(buffer, expected) != 0)
    {
        printf("Test error: converting '%s', actual result '%s', expected '%s'\n",
               input, buffer, expected);
        return false;
    }

    else
    {
        return true;
    }
}

/*
 * Performs unit tests of the reverse_in_place function
 *
 * Returns:
 *   True if all tests succeed, false otherwise
 */
bool test_reverse_in_place()
{
    bool success = true;
    if (!test_reverse_in_place_once("Carnegie Mellon", "nollem eigenrac"))
        success = false;

    if (!test_reverse_in_place_once("Four", "ruof"))
        success = false;

    if (!test_reverse_in_place_once(" One", "eno "))
        success = false;

    if (!test_reverse_in_place_once("One", "eno"))
        success = false;

    if (!test_reverse_in_place_once("    ", "    "))
        success = false;

    if (!test_reverse_in_place_once(" ", " "))
        success = false;

    if (!test_reverse_in_place_once("", ""))
        success = false;

    if (!test_reverse_in_place_once(".", "."))
        success = false;

    if (!test_reverse_in_place_once("\0\0", "\0\0"))
        success = false;

    return success;
}
// #######################################################################
/*
 * An implementation of the reverse_by_word function
 *
 * Individually reverses each word of a null-terminated string in place.
 * Whitespace characters (as identified by the C isspace() function)
 * are passed through unchanged.
 *
 * Examples:
 *
 *  "Carnegie Mellon"          "eigenraC nolleM"
 *  "\tCarnegie  Mellon "      "\teigenraC  nolleM"
 *  "Four"                     "ruoF"
 *  " One"                     " enO"
 *  "My heart is in  the work" "yM traeh si ni  eht krow"
 *
 * Parameters:
 *   str   A null terminated string to reverse
 *
 * Returns:
 *   None
 */
void reverse_by_word(char *str)
{
    int start, end;
    end = 0;
    start = 0;

    while (str[end] != '\0')
    {
        for (end = start; str[end] && !isspace(str[end]); end++)
            ;

        int ending1 = end - 1;
        char temp;
        while (start < ending1)
        {
            temp = str[start];
            str[start] = str[ending1];
            str[ending1] = temp;
            start++;
            ending1--;
        }

        start = end + 1;
    }
}

/*
 * Tests the reverse_by_word function, once
 *
 * Parameters:
 *   input      The string to pass to reverse_by_word
 *   expected   The string expected out of reverse_by_word
 *
 * Returns:
 *   true if the test passes, false otherwise
 */

bool test_reverse_by_word_once(char *input, char *expected)
{
    char bufferMemory[512];

    strcpy(bufferMemory, input);
    reverse_by_word(bufferMemory);

    if (strcmp(bufferMemory, expected) != 0)
    {
        printf("\nTest error: converting '%s', actual result '%s', expected '%s'\n",
               input, bufferMemory, expected);
        return false;
    }
    else
    {
        return true;
    }
}

/*
 * Performs unit tests of the reverse_by_word functions
 *
 * Returns:
 *   True if all tests succeed, false otherwise
 */
bool test_reverse_by_word()
{
    bool success = true;

    if (!test_reverse_by_word_once("Carnegie Mellon", "eigenraC nolleM"))
        success = false;

    if (!test_reverse_by_word_once("    Carnegie  Mellon", "    eigenraC  nolleM"))
        success = false;

    if (!test_reverse_by_word_once("My heart is in  the work", "yM traeh si ni  eht krow"))
        success = false;

    if (!test_reverse_by_word_once("Four", "ruoF"))
        success = false;

    if (!test_reverse_by_word_once(" One", " enO"))
        success = false;

    return success;
}
// #######################################################################
/*
 * An implementation of the is_prefix function
 *
 * Returns true if str begins with prefix, and false otherwise.
 * Both prefix and str are null-terminated strings.
 * Note: empty string "" is a valid prefix for all strings.
 *
 * Examples:
 *
 * prefix                  str                   Returns
 *
 * C                       Carnegie Mellon        true
 * Carnegie                Carnegie Mellon        true
 * Carnegie Mellon         Carnegie Mellon        true
 * Cab                     Carnegie Mellon        false
 *
 * Parameters:
 *   str                   A null terminated string to examine
 *   prefix                A null terminated string to check in front of str
 *
 * Returns:
 *    True if str begins with prefix, and false otherwise.
 */
bool is_prefix(const char *prefix, const char *str)
{
    // char IS TYPE INTEGER
    char preCount;
    char strCount;

    // IF THE PREFIX IS NOT SPECIFIED(NOT A NBR), true - *prefix: DEREFERENCED TO GET THE ACTUAL VALUE IN MEMORY
    if (!*prefix)
    {
        return true;
    }

    // WORKING THROUGH BOTH string AND prefix
    // INCREMENT BOTH prefix AND string, THEN COMPARE THEM UNTIL THE END
    while ((preCount = *prefix++) && (strCount = *str++))
    {
        // IF THE CURRENT chars DO NOT MATCH WITH prefix, false
        if (preCount != strCount)
        {
            return false;
        }
    }

    // IF THE string PROVIDED IS LESS THAN PREFIX, false
    if (!strCount)
    {
        return false;
    }

    // IF ALL THE ABOVE CONDITIONS ARE NOT MET, true
    return true;
}

/*
 * Tests the is_prefix function, once
 *
 * Parameters:
 *   input      The string to pass to is_prefix
 *   expected   The string expected out of is_prefix
 *
 * Returns:
 *   true if the test passes, false otherwise
 */

bool test_is_prefix_once(const char *prefix, const char *str, bool expected)
{
    if(is_prefix(prefix, str) != expected) 
    {
        printf("\nTest error: checking prefix '%s' in '%s' returned '%d', expected '%d'\n", 
                prefix, str, is_prefix(prefix, str), expected);
        return false;
    }
    else
    {
        return true;
    }
}

/*
 * Performs unit tests of the is_prefix functions
 *
 * Returns:
 *   True if all tests succeed, false otherwise
 */
bool test_is_prefix()
{
    bool success = true;

    if (!test_is_prefix_once("C", "Carnegie Mellon", true)) 
        success = false;

    if (!test_is_prefix_once("Carnegie", "Carnegie Mellon", true))
        success = false;

    if (!test_is_prefix_once("Carnegie Mellon", "Carnegie Mellon", true))
        success = false;

    if (!test_is_prefix_once("Cab", "Carnegie Mellon", false))
        success = false;

    return success;
}

// #######################################################################
/*
 * An implementation of the remove_last_substr function
 *
 * Returns true if str begins with prefix, and false otherwise.
 * Both prefix and str are null-terminated strings.
 * Note: empty string "" is a valid prefix for all strings.
 *
 * Examples:
 *
 * prefix                  str                   Returns
 *
 * C                       Carnegie Mellon        true
 * Carnegie                Carnegie Mellon        true
 * Carnegie Mellon         Carnegie Mellon        true
 * Cab                     Carnegie Mellon        false
 *
 * Parameters:
 *   str                   A null terminated string to examine
 *   prefix                A null terminated string to check in front of str
 *
 * Returns:
 *    True if str begins with prefix, and false otherwise.
 */
int remove_last_substr(char *str, const char *substr)
{

}

// #######################################################################
/*
 * An implementation of the first_word function
 *
 * Returns true if str begins with prefix, and false otherwise.
 * Both prefix and str are null-terminated strings.
 * Note: empty string "" is a valid prefix for all strings.
 *
 * Examples:
 *
 * prefix                  str                   Returns
 *
 * C                       Carnegie Mellon        true
 * Carnegie                Carnegie Mellon        true
 * Carnegie Mellon         Carnegie Mellon        true
 * Cab                     Carnegie Mellon        false
 *
 * Parameters:
 *   str                   A null terminated string to examine
 *   prefix                A null terminated string to check in front of str
 *
 * Returns:
 *    True if str begins with prefix, and false otherwise.
 */
int first_word(const char *input, char *word, int word_len)
{
}
    // #######################################################################
    // THE PROGRAM EXECUTION STARTS FROM HERE
    int main(int argc, char *argv[])
{
    // TESTING THE reverse_in_place FUNCTION FUNCTION
    bool success = true;
    if (!test_reverse_in_place())
        success = false;

    if (success)
        printf("All tests for reverse_in_place succeeded\n");
    else
        printf("Test failures for reverse_in_place occurred\n");

    // TESTING THE reverse_by_word FUNCTION FUNCTION
    if (!test_reverse_by_word())
        success = false;

    if (success)
        printf("\nAll tests for reverse_by_word succeeded\n\n");
    else
        printf("\nTest failures for reverse_by_word occurred\n\n");

    // TESTING THE is_prefix FUNCTION FUNCTION
    if (!test_is_prefix())
        success = false;

    if (success)
        printf("\nAll tests for is_prefix succeeded\n\n");
    else
        printf("\nTest failures for is_prefix occurred\n\n");
}

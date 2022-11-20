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
        // MOVING THE POINTER end TO THE LAST LETTER
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

    // CONSIDER USING BUFFER AS WELL?
    if (is_prefix(prefix, str) != expected)
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

    if (!test_is_prefix_once("log", "Parallellogram", false))
        success = false;

    if (!test_is_prefix_once("P", "Parallellogram", true))
        success = false;

    if (!test_is_prefix_once("[", "[Parallellogram", true))
        success = false;

    if (!test_is_prefix_once("", "Parallellogram", true))
        success = false;

    if (!test_is_prefix_once(" ", "Parallellogram", false))
        success = false;

    if (!test_is_prefix_once("", " Parallellogram", true))
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
 * Removes the last occurrence of substr from str,
 * modifying the result in place.
 * Returns the character position where the removal occurred,
 * or -1 if substr was not found in str.
 * Note that substr need not be a full word.
 *
 * Examples:
 *
 *  str                     substr                  Result                Returns
 * "Carnegie Mellon"        "Carnegie"              "Mellon"              0
 * "Carnegie Mellon"        "Kiltie"                "Carnegie Mellon"     -1
 * "Carnegie Mellon"        ""                      "Carnegie Mellon"     14
 * "one two one three"      "one "                  "one two three"       8
 * "one two one three"      "hr"                    "one two one tee"     13
 *
 * Parameters:
 *   str                   A null terminated string to examine
 *   substr                A null terminated string to remove
 *
 * Returns:
 *    Integer, which indicates the position where the substring was removed
 */
int remove_last_substr(char *str, const char *substr)
{
    // VARS DECLARATION
    int position, exist;
    int lenStr = 0, lenSubStr = 0;

    // STRING BUFFERS(string and substring)
    char strin[512];
    char subStr[512];

    // FINDING THE LENGTH OF THE string AND COPYING THE PROVIDED str TO strin BUFFER TO BE USED
    for (int c = 0; str[c] != '\0'; c++)
    {
        lenStr = c + 1;
        strin[c] = str[c];
    }

    // THE LENGTH OF THE substring AND COPYING THE PROVIDED substr TO subStr BUFFER TO BE USED
    for (int c = 0; substr[c] != '\0'; c++)
    {
        lenSubStr = c + 1;
        subStr[c] = substr[c];
    }

    // LOOPING FROM THE START TO END OF string (lenSubStr)
    // TRYING TO MATCH THE substr TO str FROM THE BACK
    position = -1; // START AT FALSE
    for (int i = 0; i < lenStr - lenSubStr; i++)
    {
        // MATCH subStr AT THIS POSITION
        exist = 1; // START TRUE
        for (int j = 0; j < lenSubStr; j++)
        {
            // IF subStr NOT FOUND
            if (strin[i + j] != subStr[j])
            {
                exist = 0;
                break;
            }
        }

        // IF subStr EXIST, UPDATE THE POSITION
        if (exist == 1)
            position = i;
    }

    if (position != -1)
    {
        // SHIFT CHARS TO THE LEFT
        for (int i = position; i <= lenStr - lenSubStr; i++)
            strin[i] = strin[i + lenSubStr];
    }

    return position;
}

/*
 * Tests the remove_last_substr function, once
 *
 * Parameters:
 *   input      The string to pass to remove_last_substr
 *   substr     The string to pass to remove_last_substr to be removed
 *   expected   The integer expected to be returned by remove_last_substr
 *
 * Returns:
 *   Returns the character position where the removal occurred, or -1 if substr was not found in str.
 */

bool test_remove_last_substr_once(char *input, const char *substr, int expected)
{
    char bufferMemory[512];

    strcpy(bufferMemory, input);

    if (remove_last_substr(bufferMemory, substr) != expected)
    {
        printf("\nTest error: removing '%s', from '%s', gives '%s', expected to be removed at position '%d' instead removed at '%d\n",
               substr, input, bufferMemory, expected, remove_last_substr(bufferMemory, substr));
        return false;
    }
    else
    {
        return true;
    }
}

/*
 * Performs unit tests of the remove_last_substr functions
 *
 * Returns:
 *   True if all tests succeed, false otherwise
 */
bool test_remove_last_substr()
{
    bool success = true;

    if (!test_remove_last_substr_once("Parallellogram", "l", 8))
        success = false;

    if (!test_remove_last_substr_once("Parallellogram", "ll", 7))
        success = false;

    if (!test_remove_last_substr_once("Carnegie Mellon", "Carnegie ", 0))
        success = false;

    if (!test_remove_last_substr_once("Carnegie Mellon", "Kiltie", -1))
        success = false;

    if (!test_remove_last_substr_once("Carnegie Mellon", "", 14))
        success = false;

    if (!test_remove_last_substr_once("one two one three", "one ", 8))
        success = false;

    if (!test_remove_last_substr_once("one two one three", "hr", 13))
        success = false;

    return success;
}

// #######################################################################
/*
 * An implementation of the first_word function
 *
 * Returns the first word from input, removing leading whitespace
 *
 * Examples:
 *
 * input                  Result (in word)       Returns
 *
 * ␣␣␣echo␣                 echo                   7
 * grep                    grep Mellon            4
 * \techo␣one␣two␣three     echo                   5
 * (empty string)          (empty string)         0
 *  ␣␣                      (empty string)         2
 * "one␣two"␣three          "one                   4
 * One␣Two␣Three            One                    3
 * function()␣one          function()             10
 * ␣␣␣␣␣12.34                12.34                  10
 *
 * Parameters:
 *   input                   A null terminated string to examine
 *   word                    A null terminated word to work with
 *   word_len                An integer for word's length
 *
 * Returns:
 *    Integer, which indicates the position where the space was removed
 */
int first_word(const char *input, char *word, int word_len)
{
    int index = 0, k = 0, processed = 0;

    // LOOP THE STRING, SKIPPING LEADING WHITESPACES
    while (isspace(input[index]))
        index++;

    // LOOP STARTING FROM INDEX(spaces ignored) UNTIL string ENDS '\0' OR MEET SPACE, THEN COPY CONTENT TO word
    for (int j = index; input[j] != '\0' && !(isspace(input[j])); j++)
    {
        // COPYING THE first word FROM input INTO THE word BUFFER
        word[k] = input[j];
        k++;
    }
    // ADDING THE END OF LINE '\0'
    word[k] = '\0';

    // PROCESSED CHARS = SKIPPED leading whitespaces + LENGTH OF word
    processed = k + index;
    return processed;
}
/*
 * Tests the first_word function, once
 *
 * Parameters:
 *   input      The string to pass to first_word
 *   substr     The string to pass to first_word to be removed
 *   expected   The integer expected to be returned by first_word
 *
 * Returns:
 *   Returns the character position where the removal occurred, or -1 if substr was not found in str.
 */

bool test_first_word_once(const char *input, int expected)
{
    char word[128];

    if (first_word(input, word, sizeof(word)) != expected)
    {
        printf("\nTest error: Getting the first word from '%s' gives '%s' expecting to return '%d' but returned '%d'\n", input, word, expected, first_word(input, word, sizeof(word)));
        return false;
    }

    else
    {
        return true;
    }
}

/*
 * Performs unit tests of the first_word functions
 *
 * Returns:
 *   True if all tests succeed, false otherwise
 */

bool test_first_word()
{
    bool success = true;

    const char *input = "grep";
    if (!test_first_word_once(input, 4))
        success = false;

    input = "   echo ";
    if (!test_first_word_once(input, 7))
        success = false;

    input = " echo one two three";
    if (!test_first_word_once(input, 5))
        success = false;

    input = "";
    if (!test_first_word_once(input, 0))
        success = false;

    input = "  ";
    if (!test_first_word_once(input, 2))
        success = false;

    input = "\"one two\" three";
    if (!test_first_word_once(input, 4))
        success = false;

    input = "One Two Three";
    if (!test_first_word_once(input, 3))
        success = false;

    input = "function() one";
    if (!test_first_word_once(input, 10))
        success = false;

    input = "     12.34";
    if (!test_first_word_once(input, 10))
        success = false;

    return success;
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
        printf("All tests for reverse_in_place succeeded\n\n");
    else
        printf("Test failures for reverse_in_place occurred\n\n");

    // TESTING THE reverse_by_word FUNCTION FUNCTION
    if (!test_reverse_by_word())
        success = false;

    if (success)
        printf("All tests for reverse_by_word succeeded\n\n");
    else
        printf("Test failures for reverse_by_word occurred\n\n");

    // TESTING THE is_prefix FUNCTION FUNCTION
    if (!test_is_prefix())
        success = false;

    if (success)
        printf("All tests for is_prefix succeeded\n\n");
    else
        printf("Test failures for is_prefix occurred\n\n");

    // TESTING THE remove_last_substr FUNCTION FUNCTION
    if (!test_remove_last_substr())
        success = false;

    if (success)
        printf("All tests for remove_last_substr succeeded\n\n");
    else
        printf("Test failures for remove_last_substr occurred\n\n");

    // TESTING THE first_word FUNCTION FUNCTION
    if (!test_first_word())
        success = false;

    if (success)
        printf("All tests for first_word succeeded\n\n");
    else
        printf("Test failures for first_word occurred\n\n");
}

/*
 * REFERENCES
 * 1. https://codeforwin.org/2016/04/c-program-to-remove-last-occurrence-of-word-in-string.html
 */
## stringFunctions - Code for Assignment 3 for ILSE, 04-801 B2, Fall 2022
    
__INTRODUCTION__

This repo contains a program that has five string manipulation and analysis functions. It also have their tests with multiples test cases that are used to validate the functions.

__DESCRIPTION__
    
 An implementation of five functions for ILSE Assignment 3:
 
 1. void reverse_in_place(char *str)
 2. void reverse_by_word(char *str)
 3. bool is_prefix(const char *prefix, const char *str)
 4. int remove_last_substr(char *str, const char *substr)
 5. int first_word(const char *input, char *word, int word_len)


__void reverse_in_place(char *str)__ 

An implementation of the reverse_in_place function.

 * Reverses a null-terminated string in place, converting it to all lower case in the process.

Examples:  
| Input             | Output            |
|-------------------|-------------------|
| Carnegie Mellon | nollem eigenrac |
| Four            | ruof            |
|  One            | eno             |

Parameters:  
  str :                A null terminated string to reverse  

Returns:  
  None  
    

__void reverse_by_word(char *str)__ 

An implementation of the reverse_by_word function

 * Individually reverses each word of a null-terminated string in place.
 * Whitespace characters (as identified by the C isspace() function) are passed through unchanged.

Examples:  
| Input                      | Output                     |
|----------------------------|----------------------------|
| Carnegie Mellon          | eigenraC nolleM          |
| \tCarnegie  Mellon       | \teigenraC  nolleM       |
| Four                     | ruoF                     |
|  One                     |  enO                     |
| My heart is in  the work | yM traeh si ni  eht krow |

Parameters:  
  str :       A null terminated string to reverse  

Returns:  
  None  


__bool is_prefix(const char *prefix, const char *str)__ 

An implementation of the is_prefix function  

 * Returns true if str begins with prefix, and false otherwise.
 * Both prefix and str are null-terminated strings.
 * Note: empty string "" is a valid prefix for all strings.

Examples:  
| prefix            | str               | Returns |
|-------------------|-------------------|---------|
| C               | Carnegie Mellon | true    |
| Carnegie        | Carnegie Mellon | true    |
| Carnegie Mellon | Carnegie Mellon | true    |
| Cab             | Carnegie Mellon | false   |

Parameters:  
   str :                     A null terminated string to examine  
   prefix :                  A null terminated string to check in front of str  

Returns:  
    True if str begins with prefix, and false otherwise.  



__int remove_last_substr(char *str, const char *substr)__ 

An implementation of the remove_last_substr function  

 * Removes the last occurrence of substr from str, modifying the result in place.
 * Returns the character position where the removal occurred, or -1 if substr was not found in str.
 * Note that substr need not be a full word.

Examples:  

| str                   | substr     | Result            | Returns |
|-----------------------|------------|-------------------|---------|
| Carnegie Mellon   | Carnegie | Mellon          | 0       |
| Carnegie Mellon   | Kiltie   | Carnegie Mellon | -1      |
| Carnegie Mellon   |          | Carnegie Mellon | 14      |
| one two one three | one      | one two three   | 8       |
| one two one three | hr       | one two one tee | 13      |



Parameters:  
   str                   A null terminated string to examine  
   substr                A null terminated string to remove  

Returns:  
    Integer, which indicates the position where the substring was removed.    


__int first_word(const char *input, char *word, int word_len)__ 

Returns the first word from input, removing leading whitespace 

 * Removes the last occurrence of substr from str, modifying the result in place.
 * Returns the character position where the removal occurred, or -1 if substr was not found in str.
 * Note that substr need not be a full word.

Examples:  

| input                  | Result (in word) | Returns |
|------------------------|------------------|---------|
|  ␣␣␣echo␣             | echo             | 7       |
|  grep                 | grep Mellon      | 4       |
|  \techo␣one␣two␣three | echo             | 5       |
|  (empty string)       | (empty string)   | 0       |
|   ␣␣                  | (empty string)   | 2       |
|  "one␣two"␣three      | "one             | 4       |
|  One␣Two␣Three        | One              | 3       |
|  function()␣one       | function()       | 10      |
|  ␣␣␣␣␣12.34           | 12.34            | 10      |

Parameters:  
    input                   A null terminated string to examine  
    word                    A null terminated word to work with  
    word_len                An integer for word's length  

Returns:  
    Integer, which indicates the position where the space was removed


__IMPORTANCE__

Someone may need to use these functions, when there is a need to manipulate strings o reven analyse them. this can be done via reversing the string characters or even reversing string words in place. These functions can also help in analysis of strings via searching various patterns in strings to make sure that it is the right string or even exploring large strings to know if particular information is included.


__GETTING STARTED__

- Clone this repository to get the stringFunctions.c program.
- Run the stringFunctions.c program from its containing directory to get the better of it.
- Note that the following header files needs to be included: 
#include <stdio.h>   // for inputs and outputs  
#include <stdbool.h> // for using booleans  
#include <string.h>  // For using string functions  
#include <ctype.h>   // declares a set of functions to classify (and transform) individual characters. - tolower  
- Check if it has effects.
- Happy exploration!!



__TESTING__

This program should be tested with the functions inside of it that have names starting with test. Those functions are of two types. Each functions has its own function that tests it one and another function that performs multiple test cases to confirm the authenticity. If the tests are run, the results are generated in place.
  


 __KEYWORDS__

<mark>ILSE</mark>     <mark>CMU</mark>     <mark>Assignment3</mark>     <mark>stringFunctions</mark>     <mark>C Programming</mark>     <mark>Strings</mark> 



  __AUTHOR__
    
 Written by parmenin (Niyomwungeri Parmenide ISHIMWE) at CMU-Africa - MSIT 
    

    
 __DATE__
    
 November 21, 2022" 

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

- An implementation of the reverse_in_place function.

 * Reverses a null-terminated string in place, converting it to all lower case in the process.

- Examples:  
 "Carnegie Mellon"	-> "nollem eigenrac"  
 "Four" ->             "ruof"  
 " One" ->             "eno "  

- Parameters:  
  str :                A null terminated string to reverse  

- Returns:  
  None  
    

__void reverse_by_word(char *str)__ 

- An implementation of the reverse_by_word function

 * Individually reverses each word of a null-terminated string in place.
 * Whitespace characters (as identified by the C isspace() function) are passed through unchanged.

- Examples:  
"Carnegie Mellon" ->              "eigenraC nolleM"  
"\tCarnegie  Mellon " ->          "\teigenraC  nolleM"  
"Four" ->                         "ruoF"  
" One" ->                         " enO"  
"My heart is in  the work" ->     "yM traeh si ni  eht krow"  

- Parameters:  
  str :       A null terminated string to reverse  

- Returns:  
  None  


__bool is_prefix(const char *prefix, const char *str)__ 

- An implementation of the is_prefix function  

 * Returns true if str begins with prefix, and false otherwise.
 * Both prefix and str are null-terminated strings.
 * Note: empty string "" is a valid prefix for all strings.

- Examples:  
  prefix                   | str                     | Returns  

  "C"                      | "Carnegie Mellon"       | true  
  "Carnegie"               | "Carnegie Mellon"       | true  
  "Carnegie Mellon"        | "Carnegie Mellon"       | true  
  "Cab"                    | "Carnegie Mellon"       | false  

- Parameters:  
   str :                     A null terminated string to examine  
   prefix :                  A null terminated string to check in front of str  

- Returns:  
    True if str begins with prefix, and false otherwise.  

__IMPORTANCE__

Someone may need to use these functions, when there is a need to manipulate strings o reven analyse them. this can be done via reversing the string characters or even reversing string words in place. These functions can also help in analysis of strings via searching various patterns in strings to make sure that it is the right string or even exploring large strings to know if particular information is included.


__GETTING STARTED__

- Clone this repository to get the stringFunctions.c program.
- Run the stringFunctions.c program from its containing directory to get the better of it.
- Check if it has effects.
- Happy exploration!!



__TESTING__

This program should be tested with the functions inside of it that have names starting with test. Those functions are of two types. Each functions has its own function that tests it one and another function that performs multiple test cases to confirm the authenticity. If the tests are run, the results are generated in place.
  


 __KEYWORDS__

   ILSE          CMU           Assignment3          stringFunctions           C Programming        Strings 



  __AUTHOR__
    
 Written by parmenin (Niyomwungeri Parmenide ISHIMWE) at CMU-Africa - MSIT 
    

    
 __DATE__
    
 November 21, 2022" 

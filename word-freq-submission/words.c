#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "words.h"

#define MAXBUF 500

/**
 * The make_string function will allocate a new C string given a
 * buffer of characters and its length. It is the responsibility of
 * the caller of this function to deallocate the string.
 */
static char *make_string(char buffer[], int length) {
  char *str = (char *)(malloc(length+1));
  memcpy(str, buffer, length);
  str[length] = '\0';
  return str;
}

/**
 * The words_next_word function returns the next word from standard
 * input. A word is a sequence of characters that are A-Z, a-z, or
 * 0-9. Any other character is a non-word character and is used to
 * delimit words.
 */
char *words_next_word() {
  char buf[MAXBUF];
  int input;
  int counts = 0;
 

  // TODO: The implementation of this function is simple. You must use
  // the getchar() function (as covered in class) to retrieve the next
  // character from standard input. If the character is an
  // alphanumeric character (a-z,A-Z,0-9) then it is a word character
  // and should be added to the character buffer `buf`. You keep
  // iterating, reading characters from standard input, until you
  // reach a non-word character. If you do you must call the
  // `make_string` function to create a new string from your character
  // buffer `buf` and return the new string as a result of this
  // function.
  //
  // HINTS: 
  //  (1) Pay attention to leading non-word characters, i.e., skip any non-word
  //      characters before accumulating word characters
  //  (2) Handle EOF and the last word correctly.
  //  (3) Read the result of getchar() into an int, for proper EOF testing

  input = getchar();

  while(isalnum(input)==0) //skip any non-word characters before accumulating word characters
  {
    if(input == EOF)
    {
      return NULL; // word does not exist
    } 

    input = getchar(); 
  }

  while(isalnum(input) != 0)
  {
    if(input == EOF)
    {
      break;
    }

    buf[counts] = input;
    input = getchar();
    counts++;
  }

  return make_string(buf,counts);
}

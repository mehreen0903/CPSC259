/*
 File:          recursion.c
 Purpose:       Exercises for CPSC259 lab 4
 Author:			  Mehreen Mohammed Arif
 Student #s:		65146201
 CWLs:		      marif07
 Date:				  17/11/2025
 */

 /******************************************************************
	PLEASE EDIT THIS FILE

	Comments that start with // should be replaced with code
	Comments that are surrounded by * are hints
	******************************************************************/


	/* Preprocessor directives */
#include "recursion.h"

/*
 Calculates the power.
 PARAM:     base is an integer
 PARAM:     power is an integer
 PRE:       power >= 0
 PRE:       base != 0
 RETURN:    base^power
 */
int calculate_power(int base, int power)
{
	// Replace this return statement with your own code
		if (power == 0) {
			return 1;
		}
		else {
			int ans = base * calculate_power(base, power - 1);
			return ans;
			}
}

/*
 Returns the number of digits in an integer
 PARAM:     number is an integer
 PRE:       0 < number <= INT_MAX
 RETURN:    the number of digits in the number
 */
int count_digits(int number)
{
	// Replace this return statement with your own code
	if ((number > 0) && (number <= 9)) {
		return 1;
	}
	else {
		int count = 0;
		count =  count + count_digits(number/10) + 1; // +1 to account for initial number before it divides by 10
		return count;
	}
}

/*
 Returns the length of the specified string.
 PARAM:  string, a pointer to an array of char
 PRE:    the string pointer is not a dangling pointer
 RETURN: the length of the string passed as a parameter
 */
int string_length(char* string)
{
		// Replace this return statement with your own code
		if (*string == '\0') {
			return 0;
		}
		else {
			return 1 + string_length(string+1);
		}
}

/*
 Determines if a string is a palindrome.  DOES NOT skip spaces!
 For example,
 ""     -> returns 1 (an empty string is a palindrome)
 "the"  -> returns 0
 "abba" -> returns 1
 "Abba" -> returns 0
 "never odd or even" -> returns 0
 For the recursive call, be aware that both parameters can be modified.
 PARAM:  string, a pointer to an array of char
 PARAM:  string_length, the length of the string
 PRE:    the string pointer is not a dangling pointer
 PRE:    string_length is the correct length of the string
 RETURN: IF string is a palindrome
				 THEN 1
		 END 0
 */
int is_palindrome(char* string, int string_length)
{
	// Replace this return statement with your own code
	if (string_length == 0 || string_length == 1) {
		return 1;
	}
	if (string[0] == string[string_length - 1]) {
		return 1;
		is_palindrome(string + 1, string_length - 2);
	}
	else return 0;
}
/*
 Draws a ramp.  The length of the longest rows is specified by the parameter.
 For the recursive call, be aware that both parameters can be modified.
 PARAM:     number, an integer
 PARAM:     buffer, a character array of sufficient length
 PRE:       number >= 1
						buffer has sufficient length and contains null characters from the buffer
						address to the end of its length
 POST:      draws a ramp whose height is the specified number into buffer
 RETURN:    the number of characters written into buffer. Don't forget to count your
						newline characters!
 */
	int draw_ramp(int number, char* buffer)
{
		if (number == 1) {
			draw_row(number, buffer);
		}
		else {
			draw_row(number, buffer);
			draw_ramp(number - 1, buffer);
			draw_row(number, buffer);
		}
		return number - 1;
}
/*
 Draws a row of asterisks of the specified length
 For the recursive call, be aware that both parameters can be modified.
 PARAM:  size, an integer
 PARAM:  buffer, a character array of sufficient length
 PRE:    size >= 1
				 buffer has sufficient length and contains null characters from the buffer
				 address to the end of its length
 POST:   draws a row of asterisks of specified length to buffer
 RETURN: the number of characters drawn
 */
int draw_row(int size, char* buffer)
{
	if (size == 0) {
		*(buffer + string_length(buffer)) = '\n';
		return string_length(buffer);
	}
	else {
		*(buffer + string_length(buffer)) = '*';
		draw_row(size - 1, buffer);
	}
}
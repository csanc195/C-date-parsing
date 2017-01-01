/***************************************************************************/
/*      convertDate.c 	 			Prog II			   */
/***************************************************************************/
/*  Author: Carlos L Sanchez Vila					   */
/***************************************************************************/
/*              		Program Description:			   */
/* The following program goes through imput passed through stdin and 	   */
/* reads entries that follow the pattern of 				   */
/*			number(month)/number(day)/number(year)		   */
/* verifies that they represent a valid date, that is, the date is valid   */
/* if the day is a number from 1 to 31, if a month is a number from 1 to 12*/
/* and if the year is less or equal to INT_MAX which is the largest int    */
/* number that can be expressed in c, integers range from -2^32 to (2^32)-1*/
/* The date is then tested for accuracy, that is if the date is correct and*/
/* and measured with leap year accuracy.				   */
/* dates that are found to be valid are the converted to the format:	   */
/*          day monthString year					   */
/* where monthString is represented as a capitalized 3 letter string       */
/* representing the month that corresponds to the integer number "month"   */
/* and then written into the standard output.				   */
/* After the program has parsed all possible dates, it appends the origianl*/
/* file to the output and terminates.					   */
/***************************************************************************/
/* 						Instructions/How to use:   */
/* To compile and run this specific program just enter:		           */
/* 		make build2										   				   */
/* followed by:  														   */
/*      ./dateConverter.out  > filename					   */
/* Where filename is the file that will hold the converted dates if any	   */
/*  									   */							   */
/***************************************************************************/

#include "convertDates.h"
/**
 * main: The following program takes standard imput and parses it searching for 
 * strings that follow the pattern day/month/year and converts it to the
 * format day monthString year.
 * @param  argc: The number of command line paramenters.
 * @param  argv: The parameters entered through the command line, including 
 * the program name at argv[0].
 * @return: Returns 0 which is NO_PROGRAM_ERRORS if the program runs without
 * any problems.
 */
int main(int argc, char const *argv[])
{
	translateDates(stdin, stdout);

	return NO_PROGRAM_ERRORS;
}

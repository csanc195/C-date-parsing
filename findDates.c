/***************************************************************************/
/*      findDates.c 	 Prog I 										   */
/***************************************************************************/
/* Author: Carlos L Sanchez Vila   Panther ID: 5446178					   */
/* Class: COP4338, Instructor: William Feilds Session: Tu and Th 6:25 pm   */
/***************************************************************************/
/*                      Disclaimer:										   */
/* I hereby certify that this collective work is my own and none of it is  */
/* the work of any other person or entity.								   */
/***************************************************************************/
/*              		Program Description:							   */
/* The following program goes through imput passed through stdin and 	   */
/* reads entries that follow the pattern of 							   */
/*			number(month)/number(day)/number(year)						   */
/* verifies that they represent a valid date, that is, the date is valid   */
/* if the day is a number from 1 to 31, if a month is a number from 1 to 12*/
/* and if the year is less or equal to INT_MAX which is the largest int    */
/* number that can be expressed in c, integers range from -2^32 to (2^32)-1*/
/* The date is then tested for accuracy, that is if the date is correct and*/
/* and measured with leap year accuracy.								   */
/***************************************************************************/
/* 						Instructions/How to use:						   */
/* To compile and run this specific program just enter:	                   */
/* 		make build1														   */
/* followed by: 														   */
/*      ./dateParser.out num < filename									   */
/* where num is the number of valid dates that the user desires to parse   */
/* and filename is the file to parse.							           */
/* 																		   */
/***************************************************************************/
#include "findDates.h"	/* Include the header file for the program findDates*/


/**
 * The following program parses a file and gets any string that matches 
 * the pattern month/day/year and validates that said date is correct, it 
 * then outputs them to the standard output.
 * @param  argc: the number of command line paramenters.
 * @param  argv: The parameters entered through the command line, including 
 * the program name at argv[0].
 * @return: Returns 0 which is NO_PROGRAM_ERRORS if the program runs without
 * any problems.
 */
int main(int argc, char const *argv[]){
	
   if(argc > NUM_OF_VALID_PARAMS){
   		
   		char *stringPart;
   		long val;

   		val = strtol(argv[INDEX_OF_FIRST_PARAM], &stringPart, DEC_BASE_TEN);

   		if (validateCommandLineImputs(val, stringPart)){
   			parseFileForDates(stdin, stdout, (int)val);	
   		}
	}

	return NO_PROGRAM_ERRORS;
}

/**
 * This function validates the only command line imput required by this program
 * and determines if its valid or invalid, it is valid if the number entered is 
 * greater or equal to zero and false if it is less than zero, if its not a 
 * valid number, ex: contains letters or other symbols, or if the number is 
 * larger than the size of INT_MAX, which is the size of integer.
 * 
 * @param  numOfDates: This is the number to be validated.
 * @return: True if the imput is valid, false otherwise.
 */
bool validateCommandLineImputs(long numberEntered, char *stringPart){
	bool answer = TRUE;

	if(stringPart[0] != '\0' || numberEntered < 0 || numberEntered > INT_MAX){
		answer = FALSE;
	} 
	return answer;
}










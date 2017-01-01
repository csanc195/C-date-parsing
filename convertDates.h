/***************************************************************************/
/*      convertDates.h 	 header for Prog II								                 */
/***************************************************************************/
/* This header file contains the function prototypes for the program       */
/* convertDates.c, it also contains all of the needed definitions and 	   */
/* libraries															                                 */
/***************************************************************************/

#include <stdio.h>
#include <stdlib.h>				/* Included to use strtol()					  */
#include <limits.h>				/* Included to use the constant INT_MAX       */
#define BUFFER_SIZE 512			/* The maximun buffer size decided 			  */
#define NO_PROGRAM_ERRORS 0		/* The indication of correct execution		  */
#define PROGRAM_ERRORS 1		/* The indication of incorrect execution 	  */
#define NUM_DATE_ELEM 3			/* The number of params of any date entry	  */
#define MONTH_STRING_WIDTH 3	/* The month string length to be displayed	  */
#define JANUARY 1				/* The number representing January 			  */
#define FEBRUARY 2				/* The number representing February 		  */
#define MARCH 3					/* The number representing March 			  */
#define APRIL 4					/* The number representing April 			  */
#define MAY 5					/* The number representing May 				  */
#define JUNE 6					/* The number representing June 			  */
#define JULY 7					/* The number representing July 			  */
#define AUGUST 8				/* The number representing August 			  */
#define SEPTEMBER 9				/* The number representing September 		  */
#define OCTOBER 10				/* The number representing October 			  */
#define NOVEMBER 11				/* The number representing November 		  */
#define DECEMBER 12				/* The number representing December 		  */
#define REG_DAYS_IN_FEB 28		/* The Ususal lenght of February in days 	  */
#define MAX_POS_DAYS_A_MONTH 31 /* The Max possible number of days in a month */
#define MAX_NUM_MONTHS 12		/* The max possible number of months 		  */
#define NUMBER_FOUR 4			/* The number four needed to check leap years */
#define NUMBER_ONE_HUNDREED 100 /* The number 100 needed to check leap years  */
#define NUMBER_FOUR_HUNDREED 400/* The number 400 needed to check leap years  */
typedef enum {FALSE, TRUE} bool;/* Allow the use of the boolean type 		  */


/***************************************************************************/
/* Function Prototypes	 												   */
/***************************************************************************/
/* translateDates.c Function prototypes*/
void translateDates(FILE *, FILE *);
char* getMonthString(int);
bool checkIfDateIsValid(int, int, long);
bool validateDateWithCalendar(int, int, long);
void fileCopy(FILE *, FILE *);


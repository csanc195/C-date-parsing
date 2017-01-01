/***************************************************************************/
/*      translateDate.c 	 Prog II									   */
/***************************************************************************/
/* The following file is complementary for the program convertDates.c      */
/* this file contains functions which allow to parse entries from the      */
/* standard imput and separate any string that matches the pattern         */
/* month/day/year and converts them to the format day MonthString year.    */
/***************************************************************************/

#include "convertDates.h"



/**
 * translateDates: This function takes a file and parses it line by line,
 * searching for  entires matching the format month/day/year and converts them 
 * to the format day monthString year. Dates with invalid fields will be 
 * ignored, only dates with fields that are within the limits of their types 
 * will be taken in ex: int(month)/int(day)/long(year). 
 * @param ifp This is the imput file which will be parsed searching for dates.
 * @param ofp This is the file which will carry the output if any.
 */
void translateDates(FILE *ifp, FILE *ofp){
	
	int month, day;
	long year;
 	char line[BUFFER_SIZE];
    
    while (fgets(line, sizeof(line), ifp)) {
		
    	if(sscanf(line, "%d/%d/%lu", &month, &day, &year) == NUM_DATE_ELEM){

            if(checkIfDateIsValid(month, day, year) 
                && validateDateWithCalendar(month, day, year)){

                char newDateString[BUFFER_SIZE];
                char *monthAbrev = getMonthString(month);

                sprintf(newDateString, "%2d %.*s %d \n", 
                	day, MONTH_STRING_WIDTH, monthAbrev, (int)year);

                fputs(newDateString, ofp);
            }
    	} 
    }


    FILE *dateFile;
    dateFile = fopen("./dates.dat", "r");
    
    fileCopy(dateFile, ofp);
}


/**
 * getMonthString: The following function takes a month number and returns 
 * its string representation, this function used after checkIfDateIsValid() 
 * will ensure that there is always a valid month string to be returned.
 * 
 * @param  monthNum: This is the number to be translated into a string.
 * @return: This function returns the string representation of the entered
 * month. 
 */
char* getMonthString(int monthNum){
	char *monthNames[MAX_NUM_MONTHS] = {
        "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
		"JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

	return monthNames[monthNum - 1];
}


/**
 * checkIfDateIsValid: This function validates if the entered month day
 * and year are valid and can form a valid date in conjunction.
 * @param  month: The month integer to be validated.
 * @param  day: The day integer to be validated.
 * @param  year: The year long number to be validated.
 * @return: True if the date is valid, false otherwise.
 */
bool checkIfDateIsValid(int month, int day, long year){
    bool answer = TRUE;

    if((month < 1 || month > MAX_NUM_MONTHS) 
        || (day < 1 || day > MAX_POS_DAYS_A_MONTH) || (labs(year) > INT_MAX)){
        answer = FALSE;
    }

    return answer;
}


/**
 * validateDateWithCalendar: This function validates a date and determines if 
 * the entered date is possible in a modern cadelndar setting by testing 
 * if its within the number of days per month for its month, also considering 
 * the case when there is a leap year, this function is used in conjunction 
 * with the function check if dateIsValid() which will ensure that every number
 * entered, day and month, are valid and within their limits.
 * @param  month: Month of the date to be validated.
 * @param  day: Day of the date to be validated.
 * @param  year: Year of the date to be validated.
 * @return: Retuns True if the date is valid, false otherwise.
 */
bool validateDateWithCalendar(int month, int day, long year){
    bool answer = TRUE;


    if(month == FEBRUARY && day > REG_DAYS_IN_FEB){
        int isLeap;
        isLeap = (year % NUMBER_FOUR == 0) 
                || (year % NUMBER_ONE_HUNDREED != 0) 
                || (year % NUMBER_FOUR_HUNDREED == 0);

        answer = (day <= (REG_DAYS_IN_FEB + isLeap));
    } else if(month == JANUARY 
        || month == MARCH 
        || month == MAY 
        || month == JULY 
        || month == AUGUST
        || month == DECEMBER){

        answer = TRUE;
    } else if(month == APRIL 
        || month == JUNE 
        || month == SEPTEMBER 
        || month == NOVEMBER){
        
        answer = (day < MAX_POS_DAYS_A_MONTH);
    } 

    return answer;
}


/**
 * fileCopy: This function takes a file and copies it to another file.
 * @param ifp: Source file.
 * @param ofp: The destination file.
 */
void fileCopy(FILE *ifp, FILE *ofp){

    char line[BUFFER_SIZE];

    while (fgets(line, sizeof(line), ifp)){
        fputs(line, ofp);
    }
    /* Add a new line character at the end of the file. */
    fputc('\n', ofp);

    fclose(ofp);
    fclose(ifp);
}







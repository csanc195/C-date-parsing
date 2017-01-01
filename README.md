# C-date-parsing
The following files depict two programs that parse files and obtain a desired amount of dates, both programs make use of Unix pipes and input and output commands.

The first program <b>findDates.c</b> parses through the given file and selects dates in the format <b>month/day/year</b>, and proceeds to verify that each of such dates is valid, that is if each one of the numbers is within the valid calendar parameters, including leap year verification. This program will output a number of valid dates, this number along with the file to be parsed will be provided by the user through the Unix or linux terminal like so: 
<br><b>./datesParser.out < DatesFile.txt  x</b><br>

with x being the number of dates to print, if the number 0 is entered, the program will print all valid dates contained in the file; notice that the program output can be rerouted to a destination file like so:
<br><b>./datesParser.out < DatesFile.txt x | > output.txt</b><br> 

The second program <b>converDates.c</b> parses through a file and searches for dates matching the format <b>month/day/year</b>, and converts each one to the abbreviated month & year format (i.e. 1 JAN 1900), followed by the original list of dates in month/day/year format <b>(i.e. 1/1/1900).</b>

This program will output a number of valid dates in the mentioned format, this number along with the file to be parsed will be provided by the user through the Unix or linux terminal like so: 
<br><b>$ dateConverter.out < DatesFile.txt x </b><br>
notice that the program output can be rerouted to a destination file like so: 
<br><b>$ ./dateConverter.out < DatesFile.txt x | > output.txt</b><br>

Notice that both programs can be used in conjunction to parse a file for dates using the first program, then pass this output to the second program using Unix pipes, this would enable take advantage of two diferent programs to achieve the goal of scanning through a file select valid dates and then convert said dates to the to the abbreviated month & year format (i.e. 1 JAN 1900). This can be achieved by the following line of instructions:

<b>$  ./program1  <  dates.dat  0  |  ./program2  >  output.dat		</b>

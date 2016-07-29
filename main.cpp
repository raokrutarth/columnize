/*
     A program that reads text and outputs it in multiple column format.  
     The input consists of a first line containing a single number C, the number of columns in the 
     subsequent lines. The second and later lines contain C integers per line separated by 
     whitespace. All numbers will be greater than or equal to 0 and less than 1000. The program 
     outputs the data organized into a columns as follows:  
        Each number occupies the space of 3 digits, right justified, and with no leading zeros 
        Columns are separated by the string: “ | ” (space, pipe symbol, space) 
        The first and the last line contain exactly 6C-3 dash characters (“-“), i.e. the same number of characters as each of the remaining lines 
        There is no other extraneous whitespace or trailing separators
*/

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;
char * lineMaker(int n)
{
    int i = (6*n) - 3;
    int h = 0;
    char * line = (char *)malloc(sizeof(char)*n*6);
    for(; h < i; h++)
        *(line + h) ='-';
    *(line + h) = '\0';
    return line;
}
char * NumberRow(FILE * fl, int n)
{
    char * result = (char*)malloc(sizeof(char)*n*6);
	char * num = (char*)malloc(sizeof(char)*5);
    int i = 0;
    for(int y = 0; y < n-1 && !feof(fl); y++)
	{
		fscanf(fl, "%d ", &i);
		sprintf(num, "%*d | ", 3, i);
		strcat(result, num);
	}
	fscanf(fl, "%d", &i);
	sprintf(num, "%*d", 3, i);
	strcat(result, num);		
    return result;
}
int main(int argc, char** argv)
{
    FILE *inputfile = stdin;
	FILE *outputfile = stdout;

	if( inputfile == NULL || outputfile == NULL)
        return 0;
    else
    {
        int i = 0;
        int n;
        fscanf(inputfile, "%d", &n);
        fprintf(outputfile, "%s\n", lineMaker(n) );
		//string line;
		//char  * line = (char *)malloc(sizeof(char)*n*6);
        char c = fgetc(inputfile);
        fprintf(outputfile, "%s\n", NumberRow(inputfile, n));
        while( ( c = fgetc(inputfile) ) != EOF)
        {
            if(c == '\n' )
            {
				//line[i] = '\0';
                //printf("LINE : %s\n\n", line);
                fprintf(outputfile, "%s\n", NumberRow(inputfile, n));
                //fprintf(outputfile, "%s\n", lineMaker(n) );
                //i = 0;              
            }    
        }
        fprintf(outputfile, "%s\n", lineMaker(n) );
    }
    fclose(inputfile);
    fclose(outputfile);
    return 0;
}
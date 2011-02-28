/*
 * mystrings.c
 * Sean M. Brooks
 * Project 02
 * CS 0449
 * Professor Jack Lange
 * 02.27.2011
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
	char string_to_print[101] = {""};	/* String to Print Buffer; */
	if(argc == 1)	/* Test for Argument(s); */
	{
		printf("No Argument Provided!\n");
		return (-1);	/* Fail! */
	}
	FILE *read_file;
	read_file = fopen(argv[1], "r");
	if(read_file ==	NULL)	/* Test for File Not Found; */
	{
		printf("File Not Found!");
		return (-1);	/* Fail! */
	}
	fseek(read_file, 0, SEEK_SET);	/* Seek to Beginning; */
	int char_read;	/* Character Read; */
	int con_char_count = 0;	/* Concurrent Character Count; */
	while( (char_read = fgetc(read_file)) != EOF )	/* Read All Characters; */
	{
		if(char_read >= 32 && char_read <= 126)	/* Test for Printing Character; */
		{
			string_to_print[con_char_count] = char_read;	/* Add to Buffer; */
			con_char_count++;	/* Increment Count; */
			if(con_char_count == 101)	/* Test for Full Buffer; */
			{
				string_to_print[con_char_count] = '\0';	/* Null Terminate; */
				printf("%s\n", string_to_print);	/* Print; */
				con_char_count = 0;	/* Reset Counter; */
			}
		}
		else
		{
			if(con_char_count >= 4)	/* Test for Printworthy Count; */
			{
				string_to_print[con_char_count] = '\0';	/* Null Terminate; */
				printf("%s\n", string_to_print);	/* Print; */
			}
			con_char_count = 0;	/* Reset Counter; */
		}
	}
	fclose(read_file);	/* Close File; */
	return (0);	/* Success! */
}


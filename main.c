#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stringNotFound = 1;

struct fileinfo
{
	char *readfrom;
	char *writeto;
	char *searchfor;
	char *charcase;
};


void fileappend(struct fileinfo progData, char *origInput, char *origLine, int linecount)
{
	FILE * fp;
	fp = fopen(progData.writeto, "a");
	fprintf(fp, "The string '%s' was found in '%s' on line %d\n", origInput, origLine, linecount);
	fclose(fp);
}


void strExist(char *tmp, struct fileinfo progData, int linecount, char *origLine, char *origInput)
{	
	if (strstr(tmp, progData.searchfor) != NULL)
	{
		stringNotFound = 0;
		if (strstr(progData.writeto, ".") != NULL)
		{
			fileappend(progData, origInput, origLine, linecount);
		}
		else
		{
			printf("\n\n\t--> The string '%s' was found in '%s' on line %d", origInput, origLine, linecount);
		}
	}
}


void readfromstdio(char *strinp, struct fileinfo progData) 
{
	char origLine[100];
	char origInput[100];
	origLine[0] = '\0';
	origInput[0] = '\0';
	strcpy(origLine, strinp);
	strcpy(origInput, progData.searchfor);
	
	if (strstr(progData.charcase, "I") != NULL)
	{
		
		strlwr(strinp);
		strlwr(progData.searchfor);
	}
	
	if (strstr(strinp, progData.searchfor) != NULL)
	{
		stringNotFound = 0;
		if (!strcmp(progData.writeto, "stdout"))
		{
			printf("\n\n\t--> The string '%s' was found in '%s'", origInput, origLine);
		}
		else
		{
			int linecount = 0;
			fileappend(progData, origInput, origLine, linecount);
		}
	}	
}

void openfile(struct fileinfo progData)
{
	FILE *file;
	file = fopen(progData.readfrom, "r");
	if (file == NULL)
	{
		printf("\n\t- The file %s was not found. Please try again.", progData.readfrom);
	}
	else
	{
		char ch;
		char tmp[100];
		tmp[0] = '\0';
		int count = 0;
		int linecount = 0;
		char origLine[100];
		char origInput[100];
		origLine[0] = '\0';
		origInput[0] = '\0';
		
		strcpy(origInput, progData.searchfor);
		while ((ch = fgetc(file))!= EOF)
		{
			if (ch == '\n')
			{
				linecount++;
			}
			if ((ch == ' ') || (ch == '\n'))
			{
				strcpy(origLine, tmp);
				if (!strcmp(progData.charcase, "I"))
				{
					strlwr(tmp);
					strlwr(progData.searchfor);
				}
				strExist(tmp, progData, linecount, origLine, origInput);
				memset(tmp, 0, sizeof(tmp));
				memset(origLine, 0, sizeof(origLine));
				count++;
			}
			else
			{
				char hold[100] = {ch};
				strncat(tmp, hold, 1);
			}
		}
		fclose(file);
	}
}

int main(int argc, char *argv[])
{
	char array[20][20];
	stringNotFound = 1;
	struct fileinfo progData;
	for (int i = 0; i < argc; i++)
	{
		strcpy(array[i], argv[i]);
	}

	if ((strlen(array[3])<1) || (!strcmp(array[2], "-o")))
	{
		printf("\n\t- Please enter a string/file to search through.\n");
	}
	
	else
	{
		progData.searchfor = array[1]; 
		if(!strcmp(array[2], "-i") && (strstr(array[3], ".") != NULL))
		{
			printf("\n\t- Reading data from %s", array[3]);
			progData.readfrom = array[3];
		}
		else
		{
			printf("\n\t- Reading data from keyboard");
			progData.readfrom = "stdin";
		}
		if (!strcmp(array[4], "-o"))
		{
			printf("\n\t- Writing data to %s", array[5]);
			progData.writeto = array[5];
		}
		else
		{
			printf("\n\t- Writing data to console.");
			progData.writeto = "stdout";
		}
		if (strstr(array[argc-1], "-c"))
		{
			printf("\n\t- Ignoring case");
			progData.charcase = "I";
		}
		else
		{
			progData.charcase = "U";
		}
		if (strcmp(progData.readfrom, "stdin"))
		{
			openfile(progData);
		}
		else
		{
			char *strinp = array[3];
			readfromstdio(strinp, progData);
		}	
		
		if (stringNotFound)
		{
			printf("\n\t- String not found...");
		}
	}
	puts("");		
	return 0;
}


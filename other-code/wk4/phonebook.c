#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <dirent.h>
#include <stdlib.h>

// Declare prototypes
void append_file();
void write_file();
void another_operation();
void choose_operation();
void get_contact_details();
void first_x_chars();
void print_file_to_screen();
int copy_file();
int list_files(void);
int check_file_exists(char *x);
void useFread();
void useFwrite();
void useFwriteFull();

// global variables
FILE *file;  // create pointer of type FILE using the file name 'file'
FILE *file2; // create pointer of type FILE using the file name 'file2'
char *fileName;
char *toFileName;
char *fromFileName;

int main(void)
{
    choose_operation();
    another_operation();
}

// ask user if they want to perform anything else
void another_operation()
{
    char answer;
    do
    {
        answer = get_char("Another operation? (Y/N) ");
    }
    while ((answer != 'y') && (answer != 'Y') && (answer != 'n') && (answer != 'N'));

    if (answer == 'y' || answer == 'Y')
        main();
    if (answer == 'n' || answer == 'N')
        exit(0);
}

void choose_operation()
{
    system ("clear");
    printf("\n");
    printf("1 - Make changes to file phonebook.csv\n");
    printf("2 - Recreate phonebook.csv with no data\n");
    printf("3 - Display specified number of characters from phonebook.csv\n");
    printf("4 - Display entire contents of phonebook.csv\n");
    printf("5 - Make new copy of phonebook.csv\n");
    printf("6 - List files in current directory\n");
    printf("7 - Confirm file exists\n");
    printf("8 - Read file contents using fread\n");
    //printf("9 - Write specified number of characters to a new file\n");
    printf("9 - Make a new copy using fwrite\n");
    printf("x - Quit program\n");
    printf("\n");
    char answer = get_char("Please make a selection: ");

    if (answer == '1')
        append_file();
    else if (answer == '2')
        write_file();
    else if (answer == '3')
        first_x_chars();
    else if (answer == '4')
        print_file_to_screen();
    else if (answer == '5')
        copy_file();
    else if (answer == '6')
        list_files();
    else if (answer == '7')
    {
        fileName = get_string("Enter filename: ");
        if (check_file_exists(fileName) == 1)
            printf("File found\n");
        else
            printf("File not found\n");
    }
    else if (answer == '8')
        useFread();
    // else if (answer == '9')
    //     useFwrite();
    else if (answer == '9')
        useFwriteFull();
    else if (answer == 'x')
        exit(0);
    else
    {
        choose_operation();
    }
}

void append_file()
{
    // open phonebook.csv in append mode and store location in pointer 'file'
    file = fopen("phonebook.csv", "a");

    // quit if file is null
    if (file == NULL)
        exit(0);

    get_contact_details();
}

// also creates the file if it doesn't exist
void write_file()
{
    // open phonebook.csv in write mode and store location in pointer 'file'
    file = fopen("phonebook.csv", "w");

    // quit if file is null
    if (file == NULL)
        exit(0);

    get_contact_details();
}

void get_contact_details()
{
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // this prints to a file along with the format (like printf)
    fprintf(file, "%s,%s\n", name, number);

    fclose(file);
}

void first_x_chars()
{
    // open phonebook.csv in read mode and store location in pointer 'file'
    file = fopen("phonebook.csv", "r");

    // quit if file is null
    if (file == NULL)
        exit(0);

    int numberOfChars = get_int("Enter number of characters: ");

    printf("First %i characters are: \n", numberOfChars);
    for (int i = 0; i < numberOfChars+1; i++)
    {
        char nextChar = fgetc(file);
        if (nextChar != EOF)
        {
            printf("%c", nextChar);
        }
    }
    printf("\n");
    fclose(file);
}

void print_file_to_screen()
{
    // open phonebook.csv in read mode and store location in pointer 'file'
    file = fopen("phonebook.csv", "r");

    // quit if file is null
    if (file == NULL)
        exit(0);

    char nextChar;
    // get next character from the current file and store it in nextChar, unless End Of File reached
    while((nextChar = fgetc(file)) != EOF)
    {
        printf("%c", nextChar);
    }
    fclose(file);
}

int copy_file()
{
    fileName = get_string("Please enter a name for the copy: ");

    // make sure file doesn't exist to avoid overwrite
    if (check_file_exists(fileName) == 1)
    {
        printf("File already exists.\n");
        return 1;
    }

    // open file to copy FROM in read mode and store location in pointer 'file'
    file = fopen("phonebook.csv", "r");
    if (file == NULL )
        exit(0);

    // open file to copy TO in write mode and store location in pointer 'file2'
    file2 = fopen(fileName, "w");
    if (file2 == NULL )
        exit(0);

    char nextChar;
    // get next character from the current file and store it in nextChar, unless End Of File reached
    while((nextChar = fgetc(file)) != EOF)
    {
        fputc(nextChar, file2);
    }

    fclose(file);
    return 0;
}

// the code in this function I got via Googling dirent
int list_files(void)
{
    // Pointer for directory entry
    struct dirent *de;

    // opendir() returns a pointer of DIR type.
    DIR *dr = opendir(".");

    // opendir returns NULL if couldn't open directory
    if (dr == NULL)
    {
        printf("Could not open current directory" );
        return 0;
    }

    // for readdir() refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
    while ((de = readdir(dr)) != NULL)
    {
        printf("%s\n", de->d_name);
    }

    closedir(dr);
    return 0;
}

int check_file_exists(char *x)
{
    // Pointer for directory entry
    struct dirent *de;

    // opendir() returns a pointer of DIR type.
    DIR *dr = opendir(".");

    // opendir returns NULL if couldn't open directory
    if (dr == NULL)
    {
        printf("Could not open current directory" );
        return 2;
    }

    while ((de = readdir(dr)) != NULL)
    {
        // x represents the name of the file them user is checking
        if (strcmp(de->d_name, x) == 0)
        {
            closedir(dr);
            return 1; // true if file found
        }
    }
    closedir(dr);
    return 0;  // false if file not found
}

void useFread()
{
    // open phonebook.csv in read mode and store location in pointer 'file'
    file = fopen("phonebook.csv", "r");

    // quit if file is null (not found most likely)
    if (file == NULL)
        exit(0);

    int numberOfChars = get_int("Enter number of characters: ");
    printf("First %i characters are: \n", numberOfChars);

    char tempArray[numberOfChars];
    fread(tempArray, sizeof(char), numberOfChars, file);

    // this is purely to print what's in there almost from a debug perspective really
    for (int i = 0; i < numberOfChars; i++)
    {
        printf("%c", tempArray[i]);
    }
    printf("\n");

    fclose(file);
}

void useFwrite()
{

    // ask user for filename to open
    fromFileName = get_string("Enter FROM filename: ");
    // ask user for file to create
    toFileName = get_string("Enter TO filename: ");

    // open phonebook.csv in read mode and store location in pointer 'file'
    file = fopen(fromFileName, "r");
    file2 = fopen(toFileName, "w");

    // quit if file is null
    if (file == NULL)
        exit(0);

    int numberOfChars = get_int("Enter number of characters: ");
    char tempArray[numberOfChars];

    // read required characters from file
    fread(tempArray, sizeof(char), numberOfChars, file);

    // write required characters from file
    fwrite(tempArray, sizeof(char), numberOfChars, file2);

    fclose(file);
    fclose(file2);
}


void useFwriteFull()
{

    // ask user for filename to open
    fromFileName = get_string("Enter FROM filename: ");
    // ask user for file to create
    toFileName = get_string("Enter TO filename: ");

    // open phonebook.csv in read mode and store location in pointer 'file'
    file = fopen(fromFileName, "r");
    file2 = fopen(toFileName, "w");

    // quit if file is null
    if (file == NULL)
        exit(0);

    // go to end of file
    fseek(file, 0L, SEEK_END);
    // store file size
    int size = ftell(file);
    // rewind to beginning of file
    rewind(file);

    // create variable to store data 1 byte at a time
    uint8_t buffer[size];

    // read required characters from file
    while (fread(&buffer, sizeof(uint8_t), size, file))
    {
        // check whether this fread was beyond end of file or an error was returned
        if (!feof(file2) || (!ferror(file2)))
        {
            // write required characters from file
            fwrite(&buffer, sizeof(uint8_t), size, file2);
        }
    }
    fclose(file);
    fclose(file2);
}
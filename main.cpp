#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
    fstream monsterFile;

    /**
    * Some initialization stuff to
    * get the dir
    */
    char *home = getenv("HOME");
    int length = strlen(home) + strlen("/.rlg327/maonster_desc.txt") +1;
    char *path = (char*)malloc(length);
    strcpy(path, home);
    strcat(path, "/.rlg327/monster_desc.txt");

    /**
    * Begin attepmting to open file if not terminate
    * program
    */
    monsterFile.open(path);
    if(monsterFile.is_open())
    {
        /**
         * Proceed with reading information
         */
        cout << "File was opened" << endl;
        cout << "Starting to read file" << endl;
        
        char buffer[256];
        int startFound = 0;
        

        //If the first line of the file does not match the header then exit program
        monsterFile.getline(buffer, 256);

        if(strcmp(buffer, "RLG327 MONSTER DESCRIPTION 1") != 0)
        {
            cout << "Incorrect file header\n Exiting program" << endl;
            free(path);
            monsterFile.close();
            return -1;
        }
        else
        {
            cout << "File has correct header" << endl;
            monsterFile.getline(buffer, 256);
        }

        while(!monsterFile.eof())
        {
            monsterFile.getline(buffer, 256);
            const char s[2] = " ";
            char *token;
            token = strtok(buffer,s);
            
            while(1)
            {
                if(strcmp (token, "NAME") == 0)
                {
                    while(token != NULL)
                    {
                        token = strtok(NULL, s);
                        printf("%s ", token);
                    }
                    printf("\n");
                    break;
                }
                else if(strcmp(token, "SYMB") == 0)
                {
                    while(token != NULL)
                    {
                        token = strtok(NULL, s);
                        printf("%s ", token);
        
                    }
                    printf("\n");
                    break;
                }
                else if(strcmp(token, "COLOR") == 0)
                {
                    while (token != NULL)
                    {
                        token = strtok(NULL, s);
                        printf("%s ", token);

                    }
                    printf("\n");
                    break;
                }
                else
                {
                    cout << "reached else statement" << endl;
                    token = NULL;
                    break;
                }
                //printf("%s\n", token);  
            }
            //cout << buffer << endl;
        }
    }else
    {
        cout << "File could not be found or open" << endl;
    }
    
    /**
     * Finish up the program 
     * free the memory and close the file stream object
     */ 

    monsterFile.close();
    free(path);
    return 0;
}
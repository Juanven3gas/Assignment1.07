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
    int length = strlen(home) + strlen("/.rlg327/maonster.txt") +1;
    char *path = (char*)malloc(length);
    strcpy(path, home);
    strcat(path, "/.rlg327/monster.txt");

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

        while(!monsterFile.eof())
        {
            monsterFile.getline(buffer, 256);
            cout << buffer << endl;
        }
    }
    
    /**
     * Finish up the program 
     * free the memory and close the file stream object
     */ 

    monsterFile.close();
    free(path);
    return 0;
}
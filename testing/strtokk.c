/* strtok example */
#include <stdio.h>
#include <string.h>


static char * gettokens(char str[], char * pch){
       pch = strtok(str," < ");
            
	return pch;
}

int main ()
{
      char str[] ="wc < file.txt";
        char * pch;
          printf ("Splitting string \"%s\" into tokens:\n",str);
	  gettokens(str, pch);
	  while (pch != NULL)
                    {
                            printf ("%s\n",pch);
                                pch = strtok (NULL, " ,.-");
                     }
            
                return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define REGID_LEN 64
#define REGID_FILENAME_LEN 8

int serviceGetHostId(char *idtype,int idlen, char *idval, int idvallen)
{
   strcpy(idtype,"2345678901234567890123456789");
   strcpy(idval,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
   return 0;
}
int genRegidPath(char **pfilename)
{
   char idtype[REGID_LEN], idvalue[REGID_LEN];
   memset(idtype,0,sizeof(idtype));
   memset(idvalue,0,sizeof(idvalue));
   if (0 != serviceGetHostId(idtype,REGID_LEN-1,idvalue,REGID_LEN-1))
      return 1;
   idvalue[REGID_FILENAME_LEN]=0;
   char *filename = calloc(1,REGID_FILENAME_LEN*sizeof(char));
   if (filename)
      snprintf(filename,REGID_LEN,"/tmp/%s_act.bin",idvalue);
   else
      return 1;
   *pfilename=filename;
   return 0;
}

int main()
{
   char *filename=NULL;
   int res=genRegidPath(&filename);
   printf("\n Regid filename : %s : %d\n",filename, REGID_LEN);
}

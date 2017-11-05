#include "stdio.h"
void WriteLogFile(const char* szString)
{
  #IFDEF DEBUG
 
  FILE* pFile = fopen("logFile.txt", "a");
  fprintf(pFile, "%s\n",szString);
  fclose(pFile);
 
  #ENDIF
 
}

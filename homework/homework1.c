iinclude <stdio.h>  /* helped by rulgamer07 & Lil Roi*/
#include <string.h> /*strstr*/

#define MAX 100
void quitpar(char l[MAX], char ls[MAX]); /* Eliminate < > (input, output) */
void quitspa(char l [MAX], char ls[MAX]); /* Changes the \t and ' '  by _ (input, output)  */
void strong(char l [MAX], char lstag[MAX]); /*Searches <strong> and <\strong> to change the \t and ' '  by _ (input, output) */
char ls[MAX], ls[MAX];
int pull(); /* Function that give us the line*/

int main() {
  extern char l[];
  char ls[MAX];
  char lstag[MAX];
  char lsspa[MAX];
  char lsstr[MAX];
  int ign = 0;
  int ignt = 0;

  int ignimg = 0;
  int ignforms =0;
  int spaces = 0;

  int l = 0;

  while ((l = pull()) == 0) {
    if (strstr(l, "<form") != NULL) { /* if we found  "<Form" ignore*/
      ignforms = 1;
    }
    if (strstr(l, "<table") != NULL) {
      ignt = 1;
    }
    if (strstr(l, "<script") != NULL) {
      ign = 1;
    }
    if (strstr(l, "<img") != NULL) {
      ignimg = 1;
    }

    if (strstr(l, "<div") != NULL) {
      ign = 1;
    }
    if (!ignt&&!ignforms&&!ignimg && !ign && strstr(l, "<html>") == NULL && strstr(l, "<body>") == NULL && strstr(l, "</html>") == NULL && strstr(l, "</body>") == NULL) {

    if (strstr(l, "<h1") != NULL || strstr(l, "<h2") != NULL || strstr(l, "<h3") != NULL ||  strstr(l, "<h4") != NULL || strstr(l, "<h5") != NULL  || strstr(l, "<h6") != NULL  ) {
      quitspa(l,ls);
      quitpar(ls, lstag);
      printf("%s\n", lstag);

    }
    else if (strstr(l, "<strong>") != NULL) {
      strong(l, lsstr);
      quitpar(lsstr,lstag);
      printf("%s\n", lstag);
    }


      else{
      quitpar(l,lstag);
      printf("%s\n", lstag);
    }
    }

    if (strstr(l, "</script>") != NULL) { /* if  found  "</script>" stop ignoring*/
      ign = 0;
    }
    if (strstr(l, "</div>") != NULL) {
      ign = 0;
    }
    if (strstr(l, ">") != NULL) {
      ignimg = 0;
    }
    if (strstr(l, "</form>") != NULL) {
      ignforms = 0;
    }
    if (strstr(l, "</table>") != NULL) {
      ignt = 0;
    }

  }
  return 0;
}

int pull() { // Give us the line
  extern char l[];
  int c, i = 0;

  for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n';) {

        l[i++] = c;

  }
  l[i] = '\0'; /* caracter end of string*/
  return c == EOF;
}

/* Change the \t and ' '  by _ (input, output)  */
void quitpar(char chain [MAX], char schain[MAX])
{
int a;
for (a=0;a<MAX;a++){ /*Read  the string, one by one */
   if (chain[a] != ' '&& chain[a] != '\t'){
    schain[a] = chain[a];
   }
   else{
    schain[a]= '_';
   }
}

}
/* Eliminate < > (input, output) */
void quitpar(char chain[MAX], char schain[MAX])
{
int a;
int c=0;
int b=0;
for (a=0;a<MAX;a++){
    if (chain[a]=='<'){
        c++;
    }
    if (chain[a]=='>'){
        c--;
    }
    if (chain[a]!='>'&&chain[a]!='<'&&c!=1){
        schain[b]=chain[a];
        b++;
    }

}
}

/*Search <strong> and <\strong> to change the \t and ' '  by _ (input, output) */
void strong(char chain[MAX], char schain[MAX]){
int a;
int c=0;

for (a=0;a<MAX;a++){
   if (chain[a]=='<'&&chain[a+1]=='s'&&chain[a+2]=='t'&&chain[a+3]=='r'&&chain[a+4]=='o'&&chain[a+5]=='n'&&chain[a+6]=='g'&&chain[a+7]=='>'){
    c = 1;
   }
    if (chain[a]=='<'&&chain[a+1]=='\\'&&chain[a+2]=='s'&&chain[a+3]=='t'&&chain[a+4]=='r'&&chain[a+5]=='o'&&chain[a+6]=='n'&&chain[a+7]=='g'&&chain[a+7]=='>'){
    c = 0;
   }
   if (c==1){
    if (chain[a] != ' '&& chain[a] != '\t'){
    schain[a] = chain[a];
   }
   else{
    schain[a]= '_';
   }
   }
   if (c==0){
    schain[a]=chain[a];
   }
}
}

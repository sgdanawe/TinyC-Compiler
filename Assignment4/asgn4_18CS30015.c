#include <stdio.h>
#include "y.tab.h"
extern int yyparse();

int main() {
  extern int yydebug;
  yydebug=0;
  int i=yyparse();
  if(i) printf("Failure!\n");
  else printf("Success!\n");
  return 0;
}
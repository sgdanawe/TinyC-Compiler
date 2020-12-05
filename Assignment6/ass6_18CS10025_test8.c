int prints(char *c);
int printi(int i);
int readi(int *eP);
int e=5;			// test : scope of global variables

int main()
{
  	// scope management 
  { int w=1;
    prints("\nScope1:");printi(w);
    { 
      int w=2;
      prints("\nScope2:");printi(w);
      { 
        int w=3;
        if ( w = 9)prints("I entered it");
        prints("\nScope3:");printi(w);

      }
    }

  }
    /*
    test do while
    */
    int do_iterator=0;
    do {
      prints("\nHi this is my ");
      printi(do_iterator++);			// incrementor in prints
      prints("loop");

      }while(do_iterator<10);



  return 0;
}

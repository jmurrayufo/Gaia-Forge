// This document should have just about every example we will need to use


// Functions
int foo(int x, int y)   // Spaces after the , 
{   // This always gets it's own line!
    int x;      // Just an int
    int y=5;    // You can declare stuff if needed!
    int *z;     // * on pointers go with the VARiABLE! 

    while( 1 ) // Spaces around the arguments help readability 
    {   // This always gets it's own line!
        int food;   // This scopes to the While loop, and is removed when you leave it. 
    }
}

//**************************
//*** Class Header Files ***
//**************************

// All class header files must be protected by a #ifndef. Use the _Cname_H_ style (always all caps)
#ifndef _CFOO_H_
    #define _CFOO_H_

// Class names begin with a C, following by a descriptive name. 
class CFoo {
public:
   CFoo();
   ~CFoo();

   void OnCleanup();

   void OnInit();

   void OnLoop();

   void OnRednerGL();

};
// Mark your endif to show what it links too. 
#endif // CFoo 


// Class Source Files

// TODO: Add the following to the code style sheet
/*
    Comments
    Class Variables
    Function/Variable Names
    Header Files
    Defines
    Globals
*/
2016/04/26
Starting to play with Visual Studio Refactoring. Compiles before starting. This archive for rollback if refactoring breaks it.

2016/04/26

Did a little work moving some public functions to private. compiles.

2016/04/20
This is work in progress. Might be broken. Go back to archive version if doesn't work.

TODO:
0. Concentrate on structure. Come up with a plan. Clean up existing code
1. DONE:Break up UserInterface.h and UserInterface.cpp into four separate files for clarity (and "one class one file" rule): 
UserInterface.h and UserInterface.cpp
WidgetTable.h and WidgetTable.cpp
2. Clean up WidgetTable - make most functions and members private, create access functions.
3. For now, implementation of functions does not have to be done - just leave a 'cout << "function such and such called" << endl;' if you need to.

2016/04/17

Builds and runs without issues
This has been put into a new solution on April 17th 2016.
Using settings that worked previously.
Headers + source files in 'src' folder.
Do not modify files in src/FLUID - these are used by FLUID, an FLTK editor.
The header file and source file in src/FLUID must be included in the project for it to work.
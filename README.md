# ITDEV-185-Advanced-OOP

**ASSIGNMENT 1**-  This assignment had us design a program that would take in a date (month/year) and any amount of money.  The amount would be how much a business brought in in a month total.  The code would then take that money and calcuate various tax amounts and output several things such as county tax collected, sales tax collected, total tax etc.
The objective was for us to familiarize ourselves with formatting output in C++ and how to handle input and output data.


**ASSIGNMENT 2**-  The program asks the user to input various names to a file.  The names are then read from the file back into the program.  The output is the student who is at the front of the line alphabetically and the student who is at the back of the line alphabetically.  No arrays or vectors are used, the program simply compares each name with the name that currently holds the spot as either last in line or first in line.  The objective was for us to familarize ourselves with text reading and writing and also how to compare string values.


**ASSIGNMENT 3**-  This program asks the user to input several values including how many spools to be ordered, how many spools are in stock, any special shipping charges to apply.  The program validates the input and then the input is sent to a separate function that does several calculations to determine a final cost.  The objective of this assignment was to familiarize us with more complicated format outputting and also to start using separate functions in our program instead of running everything in Main().


**ASSIGNMENT 4**-  This program has the user flip coins until the total either equals $1 exactly for a win or goes over $1 for a lose.  The program instantiates 3 Coin classes (one nickel, one dime, and one quarter).  Each turn, all 3 coins are flipped.  If the coin lands on heads, it's amount is added to the balance, if it lands on tails nothing is added to the balance.  This continues until the total reaches a dollar or more.  The objective of this program was to get us familiar with using creating our own classes, instantiating those classes, and then using them in a program.  


**ASSIGNMENT 5**-  This program is a slot machine.  I created 3 classes, one called Reel that randomly chose an animal from an array.  One called slot machine that had 3 Reel objects as its game face.  It would spin the "wheel" of Reel objects and check for when all three Reel objects were equal.  The main function kept track of how many games were played until a win occured.  The purpose of this assignment was to get us more familiar with using header files, implementation files, and using each of them together.  


**ASSIGNMENT 6**-  This program simulates 100 different "Players" rolling 20 dice each.  All 20 dice from each individual player is added up and the player with the highest total is declared the winner.  The purpose of this assignment was to start using pointers.  Pointers were used to pass arguments to a function and also as a return value from a function.


**ASSIGNMENT 7**-  This program was a bit of a redo from assignment 4 but was an introduction to child classes and static member functions and variables.  So the logic was the same but we created 3 child classes, one for each of a nickel, dime and a quarter.  Each of these child classes was instantiated in main() and then passed by a pointer to a function where it's value was added to a static balance variable.  

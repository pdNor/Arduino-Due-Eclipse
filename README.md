##Arduino Due template for Eclipse

This project is based on the arduino due template found [here](http://sourceforge.net/p/gnuarmeclipse/feature-requests/64/) The only difference is that this template includes the arduino standard library. This project may be used by anyone, but it is used at own risk! Bugs are very likely to occur.

##Notes
1. delay function rewritten not calibrated. wiring.c

##Issues 
 
1. Strange error in syscalls.h line 43 removed
2. Check all warnings
3. In order to compile the project, the symbol SAM3X8E must be defined.
4. In order to compile the project, the symbol F_CPU must be defined.
5. Calibrate delay function.
6. analogWrite functions
7. Interrupt functions
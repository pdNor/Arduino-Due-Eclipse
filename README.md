#Arduino Due template for Eclipse

This project is based on the arduino due template found [here](http://sourceforge.net/p/gnuarmeclipse/feature-requests/64/) .The only difference is that this template includes the arduino standard library. This project may be used by anyone, but it is used at own risk! Bugs are very likely to occur.


##How to set up the project

###Clone the repo

Clone from

*git clone https://github.com/pdNor/Arduino-Due-Eclipse.git*

###Setting up Eclipse for linux and mac

Follow [this](http://gnuarmeclipse.livius.net/blog/install/) guide to set up the project for linux and mac.

###Setting up Eclipse for Windows

1. Download and install the latest Java SE Dev Kit

2. Download and install the latest version of Eclipse IDE for C/C++ Developers
[https://eclipse.org/downloads/](https://eclipse.org/downloads/) 
*(Eclipse mars was used when cerating this project)*

3. Install GNU ARM Eclipse Plug-ins
Open Eclipse.
Help -> Install New Software -> Add...
Name: GNU ARM Eclipse Plug-ins
Location: http://gnuarmeclipse.sourceforge.net/updates

Select everything and install

4. Download GNU Tools for ARM Embedded Processors
https://launchpad.net/gcc-arm-embedded/4.8/4.8-2014-q2-update/+download/gcc-arm-none-eabi-4_8-2014q2-20140609-win32.exe
Install and UNCHECK "Launch gccvar.bat" and "Add path to environment variable"

5. Download Cross Build Tools
http://sourceforge.net/projects/gnuarmeclipse/files/Build%20Tools/
Extract to C:/Program Files/Cross Build Tools/
Remove "cs-" prefix on make and rm. (It should now say rm.exe and make.exe)

6. In Eclipse import the porject to your workspace.

#Setting up Bossac

Most of this guide is shamelessly copied from [https://github.com/theolind/mahm3lib/wiki/How-to-set-up-the-project](https://github.com/theolind/mahm3lib/wiki/How-to-set-up-the-project)

###Bossac for Eclipse (Windows)


##Notes
1. delay function rewritten not calibrated. wiring.c

##Issues 
 
1. Strange error in syscalls.h line 43 removed (ugly solution)
2. Check all warnings
3. In order to compile the project, the symbol SAM3X8E must be defined.
4. In order to compile the project, the symbol F_CPU must be defined.
5. Calibrate delay function.
6. analogWrite functions.
7. Interrupt functions.
8. Uncommented code in _write.c to prevent multiple declaration. (ugly solution)
9. syscals_sam3x.c _sbrk removed to prevent multiple declarations.(ugly solution)
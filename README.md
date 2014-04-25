#COP3503 Project #1

##Dependancies

####PCRE - http://pcre.org/

###Instructions for installing PCRE:

Download the latest version [here](http://ftp.csx.cam.ac.uk/pub/software/programming/pcre/)

Extract the file

    tar -zxf pcre-833.tar.bz2 

Build the source code

    ./configure

    make 

    make install

### Installing Calculator

    cd /path/to/dir

    make
    
    ./Calc

##Syntax

Tokens must be seperated by a space.

Example of valid input:

''''

    3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3
    
    1/2 + 3/2
    
    log_2:2 + 1

    2rt:16

''''

##Bugs/Errors

* Can currently only take nth roots involving integers.

* Logs, roots, and powers with pi and e currently not supported 
 

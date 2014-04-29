#COP3503 Project #1

##Dependancies

####PCRE - http://pcre.org/

###Instructions for installing PCRE:

##### Install using package manager

    sudo apt-get install


##### Install from source

1. Download the latest version [here](http://ftp.csx.cam.ac.uk/pub/software/programming/pcre/)

2. Extract the files

    tar -zxf pcre-833.tar.bz2 

3. Build the source code

    ./configure

    make 

    make install

### Installing/Running Calculator

    cd /path/to/dir

    make
    
    ./Calc

##Syntax

Tokens must be seperated by a space.

Example of valid input:

    3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3
    
    1/2 + 3/2
    
    log_2:2 + 1

    2rt:16

##Bugs/Errors

* Some complex cases are currently not implemented and therefore will not solve.
 

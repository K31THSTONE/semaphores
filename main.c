#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "utils.h"



int main(int argc, char** argv)
{
    char* filename = NULL;  // DO NOT MODIFY THIS VARIABLE NAME
    int num_procs = 0;      // DO NOT MODIFY THIS VARIABLE NAME
    int num_threads = 0;    // DO NOT MODIFY THIS VARIABLE NAME
    
    
    // TODO: parse arguments
    int aflag = 0;
    int bflag = 0;
    char *cvalue = NULL;
    int index;
    int c;

    opterr = 0;


    while ((c = getopt (argc, argv, "abc:")) != -1)
      switch (c)
        {
        case 'a':
          aflag = 1;
          break;
        case 'b':
          bflag = 1;
          break;
        case 'c':
          cvalue = optarg;
          break;
        case '?':
          if (optopt == 'c')
            fprintf (stderr, "Option -%c requires an argument.\n", optopt);
          else if (isprint (optopt))
            fprintf (stderr, "Unknown option `-%c'.\n", optopt);
          else
            fprintf (stderr,
                     "Unknown option character `\\x%x'.\n",
                     optopt);
          return 1;
        default:
          abort ();
        }

    
    
    // TODO: write initial '0' to file
    open_file();
    //write 0
    close_file();
    

    // TODO: create a named semaphore
    //sem_t *sem_open(const char *name, int oflag, mode_t mode, int value);
    
    
    // TODO: fork off child processes and wait for them to finish
    if(fork() == 0){
    }
    else{
      sem_wait();
    }
 
    
    // TODO: clean up and close named semaphore
    
    
    
    
    
    
    
    /////////////////////////////////////////////////////////////////////////////////////
    //
    // ** IMPORTANT: DO NOT REMOVE/CHANGE/MODIFY/EDIT OR DO ANYTHING TO THE CODE BETWEEN
    //               HERE AND THE END OF THIS FILE.  YOU CANNOT CHANGE THIS CODE TO MAKE
    //               IT WORK WITH YOUR PROGRAM.  IF YOUR PROGRAM DOESN'T WORK WITH THIS
    //               CODE, THEN YOUR PROGRAM -DOES NOT WORK-.  CHANGE YOUR PROGRAM AS
    //               NECESSARY TO WORK WITH THIS CODE.  ANY CHANGES TO THE CODE BELOW WILL
    //               RESULT IN 0 CREDIT FOR THIS LAB.  BE SURE ALL OF YOU CHILD PROCESSES
    //               HAVE TERMINATED BEFORE THIS POINT.
    //
    /////////////////////////////////////////////////////////////////////////////////////
    // This section checks the output file to see if everthing went as planned.  A message
    // is printed to the terminal indicated if everything works correctly.
    /////////////////////////////////////////////////////////////////////////////////////
    FILE* fpt = open_file(filename, "r");   // open the file for reading
    int max_value = num_procs * num_threads;
    int value;
    int success = 1;
    
    // The following loop will read the file after it has been written by all of the
    // child processes and threads.  It will read each line and compare it to the
    // expected value.  If an error is encoutered, the 'success' flag will be set
    // to false.
    for (int expected_value=0; expected_value <= max_value; expected_value++) {
        fscanf(fpt, "%i", &value);
        if (expected_value != value) {
            success = 0;
            break;
        }
    }
    close_file(fpt);                        // close the file
    
    
    if (success) {
        printf("\n\n-SUCCESS-\n\n");
    } else {
        printf("\n\n-EPIC FAIL-\n\n");
    }
    /////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////
    
    return 0;
}


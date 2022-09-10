#include <stdio.h>
#include <unistd.h>    // for write
#include <pthread.h>   // for pthreads
#include <stdlib.h>    // for exit

// Print out an error message and exit.
static void fail( char const *message ) {
  fprintf( stderr, "%s\n", message );
  exit( 1 );
}

// Define the start routines for your three threads.  Each thread will
// use two calls to write() to print its two characters, then it will
// terminate.

// ...
void *abThread( void * arg) {
    write(STDOUT_FILENO, "a", 1);
    write(STDOUT_FILENO, "b", 1);

    return NULL;
}

void *cdThread( void * arg) {
    write(STDOUT_FILENO, "c", 1);
    write(STDOUT_FILENO, "d", 1);
    
    return NULL;
}

void *efThread( void * arg) {
    write(STDOUT_FILENO, "e", 1);
    write(STDOUT_FILENO, "f", 1);

    return NULL;
}

int main( int argc, char *argv[] ) {
  // A bunch of times.
  for ( int i = 0; i < 100000; i++ ) {
    // Make three threads.
    pthread_t ab;
    pthread_t cd;
    pthread_t ef;
    
    if ( pthread_create( &ab, NULL, abThread, NULL ) != 0 ) {
        fail( "Can't create ab thread" );
    }

    if ( pthread_create( &cd, NULL, cdThread, NULL ) != 0 ) {
        fail( "Can't create cd thread" );
    }

    if ( pthread_create( &ef, NULL, efThread, NULL ) != 0 ) {
        fail( "Can't create ef thread" );
    }

    // Join with the three threads.

    pthread_join(ab, NULL);
    pthread_join(cd, NULL);
    pthread_join(ef, NULL);

    // Use the write system call to print out a newline.  The string
    // we're passing to write is null terminated (since that's what
    // double quotesd strings are in C), but we're just using the
    // first byte (the newline).  Write doesn't care about null
    // terminated strings, it just writes out any sequence of bytes
    // you ask it to.
    write( STDOUT_FILENO, "\n", 1 );
  }

  return 0;
}
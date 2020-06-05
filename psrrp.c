#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

// Program that test srrp system call.
int
main(int argc, char *argv[])
{
  if (fork() == 0)
  {
    if (fork() == 0)
    {
      if (fork() == 0)
      {
        // Process 1
        sbrk(10);         // Allocate 10 bytes to Process 1.
        sleep(10);        // Sleep 10 secs to make process alive.
      }
      else
      {
        // Process 2
        sbrk(20);         // Allocate 20 bytes to Process 2.
        sleep(10);        // Sleep 10 secs to make process alive.
      }
    }
    else
    {
      if (fork() == 0)
      {
        // Process 3
        sbrk(30);         // Allocate 30 bytes to Process 3.
        sleep(10);        // Sleep 10 secs to make process alive.
      }
      else
      {
        // Process 4
        sbrk(40);         // Allocate 40 bytes to Process 4.
        sleep(10);        // Sleep 10 secs to make process alive.
      }
    }
  }
  else
  {
    if (fork() == 0)
    {
      if (fork() == 0)
      {
        // Process 5
        sbrk(50);         // Allocate 50 bytes to Process 5.
        sleep(10);        // Sleep 10 secs to make process alive.
      }
      else
      {
        // Process 6
        sbrk(60);         // Allocate 60 bytes to Process 6.
        sleep(10);        // Sleep 10 secs to make process alive.
      }
    }
    else
    {
      if (fork() == 0)
      {
        // Process 7
        sbrk(70);         // Allocate 70 bytes to Process 7.
        sleep(10);        // Sleep 10 secs to make process alive.
      }
      else
      {
        // Process 8
        sbrk(80);         // Allocate 80 bytes to Process 8.
        sleep(5);        // Sleep 10 secs to make process alive.
        srrp();           // Call srrp system call.
      }
    }
  }
  exit();
}

//This program forks, creates shared memory on one side and just uses it on the other. The creating side writes the alphabet into this and the other side reads it. 

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream.h> 
main()
{
  int shmid;
  char *shmPtr;
  int n;
  if (fork() == 0) 
{    /* Child Side */
    shmid = shmget(2041,32,666);
    if (shmid == -1)
      exit(1);
    shmPtr = (char *)shmat(shmid,0,0);
    if (shmPtr == (char *) -1) 
      exit(2);
    for (n = 0; n < 26; n++)
      shmPtr[n] = 'a' + n;
    for (n = 0; n < 26; n++)
         cout<<shmPtr[n];
         cout<<“\n”;  
}
else
 {    /* Parent Side */
sleep(5);
shmid = shmget(2041,32,0);
    if (shmid == -1)
      exit(1);
 shmPtr = (char *)shmat(shmid,0,0);
    if (shmPtr == (char *) -1) 
      exit(2);
    for (n = 0; n < 26; n++)
         cout<<shmPtr[n];
         cout<<“\n”;  
      }
shmdt(&shmid);
}


//Destroying Shared Memory Segment:
//root@localhost root]# ipcs		                (To view available ipcs)
//root@localhost root]# ipcrm –m shmid	(To remove by specifying shmid)

#include <unistd.h>
#include <iostream>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
  int fd;
  
  if((fd = open(argv[1], O_RDONLY))<0)
  {
    cout<<"Unable to open FIFO"<<endl;
    return -1;
  }
  
  char c;
  int s;
  string x;
  while(read(fd,&c,1)>0)
  {
    cout<<c;
  }
  close(fd);
  
  return 1;
}

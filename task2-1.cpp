#include <unistd.h>
#include <iostream>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
  int fd;
  umask(0);
  if(mkfifo(argv[1], 0666)<0)
  {
    cout<<"Unable to create FIFO"<<endl;
    return -1;
  }
  string msg;
  getline(cin,msg);
  char lend[]="\n";
  while(msg!="END")
  {
    fd = open(argv[1], O_RDWR);
    write(fd,(msg).c_str(),msg.size());
    write(fd,lend,1);
    getline(cin,msg);
    close(fd);
  }
  return 1;
}

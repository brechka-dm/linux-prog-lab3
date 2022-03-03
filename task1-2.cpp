#include <unistd.h>
#include <fcntl.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  int fd;
  if((fd=open(argv[1],O_RDONLY))<0)
  {
    cout<<"Unable to open file"<<endl;
    exit(-1);
  }
  char c;
  while(read(fd,&c,1)>0) cout<<c;
  cout<<endl;
  close(fd);
}


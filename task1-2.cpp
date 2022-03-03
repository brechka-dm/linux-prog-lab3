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

/*
TASK

PROGRAM #2

Напишите две программы, одна из которых записывает текстовое
сообщение, переданное пользователем в качестве параметра, в файл, а
вторая, читает информацию из этого файла и выводит ее на экран. Для
работы с файлом используйте системные вызовы open(), read(), write() и
close().
*/


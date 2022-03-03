#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
  int fd;
  if((fd = open("task1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666))<0)
  {
    cout<<"Unable to open/create file"<<endl;
    exit(-1);
  }
  int size = write(fd, argv[1], strlen(argv[1])+1);
  if(size!=strlen(argv[1])+1)
  {
    cout<<"Unable to write file"<<endl;
  }
  close(fd);
}

/*
TASK

PROGRAM #1

Напишите две программы, одна из которых записывает текстовое
сообщение, переданное пользователем в качестве параметра, в файл, а
вторая, читает информацию из этого файла и выводит ее на экран. Для
работы с файлом используйте системные вызовы open(), read(), write() и
close().
*/
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

using namespace std;
void parent(int* pd1, int* pd2)
{
  close(pd1[0]);
  close(pd2[1]);
  int size = write(pd1[1], "Parent to child", 15);
  char resstring[20]="\0";
  read(pd2[0], resstring, 15);
  cout<<resstring<<endl;
  close(pd1[1]);
  close(pd2[0]);
}

void child(int* pd1, int* pd2)
{
  close(pd1[1]);
  close(pd2[0]);
  char resstring[20]="\0";
  read(pd1[0], resstring, 15);
  cout<<resstring<<endl;
  int size = write(pd2[1],"Child to parent", 15);
  close(pd1[0]);
  close(pd2[1]);
}

int main()
{
  int fd1[2], fd2[2];
  if((pipe(fd1)<0)||(pipe(fd2)<0)) {
    cout<<"Pipe error"<<endl;
    return -1;
  }

  pid_t pid = fork();
  if(pid==-1) cout<<"Fork error"<<endl;
  else if(pid==0) child(fd1, fd2);
  else {
    parent(fd1, fd2);
    wait(0);
  }
  return 0; 
}

/*
TASK

Напишите программу, порождающую два процесса и организующую
взаимодействие этих процессов через pipe. Процесс-родитель создает два
pipe, записывает информацию в первый, и ждет поступления сообщения
от процесса-потомка во второй pipe. Процесс-потомок читает сообщение
из первого pipe и записывает во второй. Переданные и принятые
сообщения процессы выводят на экран. Во избежание возможных
блокировок закрывайте процессам доступ на чтение тех pipe, в которые
они должны только записывать сообщения, также закрывайте доступ на
запись к тем pipe, которые процессы только читают.
*/
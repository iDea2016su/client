#include <iostream>
#include <string>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

using namespace std;

int main()
{
  int sockfd;
  struct sockaddr_in seraddr;
  sockfd = socket(AF_INET,SOCK_STREAM,0);
  seraddr.sin_family = AF_INET;
  seraddr.sin_port = htons(5566);
  seraddr.sin_addr.s_addr = inet_addr("119.23.210.52");
  memset(&seraddr.sin_zero,0,8);
  int rec = connect(sockfd,(struct sockaddr*)&seraddr,sizeof(struct sockaddr));
  if(rec<0)
  {
    cout<<"connecting error"<<endl;
    return 0;
  }
  char get[100]={0};
  recv(sockfd,get,100,0);
  cout<<get<<endl;
}

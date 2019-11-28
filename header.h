#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include<readline/readline.h> 
#include<readline/history.h> 
#include<dirent.h> 
#include<sys/stat.h>
#include<fcntl.h>
#include<pwd.h>
#include<grp.h>
#include<signal.h>
#define KCYN  "\x1B[36m"
#define RESET "\x1B[0m"
#define clear() printf("\033[H\033[J") 
extern int size,nameindex,currfg;
extern char cwd[1024]; 
extern char cwdm[1024]; 
extern char host[1024];
extern char name[100][100];
extern int pi[100];
extern char* strcut[100];
extern char* stt[20];
extern char* stok[100];
extern char* strcut3[100];
extern char* pip[100];
extern char* input;




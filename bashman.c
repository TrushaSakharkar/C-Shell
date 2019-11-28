#include"header.h"
#include"trim.h"
#include"shell.h"
#include"handler.h"
#include"cd.h"
#include"pcwd.h"
#include"echo.h"
#include"ls.h"
#include"pinfo.h"
#include"jobs.h"
#include"fg.h"
#include"kjob.h"
#include"bg.h"
#include"overkill.h"
#include"env.h"
#include"functions.h"
#include"redirectnew.h"
#include"pipes.h"
int size,nameindex,red;
char cwd[1024]; 
char cwdm[1024]; 
char host[1024];
char name[100][100];
int pi[100];
char* strcut[100];
char* strcut3[100];
char* stok[100];
char* pip[100];
int currfg;
char* input=NULL;
	char trusha[1000]={0};


void functions(int k);
/*void sigintHandler (int sig)
{
	 pid_t process = currfg;
    if (process !=0 && process!=-1) 
    {
        kill(process, SIGINT);
        printf("\n");
        fflush(stdout);
    } 
    else 
    {
        printf("\n");
        // print_dirname(size);
       // prompt();
        	char* username = getenv("USER"); 
		getcwd(cwd, sizeof(cwd));
		char t[100]={};
		z=0;
		if(strlen(cwd)<size)
		{
			sprintf(trusha,"%s%s@%s:%s$%s",KCYN,username,host,cwd,RESET);
		}	
		else
		{
			for(i=size;i<strlen(cwd);i++)
			{
				t[z++]=cwd[i];
			}
			sprintf(trusha,"%s%s@%s:~%s$%s",KCYN,username,host,t,RESET);
		}
        fflush(stdout);
    }
}
void sigtstpHandler(int sig_num) 
{ 
	if(currfg!=0 && currfg!=-1)
	{
		int flag = 1;
		for(int i=1;i<=nameindex;i++)
		{
			if(pi[i] == currfg)
			{
				flag = 0;
				printf("\n%s\t\t%s\t[%d]\n","Stopped",name[i],pi[i]);
				break;
			}
		}
		if(flag)
		{
			//proc_cnt++;
			nameindex++;
			pi[nameindex] = currfg;
			// proc[num_background_proc].state = 1;
			strcpy(proc_arr[proc_cnt].name,ff[0]);
			// back_proc[num_background_proc].jobid = num_background_proc;
				printf("\n%s\t\t%s\t[%d]\n","Stopped",proc_arr[proc_cnt].name,proc_arr[proc_cnt].id);

			// printf("\n%s\t\t%s\t[%d]\n","Stopped",back_proc[num_background_proc].command,back_proc[num_background_proc].pid);

			// num_background_proc++;/
		}

		int temp = globpid;
		kill(globpid, sig_num);
		globpid = 0;
		printf("\n");
		fflush(stdout);
	}
	else
	{
		printf("\n");
		prompt();
		fflush(stdout);
	}
	/*signal(SIGTSTP, sigtstpHandler);
	if(currfg!=0) 
	{
		strcpy(name[nameindex],strcut[0]);
				pi[nameindex]=currfg;
				nameindex++;
				for(int i=0;i<nameindex;i++)
				{
					printf("tru%d %s\n",i,name[i]);
				}
		printf("Stopped: %d %s\n",currfg,strcut[0]);
		kill(currfg,SIGKILL);
	}
	fflush(stdout);*/
void ctrlc(int sig)
{
	for(int i=0;i<nameindex;i++)
	{
		if(getpid()==pi[i])
		{
			exit(0);
			break;
		}
	}
	
		return;
	}
void ctrlz(int sig)
{
	

	return;
}
void check(char *input)
{

	int i,k,j,z,y,count=0; 
	stok[0]=strtok(input,";");
	i=0;
	if(stok[i]==NULL || strcmp(stok[i],";")==0)
	{
		printf("INVALID COMMAND\n");
		return;
	}
	while(stok[i]!=NULL)
	{
		//printf("%s\n",stok[i]);
		i++;
		stok[i]=strtok(NULL,";");
	}
	count=i;
	for(int it=0;it<count;it++)
	{
		pip[0]=strtok(stok[it],"|");
		i=0;
		while(pip[i]!=NULL)
		{
			i++;
			pip[i]=strtok(NULL,"|");
		}
		if(i>1)
		{
			//printf("ashfgbhak\n");
			pipes(i);
			j=i;
			for(i=0;i<j;i++)
				pip[i]=NULL;
		}
		else
		{
			strcut3[0]=strtok(stok[it]," ");
			i=0;
			while(strcut3[i]!=NULL)
			{
				i++;
				strcut3[i]=strtok(NULL," ");
			}
			k=i;
			redirect(k);
		
			for(i=0;i<k;i++)
			{
				strcut3[i]=NULL;
			}
		}
	
		for(i=0;i<count;i++)
		{
			stok[i]=NULL;
		}
	}
	return;

}
/*void add(char *input)
{
	char *temp;
	strcpy(temp,cwdm);
	strcat(temp,"")
}*/
int main()
{
	/*char c[] = "     klaslkx    alknsl   lol     -       ";
	trim(c);
	printf("*%s*\n",c);*/
	signal(SIGINT, ctrlc);
	signal(SIGTSTP, ctrlz);
	 clear();
	shell();
	int i,z,flag=0;
	red=0,nameindex=1;
	using_history();

	while(1)
	{
		input=readline(trusha);
		add_history(input);
		//add(input);
		//for(i=0;i<100;i++)
		//	strcut[i][0]=NULL;
		check(input);
		char* username = getenv("USER"); 
		getcwd(cwd, sizeof(cwd));
		char t[100]={};
		z=0;
		if(strlen(cwd)<size)
		{
			sprintf(trusha,"%s%s@%s:%s$%s",KCYN,username,host,cwd,RESET);
		}	
		else
		{
			for(i=size;i<strlen(cwd);i++)
			{
				t[z++]=cwd[i];
			}
			sprintf(trusha,"%s%s@%s:~%s$%s",KCYN,username,host,t,RESET);
		}

	}
}
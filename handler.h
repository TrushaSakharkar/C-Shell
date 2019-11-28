
void handler(int sig)

{
	pid_t pid;
	int status;
	char *exit=(char *)malloc(100000);
	char *exit_status=(char *)malloc(100000);
	pid=waitpid(0,&status,WNOHANG);
	char string[100]={0}; 
	for(int i=1;i<=nameindex;i++)
	{
		if(pid==pi[i])
			strcpy(string,name[i]);
	}
	sprintf(exit,"\n%s with pid %d exited\n",string,pid);
	if(WIFEXITED(status))
	{
		int r=WEXITSTATUS(status);
		if(r)
			sprintf(exit_status,"abnormally\n");
		else
			sprintf(exit_status,"normally\n");
	}
	if(pid>0)
	{
		write(2,exit,strlen(exit));
		write(2,exit_status,strlen(exit_status));
	char *prompt=(char *)malloc(100000);
	char* username = getenv("USER"); 
    getcwd(cwd, sizeof(cwd)); 
    gethostname(host,sizeof(host));
    char t[100]={};
    	int i,z=0;
    	if(strlen(cwd)<size)
    	{
			sprintf(prompt,"%s%s@%s:%s$%s",KCYN,username,host,cwd,RESET);
    	}	
    	else
    	{
	    	for(i=size;i<strlen(cwd);i++)
	    	{
	    		t[z++]=cwd[i];
	    	}
			sprintf(prompt,"%s%s@%s:~%s$%s",KCYN,username,host,t,RESET);
		}
		write(2,prompt,strlen(prompt));
	}
	return;
}

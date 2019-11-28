extern void functions(int k)
{
	if(strcmp("cd",strcut[0])==0)
		cd(k);
	else if(strcmp("pwd",strcut[0])==0)
		pcwd(k);
	else if(strcmp("echo",strcut[0])==0)
		echo(k);
	else if(strcmp("ls",strcut[0])==0)
		ls(k);
	else if(strcmp("pinfo",strcut[0])==0)
		pinfo(k);
	else if(strcmp("jobs",strcut[0])==0)
		jobs(k);
	else if(strcmp("kjob",strcut[0])==0)
		kjob(k);
	else if(strcmp("fg",strcut[0])==0)
		fg(k);
	else if(strcmp("bg",strcut[0])==0)
		bg(k);
	else if(strcmp("overkill",strcut[0])==0)
		overkill(k);
	else if(strcmp("quit",strcut[0])==0)
		exit(0);
	else if(strcmp("setenv",strcut[0])==0)
		env(k,1);
	else if(strcmp("unsetenv",strcut[0])==0)
		env(k,2);
	else 
	{

		char* strcut2[100];
		int z=0,b=0;
		int i=0;
		while(strcut[i]!=NULL && i<=k-1)
		{
			if(strcmp(strcut[i],"&")==0)
			{
				b=1;
				break;
			}
			strcut2[z++]=strcut[i];
			i++;
		}
		strcut2[z]=NULL;
		
		if(b==1)
		{

			pid_t pid;
			pid=fork();
			if (pid == -1)
			{
				printf("can't fork, error occured\n"); 
				exit(EXIT_FAILURE); 
			}
			else if(pid==0)
			{	
				execvp(strcut[0],strcut2);
				printf("Error\n");
			}
			else
			{
				strcpy(name[nameindex],strcut[0]);
				pi[nameindex]=pid;
				nameindex++;
				signal(SIGCHLD,handler);

			}
		}
		else
		{
			pid_t pid;
			pid=fork();
			if (pid == -1)
			{
				printf("can't fork, error occured\n"); 
				exit(EXIT_FAILURE); 
			}
			else if(pid==0)
			{
				if(execvp(strcut[0],strcut2)<0)
					printf("error\n");
			}
			else if(pid)
			{
				int status;
				currfg=pid;
				wait(&status);
			}
		}
	}
	for(int i=0;i<k;i++)
		strcut[i]=NULL;
}
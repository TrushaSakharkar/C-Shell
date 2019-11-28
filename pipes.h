void pipes(int k)
{
	int i,j,n,out,in;
	pid_t pid;
	int pipefds[2];
	out=dup(1);
	in=dup(0);
	j=0;
	// printf("%d\n",k);
	for(i=0;i<k;i++)
	{
		trim(pip[i]);

		//printf("%s\n",pip[i]);
		strcut3[0]=strtok(pip[i]," ");
		int m=0;

		while(strcut3[m]!=NULL)
		{

			m++;
			strcut3[m]=strtok(NULL," ");
		}
			//strcut33[m]=NULL;
			//printf("trusha\n");

		if(i!=0)
		{	
			close(pipefds[1]);
			if(dup2(pipefds[0], 0)==-1)
			{
				perror("pipe1");
				exit(EXIT_FAILURE);
			}
			close(pipefds[0]);
		}
		else if(i!=k-1)
		{
			pipe(pipefds);
			if(dup2(pipefds[1], 1)==-1)
			{
				perror("pipe2");
				exit(EXIT_FAILURE);
			}

		}
		pid=fork();
		if(pid==0)
		{
			redirect(m);
			fflush(stdout);
			exit(0);
		}
		else if(pid<0)
		{
			perror("error");
			exit(0);
		}
		else
		{
			int status;
			waitpid(pid,&status,WUNTRACED);
			dup2(in,0);
			dup2(out,1);

		}
		
		for(n=0;n<m;n++)
		{
			strcut3[n]=NULL;
		}
	}
	
}
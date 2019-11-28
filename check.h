void check(char *input,char **strcut)
{
	int i,k,j,z,y,count=0;
	for(i=0;i<strlen(input);i++)
	{
		if(input[i]==' ')
			count++;
	}
	count++;
	int sc[50]={0};
	int m=0,idex=0;
	for(i=0;i<count;i++)
	{
		strcut[i]=strsep(&input," ");
		while(strcmp(strcut[i],"")==0)
		{
			strcut[i]=strsep(&input," ");
			count--;
		}
		if(strcmp(strcut[i],";")==0)
		{
			sc[m++]=i;
		}
	}	
	k=0;
	m++;
	while(idex<m)
	{
			if(strcmp("cd",strcut[k])==0)
			{
				if(strcmp(strcut[k+1],"~")==0)
					chdir(cwdm);
				else
					chdir(strcut[k+1]);
				//cd(k,strcut);
		   	}
			else if(strcmp("pwd",strcut[k])==0)
			{
				getcwd(cwd, sizeof(cwd));
		    	char t[100]={};
		    	z=0;
		    	for(i=size;i<strlen(cwd);i++)
		    	{
		    		t[z++]=cwd[i];
		    	}
				printf("~%s\n",t);
			}
			else if(strcmp("echo",strcut[k])==0)
			{
				for(i=k+1;i<count;i++)
				{
					if(strcmp(strcut[i],";")==0)
					break;
					printf("%s ",strcut[i]);
				}
				printf("\n");
			}
			else if(strcmp("ls",strcut[k])==0)
			{

				char dir[50]={0};
				i=k+1;
				int flag=0;
				while(strcut[i]!=NULL && strcmp(strcut[i],";")!=0)
				{
					char d[2]={0};
					int d1=1;
						while(d1--)
						{
							d[d1]=strcut[i][d1];
						}
					if(strcmp(d,"-")!=0)
					{	flag=1;

						strcpy(dir,strcut[i]);
						break;
					}
					i++;
				}
				if(flag==0)
				{
					struct dirent *de;
					DIR *dr =opendir(".");
				
				struct stat sfile;
				if(strcut[k+1]==NULL)
				{
				while((de=readdir(dr))!=NULL)
					{	
						char a[100],d[2]={0};
						strcpy(a,de->d_name);
						int d1=1;
						while(d1--)
						{
							d[d1]=a[d1];
						}
						if(strcmp(d,".")!=0)
							printf("%s\n",de->d_name);
					}
				}
			    else if(strcmp("-a",strcut[k+1])==0)
				{
					while((de=readdir(dr))!=NULL)
						printf("%s\n",de->d_name);
				}
				else if(strcmp("-l",strcut[k+1])==0)
				{
					while((de=readdir(dr))!=NULL)
					{
						char a[100],d[2]={0};
						strcpy(a,de->d_name);
						int d1=1;
						while(d1--)
						{
							d[d1]=a[d1];
						}
						if(strcmp(d,".")!=0)
						    stat(a,&sfile);
						else
							continue;

					     printf( (S_ISDIR(sfile.st_mode)) ? "d" : "-");
					    printf( (sfile.st_mode & S_IRUSR) ? "r" : "-");
					    printf( (sfile.st_mode & S_IWUSR) ? "w" : "-");
					    printf( (sfile.st_mode & S_IXUSR) ? "x" : "-");
					    printf( (sfile.st_mode & S_IRGRP) ? "r" : "-");
					    printf( (sfile.st_mode & S_IWGRP) ? "w" : "-");
					    printf( (sfile.st_mode & S_IXGRP) ? "x" : "-");
					    printf( (sfile.st_mode & S_IROTH) ? "r" : "-");
					    printf( (sfile.st_mode & S_IWOTH) ? "w" : "-");
					    printf( (sfile.st_mode & S_IXOTH) ? "x" : "-");

					    printf(" %ld ",(long)sfile.st_nlink);

					    struct passwd *pwuser;
					    pwuser=getpwuid(sfile.st_uid);
					    printf("%s ",pwuser->pw_name);

					    struct group *grpname;
					    grpname = getgrgid(sfile.st_gid);
					    printf("%s ",grpname->gr_name);

					    printf("%ld ",sfile.st_size);

					    char *time =ctime(&sfile.st_mtime);
					    if(time[strlen(time)-1]=='\n')
					    	time[strlen(time)-1]='\0';
					   	printf("%s ",time);

					    printf("%s\n",a);

					}
				}
				else if(strcmp("-al",strcut[k+1])==0 || strcmp("-la",strcut[k+1])==0)
				{
					while((de=readdir(dr))!=NULL)
					{
						char a[100];
						strcpy(a,de->d_name);
						stat(a,&sfile);

					    printf( (S_ISDIR(sfile.st_mode)) ? "d" : "-");
					    printf( (sfile.st_mode & S_IRUSR) ? "r" : "-");
					    printf( (sfile.st_mode & S_IWUSR) ? "w" : "-");
					    printf( (sfile.st_mode & S_IXUSR) ? "x" : "-");
					    printf( (sfile.st_mode & S_IRGRP) ? "r" : "-");
					    printf( (sfile.st_mode & S_IWGRP) ? "w" : "-");
					    printf( (sfile.st_mode & S_IXGRP) ? "x" : "-");
					    printf( (sfile.st_mode & S_IROTH) ? "r" : "-");
					    printf( (sfile.st_mode & S_IWOTH) ? "w" : "-");
					    printf( (sfile.st_mode & S_IXOTH) ? "x" : "-");

					    printf(" %ld ",(long)sfile.st_nlink);

					    struct passwd *pwuser;
					    pwuser=getpwuid(sfile.st_uid);
					    printf("%s ",pwuser->pw_name);

					    struct group *grpname;
					    grpname = getgrgid(sfile.st_gid);
					    printf("%s ",grpname->gr_name);

					    printf("%ld ",sfile.st_size);

					    char *time =ctime(&sfile.st_mtime);
					    if(time[strlen(time)-1]=='\n')
					    	time[strlen(time)-1]='\0';
					   	printf("%s ",time);

					    printf("%s\n",a);

					}
				}
				closedir(dr); 

				}
				else if(flag==1)
				{
					struct dirent *de;
					DIR *dr;
					char cwd1[100]={0};
					getcwd(cwd1, sizeof(cwd1));
					chdir(dir);
					dr =opendir(".");
					struct stat sfile;

				if(strcut[k+2]==NULL)
				{
					while((de=readdir(dr))!=NULL)
					{	
						char a[100],d[2]={0};
						strcpy(a,de->d_name);
						int d1=1;
						while(d1--)
						{
							d[d1]=a[d1];
						}
						if(strcmp(d,".")!=0)
							printf("%s\n",de->d_name);
					}
				}
			    else if(strcmp("-a",strcut[k+2])==0)
				{
					while((de=readdir(dr))!=NULL)
						printf("%s\n",de->d_name);
				}
				else if(strcmp("-l",strcut[k+2])==0)
				{
					while((de=readdir(dr))!=NULL)
					{
						char a[100],d[2]={0};
						strcpy(a,de->d_name);
						int d1=1;
						while(d1--)
						{
							d[d1]=a[d1];
						}
						if(strcmp(d,".")!=0)
						    stat(a,&sfile);
						else
							continue;

					     printf( (S_ISDIR(sfile.st_mode)) ? "d" : "-");
					    printf( (sfile.st_mode & S_IRUSR) ? "r" : "-");
					    printf( (sfile.st_mode & S_IWUSR) ? "w" : "-");
					    printf( (sfile.st_mode & S_IXUSR) ? "x" : "-");
					    printf( (sfile.st_mode & S_IRGRP) ? "r" : "-");
					    printf( (sfile.st_mode & S_IWGRP) ? "w" : "-");
					    printf( (sfile.st_mode & S_IXGRP) ? "x" : "-");
					    printf( (sfile.st_mode & S_IROTH) ? "r" : "-");
					    printf( (sfile.st_mode & S_IWOTH) ? "w" : "-");
					    printf( (sfile.st_mode & S_IXOTH) ? "x" : "-");

					    printf(" %ld ",(long)sfile.st_nlink);

					    struct passwd *pwuser;
					    pwuser=getpwuid(sfile.st_uid);
					    printf("%s ",pwuser->pw_name);

					    struct group *grpname;
					    grpname = getgrgid(sfile.st_gid);
					    printf("%s ",grpname->gr_name);

					    printf("%ld ",sfile.st_size);

					    char *time =ctime(&sfile.st_mtime);
					    if(time[strlen(time)-1]=='\n')
					    	time[strlen(time)-1]='\0';
					   	printf("%s ",time);

					    printf("%s\n",a);

					}
				}
				else if(strcmp("-al",strcut[k+2])==0 || strcmp("-la",strcut[k+2])==0)
				{
					while((de=readdir(dr))!=NULL)
					{
						char a[100];
						strcpy(a,de->d_name);
						stat(a,&sfile);

					    printf( (S_ISDIR(sfile.st_mode)) ? "d" : "-");
					    printf( (sfile.st_mode & S_IRUSR) ? "r" : "-");
					    printf( (sfile.st_mode & S_IWUSR) ? "w" : "-");
					    printf( (sfile.st_mode & S_IXUSR) ? "x" : "-");
					    printf( (sfile.st_mode & S_IRGRP) ? "r" : "-");
					    printf( (sfile.st_mode & S_IWGRP) ? "w" : "-");
					    printf( (sfile.st_mode & S_IXGRP) ? "x" : "-");
					    printf( (sfile.st_mode & S_IROTH) ? "r" : "-");
					    printf( (sfile.st_mode & S_IWOTH) ? "w" : "-");
					    printf( (sfile.st_mode & S_IXOTH) ? "x" : "-");

					    printf(" %ld ",(long)sfile.st_nlink);

					    struct passwd *pwuser;
					    pwuser=getpwuid(sfile.st_uid);
					    printf("%s ",pwuser->pw_name);

					    struct group *grpname;
					    grpname = getgrgid(sfile.st_gid);
					    printf("%s ",grpname->gr_name);

					    printf("%ld ",sfile.st_size);

					    char *time =ctime(&sfile.st_mtime);
					    if(time[strlen(time)-1]=='\n')
					    	time[strlen(time)-1]='\0';
					   	printf("%s ",time);

					    printf("%s\n",a);

					}
				}
				chdir(cwd1);
				closedir(dr);

				}	
				
			}
			else if(strcmp("pinfo",strcut[k])==0)
			{
						int fd;
						if(strcut[k+1]==NULL)
							fd=open("/proc/self/stat",O_RDONLY);
						else
						{							
							char s[50]="/proc/";
							strcat(s,strcut[k+1]);
							strcat(s,"/stat");
							fd=open(s,O_RDONLY);
						}
						char *buff= (char *) malloc(100000*sizeof(char));
                		read(fd,buff,100000);
                		int count1=0;
                		for(i=0;i<strlen(buff);i++)
						{
							if(buff[i]==' ')
								count1++;
						}
						char* strcut1[1000000];
						for(i=0;i<count1;i++)
						{
							strcut1[i]=strsep(&buff," ");
						}
						printf("pid--%s\n",strcut1[0]);
						printf("Process Status--%s\n",strcut1[2]);
						printf("Virtual Memory--%s\n",strcut1[22]);
						char ss[50]="/proc/";
						strcat(ss,strcut1[0]);
						strcat(ss,"/exe");
						strcpy(buff,"");

						int l=readlink(ss,buff,100000);
				    	char t[100]={};
				    	int z=0;
				    	if(strlen(buff)<size)
				    	{

					    	printf("Executable Path-- %s\n",buff);
				    	}	
				    	else
				    	{
					    	for(i=size;i<strlen(buff);i++)
					    	{
					    		t[z++]=buff[i];
					    	}
					    	printf("Executable Path-- ~%s\n",t);
					    }
						close(fd);
									
			}
			else 
			{
					char* strcut2[100];
					int z=0,b=0;
					int i=k;
					while(strcut[i]!=NULL && strcmp(strcut[i],";")!=0)
					{
						if(strcmp(strcut[i],"&")==0)
						{
							b=1;
							break;
						}
						strcut2[z++]=strcut[i];
						i++;
					}
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
							execvp(strcut[k],strcut2);
								printf("Error\n");
						}
						else
						{
							strcpy(name[nameindex],strcut[k]);
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

							execvp(strcut[k],strcut2);
						}
						else if(pid)
						{
							wait(NULL);
						}
					}
			}

					k=sc[idex++]+1;

	}
	return;
}
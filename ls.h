void ls(int k)
{
	char dir[50]={0};
	int i=1;
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
			if(strcut[1]==NULL)
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
			else if(strcmp("-a",strcut[1])==0)
			{
				while((de=readdir(dr))!=NULL)
					printf("%s\n",de->d_name);
			}
			else if(strcmp("-l",strcut[1])==0)
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
			else if(strcmp("-al",strcut[1])==0 || strcmp("-la",strcut[1])==0)
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
			else if(strcmp("-a",strcut[2])==0)
			{
				while((de=readdir(dr))!=NULL)
					printf("%s\n",de->d_name);
			}
			else if(strcmp("-l",strcut[2])==0)
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
			else if(strcmp("-al",strcut[2])==0 || strcmp("-la",strcut[2])==0)
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
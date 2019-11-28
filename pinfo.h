void pinfo(int k)
{
		int fd,i;
						if(strcut[1]==NULL)
							fd=open("/proc/self/stat",O_RDONLY);
						else
						{							
							char s[50]="/proc/";
							strcat(s,strcut[1]);
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
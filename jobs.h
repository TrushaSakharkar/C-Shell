void jobs(int k)
{
	int i,p;
	char prname[50];
	char c;
	if(nameindex==1)
		printf("No processes in bg\n");
	else
	{
		for(i=1;i<nameindex;i++)
		{
			char s[50]="/proc/";
			char temp[50]={0};
			sprintf(temp,"%d",pi[i]);
			strcat(s,temp);
			strcat(s,"/stat");

			FILE *fd;
			if((fd=fopen(s,"r"))==NULL)
			{
				printf("trush\n");
				continue;
			}
			else
			{
				fscanf(fd,"%d %s %c",&p,prname,&c);
				fclose(fd);
				printf("[%d] ",i);
				if(c=='T')
					printf("Stopped");
				else
					printf("Running");
				printf(" %s [%d]\n",name[i],pi[i]);
			}

		}
	}

}
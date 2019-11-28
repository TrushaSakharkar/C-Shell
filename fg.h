void fg(int k)
{
	int i=atoi(strcut[1]);
			char s[50]="/proc/";
			char temp[50]={0};
			sprintf(temp,"%d",pi[i]);
			strcat(s,temp);
			strcat(s,"/stat");
			FILE *fd;
			if((fd=fopen(s,"r"))==NULL)
			{
				printf("No such process in background\n");
			}
			else
			{
				kill(pi[i],SIGCONT);
				int j=i;
				for(j=i;j<nameindex;j++)
				{
					//strcpy(name[j],'\0');
					strcpy(name[j],name[j+1]);
					pi[j]=pi[j+1];
				}
				nameindex--;
				waitpid(-1,NULL,WUNTRACED);
			}

}
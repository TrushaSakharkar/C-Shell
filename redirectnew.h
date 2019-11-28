extern void redirect(int k)
{
			int tru2=0;
			int tru3=0;
			int tru4=0;
			int i;

			for(i=0;i<k;i++)
			{
				 if(strcmp(strcut3[i],">")==0)
					tru2=1;
				else if(strcmp(strcut3[i],"<")==0)
					tru3=1;
				else if(strcmp(strcut3[i],">>")==0)
					tru4=1;
			}
	int fd,in=dup(0),out=dup(1);
	if((tru2 && tru3) || (tru4 && tru3))
	{
		char *strcut4[100];
		for(i=0;i<k;i++)
		{
			if(strcmp(strcut3[i],"<")==0)
			{
				i++;
				for(int j=i;j<k;j++)
				{
					strcut4[j-1]=strcut3[j];
				}
		for(i=0;i<k-1;i++)
		{
			if(strcmp(strcut4[i],">")==0)
			{
				fd=open(strcut4[i+1],O_WRONLY | O_TRUNC | O_CREAT,0644);
				if(fd<0)
				{
					perror("error '>'");
					return;
				}
				//strcut[i]=NULL;
				break;
			}
			if(strcmp(strcut4[i],">>")==0)
			{
				fd=open(strcut4[i+1],O_WRONLY | O_CREAT | O_APPEND,0644);
				if(fd<0)
				{
					perror("error '>'");
					return;
				}
				strcut[i]=NULL;
				break;
			}
			strcut[i]=strcut4[i];
		}
			dup2(fd,1);
			break;

			}
			strcut4[i]=strcut3[i];
		}
	}
	else if(tru3)
	{
		for(i=0;i<k;i++)
		{

			if(strcmp(strcut3[i],"<")==0)
			{
				fd=open(strcut3[i+1],O_RDONLY);
				if(fd<0)
				{
					perror("error '<'");
					return;
				}
				strcut[i]=NULL;
				break;
			}
			strcut[i]=strcut3[i];
		}
		dup2(fd,0);
	}
	else if(tru2 || tru4)
	{
		for(i=0;i<k;i++)
		{
			if(strcmp(strcut3[i],">")==0)
			{
				fd=open(strcut3[i+1],O_WRONLY | O_TRUNC | O_CREAT,0644);
				if(fd<0)
				{
					perror("error '>'");
					return;
				}
				//strcut[i]=NULL;
				break;
			}
			if(strcmp(strcut3[i],">>")==0)
			{
				fd=open(strcut3[i+1],O_WRONLY | O_CREAT | O_APPEND,0644);
				if(fd<0)
				{
					perror("error '>'");
					return;
				}
				strcut[i]=NULL;
				break;
			}
			strcut[i]=strcut3[i];
		}
			dup2(fd,1);
	}
	else
	{
		for(i=0;i<k;i++)
			strcut[i]=strcut3[i];
	}
	functions(k);
	dup2(in,0);
	dup2(out,1);


}
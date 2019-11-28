void pcwd(int k)
{
	getcwd(cwd, sizeof(cwd));
		    	char t[100]={};
		    	int z=0;
		    	for(int i=size;i<strlen(cwd);i++)
		    	{
		    		t[z++]=cwd[i];
		    	}
				printf("~%s\n",t);
}
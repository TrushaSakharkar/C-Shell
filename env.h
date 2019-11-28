void env(int k,int n)
{
	if(n==1)
	{
	
			if(k==3)
				setenv(strcut[1],strcut[2],1);
			else if(k==2)
				setenv(strcut[1]," ",1);
			else 
				printf("error\n");
	}
	else
	{
		if(k==2)
			unsetenv(strcut[1]);
		else
			printf("error\n");
	}
}
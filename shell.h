void shell()
{
	char* username = getenv("USER"); 
    getcwd(cwdm, sizeof(cwdm)); 
    gethostname(host,sizeof(host));
    printf("%s%s@%s:~$%s",KCYN,username,host,RESET);
    size=strlen(cwdm); 
}
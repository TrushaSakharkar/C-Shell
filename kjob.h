void kjob(int k)
{
	int jid=atoi(strcut[1]);
	int sig =atoi(strcut[2]);
	kill(pi[jid],sig); 
}
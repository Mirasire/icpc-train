/* 
 * Autor: Mirasire 
 * GithubRepo: https://github.com/Mirasire/icpc-train/
 * Tag: String Min Express , String Max Express
 *
 */
int getStrMinExp(int n) {
	int i=0,j=1,k=0;
	while(i<n&&j<n&&k<n) {
		if(sec[(i+k)%n]==sec[(j+k)%n])	k++;
		else {
			sec[(i+k)%n]>sec[(j+k)%n]? i+=k+1 : j+=k+1;
			//String Max Express
			//sec[(i+k)%n]>sec[(j+k)%n]? j+=k+1 : i+=k+1;
			k=0;
			if(i==j) j++;
		}
	}
	return min(i,j);
}

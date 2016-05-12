#include <stdio.h>
#include "csapp.h"

int main() 
{	
	int clientfd;
	clientfd = Open_clientfd("flamingo.jacelridge.com",48579);
	if(clientfd < 0)
	{
		printf("%s\n","Connection Error");
	}
	else
	{
		//connect to server
		printf("%s\n","Connected to server.");
		FILE *file = Fdopen(clientfd,"a+");

		//sending spire id 
		printf("%s\n","Sending Spire ID 29992867.");
		fprintf(file,"29992867");

		//recieve problem
		char *line = NULL;
		int count;
		getline(&line,&count,file);
		printf("%s","Received problem: ");
		printf("%s\n",line);

		//calculate starts from here
		int arg1,pointer,sum = 0, remainders;
		count = sscanf(line, "ADD%d", &arg1);
		pointer = arg1;
		while(pointer != 0)
		{
			remainders = pointer % 10;
			sum = sum + remainders;
			pointer = pointer/10;
		}

		//sending answer
		printf("Sending solution: %d\n",sum);
			//convert int into string
			char *ans = (char*)malloc(12*sizeof(char));
			sprintf(ans,"%d",sum);
			free(line);
			line = NULL;
		fprintf(file,"%s",ans);

		//success or not
		getline(&line,&count,file);
		printf("%s\n",line);
		free(line);
		line = NULL;

		//sending bonus answer
		printf("Sending bonus: %s\n","HW9");
		fprintf(file,"%s","HW9");

		//success or not
		getline(&line,&count,file);
		printf("%s\n",line);
		free(line);
		line = NULL;

		Fclose(file);
		close(clientfd);
		printf("%s\n","Disconnected from server.");
	}

	

}
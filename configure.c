#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main()
{
	FILE* log = fopen("/usr/log.txt" , "r");
	if (log == NULL){
		FILE *cmd=popen("xrandr", "r");
		char result[2];
		int VGA_len = 0;
		char* VGA = NULL;
		bool seen_line = false;
		bool seen_space = false;
		while (fgets(result, sizeof(result), cmd) !=NULL){

			if (result[0] == '\n'){
				seen_line = true;
				if(!seen_space){
					continue;
				}
			}
			if ((seen_line)&&(result[0] == ' ')){
				seen_space = true;
			}
			if (seen_line && !seen_space){
				++VGA_len;
				if (VGA){
					VGA = (char*)realloc(VGA , VGA_len*sizeof(char));
				}else{
					VGA = (char*)malloc(sizeof(char)*VGA_len);
				}
				VGA[VGA_len - 1] = result[0];
			}
			printf("%s",result);

		}

		printf("from the above modes select one\n");
		char mode[254];
		scanf("%s" , mode);
		printf("to change this config you can edit file ./log.txt");
		char out[1024];
		sprintf(out , "xrandr --output %s --mode %s" , VGA , mode);
		FILE* usr_choice = fopen("/usr/log.txt","w");
		fwrite(out , 1024*sizeof(char) , 1  ,usr_choice);
		fclose(usr_choice);

		system(out);
		free(VGA);
		pclose(cmd);
	}else{
		char out[1024];
		fread(out , sizeof(char)*1024 , 1 , log);
		fclose(log);
		system(out);
	}

	return 0;
}

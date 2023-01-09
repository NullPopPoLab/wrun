#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int WINAPI WinMain(HINSTANCE hi,HINSTANCE hpi,LPSTR cmd,int show)
{
	char fn[MAX_PATH+1];
	struct stat fs;
	FILE *fd;
	char *buf,*c;
	int r=1;

	strncpy(fn,(*cmd)?cmd:"wrun",MAX_PATH);
	for(c=fn;c<fn+MAX_PATH;++c){
		if(*c>=' ')continue;
		*c=0;
		break;
	}
	strncat(fn,".run",MAX_PATH);
	fn[MAX_PATH]=0;

	if(stat(fn,&fs)){
		printf("fstat failed; %s\n",fn);
		return 1;
	}

	buf=malloc(fs.st_size+1);
	if(!buf){
		printf("malloc failed; %d\n",fs.st_size+1);
	}
	else{
		fd=fopen(fn,"rb");
		if(!fd){
			printf("fopen failed; %s\n",fn);
			free(buf);
		}
		else{
			if(fread(buf,fs.st_size,1,fd))r=0;
			else{
				printf("fread failed; %d\n",fs.st_size);
				r=1;
			}
			fclose(fd);
			buf[fs.st_size]=0;
		}
	}

	if(!r){
		char *d=buf;
		for(c=buf;c<=&buf[fs.st_size];++c){
			if(*c=='\0');
			else if(*c=='\r');
			else if(*c=='\n');
			else continue;
			*c=0;
			if(!*d){
				d=c+1;
				continue;
			}
			r=system(d);
			if(r)break;
			d=c+1;
		}
	}

	if(buf)free(buf);
	return r;
}

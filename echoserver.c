#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/md5.h>

#define BSIZE 20
static int magicNum = 0;
static void activate_code_gen(const void* pv, size_t len)
{
    const unsigned char * p = (const unsigned char*)pv;
    if (NULL == pv)
        printf("NULL");
    else
    {
        size_t i = 0;
        for (; i<len;++i)
            printf("%02X", *p++);
    }
    printf("\n");
    __asm__ __volatile__(
        "nop\n"
        "nop\n"
        "nop\n"
        "nop\n"
        "nop\n"
    );
}

void echo(){
	char in[BSIZE];
	char buf[100];
	memset(in, 0, BSIZE);
	__asm__ __volatile__(
		"nop\n"
		"nop\n"
		"nop\n"
		"nop\n"
	);
	read(0, in, BSIZE);
	        __asm__ __volatile__(
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
        );
//	puts(buf);
	if(!strncmp(in,"F1@g_",5)){
		puts("You are very close! Now patch me~");
	        __asm__ __volatile__(
        	        "nop\n"
        	        "nop\n"
                	"nop\n"
			"nop\n"
               		"nop\n"
                	"nop\n"
			"nop\n"
               		"nop\n"
               		"nop\n"
       		);
	      	//magicNum = 1;
	       //	if(magicNum) exit(1);
		__volatile__ unsigned char *secret;
		secret = MD5((unsigned char*)in+1,strlen(in),NULL);
		activate_code_gen(secret,16);
	}else{
		activate_code_gen(in,strlen(in)-1);
	}
	fflush(stdout);
}

int main(int argc, char **argv){
	setbuf(stdin,0);
	setbuf(stdout,0);
	puts("               **************\n               Echo Server 0.1 ALPHA\n               **************");
	echo();
	return 0;
}


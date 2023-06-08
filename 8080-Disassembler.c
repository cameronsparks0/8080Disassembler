#include <stdio.h>
#include <stdlib.h>

int Disassemble8080Op(unsigned char *codebuffer, int pc){
    unsigned char *codeSeg = &codebuffer[pc];
    int opBytes = 1;
    printf("%04x:   ",pc);
    switch (*codeSeg)
    {
    case 0x00: printf("NOP"); break;
    case 0x01: printf("LXI      B,#$%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break;
    case 0x02: printf("STAX     B"); break;
    }
    printf("\n");
    return opBytes;
}
  

int main(int argc, char *argv[])
{
    FILE *fp;
    unsigned char *buffer=0;
    long length;
    int pc=0;
    if(argc==2){
        fp = fopen(argv[1],"r");
        fseek(fp,0,SEEK_END);
        length = ftell(fp);
        fseek(fp,0,SEEK_SET);
        buffer = (unsigned char*)malloc(length*sizeof(unsigned char));
        if(buffer!=0){
            fread(buffer,1,length,fp);
            while(pc<length){
                pc = pc + Disassemble8080Op(buffer,pc);
            }
            free(buffer);
        }
        fclose(fp);
    }
    else{
        printf("Invalid Number of Arguments");
        return 0;
    }
  
    return 0;
}
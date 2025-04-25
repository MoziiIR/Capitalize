#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<ctype.h>


int str_len(char *);

char* cap(char *);

uint32_t numbers(char *str);

void ctr_char(char *str);


void main()
{
    FILE *file;

    char *name = "HAj 26811 56 MohSen";
    char buffer[100];
    sprintf(buffer,"Sum of numbers ~~~> %u",numbers(name));
    printf("Sum = %u\n",numbers(name)); 
    ctr_char(name);
    char *show = cap(name);
    //printf("%s",show);

    file = fopen("Print.txt","w+");
    fprintf(file,"Before CAP~~~> %s\n\nAfter CAP~~~> %s\n",name,show);
    fprintf(file,"%s\n\n",buffer);

    fclose(file);


}


char* cap(char *str)
{
    // int size = sizeof(*str)/sizeof(str[0]);
    int size = str_len(str); 
    uint8_t k=0;
    char *pt = (void*)malloc(size*sizeof(*str));
    for(int i=0;i<size;i++)
    {
        k = str[i];
        if(k>=65&&k<=90) k+=32;
        pt[i] = k;
    }    
    
    return pt;
    //free(pt);
}

int str_len(char *str)
{
    int i=0;
    while(str[i]) i++;


    i++;
    return i;
}

uint32_t numbers(char *str)
{
    uint32_t sum=0;
    uint16_t ctr=0;
    uint8_t k,i=0;


    while(str[i])
    {
        if(isdigit(str[i]))
        {
            k=str[i]-48;
            ctr++;
            sum += k;
        }
        i++;
    }
    //printf("\nCTR OF Numbers = %u\n\n",ctr);
    return sum;
}

void ctr_char(char *str)
{
    uint8_t ctn=0;
    for(int i=0;i<str_len(str);i++)
        if(isalpha(str[i])) ctn++;

        printf("\nCTR OF Charachters = %u\n\n",ctn);
}
#include <stdio.h>  
#include <unistd.h>  

#ifdef RDP2
#define VNCOPT "V:Q"
#else
#define VNCOPT "V:"
#endif
 
int main(int argc, char **argv)  
{  
        int ch;  
        opterr = 0;  
        while ((ch = getopt(argc,argv, VNCOPT ":a:bcde::f"))!=-1)  
        {  
                switch(ch)  
                { 		
						case 'V':
								printf("option V:'%s'\n",optarg);
								break; 
                        case 'a':  
                                printf("option a:'%s'\n",optarg);  
                                break;  
                        case 'b':  
                                printf("option b :b\n");  
                                break; 
						case 'e':
								printf("option e:'%s'\n",optarg);
								break; 
                        default:  
                                printf("other option :%c\n",ch);  
                }  
        }  
        printf("optopt +%c\n",optopt);  

	return 1;
}

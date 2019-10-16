#include <stdio.h> 

void main ()
{  
	FILE *dosya,*dosya2; 
	char karekter;
	int sayac=0;
	int todoBulunma=0;

	 dosya2=fopen("todoDosya.txt","w");
     dosya=fopen("todoKod.c","r");
     
	if(dosya!=NULL){
		while(!feof(dosya)) //TODO calýsmasý 2
		{
			fscanf(dosya,"%c",&karekter); 

			if(todoBulunma==1 && karekter!='\n')  
			 fprintf(dosya2, "%c",karekter);
			
			if(sayac==0 && karekter=='T' )     
				sayac++; 
			else if(sayac==1 && karekter=='O') 
				sayac++; 
			else if(sayac==2 &&  karekter=='D') 
				sayac++; 
		    else if(sayac==3 && karekter=='O') 
				sayac++;
			else                               
		          sayac=0;

			if(sayac==4){  
			 todoBulunma=1;  
			}
			if(karekter=='\n'){  
				if(todoBulunma==1){ 
				     fprintf(dosya2,"\n"); 
				}
			 	todoBulunma=0; 
			}
		}
	} 
	fclose(dosya);
}

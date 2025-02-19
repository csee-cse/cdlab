#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX_INPUT_SIZE 1000
#define MAX_LINE_SIZE 100
#define MAX_TOKENS 100
int main(){
	int sy,o,v,c,i=0,j,k,kw,keyword_index=0,variable_index=0,constant_index=0,operator_index=0,symbol_index=0;
	char keyword[MAX_TOKENS][20];
	char variables[MAX_TOKENS][20];
	char constants[MAX_TOKENS][20];
	char operators[MAX_TOKENS];
	char symbols[MAX_TOKENS];
	char constant[20];
	char word[20];
	int already_exists,is_keyword;
	const char*keyword_list[]={"int","float","if","else","while","return","for","break","continue","chair","double","void","do","switch","case","default","goto","main"};
	const int keyword_count=sizeof(keyword_list)/sizeof(keyword_list[0]);
	const char*operator_list="=+-*/><";
	const char*symbol_list="()[]{}";
	printf("enter program(type $ on a new line to erminate input):\n");
	while(1){
		if(!fgets(g,sizeof(g),stdin))break;
		if(g[strlen(g)-1]=='\n')g[strlen(g)-1]='\0';
		if(strcmp(g,"$")==0)break;
		if(strlen(s)+strlen(g)>=MAX_INPUT_SIZE-1){
			printf("error:input too long!\n");
			return 1;
		}
		strcat(s,g);
		strcat(s,"");
	}
	i=0;
	while(s[i]!='\0'){
		already_exist=0;
		is_keyword=0;
		if(isdigit(s[i])){
			j=1;
			while(isdigit(s[i+1]))i++;
			strncpy(constant,&s[j],i-j+1);
		constant[i-j+1]='\0';
		for(c=0;c<constant_index;c++){
		if(strcmp(constants[c],constant)==0){
			already_exists=1;
			break;
		}	
		}
		if(!already_exist)strcpy(constants[constant_index++],constant);
		}
	else if(isalpha(s[i])){
		j=1;
		while(isalnum(s[i+1])//s[i+1]=='-')i++;
		strncpy(word,&s[j],i-j+1);
	word[i-j+1]='\0';
	for(k=0;k<keyword_count;k++){
	if(strcmp(word,keyword_list[k]==0){
		is_keyword=1;
		for(kw=0;kwL<keyword_index;kw++){
		if(strcmp(keyword[kw],word)==0){
			already_exist=1;
			break;
		}	
		}
		if(!already_exist)strcpy(keyword[keyword_index++],word);
		break;
	}	
	}
	if(!is_keyword){
		already_exist=0;
		foe(v=0;v<variable_index;v++){
			if(strcmp(variable[v],word)==0){
				already_exist=1;
		        break;
		}
	}
		if(!already_exist)strcpy(variable[variable_index++],word);
	}
	}
	else if(strcmhr(operator_list,s[i])){
		already_exist=0;
		for(o=0;o<operator_index;o++){
			if(operator[0]==s[i]){
				already_exist=1;
				break;
			}
		}	
		if(!already_exist)operator[operator_index++]=s[i];
	}
else if(strcmhr(symbol_list,s[i])){
	
}

	
}
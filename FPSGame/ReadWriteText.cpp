//
//  ReadWriteText.cpp
//  ShaderTest
//
//  Created by Dimitriy Dounaev on 4/05/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "ReadWriteText.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *textFileRead(const char *fn) {
    
    
	FILE *fp;
	char *content = NULL;
    
	int count=0;
    
	if (fn != NULL) {
		fp = fopen(fn,"rt");
        
		if (fp != NULL) {
            
            fseek(fp, 0, SEEK_END);
            count = (int)ftell(fp);
            rewind(fp);
            
			if (count > 0) {
				content = (char *)malloc(sizeof(char) * (count+1));
				count = (int)fread(content,sizeof(char),count,fp);
				content[count] = '\0';
			}
			fclose(fp);
		}
	}
    
    //std::cout << content;
	return content;
}

int textFileWrite(char *fn, char *s) {
    
	FILE *fp;
	int status = 0;
    
	if (fn != NULL) {
		fp = fopen(fn,"w");
        
		if (fp != NULL) {
			
			if (fwrite(s,sizeof(char),strlen(s),fp) == strlen(s))
				status = 1;
			fclose(fp);
		}
	}
	return(status);
}


//
//  ReadWriteText.h
//  ShaderTest
//
//  Created by Dimitriy Dounaev on 4/05/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __ShaderTest__ReadWriteText__
#define __ShaderTest__ReadWriteText__

#include <iostream>

char *textFileRead(const char *fn);
int textFileWrite(char *fn, char *s);

#endif /* defined(__ShaderTest__ReadWriteText__) */

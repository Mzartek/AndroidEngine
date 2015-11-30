#ifndef ANDROIDPROJECT_STRINGHANDLER_H
#define ANDROIDPROJECT_STRINGHANDLER_H

#include "../Object.h"

namespace Engine
{
     namespace Tools
     {
	  extern std::string getDir(const char *filePath);
	  extern char *readText(const char *filePath);
     }
}

#endif //ANDROIDPROJECT_STRINGHANDLER_H

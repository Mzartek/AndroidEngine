//
// Created by mzartek on 24/09/15.
//

#include "StringHandler.h"

std::string Engine::Tools::getDir(const char *filePath)
{
     size_t size, i;
     std::string path;

     for (size = i = 0; filePath[i] != '\0'; i++)
	  if (filePath[i] == '/' || filePath[i] == '\\')
	       size = i + 1;

     path.insert(0, filePath, 0, size);

     return path;
}

char* Engine::Tools::readText(const char *filePath)
{
     std::ifstream file(filePath, std::ifstream::in | std::ifstream::binary);
     char *content;
     size_t size;

     if (!file.is_open())
     {
	  ALOGE("Error while opening file: %s", filePath);
	  throw std::exception();
     }
     // Lenght of the file
     file.seekg(0, std::ifstream::end);
     size = static_cast<size_t>(file.tellg());
     file.seekg(0, std::ifstream::beg);

     // Add content
     content = new char[size + 1];
     file.read(content, size);
     content[size] = '\0';

     file.close();

     return content;
}

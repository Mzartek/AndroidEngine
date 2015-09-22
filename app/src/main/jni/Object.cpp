//
// Created by mzartek on 22/09/15.
//

#include "Object.h"

std::map<Engine::ObjectHandler, const Engine::Object *> Engine::Object::objectsHandler;

Engine::ObjectHandler Engine::Object::GenerateHandler(void)
{
    static ObjectHandler objectHandler = 1;

    while (objectsHandler.find(objectHandler) != objectsHandler.end())
    {
        objectHandler++;
    }

    return objectHandler++;
}

Engine::Object::Object(void)
        : _handler(GenerateHandler())
{
    objectsHandler[_handler] = this;
}

Engine::Object::~Object(void)
{
    objectsHandler.erase(_handler);
}

Engine::ObjectHandler Engine::Object::getHandler(void)
{
    return _handler;
}
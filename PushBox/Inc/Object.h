#pragma once
#include<string> 
#include<iostream>

class Object
{
private:
protected:
public:
    Object(){}
    virtual ~Object(){}
    virtual std::string GetString()=0;
    virtual void Display()=0;
};


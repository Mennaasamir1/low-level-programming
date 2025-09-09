#pragma once
#include <iostream>
using namespace std;

/* This is an abstract class */
class InterfaceCommunication
{
    public:
        virtual void SendEmail(string Title, string Body) = 0;
        
        virtual void SendFax(string Title, string Body) = 0;

        virtual void SendSMS(string Title, string Body) = 0;

};
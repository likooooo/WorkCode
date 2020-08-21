#ifndef OpcUaWrapper_H
#define OpcUaWrapper_H

#include <signal.h>
#include <iostream>
#include <open62541.h>

class OpcUaWrapper
{
private:
    /* data */
public:
    // OpcUaWrapper(/* args */);
    // ~OpcUaWrapper();
     bool RunService(const char * ip);
     bool StopService(const char* ip);
     bool ConnectService(const char* ip);
     bool DisConnectService(const char* ip);
};

// OpcUaWrapper::OpcUaWrapper(/* args */)
// {
// }

// OpcUaWrapper::~OpcUaWrapper()
// {
// }
#endif
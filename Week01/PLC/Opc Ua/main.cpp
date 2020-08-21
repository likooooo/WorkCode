#include "OpcUaWrapper.h"

using namespace std;


int main(int, char**) {
    std::cout << "Hello, world!\n"<<endl;
    //opcService默认就是4840端口
    string ip =  "opc.tcp://localhost:4840";
    OpcUaWrapper opc;
    bool res =opc.ConnectService(ip.c_str());
    //
    std::string  description = "ConnectService";
    description.append(ip);
    cout<< description <<endl;
    cout<< res <<endl;
    //
    res =opc.RunService(ip.c_str());
    description = "---\nRunService:";
    description.append(ip);
    cout<< description <<endl;
    cout<< res <<endl;
    //
    res = opc.ConnectService(ip.c_str());
    description = "\nConnectService:";
    description.append(ip);
    cout<< description <<endl;
    cout<< res <<endl;
    return 0;   
}

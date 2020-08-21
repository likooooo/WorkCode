#include "OpcUaWrapper.h"

using namespace std;


int main(int, char**) {
    //opcService默认就是4840端口
    string ip =  "opc.tcp://localhost:4840";
    OpcUaWrapper opc;
    bool res =opc.RunService(ip.c_str());
    description = "---\nRunService:";
    description.append(ip);
    cout<< description <<endl;
    cout<< res <<endl;

    return 0;   
}

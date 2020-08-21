#include "OpcUaWrapper.h"

UA_Boolean running = true;
void signalHandler(int sig) {
    running = false;
}


bool OpcUaWrapper::RunService(const char * ip)
{
    signal(SIGINT, signalHandler); /* catch ctrl-c */
    /* Create a server listening on port 4840 */
    UA_ServerConfig* config = UA_ServerConfig_new_default();
    UA_Server* server = UA_Server_new(config);

    /* Add a variable node */
    /* 1) Define the node attributes */
    UA_VariableAttributes attr = UA_VariableAttributes_default;
    attr.displayName = UA_LOCALIZEDTEXT("en-US", "the answer");
    UA_Int32 myInteger = 42;
    UA_Variant_setScalar(&attr.value, &myInteger, &UA_TYPES[UA_TYPES_INT32]);

    /* 2) Define where the node shall be added with which browsename */
    UA_NodeId newNodeId = UA_NODEID_STRING(1, "the.answer");
    UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER);
    UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES);
    UA_NodeId variableType = UA_NODEID_NULL; /* take the default variable type */
    UA_QualifiedName browseName = UA_QUALIFIEDNAME(1, "the answer");

    /* 3) Add the node */
    UA_Server_addVariableNode(server, newNodeId, parentNodeId, parentReferenceNodeId,
        browseName, variableType, attr, NULL, NULL);

    /* Run the server loop */
    UA_StatusCode status = UA_Server_run(server, &running);
    UA_Server_delete(server);
    UA_ServerConfig_delete(config);
    return status;
       
}

bool  OpcUaWrapper::StopService(const char* ip)
{
      return 1;
}

bool OpcUaWrapper::ConnectService(const char* ip)
{
     /* Create a client and connect */
    UA_Client* client = UA_Client_new(UA_ClientConfig_default);
    UA_StatusCode status = UA_Client_connect(client,ip);
    if (status != UA_STATUSCODE_GOOD) {
        UA_Client_delete(client);
        return status;
    }

    /* Read the value attribute of the node. UA_Client_readValueAttribute is a
     * wrapper for the raw read service available as UA_Client_Service_read. */
    UA_Variant value; /* Variants can hold scalar values and arrays of any type */
    UA_Variant_init(&value);

    char str[] = "the.answer";
    char* strPtr = str;
    status = UA_Client_readValueAttribute(client, UA_NODEID_STRING(1, str), &value);
    if (status == UA_STATUSCODE_GOOD &&
        UA_Variant_hasScalarType(&value, &UA_TYPES[UA_TYPES_INT32])) {
        printf("the value is: %i\n", *(UA_Int32*)value.data);
    }

    /* Clean up */
    UA_Variant_deleteMembers(&value);
    UA_Client_delete(client); /* Disconnects the client internally */
    system("pause");
    return status;
}

bool OpcUaWrapper::DisConnectService(const char* ip)
{
    return 1;
}



















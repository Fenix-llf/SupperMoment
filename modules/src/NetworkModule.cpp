#include "NetworkModule.h"

NetworkModule::NetworkModule(std::map<std::string, std::string> parameters)
{
    this->ident = "net";
    this->parameters = parameters;
}

void NetworkModule::init()
{
    
}

void NetworkModule::deinit()
{
}

Module::TEST_RES NetworkModule::test()
{
    return TEST_SUCCESS;
}

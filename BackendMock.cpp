#include "applications/ng/ascm/ascm_web/inc/BackendMock.h"

BackendMock::~BackendMock()
{

}

bool BackendMock::isRollBackEnabled()
{
    return m_rollbackEnabled; 
}

void BackendMock::setRollBack(bool enabled)
{
    m_rollbackEnabled = enabled;
}

int BackendMock::getHardwareId()
{
    return 1234;
}

//Functions related to building a ModemDto object:
bool BackendMock::getRX_locked_status(){
    return true;
}

double BackendMock::getRX_IF_frequency(){
    return 1234.5;
}

bool BackendMock::getTX_allowed(){
    return true;
}

double BackendMock::getTX_IF_frequency(){
    return 1234.5;
}

double BackendMock::getTX_reference(){
    return 1234.5;
}

std::string BackendMock::getModelName(){
    return "dummy";
}

std::string BackendMock::getStatus(){
    return "dummy";
}




void BackendMock::setRollBack(bool enabled){ }
bool BackendMock::isRollBackEnabled(){return true;}
int BackendMock::getHardwareId(){return 7331;}
bool BackendMock::getRX_locked_status(){return true;}
double BackendMock::getRX_IF_frequency(){return 123.456;}
bool BackendMock::getTX_allowed(){return true;}
double BackendMock::getTX_IF_frequency(){return 123.456;}
double BackendMock::getTX_reference(){return 123.456;}
std::string BackendMock::getModelName(){return "abcd";}
std::string BackendMock::getStatus(){return "abcd";}

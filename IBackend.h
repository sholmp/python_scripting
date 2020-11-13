#ifndef SRC_IBACKEND_H
#define SRC_IBACKEND_H

#include <string>

class IBackend {
  public:
    virtual ~IBackend()
    {
    }

    virtual void setRollBack(bool enabled) = 0;
    virtual bool isRollBackEnabled()       = 0;
    virtual int  getHardwareId()           = 0;


    //Functions related to building a ModemDto object:
    virtual bool getRX_locked_status() = 0;
    virtual double getRX_IF_frequency() = 0;
    
    virtual bool getTX_allowed() = 0;
    virtual double getTX_IF_frequency() = 0;
    virtual double getTX_reference() = 0;

    virtual std::string getModelName() = 0;
    virtual std::string getStatus() = 0;
    
    

};


#endif /* SRC_IBACKEND_H */

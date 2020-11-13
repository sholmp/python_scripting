#ifndef SRC_MOCKBACKEND_H
#define SRC_MOCKBACKEND_H

#include <string>

class MockBackend {
  public:
    virtual ~MockBackend()
    {
    }

    virtual void setRollBack(bool enabled) override;
    virtual bool isRollBackEnabled()       override;
    virtual int  getHardwareId()           override;


    //Functions related to building a ModemDto object:
    virtual bool getRX_locked_status() override;
    virtual double getRX_IF_frequency() override;
    
    virtual bool getTX_allowed() override;
    virtual double getTX_IF_frequency() override;
    virtual double getTX_reference() override;

    virtual std::string getModelName() override;
    virtual std::string getStatus() override;
    
    

};


#endif /* SRC_MOCKBACKEND_H */

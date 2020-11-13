#ifndef BACKENDMOCK_H
#define BACKENDMOCK_H

#include "IBackend.h"

class BackendMock : public IBackend {
  public:
    BackendMock() = default;
    virtual ~BackendMock();

    virtual bool isRollBackEnabled() override;
    virtual void setRollBack(bool enabled) override;
    virtual int getHardwareId();

    //Functions related to building a ModemDto object:
    virtual bool getRX_locked_status() override;
    virtual double getRX_IF_frequency() override;

    virtual bool getTX_allowed();
    virtual double getTX_IF_frequency();
    virtual double getTX_reference();

    virtual std::string getModelName() override;
    virtual std::string getStatus() override;

};


#endif //BACKENDMOCK_H
    
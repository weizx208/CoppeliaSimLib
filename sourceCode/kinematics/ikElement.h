#pragma once

#include "ser.h"
#include "extIkSer.h"
#include "MyMath.h"
#include "_ikElement_.h"

class CIkElement : public _CIkElement_
{
public:
    CIkElement();
    CIkElement(int theTooltip);
    virtual ~CIkElement();

    // Overridden from CSyncObject:
    void buildUpdateAndPopulateSynchronizationObject(const std::vector<SSyncRoute>* parentRouting);
    void connectSynchronizationObject();
    void removeSynchronizationObject(bool localReferencesToItOnly);

    void initializeInitialValues(bool simulationIsRunning);
    void simulationEnded();
    CIkElement* copyYourself() const;
    void serialize(CSer& ar);
    void serializeWExtIk(CExtIkSer& ar) const;
    bool announceObjectWillBeErased(int objID,bool copyBuffer);
    void performObjectLoadingMapping(const std::vector<int>* map);

    int getTargetHandle() const;
    int getIkPluginCounterpartHandle() const;
    void setIkGroupPluginCounterpartHandle(int h);

    // Overridden from _CIkElement_:
    bool setMinLinearPrecision(float prec);
    bool setMinAngularPrecision(float prec);
    bool setPositionWeight(float weight);
    bool setOrientationWeight(float weight);

    std::string getTipLoadName() const;
    std::string getBaseLoadName() const;
    std::string getAltBaseLoadName() const;

    void setAllInvolvedJointsToIkPluginPositions() const;
    void setAllInvolvedJointsToNewJointMode(int jointMode) const;

private:
    void _commonInit();

    // Overridden from _CIkElement_:
    void _setEnabled_send(bool e) const;
    void _setBase_send(int h) const;
    void _setAlternativeBaseForConstraints_send(int h) const;
    void _setMinLinearPrecision_send(float f) const;
    void _setMinAngularPrecision_send(float f) const;
    void _setPositionWeight_send(float f) const;
    void _setOrientationWeight_send(float f) const;
    void _setConstraints_send(int c) const;

    int _ikGroupPluginCounterpartHandle;
    int _ikElementPluginCounterpartHandle;

    std::string _tipLoadName;
    std::string _baseLoadName;
    std::string _altBaseLoadName;
};

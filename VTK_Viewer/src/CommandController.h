#pragma once
#include <QObject>
#include "rc.h"
#include "SketcherInteractorStyle.h"
#include "CommandInterface.h"
#include "CommandDrawPoint.h"

class CommandController : public QObject 
{
    Q_OBJECT
public:
    CommandController();
    ~CommandController();
    void connectIcon();
    void setCurrentCommand(CommandType type){
        CommandInterface* cmd = nullptr;
        switch (type)
        {
        case CommandType::CommandNone
            break;
        case CommandType::CommandDrawPoint
            cmd = new CommandDrawPoint();
        default:
            break;
        }
        
    }
public slots:
    void slotDrawPoint();
private:
    SketcherInteractorStyle* style;
};
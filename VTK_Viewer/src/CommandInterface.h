#pragma once
#include <QObject>

class QAction;
class QKeyEvent;
class QString;

class CommandInterface : public QObject{
   Q_OBJECT
public:
   CommandInterface();
	virtual ~CommandInterface() = default;
   virtual void mouseMoveEvent(QMouseEvent*) =0;
   virtual void mousePressEvent(QMouseEvent*)=0;
   virtual void mouseReleaseEvent(QMouseEvent*)=0;
   virtual void keyPressEvent(QKeyEvent* e)=0;
   virtual void keyReleaseEvent(QKeyEvent* e)=0;
   virtual bool isFinished() const;
   virtual void setFinished();
   virtual void finish(bool updateTB = true );
};

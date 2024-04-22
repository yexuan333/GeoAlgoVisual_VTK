#pragma once
#include "CommandInterface.h"
#include "Container.h"
#include "Point3d.h"


class CommandDrawPoint : public CommandInterface {
	Q_OBJECT
public:
    CommandDrawPoint(Container& container);
	~CommandDrawPoint() override;
	void trigger();
    void mouseMoveEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void keyPressEvent(QKeyEvent* e) override;
    void keyReleaseEvent(QKeyEvent* e) override;
private:
	Point3d p;
};
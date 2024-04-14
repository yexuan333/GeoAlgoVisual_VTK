//#ifndef RS_ACTIONDRAWPOINT_H
//#define RS_ACTIONDRAWPOINT_H
//
//#include "PreviewActionInterface.h"
//
//
///**
// * This action class can handle user events to draw points.
// *
// * @author Andrew Mustun
// */
//class ActionDrawPoint : public PreviewActionInterface {
//	Q_OBJECT
//public:
//    ActionDrawPoint(Container& container);
//	~ActionDrawPoint() override;
//
//	void trigger() override;
//
//	void mouseMoveEvent(QMouseEvent* e) override;
//	void mouseReleaseEvent(QMouseEvent* e) override;
//	
//	void coordinateEvent(RS_CoordinateEvent* e) override;
//	void commandEvent(RS_CommandEvent* e) override;
//		QStringList getAvailableCommands() override;
//
//	void updateMouseButtonHints() override;
//	void updateMouseCursor() override;
//
//private:
//	std::unique_ptr<Point3d> pt;
//};
//
//#endif

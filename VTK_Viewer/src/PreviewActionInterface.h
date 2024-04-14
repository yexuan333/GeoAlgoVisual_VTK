//#pragma once
//#include <memory>
//#include "Actioninterface.h"
//
///**
// * This is the interface that must be implemented for all
// * action classes which need a preview.
// *
// * @author Andrew Mustun
// */
//class PreviewActionInterface : public ActionInterface {
//public:
//    PreviewActionInterface();
//	~PreviewActionInterface() override;
//
//	void init(int status=0) override;
//	void finish(bool updateTB=true) override;
//	void suspend() override;
//	void resume() override;
//	void trigger() override;
//    void drawPreview();
//    void deletePreview();
//protected:
//    /**
//     * Preview that holds the entities to be previewed.
//     */
//	std::unique_ptr<RS_Preview> preview;
//    bool hasPreview = true;//whether preview is in use
//};
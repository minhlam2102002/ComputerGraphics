#include "RenderEngine.h"

RenderEngine *RenderEngine::renderEngine = nullptr;

RenderEngine::RenderEngine() {
    this->_state = 0;
    this->layer = 0;
    this->color = nullptr;
    this->mouseDown = nullptr;
    this->mouseUp = nullptr;
    this->object = nullptr;
}
RenderEngine *RenderEngine::getInstance() {
    if (renderEngine == nullptr) {
        renderEngine = new RenderEngine();
    }
    return renderEngine;
}
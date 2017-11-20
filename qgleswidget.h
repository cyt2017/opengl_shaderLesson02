#ifndef QGLESWIDGET_H
#define QGLESWIDGET_H

#include <QWidget>
#include <FreeImage.h>
#include "tool/CELLMath.hpp"
#include "tool/program_p2_c4.h"
#define MESA_EGL_NO_X11_HEADERS
#include <EGL/egl.h>


#define NUM_PARTICLES	1000
#define PARTICLE_SIZE   7

class QGLESWIDGET : public QWidget
{
    Q_OBJECT
public:
    explicit QGLESWIDGET(QWidget *parent = 0);
    ~QGLESWIDGET();

    //! 窗口的高度
    int         _width;
    //! 窗口的宽度
    int         _height;
    /// for gles2.0
    EGLConfig   _config;
    EGLSurface  _surface;
    EGLContext  _context;
    EGLDisplay  _display;

    //! 增加shader
    PROGRAM_P2_C4   _shader;
    unsigned int    _texture;
    unsigned int    _texture1;
    double          _hasElasped;

    bool init_QGW(std::vector<QString> fileName);

    //! 初始化 OpenGLES2.0
    bool    initOpenGLES20();
    //! 销毁OpenGLES2.0
    void    destroyOpenGLES20();
    virtual void render();
    virtual unsigned int loadTexture(QString name);

    void drawImage();
signals:

public slots:
};

#endif // QGLESWIDGET_H

#include "program_p2_c4.h"

PROGRAM_P2_C4::PROGRAM_P2_C4()
{
    _pos        =   -1;
    _mvp        =   -1;
    _uv         =   -1;
    _texture    =   -1;
    _texture1   =   -1;
    _offset     =   -1;
}

bool PROGRAM_P2_C4::initialize()
{
    const char* vs  =
    {
        "uniform    mat4    _mvp;"
        "attribute  vec3    _pos;"
        "attribute  vec2    _uv;"
        "varying    vec2    _outUV;"
        "void main()"
        "{"
        "   _outUV      = _uv;"
        "   gl_Position = _mvp * vec4(_pos.x,_pos.y,_pos.z,1.0);"
        "}"
    };
    const char* ps  =
    {
        "precision  mediump     float;"
        "uniform    sampler2D   _texture;"
        "uniform    sampler2D   _texture1;"
        "uniform    float       _offset;"
        "varying    vec2        _outUV;"
        "void main()"
        "{"
        "  vec4 texColor    =   texture2D( _texture,_outUV);"
        "  vec4 texColor1   =   texture2D( _texture1,_outUV);"
        "  vec4 color       =   texColor *(1.0-_offset) + texColor1*_offset;"
        "  gl_FragColor     =   color;"
        "}"
    };


    bool    res =   createProgram(vs,ps);
    if(res)
    {
        _pos    =   glGetAttribLocation ( _programId, "_pos" );
        _uv     =   glGetAttribLocation ( _programId, "_uv" );

        // Get the uniform locations
        _mvp     =   glGetUniformLocation ( _programId, "_mvp" );
        _texture =   glGetUniformLocation ( _programId, "_texture" );
        _texture1=   glGetUniformLocation ( _programId, "_texture1" );
        _offset  =   glGetUniformLocation ( _programId, "_offset" );

    }
    return  res;
}

void PROGRAM_P2_C4::begin()
{
    glUseProgram(_programId);
    glEnableVertexAttribArray ( _pos );
    glEnableVertexAttribArray ( _uv );
}

void PROGRAM_P2_C4::end()
{
    glDisableVertexAttribArray ( _pos );
    glDisableVertexAttribArray ( _uv );
    glUseProgram(0);
}

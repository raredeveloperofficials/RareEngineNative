#pragma once
// Enable / Disable
#define GL_DEPTH_TEST               0x0B71
#define GL_STENCIL_TEST             0x0B90
#define GL_SCISSOR_TEST             0x0C11
#define GL_CULL_FACE                0x0B44
#define GL_BLEND                    0x0BE2
#define GL_DITHER                   0x0BD0
#define GL_POLYGON_OFFSET_FILL      0x8037

// Clear bits
#define GL_DEPTH_BUFFER_BIT         0x00000100
#define GL_STENCIL_BUFFER_BIT       0x00000400
#define GL_COLOR_BUFFER_BIT         0x00004000

// Boolean
#define GL_FALSE                     0
#define GL_TRUE                      1

// Primitive types
#define GL_POINTS                   0x0000
#define GL_LINES                    0x0001
#define GL_LINE_LOOP                0x0002
#define GL_LINE_STRIP               0x0003
#define GL_TRIANGLES                0x0004
#define GL_TRIANGLE_STRIP           0x0005
#define GL_TRIANGLE_FAN             0x0006

// Depth functions
#define GL_NEVER                    0x0200
#define GL_LESS                     0x0201
#define GL_EQUAL                    0x0202
#define GL_LEQUAL                   0x0203
#define GL_GREATER                  0x0204
#define GL_NOTEQUAL                 0x0205
#define GL_GEQUAL                   0x0206
#define GL_ALWAYS                   0x0207

// Face culling
#define GL_FRONT                    0x0404
#define GL_BACK                     0x0405
#define GL_FRONT_AND_BACK           0x0408

#define GL_CW                      0x0900
#define GL_CCW                     0x0901

// Data types
#define GL_BYTE                     0x1400
#define GL_UNSIGNED_BYTE            0x1401
#define GL_SHORT                    0x1402
#define GL_UNSIGNED_SHORT           0x1403
#define GL_INT                      0x1404
#define GL_UNSIGNED_INT             0x1405
#define GL_FLOAT                    0x1406

// Buffers
#define GL_ARRAY_BUFFER             0x8892
#define GL_ELEMENT_ARRAY_BUFFER     0x8893

#define GL_STREAM_DRAW              0x88E0
#define GL_STATIC_DRAW              0x88E4
#define GL_DYNAMIC_DRAW             0x88E8

// Textures
#define GL_TEXTURE_2D               0x0DE1

#define GL_TEXTURE0                 0x84C0
#define GL_TEXTURE1                 0x84C1
#define GL_TEXTURE2                 0x84C2
#define GL_TEXTURE3                 0x84C3

#define GL_NEAREST                  0x2600
#define GL_LINEAR                   0x2601

#define GL_TEXTURE_MAG_FILTER       0x2800
#define GL_TEXTURE_MIN_FILTER       0x2801
#define GL_TEXTURE_WRAP_S           0x2802
#define GL_TEXTURE_WRAP_T           0x2803

#define GL_REPEAT                   0x2901
#define GL_CLAMP_TO_EDGE            0x812F
#define GL_MIRRORED_REPEAT          0x8370

// Shaders
#define GL_VERTEX_SHADER            0x8B31
#define GL_FRAGMENT_SHADER          0x8B30

#define GL_COMPILE_STATUS           0x8B81
#define GL_LINK_STATUS              0x8B82
#define GL_VALIDATE_STATUS          0x8B83
#define GL_INFO_LOG_LENGTH          0x8B84

// Framebuffers
#define GL_FRAMEBUFFER              0x8D40
#define GL_RENDERBUFFER             0x8D41

#define GL_COLOR_ATTACHMENT0        0x8CE0
#define GL_DEPTH_ATTACHMENT         0x8D00
#define GL_STENCIL_ATTACHMENT       0x8D20

#define GL_FRAMEBUFFER_COMPLETE     0x8CD5

// Errors
#define GL_NO_ERROR                 0
#define GL_INVALID_ENUM             0x0500
#define GL_INVALID_VALUE            0x0501
#define GL_INVALID_OPERATION        0x0502
#define GL_OUT_OF_MEMORY            0x0505
// Blending
#define GL_ZERO                         0x0000
#define GL_ONE                          0x0001
#define GL_SRC_COLOR                    0x0300
#define GL_ONE_MINUS_SRC_COLOR          0x0301
#define GL_SRC_ALPHA                    0x0302
#define GL_ONE_MINUS_SRC_ALPHA          0x0303
#define GL_DST_ALPHA                    0x0304
#define GL_ONE_MINUS_DST_ALPHA          0x0305
#define GL_DST_COLOR                    0x0306
#define GL_ONE_MINUS_DST_COLOR          0x0307
#define GL_SRC_ALPHA_SATURATE           0x0308

#define GL_FUNC_ADD                     0x8006
#define GL_FUNC_SUBTRACT                0x800A
#define GL_FUNC_REVERSE_SUBTRACT        0x800B


// Texture formats
#define GL_RED                          0x1903
#define GL_RG                           0x8227
#define GL_RGBA8                        0x8058
#define GL_RGB8                         0x8051

#define GL_DEPTH_COMPONENT              0x1902
#define GL_DEPTH_COMPONENT16            0x81A5
#define GL_DEPTH_COMPONENT24            0x81A6
#define GL_DEPTH_COMPONENT32F           0x8CAC


// Texture units
#define GL_TEXTURE4                     0x84C4
#define GL_TEXTURE5                     0x84C5
#define GL_TEXTURE6                     0x84C6
#define GL_TEXTURE7                     0x84C7
#define GL_TEXTURE8                     0x84C8
#define GL_TEXTURE9                     0x84C9
#define GL_TEXTURE10                    0x84CA
#define GL_TEXTURE11                    0x84CB
#define GL_TEXTURE12                    0x84CC
#define GL_TEXTURE13                    0x84CD
#define GL_TEXTURE14                    0x84CE
#define GL_TEXTURE15                    0x84CF
#define GL_TEXTURE16                    0x84D0
#define GL_TEXTURE17                    0x84D1
#define GL_TEXTURE18                    0x84D2
#define GL_TEXTURE19                    0x84D3
#define GL_TEXTURE20                    0x84D4
#define GL_TEXTURE21                    0x84D5
#define GL_TEXTURE22                    0x84D6
#define GL_TEXTURE23                    0x84D7
#define GL_TEXTURE24                    0x84D8
#define GL_TEXTURE25                    0x84D9
#define GL_TEXTURE26                    0x84DA
#define GL_TEXTURE27                    0x84DB
#define GL_TEXTURE28                    0x84DC
#define GL_TEXTURE29                    0x84DD
#define GL_TEXTURE30                    0x84DE
#define GL_TEXTURE31                    0x84DF


// Framebuffer / renderbuffer
#define GL_RENDERBUFFER_WIDTH           0x8D42
#define GL_RENDERBUFFER_HEIGHT          0x8D43

#define GL_FRAMEBUFFER_BINDING          0x8CA6
#define GL_RENDERBUFFER_BINDING         0x8CA7

#define GL_DRAW_FRAMEBUFFER             0x8CA9
#define GL_READ_FRAMEBUFFER             0x8CA8

#define GL_COLOR_ATTACHMENT1            0x8CE1
#define GL_COLOR_ATTACHMENT2            0x8CE2
#define GL_COLOR_ATTACHMENT3            0x8CE3
#define GL_COLOR_ATTACHMENT4            0x8CE4
#define GL_COLOR_ATTACHMENT5            0x8CE5
#define GL_COLOR_ATTACHMENT6            0x8CE6
#define GL_COLOR_ATTACHMENT7            0x8CE7


// Vertex attributes
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED          0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE             0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE           0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE             0x8625
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED      0x886A
#define GL_VERTEX_ATTRIB_ARRAY_POINTER          0x8645
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING   0x889F


#define GL_ACTIVE_ATTRIBUTES             0x8B89
#define GL_ACTIVE_UNIFORMS               0x8B86
#define GL_CURRENT_PROGRAM               0x8B8D
#define GL_ATTACHED_SHADERS              0x8B85


// Viewport / scissor
#define GL_VIEWPORT                     0x0BA2
#define GL_SCISSOR_BOX                  0x0C10


// Additional errors
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506


// Pixel storage
#define GL_UNPACK_ALIGNMENT              0x0CF5
#define GL_PACK_ALIGNMENT                0x0D05


// Common texture targets
#define GL_TEXTURE_CUBE_MAP             0x8513
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X  0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X  0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y  0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y  0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z  0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z  0x851A


// Mipmap filtering
#define GL_NEAREST_MIPMAP_NEAREST        0x2700
#define GL_LINEAR_MIPMAP_NEAREST         0x2701
#define GL_NEAREST_MIPMAP_LINEAR         0x2702
#define GL_LINEAR_MIPMAP_LINEAR          0x2703



#define GL_DEPTH_FUNC                    0x0B74
#define GL_DEPTH_WRITEMASK               0x0B72
#define GL_COLOR_WRITEMASK               0x0C23


// Polygon offset
#define GL_POLYGON_OFFSET_FACTOR        0x8038
#define GL_POLYGON_OFFSET_UNITS         0x2A00

#include<string>
class GraphicsBackend
{
public:
    virtual void Clear() = 0;

    virtual void SetClearColor(
        float r,
        float g,
        float b,
        float a
    ) = 0;

    virtual void SetViewport(
        int x,
        int y,
        int width,
        int height
    ) = 0;
    virtual int CreateProgram(const std::string& vertex,const std::string& fragment) = 0;
    virtual void UseProgram(int program)=0;
    virtual void EnableFeature(int feature)=0;
    virtual void DisableFeature(int feature)=0;
    virtual void BlendFunction(int sfact,int dfact) = 0;
    virtual void CullFace(int type) = 0;
    virtual void FrontFace(int face) = 0;
    virtual ~GraphicsBackend() = default;
};

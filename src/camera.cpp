#include "camera.h"
#include "sdlinclude.h"

namespace vik
{

Camera2D::Camera2D(f32 width, f32 height):
width(width),
height(height),
position(0.0f,0.0f),
scale(1.0f,1.0f),
rotation(0.0f)
{
}

void Camera2D::OnInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, width, height, 0.0);
}

void Camera2D::OnPreRender()
{
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(-position.x, -position.y, 0.0f);
    glScalef(scale.x, scale.y, 1.0f);
    glRotatef(rotation, 0.0f, 0.0f, 1.0f);
}

} // end namespace vik

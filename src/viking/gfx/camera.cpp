#include "viking/gfx/camera.h"
#include "viking/sdl/include.h"

namespace vik
{

Camera2D::Camera2D():
view(0.0f,0.0f),
position(0.0f,0.0f),
scale(1.0f,1.0f),
rotation(0.0f)
{
}

void Camera2D::OnPreRender()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, view.x, view.y, 0.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-position.x, -position.y, 0.0f);
    glScalef(scale.x, scale.y, 1.0f);
    glRotatef(rotation, 0.0f, 0.0f, 1.0f);
}

} // end namespace vik

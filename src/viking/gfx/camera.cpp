#include "viking/gfx/camera.h"
#include "viking/sdl/include.h"

namespace vik
{

Camera::Camera():
view(0.0f,0.0f)
{
}

void Camera::OnPreRender()
{
    const Transformf& inv(GetInverseTransform());

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, GetView().x, GetView().y, 0.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMultMatrixf(inv.GetData());
}

void Camera::SetView(const Vector2f& view)
{
    this->view = view;
}

Vector2f& Camera::GetView()
{
    return view;
}

} // end namespace vik

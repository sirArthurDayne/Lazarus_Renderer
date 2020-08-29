#include"Framebuffer.h"
#include "Camera.h"


vec3 RenderScene(const Ray& ray)
{
	vec3 colorA = { 255.0f};
	vec3 colorB = { 128.0f,200.0f,255.0f };
    vec3 dir = ray.direction;
    float t = dir.y * 0.5f + 1.f;
    return colorA.interpolate(colorB, t);
}

int main()
{
	const int WIDTH = 320;
	const int HEIGHT = 156;

    vec3 origin = vec3(0.0f, 0.0f, -2.0f);
    Camera camera {origin, 45.0f, (float)WIDTH/(float)HEIGHT};
	Framebuffer buffer {WIDTH,HEIGHT,3};
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
            const float u = float(x) / float(WIDTH);
            const float v = float(y) / float(HEIGHT);
            Ray ray = camera.getray(u,v);
			buffer.write(x, y, RenderScene(ray));
		}
	}
	buffer.save("images/result.png");
	return 0;
}

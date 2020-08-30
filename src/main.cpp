#include"Framebuffer.h"
#include "Camera.h"

bool hit_sphere(const Ray& ray, vec3 center, float radius)
{
    vec3 origin = ray.origin;
    vec3 oc = origin - center;
    float b = 2.0f *oc.dot(ray.direction);
    float c = oc.dot(oc) - radius * radius;
    float discr = b*b - 4.0f * c;
    return (discr > 0.0f);
}

vec3 RenderScene(const Ray& ray)
{
	vec3 colorA = { 255.0f};
	vec3 colorB = { 128.0f,200.0f,255.0f };
    if(hit_sphere(ray,vec3(0.0f,0.0f,-1.0f), .50f))
        return vec3(255.0f,0.0f,0.0f);

    vec3 dir = ray.direction;
    float t = dir.y * 0.5f + 1.f;
    return colorA.interpolate(colorB, t);
}

int main()
{
	const int WIDTH = 480;
	const int HEIGHT = 320;

    vec3 origin = vec3(0.0f, 0.0f, -5.0f);
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

#include"Framebuffer.h"

int main()
{
	const int WIDTH = 200;
	const int HEIGHT = 100;
	vec3 colorA = { 255.0f,0.0f,0.0f };
	vec3 colorB = { .0f,0.0f,255.0f };
	Framebuffer buffer {WIDTH,HEIGHT,3};
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			buffer.write(x, y, colorA.interpolate(colorB,float(x) /float(WIDTH) ));
		}
	}
	buffer.save("images/result.png");
	return 0;
}

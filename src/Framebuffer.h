#pragma once
#include <vector>
#include <string>
#include "vec.h"

class Framebuffer
{
public:
	Framebuffer();
	Framebuffer(int  w, int  h, int channels);
	void write(int  x, int  y, const vec3& color);
	void save(const std::string path);
	int width() const;
	int height() const;
private:
	void save_png(const char* path);
	void save_ppm(const char* path);
	int getIndex(int x, int y) const;
	int  m_width=0, m_height=0, m_channels=0;
	std::vector<vec3> m_colorData;
};


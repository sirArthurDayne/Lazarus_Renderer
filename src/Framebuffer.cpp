#define _CRT_SECURE_NO_WARNINGS
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include"stb_image_write.h"
#include "Framebuffer.h"


Framebuffer::Framebuffer() =default;
Framebuffer::Framebuffer(int  w, int  h, int channels) : m_width(w), m_height(h), m_channels(channels)
{
	m_colorData.resize(m_width * m_height);
}
void Framebuffer::write(int  x, int  y, const vec3& color)//range from 0 to 255
{
	int index = getIndex(x, y);
	m_colorData[index] = color;
}

void Framebuffer::save(const std::string path)
{
	const std::string extensions[2]{ ".png",".ppm" };
	const auto ext_begin = path.find('.');
	std::string extracted_extension = path.substr(ext_begin, path.length());

	if (extracted_extension == extensions[0]) save_png(path.c_str());
	else if (extracted_extension == extensions[1]) save_ppm(path.c_str());
}

int Framebuffer::width() const { return m_width; };
int Framebuffer::height() const { return m_height; };
int Framebuffer::getIndex(int x, int y) const { return y * m_width + x; }


void Framebuffer::save_png(const char* path)
{
	unsigned char* data = new unsigned char[m_width * m_height * m_channels];
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			//transfer color data to arrays
			int index = getIndex(x, y) * m_channels;
			auto color = m_colorData[getIndex(x, y)];
			data[index++] = color.x;
			data[index++] = color.y;
			data[index] = color.z;
		}
	}
	//generate image 
	stbi_write_png(path, m_width, m_height, m_channels, data, m_width * m_channels);
	delete[] data;
}

void Framebuffer::save_ppm(const char* path)
{
	FILE* file = fopen(path, "wb");

	(void)fprintf(file, "P6\n%d %d\n255\n", m_width, m_height);
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			//transfer color data to arrays
			int index = getIndex(x, y);
			auto color = m_colorData[index];
			static unsigned char output[3];
			output[0] = color.x;
			output[1] = color.y;
			output[2] = color.z;
			(void)fwrite(output, 1, 3, file);
		}
	}
	(void)fclose(file);
}


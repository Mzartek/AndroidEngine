//
// Created by mzartek on 27/09/15.
//

#include "Texture.h"

#include <cstdio>
#include <cstdlib>
#include <png.h>

template<typename T>
GLubyte valueToByte(T value)
{
    return static_cast<GLubyte>(static_cast<unsigned long long>(value) * static_cast<GLubyte>(~0) / static_cast<T>(~0));
}

Engine::Image Engine::Image::loadPNG(const ::Engine::Image::GLchar *file)
{
    Image res;

    FILE *input = fopen(file, "rb");
    if (!input)
    {
        throw std::runtime_error(std::string(file) + ": Unable to open");
    }

    int number = 8;
    png_byte header[number];
    fread(header, 1, number, input);
    if (png_sig_cmp(header, 0, number))
    {
        fclose(input);

        throw std::runtime_exception(std::string(inFile) + ": It's not a png image");
    }

    png_structp png_ptr = png_create_read_struct (PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr)
    {
        fclose(input);

        throw std::runtime_error(std::string(inFile) + ": Failed to create read struct");
    }

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
    {
        png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
        fclose(input);

        throw std::runtime_error(std::string(inFile) + ": Failed to create info struct");
    }

    png_infop end_info_ptr = png_create_info_struct(png_ptr);
    if (!end_info_ptr)
    {
        png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
        fclose(input);

        throw std::runtime_error(std::string(inFile) + ": Failed to create end info struct");
    }

    if (setjmp(png_jmpbuf(png_ptr)))
    {
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info_ptr);
        fclose(input);

        throw std::runtime_error(std::string(inFile) + ": Error while reading");
    }

    png_init_io(png_ptr, input);
    png_set_sig_bytes(png_ptr, number);

    png_read_info(png_ptr, info_ptr);

    png_uint_32 width, height;
    int bit_depth, color_type, interlace_method, compression_type, filter_method;

    png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, &interlace_method, &compression_type, &filter_method);

    res.width = static_cast<GLsizei>(width);
    res.height = static_cast<GLsizei>(height);

    size_t num_channel;
    switch (color_type)
    {
        case PNG_COLOR_TYPE_RGB:
            num_channel = 3;
            break;
        case PNG_COLOR_TYPE_RGBA:
            num_channel = 4;
            break;
        default:
            throw std::runtime_error(std::string(inFile) + ": Unsupported color type");
    }

    size_t size_channel;
    switch (bit_depth)
    {
        case 8:
            size_channel = sizeof(png_uint_8);
            break;
        case 16:
            size_channel = sizeof(png_uint_16);
            break;
        default:
            throw std::runtime_error(std::string(inFile) + ": Unsupported bit depth");
    }

    png_bytep row = reinterpret_cast<png_bytep>(malloc(num_channel * size_channel * width));
    for (png_uint_32 y = 0 ; y < height ; y++)
    {
        png_read_row(png_ptr, row, NULL);
        for (png_uint_32 x = 0 ; x < width ; x++)
        {
            Color color;

            color.r = valueToByte(row[(x*num_channel  ) * size_channel]);
            color.g = valueToByte(row[(x*num_channel+1) * size_channel]);
            color.b = valueToByte(row[(x*num_channel+2) * size_channel]);
            color.a = num_channel == 4
                    ? valueToByte(row[(x*num_channel+3) * size_channel])
                    : 255

            res.data.push_back(color);
        }
    }
    free(row);

    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info_ptr);
    fclose(input);

    return res;
}

Engine::Texture::Texture(void)
        : _idTexture(0)
{
}

Engine::Texture::~Texture(void)
{
    if (glIsTexture(_idTexture)) glDeleteTextures(1, &_idTexture);
}

GLuint Engine::Texture::getId(void) const
{
    return _idTexture;
}
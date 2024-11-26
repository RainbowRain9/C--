#include <iostream>
#include <atlimage.h>
using namespace std;

int main()
{
    // 读取图片
    CImage image;
    image.Load(_T("6.jpg"));

    // 调整亮度和对比度
    double alpha = 1.5; // 对比度控制，1.0表示原始对比度
    int beta = 50;      // 亮度控制，0表示原始亮度

    // 获取图片的宽度和高度
    int width = image.GetWidth();
    int height = image.GetHeight();

    // 遍历图片的每个像素
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // 获取当前像素的颜色
            RGBQUAD color;
            image.GetPixelInfo(x, y, &color);

            // 分解颜色
            BYTE red = color.rgbRed;
            BYTE green = color.rgbGreen;
            BYTE blue = color.rgbBlue;

            // 调整颜色
            red = saturate_cast<BYTE>(alpha * red + beta);
            green = saturate_cast<BYTE>(alpha * green + beta);
            blue = saturate_cast<BYTE>(alpha * blue + beta);

            // 合成颜色
            color.rgbRed = red;
            color.rgbGreen = green;
            color.rgbBlue = blue;

            // 设置新的像素颜色
            image.SetPixelInfo(x, y, &color);
        }
    }

    // 保存调整后的图片
    image.Save(_T("new_6.jpg"));

    return 0;
}
.h >
    using namespace std;

int main()
{
    // 读取图片
    CImage image;
    image.Load(_T("6.jpg"));

    // 调整亮度和对比度
    double alpha = 1.5; // 对比度控制，1.0表示原始对比度
    int beta = 50;      // 亮度控制，0表示原始亮度

    // 获取图片的宽度和高度
    int width = image.GetWidth();
    int height = image.GetHeight();

    // 遍历图片的每个像素
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // 获取当前像素的颜色
            COLORREF color = image.GetPixel(x, y);

            // 分解颜色
            BYTE red = GetRValue(color);
            BYTE green = GetGValue(color);
            BYTE blue = GetBValue(color);

            // 调整颜色
            red = saturate_cast<BYTE>(alpha * red + beta);
            green = saturate_cast<BYTE>(alpha * green + beta);
            blue = saturate_cast<BYTE>(alpha * blue + beta);

            // 合成颜色
            COLORREF new_color = RGB(red, green, blue);

    // 设置新的像素颜色

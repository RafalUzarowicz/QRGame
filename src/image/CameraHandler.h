#include <linux/videodev2.h>
#include <vector>

// FIXME To juz jest potrzebne w obecnej wersji ale moze do czegos bedziecie potrzebowac to nie usuwam

class CameraHandler {

public:

    CameraHandler();

    ~CameraHandler();

    void askDevice();

    void specifyFormat();

    void requestDeviceBuffer();

    void queryDeviceBuffer();

    void startStreaming();

    void stopStreaming();

    void captureFrame();

    // IplImage * getOpenCVImage();

    void configure();

    void getFrame();

    void setWidth(int width);

    void setHeight(int height);

    void setFilename(std::string filename);

    void setFrameDelay(int delay);

    int getWidth();

    int getHeight();

    void ConvertYUVtoRGB(int y, int u, int v, unsigned char *buff);

private:

    int fd;
    int imageWidth;
    int imageHeight;

    int frameDelay;
public:
    int getFrameDelay() const;

private:
    std::string filename;

    struct v4l2_buffer infoBuffer{};
    unsigned char *buffer{nullptr};
public:
    unsigned char *getBuffer() const;

private:

    std::vector<unsigned char> externalBuffer;

};
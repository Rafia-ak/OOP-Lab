#include <iostream>
#include <string>

using namespace std;

class MediaFile {
public:
    string filePath;
    size_t fileSize;

    MediaFile(string path, size_t size) : filePath(path), fileSize(size) {}

    virtual void play() {
        cout << "Playing media from " << filePath << endl;
    }

    virtual void stop() {
        cout << "Stopping media from " << filePath << endl;
    }

    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile {
public:
    int resolutionWidth;
    int resolutionHeight;

    VisualMedia(string path, size_t size, int width, int height)
        : MediaFile(path, size), resolutionWidth(width), resolutionHeight(height) {}

    void showResolution() {
        cout << "Resolution: " << resolutionWidth << "x" << resolutionHeight << endl;
    }

    virtual ~VisualMedia() {}
};

class AudioMedia : virtual public MediaFile {
public:
    int sampleRate;

    AudioMedia(string path, size_t size, int rate)
        : MediaFile(path, size), sampleRate(rate) {}

    void showSampleRate() {
        cout << "Sample Rate: " << sampleRate << " Hz" << endl;
    }

    virtual ~AudioMedia() {}
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, size_t size, int width, int height, int rate)
        : MediaFile(path, size), VisualMedia(path, size, width, height), AudioMedia(path, size, rate) {}

    void play() override {
        cout << "Playing video from " << filePath << endl;
        showResolution();
        showSampleRate();
    }

    void stop() override {
        cout << "Stopping video from " << filePath << endl;
    }
};

int main() {
    MediaFile* mediaFiles[3];

    mediaFiles[0] = new VideoFile("video.mp4", 500, 1920, 1080, 44100);
    mediaFiles[1] = new AudioMedia("audio.mp3", 50, 44100);
    mediaFiles[2] = new VisualMedia("image.jpg", 20, 1920, 1080);

    for (int i = 0; i < 3; ++i) {
        mediaFiles[i]->play();
        mediaFiles[i]->stop();
        delete mediaFiles[i];
    }

    return 0;
}


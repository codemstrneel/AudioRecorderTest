#ifndef WAVEFILEWRITER_H
#define WAVEFILEWRITER_H

#include <fstream>
#include <string>
#include <windows.h>
#include <mmreg.h>

class WaveFileWriter {
public:
    WaveFileWriter(const std::string& filename, WAVEFORMATEX* format);
    ~WaveFileWriter();

    void writeData(const BYTE* data, size_t size);
    void finalize();

private:
    std::ofstream file;
    WAVEFORMATEX* format;
    size_t dataChunkSize;
    size_t fileSize;
};

#endif // WAVEFILEWRITER_H

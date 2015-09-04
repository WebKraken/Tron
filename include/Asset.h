#ifndef ASSET_H
#define ASSET_H
#include <string>

class Asset
{
public:
    virtual std::string getName() = 0;
    virtual std::string getPath() = 0;
    virtual bool init() = 0;
};

class Image : public Asset
{
public:
    virtual bool draw() = 0;

private:
    enum ImageType { BITMAP };
};

class Sound : public Asset
{
public:
    virtual bool play() = 0;
};


#endif // ASSET_H

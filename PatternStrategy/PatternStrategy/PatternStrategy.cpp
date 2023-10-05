

#include <iostream>
class Reader {
public:
    virtual void Parce(const std::string& ) = 0;
    virtual ~Reader() {};
};

class ResourceReader {
    Reader* reader{nullptr};
public:
    void SetReader(Reader* rd) {
        if (reader != nullptr) delete reader;
        reader = rd;
    }
    void Read(const std::string& url)
    {
        reader->Parce(url);
    }
    ~ResourceReader() { delete reader; }
};

class NewsReader : public Reader {
public:
    void Parce(const std::string& url) {
        std::cout << "News reader " << url << std::endl;
    }

};

class FacebookReader : public Reader {
public:
    void Parce(const std::string& url) {
        std::cout << "Facebook reader " << url << std::endl;
    }

};
class TelegramReader : public Reader {
public:
    void Parce(const std::string& url) {
        std::cout << "Telegram Reader" << url << std::endl;
    }

};


int main()
{
    ResourceReader reader;
    reader.SetReader(new NewsReader);
    std::string url = "http://korrespondent.net";
    reader.Read(url);

    url = "https://facebook.com";
    reader.SetReader(new FacebookReader);
    reader.Read(url);

    url = "@telegram_read";
    reader.SetReader(new TelegramReader);
    reader.Read(url);


}


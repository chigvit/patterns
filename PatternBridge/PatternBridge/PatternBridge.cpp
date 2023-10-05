// PatternBridge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class DataReader {
private:
  
public:
   virtual std::string getData() = 0;
};

class DatabaseReader : public DataReader{
    std::string data;
public:
    std::string getData() override
    {
        data = "This data from database";
        return data;
    }
};

class DataFileReader : public DataReader {
    std::string data;
public:
    std::string getData() override
    {
        data = "This data from FILE";
        return data;
    }
};

class Sender {
protected:
    std::unique_ptr<DataReader> data_reader;
public:
    Sender(DataReader* dr) :data_reader(dr) {}
    void setReader(DataReader* dr) { data_reader.reset(dr); }

    virtual void sendData() = 0;
};


class EmailSender : public Sender {
public:
    EmailSender(DataReader* reader) :Sender(reader) {}
    void sendData() { std::cout << data_reader.get()->getData() << " Send by Email" << std::endl; }
};

class TelegramSender : public Sender {
public:
    TelegramSender(DataReader* reader) :Sender(reader) {}

    void sendData() { std::cout << data_reader.get()->getData() << " Send by Telegram" << std::endl; }
};
int main()
{
    std::shared_ptr<Sender> sender =  std::make_shared< EmailSender>(new DatabaseReader) ;
    sender-> sendData();

    sender->setReader(new DataFileReader);
    sender->sendData();

    sender = std::make_shared<TelegramSender>(new DatabaseReader);
    sender->sendData();

}


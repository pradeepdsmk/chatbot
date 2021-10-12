class Brain
{
private:
    uint a[100][100][100];
    std::string inputStr;
    const std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 `~!@#$%^&*()-_=+\\|[]{};':\",./<>?";
    bool isEnglish = true;
    ushort letterMap[128] = {0};

public:
    Brain();
    ~Brain();
    void getUserInput();
    void updateNeurons();
    void showMap();
};
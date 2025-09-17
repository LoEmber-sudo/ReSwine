
class SLogger {
public:
    char LogFileName[256];
    char AppName[256];
    int LogLevel;
    bool Logging;
    bool LogToFile;
    int LogBufferUsed;
    char LogBufferContent[512][524];

    SLogger(const char* fileName, const char* appname, int logLevel, bool logToFile);

    void Log(int loglev, const char* message, ...);
    void WriteBufferToLog();
};

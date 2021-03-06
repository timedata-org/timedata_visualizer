#include <timedata_visualizer/juce/JuceApplication.h>

namespace timedata {

inline static StringCaller& globalCallback() {
    static StringCaller callback;
    return callback;
}

inline void quitJuceApplication() {
    MessageManager::callAsync(JUCEApplicationBase::quit);
}

class ApplicationBase final : public juce::JUCEApplicationBase {
  public:
    const String getApplicationName() override { return "timedata_visualizer"; }
    const String getApplicationVersion() override { return "0.0"; }
    bool moreThanOneInstanceAllowed() override { return true; }

    void initialise(const String&) override {
        globalCallback()("{\"event\":\"start\"}");
    }

    void systemRequestedQuit() override {
        quit();
    }

    void shutdown() override {}
    void anotherInstanceStarted(const String&) override {}
    void suspended() override {}
    void resumed() override {}
    void unhandledException(const std::exception*, const String&, int) override
    {}
};

inline juce::JUCEApplicationBase* juce_CreateApplication() {
    return new ApplicationBase();
}

inline void startJuceApplication(StringCaller cb) {
    globalCallback() = cb;
    juce::JUCEApplicationBase::createInstance = &juce_CreateApplication;
    static const char* argv[] = {"timedata_visualizer"};
    juce::JUCEApplicationBase::main(1, argv);
}

inline void callTimedata(std::string const& s) {
    globalCallback()(s.c_str());
}

} // timedata

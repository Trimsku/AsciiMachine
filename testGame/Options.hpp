#ifndef GAME_OPTIONS_HPP
#define GAME_OPTIONS_HPP

class Options {
    private:
        Options() noexcept;
        ~Options() noexcept;
        static Options* singleton_;
        bool _isDebugging;
    public:
        void setDebugging(bool value) noexcept;
        bool isDebugging() noexcept;
        static Options &getInstance() noexcept;
};

#endif
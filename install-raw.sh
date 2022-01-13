cd spam
g++ src/*.cpp src/astd/Container.cpp src/lua/onelua.cpp src/target/*.cpp src/util/*.c* -I src/ -DNDEBUG
sudo install spam /usr/local/bin/spam
cd ..
spam --target-os Linux
./bin/Release/AsciiGame
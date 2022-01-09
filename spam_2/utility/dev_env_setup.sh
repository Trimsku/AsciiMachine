mkdir -p installing
cd installing

architecture=$(uname -m)

echo $OSTYPE
echo $architecture
if [[ $OSTYPE == 'darwin'* && ( $architecture == 'x86_64' || architecture == 'amd64' ) ]]; then
    wget https://github.com/prasmussen/gdrive/releases/download/2.1.1/gdrive_2.1.1_darwin_amd64.tar.gz -O "gdrive.tar.gz" -q
elif [[ $OSTYPE == 'linux-gnu'* && $architecture == 'i386' ]]; then
    wget https://github.com/prasmussen/gdrive/releases/download/2.1.1/gdrive_2.1.1_linux_386.tar.gz -O "gdrive.tar.gz" -q
elif [[ $OSTYPE == 'linux-gnu'* && ( $architecture == 'x86_64' || architecture == 'amd64' ) ]]; then
    wget https://github.com/prasmussen/gdrive/releases/download/2.1.1/gdrive_2.1.1_linux_amd64.tar.gz -O "gdrive.tar.gz" -q
elif [[ $OSTYPE == 'linux-gnu'* && $architecture == 'arm' ]]; then
    wget https://github.com/prasmussen/gdrive/releases/download/2.1.1/gdrive_2.1.1_linux_arm.tar.gz -O "gdrive.tar.gz" -q
elif [[ $OSTYPE == 'linux-gnu'* && $architecture == 'arm64' ]]; then
    wget https://github.com/prasmussen/gdrive/releases/download/2.1.1/gdrive_2.1.1_linux_arm64.tar.gz -O "gdrive.tar.gz" -q
else
    echo "Your OS or architecture doesn't support!"
fi

tar xvzf gdrive.tar.gz
rm -rf gdrive.tar.gz
chmod +x gdrive
sudo install gdrive /usr/bin/gdrive
sudo pacman -Ss 
gdrive list
cd ..
rm -rf installing
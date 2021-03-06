![image](https://github.com/invertNetwork/invert-imagery/blob/master/logos/splash.png)

![](https://github.com/bomb-on/invert-core/workflows/Ubuntu%2016.04/badge.svg) ![](https://github.com/bomb-on/invert-core/workflows/Ubuntu%2018.04/badge.svg) ![](https://github.com/bomb-on/invert-core/workflows/Windows/badge.svg) ![](https://github.com/bomb-on/invert-core/workflows/macOS/badge.svg)

# invert Core (CLI)
Latest Release: v6.4.9

Maintained by invert Developers.

## Information
invert Network is a secure peer-to-peer privacy framework empowering individuals and organizations to anonymously communicate and interact financially in a decentralized and censorship resistant ecosystem.

invert is based on the original Cryptonote protocol and runs on a secure peer-to-peer network technology to operate with no central authority. You control your private keys to your funds, you control your destiny. invert Network is accessible by anyone in the world regardless of his/her geographic location or status. Our blockchain is resistant to any kind of analysis. All your inv transactions and messages are anonymous. invert Network provides an instant secure, untraceable and unlinkable way of encrypted communication - crypto messages.

invert is open-source, community driven and truly decentralized. No one owns it, everyone can take part.

## Resources
- Web: [https://invert.network](https://invert.network/)
- GitHub: [https://github.com/invertNetwork/invert-core](https://github.com/invertNetwork/invert-core)
- Wiki: [https://invert.network/wiki](https://invert.network/wiki/doku.php)
- Explorer: [https://explorer.invert.network](https://explorer.invert.network)
- Paperwallet: [https://invert.network/paperwallet](https://invert.network/paperwallet/)
- Discord: [https://discord.gg/YbpHVSd](https://discord.gg/YbpHVSd)
- Twitter: [https://twitter.com/invertNetwork](https://twitter.com/invertNetwork)
- Medium: [https://medium.com/@invertNetwork](https://medium.com/@invertNetwork)
- Reddit: [https://www.reddit.com/r/invertNetwork/](https://www.reddit.com/r/invertNetwork/)
- Bitcoin Talk: [https://bitcointalk.org/index.php?topic=4515873](https://bitcointalk.org/index.php?topic=4515873)


## Compiling invert from source

### System Memory

The build process can consume upto 13GB of memory and may fail if enough resources are not available.
In some build scenarios it may be necessary to increase the size of the SWAP to compensate for less RAM.

For example if you have 8GB of RAM, then your SWAP size should be 5GB

- Ubuntu / Linux
	```bash
	sudo fallocate -l 5G /swapfile
	sudo chmod 600 /swapfile
	sudo mkswap /swapfile
	sudo swapon /swapfile
	```

- Rasberry Pi OS
	```bash
	sudo dphys-swapfile swapoff
	sudo nano /etc/dphys-swapfile
	CONF_SWAPSIZE=5120
	sudo nano /sbin/dphys-swapfile
	#CONF_MAXSWAP=2048
	sudo dphys-swapfile setup
	sudo dphys-swapfile swapon
	```

### Linux / Ubuntu

#### Prerequisites

- You will need the following dependencies to build the invert CLI: boost, cmake, git, gcc, g++, python, and make.
- On Ubuntu: `sudo apt-get install -y build-essential python-dev gcc g++ git cmake libboost-all-dev`

#### Building

- `git clone https://github.com/invertNetwork/invert-core`
- `cd invert-core`
- `mkdir build && cd $_`
- `cmake ..`
- `make`

If the build is successful the binaries will be in the `src` folder.

### Raspberry Pi / ARM

Tested on a Raspberry Pi 4 with Raspberry Pi OS (32/64bit) images.

Other ARM CPU/OS combinations should be possible if the CPU supports Neon/AES.

- Follow the Linux / Ubuntu procedure to build.

### Windows 10

#### Prerequisites

- Install [Visual Studio 2019 Community Edition](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&rel=16)
- Install [CMake](https://cmake.org/download/)
- When installing Visual Studio, you need to install **Desktop development with C++** and the **MSVC v142 - VS 2019 C++ x64/x86 build tools** components. The option to install the v142 build tools can be found by expanding the "Desktop development with C++" node on the right. You will need this for the project to build correctly.
- Install [Boost 1.73.0](https://sourceforge.net/projects/boost/files/boost-binaries/1.73.0/boost_1_73_0-msvc-14.2-64.exe/download), **ensuring** you download the installer for **MSVC 14.2**.

#### Building

From the start menu, open 'x64 Native Tools Command Prompt for vs2019' or run "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsMSBuildCmd.bat" from any command prompt.

```bash
git clone https://github.com/invertNetwork/invert-core
cd invert-core
mkdir build
cmake .. -G "Visual Studio 16 2019" -A x64 -DBOOST_LIBRARYDIR="c:\local\boost_1_73_0\lib64-msvc-14.2"
msbuild invertX.sln /p:Configuration=Release /m
```

If the build is successful the binaries will be in the `src/Release` folder.

### macOS

#### Prerequisites

In order to install prerequisites, [XCode](https://developer.apple.com/xcode/) and [Homebrew](https://brew.sh/) needs to be installed.
Once both are ready, open Terminal app and run the following command to install additional tools:

```bash
$ xcode-select --install
```

On newer macOS versions (v10.14 and higher) this step is done through Software Update in System Preferences.

After that, proceed with installing dependencies:

```bash
$ brew install git python cmake gcc boost
```

#### Building

When all dependencies are installed, build invert Core binaries:

```bash
$ git clone https://github.com/invertNetwork/invert-core
$ cd invert-core
$ mkdir build && cd $_
$ cmake ..
$ make
```

If the build is successful the binaries will be located in `src` directory.

#### Special Thanks
Special thanks goes out to the developers from Cryptonote, Bytecoin, Monero, Forknote, TurtleCoin, Karbo and Masari.

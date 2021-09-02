
Install dependencies:

```bash
sudo apt-get install gcc git wget make libncurses-dev flex bison gperf
```

Get the toolchain (I prefer to place it under $HOME):

```bash
mkdir -p $HOME/.espressif && curl -s https://dl.espressif.com/dl/xtensa-lx106-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz | tar -xz -C $HOME/.espressif
```

Add binaries to the path:

```bash
export PATH="$HOME/.espressif/xtensa-lx106-elf/bin:$PATH"
```

Remember to add current user to dialout group:

```bash
sudo usermod -a -G dialout $USER
```

Clone the SDK (IDF_PATH should point to this directory):

```bash
git clone https://github.com/espressif/ESP8266_RTOS_SDK.git
```

Install python deps:

```bash
./install.sh
```

Reference: https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html

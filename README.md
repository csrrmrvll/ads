# ads

## Install the C++ toolchain (GNU complier tools and GDB)

[vscode c++ config](https://code.visualstudio.com/docs/cpp/config-wsl)

```txt
sudo apt install build-essential gdb -y
```

## Add the needed flags to compiler call

```txt
- I {ads-path}/include/ -std=c++20
```

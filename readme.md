perl: warning: Please check that your locale settings:

$ sudo apt install locales-all

### google test
# https://blog.csdn.net/joelcat/article/details/90766192
wget -O googletest-1.8.1.tar.gz https://github.com/google/googletest/archive/release-1.8.1.tar.gz
tar -zxf googletest-1.8.1.tar.gz
cd googletest-release-1.8.1
mkdir build && cd build
cmake ..
make
sudo make install
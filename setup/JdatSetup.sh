#!/bin/bash

if [ "$EUID" -ne 0 ]; then 
  echo "Please run as root (use sudo)"
  exit
fi

echo "Installing Jdat to /usr/bin and /usr/local/include..."
BASE_URL="https://github.com/TON_USERNAME/TON_REPO/releases/latest/download"

curl -L -o /usr/local/lib/libjdat.so "$BASE_URL/libjdat.so"
curl -L -o /usr/local/include/jdat.h "$BASE_URL/jdat.h"

ldconfig

echo "Installation complete."
echo "libjdat.so installed in /usr/local/lib"
echo "jdat.h installed in /usr/local/include"
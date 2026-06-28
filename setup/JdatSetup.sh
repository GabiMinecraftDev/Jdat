#!/bin/bash

if [ "$EUID" -ne 0 ]; then 
  echo "Please run as root (use sudo)"
  exit
fi

echo "Installing Jdat to /usr/bin and /usr/local/include..."
BASE_URL="https://github.com/GabiMinecraftDev/Jdat"

curl -L -o /usr/local/Jdat/libjdat.so "$BASE_URL/bin/libjdat.so"
curl -L -o /usr/local/Jdat/jdat.h "$BASE_URL/include/jdat.h"

ldconfig

echo "Installation complete."
echo "libjdat.so installed in /usr/local/Jdat"
echo "jdat.h installed in /usr/local/Jdat"

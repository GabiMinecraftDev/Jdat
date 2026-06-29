#!/bin/bash

DEST_DIR="/usr/local/lib/jdat"

echo "Installing Jdat to $DEST_DIR..."

mkdir -p "$DEST_DIR"

BASE_URL="https://github.com/GabiMinecraftDev/blob/main"

curl -L -o "$DEST_DIR/libjdat.so" "$BASE_URL/bin/libjdat.so" || { echo "Erreur lors du téléchargement de libjdat.so"; exit 1; }
curl -L -o "$DEST_DIR/jdat.h" "$BASE_URL/include/jdat.h" || { echo "Erreur lors du téléchargement de jdat.h"; exit 1; }

echo "Installation complete."
echo "Library location: $DEST_DIR/libjdat.so"
echo "Header location: $DEST_DIR/jdat.h"

pause

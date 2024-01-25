#!/bin/bash

display() {
  local code=$1
  printf "\e[48;5;${code}m%4d\e[0m" ${code}
}

echo "Basic 8 Colors:"
for color in {0..7}; do
  display $color
done
echo
echo

echo "Bright 8 Colors:"
for color in {8..15}; do
  display $color
done
echo
echo

echo "256-Color Palette:"
for color in {16..231}; do
  display $color
  if [ $(( ($color - 15) % 6 )) -eq 0 ]; then
    echo
  fi
done
echo

echo "Grayscale Colors:"
for color in {232..243}; do
  display $color
done
echo

for color in {244..255}; do
  display $color
done
echo

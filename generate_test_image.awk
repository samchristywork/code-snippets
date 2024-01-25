#!/usr/bin/awk -f

BEGIN {
  # Header
  print "P3"
  print "256 256"
  print "255"

  for (y = 0; y < 256; y++) {
    for (x = 0; x < 256; x++) {
      red = x
      green = y

      if (((int(x / 16) + int(y / 16)) % 2) == 0) {
        blue = 255
      } else {
        blue = 0
      }

      print red, green, blue
    }
  }
}
